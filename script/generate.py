# Script to generate libpng-loader.h
# Usage:
#   1. Put "png.h" and "libpng-api-document-base.h" into the same directory as generate.py
#   2. Run "python generate.py" (requires python 3.10 or later)
#   3. It generates "libpng-api-document-generated.h" in the same directory as generate.py

import argparse
from enum import Enum, auto
import os

class MacroType(Enum):
    UNKNOWN = 0
    CALLBACK = auto()
    FUNCTION = auto()
    EXPORT = auto()
    EXPORTA = auto()
    FP_EXPORT = auto()
    FIXED_EXPORT = auto()

def split_in_two(line, c):
    ret = line.split(c, 1)
    if len(ret) == 1:
        return ret[0].strip(), ""
    return ret[0].strip(), ret[1].strip()

def rsplit_in_two(line, c):
    ret = line.rsplit(c, 1)
    if len(ret) == 1:
        return ret[0].strip(), ""
    return ret[0].strip(), ret[1].strip()

def type_normalize(t):
    if t.endswith("charp"):
        t = t[:-1] + " *"
    if t.endswith("colorp"):
        t = t[:-1] + " *"
    if t.endswith("point_p"):
        t = t[:-2] + " *"
    if t.endswith("rp"):
        t = t[:-2] + " *"
    if t.endswith("pp"):
        t = t[:-2] + " **"
    if t.endswith("p"):
        t = t[:-1] + " *"
    if t.startswith("png_const_"):
        t = "const png_" + t[10:]
    if t.endswith(" PNG_RESTRICT"):
        t = t[:-13]
    return t

class FuncDef:
    def __init__(self):
        self.macro_type = MacroType.UNKNOWN
        self.ordinal = None
        self.return_type = None
        self.name = None
        self.args = None
        self.is_removed = False

        self.reading_args = False
        self.skip_first_arg = False


    def append_arg(self, arg):
        arg_type, arg_name = rsplit_in_two(arg, " ")
        arg_type = type_normalize(arg_type)
        if arg_name.startswith("**"):
            arg_type += " **"
        elif arg_name.startswith("*"):
            arg_type += " *"
        self.args.append(arg_type)

    def is_callback(self):
        return self.macro_type == MacroType.CALLBACK or self.macro_type == MacroType.FUNCTION

    def get_typedef(self):
        if self.is_callback():
            name = self.name
        else:
            name = "*PFN_" + self.name
        return f"typedef {self.return_type} ({name})({", ".join(self.args)});"

    def get_def(self):
        desc = (
            "/**\n"
            " * TODO\n"
        )
        if self.return_type != "void":
            desc += " * @return TODO\n"
        if not (len(self.args) == 1 and self.args[0] == "void"):
            desc += " * @param TODO\n" * len(self.args)
        desc += (
            " * @version unknown\n"
            " */\n"
            f"{self.return_type} {self.name}({", ".join(self.args)})\n"
        )
        return desc

    def read(self, line):
        if self.macro_type == MacroType.UNKNOWN:
            macro, line = split_in_two(line, "(")
            match macro:
                case "typedef PNG_CALLBACK":
                    self.macro_type = MacroType.CALLBACK
                case "PNG_FUNCTION":
                    self.macro_type = MacroType.FUNCTION
                case "PNG_EXPORT":
                    self.macro_type = MacroType.EXPORT
                case "PNG_EXPORTA":
                    self.macro_type = MacroType.EXPORTA
                case "PNG_FP_EXPORT":
                    self.macro_type = MacroType.FP_EXPORT
                case "PNG_FIXED_EXPORT":
                    self.macro_type = MacroType.FIXED_EXPORT
        if not self.is_callback() and self.ordinal is None:
            if line == "":
                return True
            self.ordinal, line = split_in_two(line, ",")
        if self.return_type is None:
            if line == "":
                return True
            ret_type, line = split_in_two(line, ",")
            self.return_type = type_normalize(ret_type)
        if self.name is None:
            if line == "":
                return True
            self.name, line = split_in_two(line, ",")
            if self.macro_type == MacroType.FUNCTION:
                _, self.name = split_in_two(self.name, " ")
                self.name = self.name[:-1]
        if self.args is None:
            self.args = []
            self.reading_args = True
        if self.reading_args:
            line = line.lstrip("(")
            if line == "":
                return True
            while self.reading_args:
                if line == "":
                    return True
                flag = False
                for i in range(0, len(line)):
                    if line[i] == ",":
                        arg, line = split_in_two(line, ",")
                        if self.skip_first_arg:
                            self.skip_first_arg = False
                        else:
                            self.append_arg(arg)
                        flag = True
                        break
                    if line[i] == ")":
                        arg, line = split_in_two(line, ")")
                        if self.skip_first_arg:
                            self.skip_first_arg = False
                        else:
                            self.append_arg(arg)
                        flag = True
                        self.reading_args = False
                        break
                if not flag:
                    self.append_arg(line)
                    self.skip_first_arg = True
                    return True
        return False

class StructDef:
    def __init__(self):
        self.first_line = None
        self.members = None
        self.name = None
        self.reading_members = False

    def read(self, line):
        if self.first_line is None:
            self.first_line = line
            return True
        if self.members is None:
            self.members = []
            self.reading_members = True
            return True
        if line.startswith("}"):
            self.reading_members = False
            line = line[1:]
        if self.reading_members:
            if ";" in line:
                line, _ = split_in_two(line, ";")
            else:
                return True
            member_type, member_name = split_in_two(line, " ")
            member_type = type_normalize(member_type)
            self.members.append([member_type, member_name])
            return True
        if self.name is None:
            if line == "":
                return True
            self.name, _ = split_in_two(line, ";")
            self.name, _ = split_in_two(self.name, ",")
        return False

    def get_typedef(self):
        typedef_str = self.first_line + " {\n"
        for member in self.members:
            typedef_str += f"    {member[0]} {member[1]};\n"
        typedef_str += "} " + self.name + ";\n"
        return typedef_str

def contain_one_of_items(s, items):
    for i in items:
        if i in s:
            return True
    return False

class HeaderGenerator:
    def __init__(self, remove_keywords, remove_functions):
        self.callbacks = []
        self.api_functions = []
        self.structs = []
        self.macros = []
        self.remove_keywords = remove_keywords
        self.remove_functions = remove_functions

    def append_func(self, func):
        if func.is_callback():
            self.callbacks.append(func)
        else:
            self.api_functions.append(func)

    def append_macro(self, macro):
        macro, _ = split_in_two(macro, "//")
        macro, _ = split_in_two(macro, "/*")
        self.macros.append(macro)

    def append_macro_multiline(self, macro):
        macro, _ = split_in_two(macro, "//")
        self.macros[-1] = self.macros[-1] + "\n    " + macro

    def read_png_h(self, filepath):
        with open(filepath, "r", encoding="utf-8") as infile:
            print(f"reading {filepath}...")
            in_comment = False
            in_macro = False
            in_define_macro = False
            in_func = False
            in_struct = False
            in_ifdef = False
            in_else = False
            func_def = FuncDef()
            struct_def = StructDef()

            while True:
                line = infile.readline()
                if line == "":
                    break
                line = line.strip()
                if in_comment:
                    if line.endswith("*/"):
                        in_comment = False
                    continue
                if in_macro:
                    if in_define_macro:
                        self.append_macro_multiline(line)
                    if not line.endswith("\\"):
                        in_macro = False
                        in_define_macro = False
                    continue
                if line.startswith("//"):
                    continue
                if line.startswith("/*"):
                    if not line.endswith("*/"):
                        in_comment = True
                    continue
                if in_else:
                    if line.startswith("#endif"):
                        in_else = False
                    continue
                if line.startswith("#"):
                    if line.startswith("#define"):
                        self.append_macro(line[8:])
                    elif line.startswith("#  define"):
                        self.append_macro(line[10:])
                    if line.endswith("\\"):
                        in_macro = True
                        if line.startswith("#define") or line.startswith("#  define"):
                            in_define_macro = True
                        continue
                    if line.startswith("#ifdef") and ("SUPPORTED" in line):
                        in_ifdef = True
                    elif in_ifdef and line.startswith("#else"):
                        in_ifdef = False
                        in_else = True
                    continue
                if in_struct:
                    in_struct = struct_def.read(line)
                    if not in_struct:
                        self.structs.append(struct_def)
                        struct_def = StructDef()
                    continue
                if line.startswith("typedef struct"):
                    if not line.endswith(";"):
                        in_struct = struct_def.read(line)
                    continue
                if in_func:
                    in_func = func_def.read(line)
                    if not in_func:
                        self.append_func(func_def)
                        func_def = FuncDef()
                    continue
                if (line.startswith("typedef PNG_CALLBACK") or
                    line.startswith("PNG_FUNCTION") or
                    line.startswith("PNG_EXPORT") or
                    line.startswith("PNG_FP_EXPORT") or
                    line.startswith("PNG_FIXED_EXPORT")):
                    in_func = func_def.read(line)
                    if not in_func:
                        self.append_func(func_def)
                        func_def = FuncDef()
            print(f"found {len(self.callbacks)} callbacks.")
            print(f"found {len(self.api_functions)} functions.")
            print(f"found {len(self.structs)} structs.")
            print(f"found {len(self.macros)} macros.")
            for func in self.api_functions:
                if (contain_one_of_items(func.name, self.remove_keywords) or
                    func.name in self.remove_functions):
                    func.is_removed = True
            removed = [func for func in self.api_functions if func.is_removed]
            if len(removed) > 0:
                print("The following functions were removed from libpng-api-document.")
                for func in removed:
                    print(f"  {func.name}")

    def write_loader_h(self, basepath, outpath):
        with open(basepath, "r", encoding="utf-8") as infile:
            print(f"reading {basepath}...")
            base_lines = infile.readlines()[1:]

        with open(outpath, "w", encoding="utf-8") as outfile:
            print(f"writing {outpath}...")
            outfile.write("// This file was generated by script/generate.py\n")
            for i in range(0, len(base_lines)):
                line = base_lines[i]
                if line.startswith("// ------ Macros"):
                    break
                outfile.write(line)
            macro_line = base_lines[i]
            base_lines = base_lines[i + 1:]

            outfile.write("// public structs\n")
            for st in self.structs:
                outfile.write(st.get_typedef())
                outfile.write(
                    "\n"
                    f"typedef {st.name} *{st.name}p;  // deprecated\n"
                    "\n"
                )

            outfile.write(macro_line + "\n")

            for m in self.macros:
                outfile.write(f"#define {m}\n")

            outfile.write(
                "\n"
                "// ------ Callback Types ------\n"
                "\n"
            )
            for func in self.callbacks:
                outfile.write(func.get_typedef() + "\n")
            outfile.write(
                "\n"
                "// ------ Functions ------\n"
                "\n"
            )
            for func in self.api_functions:
                outfile.write(func.get_def() + "\n")

            outfile.write("\n")
            for line in base_lines:
                outfile.write(line)

def get_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("--png_h", default=None, type=str, help="path to png.h")
    parser.add_argument("--base_h", default=None, type=str, help="path to libpng-api-document-base.h")
    parser.add_argument("--generated_h", default=None, type=str, help="path to libpng-api-document-generated.h")
    parser.add_argument("--overwrite_loader", action='store_true',
        help="overwrite libpng-api-document.h instead of generating libpng-api-document-generated.h")
    parser.add_argument(
        "--remove_keywords",
        default="", type=str,
        help="comma separeted list of keywords to remove APIs which contain one of the keywords"
    )
    parser.add_argument(
        "--remove_functions", default="png_set_strip_error_numbers", type=str,
        help="comma separeted list of functions to remove them from libpng-api-document"
    )
    return parser.parse_args()

if __name__ == "__main__":
    # Get args
    args = get_args()
    png_h = args.png_h
    base_h = args.base_h
    generated_h = args.generated_h
    remove_keywords = [s for s in args.remove_keywords.split(",") if len(s) > 0]
    remove_functions = [s for s in args.remove_functions.split(",") if len(s) > 0]

    # Set default paths
    base_dir = os.path.dirname(os.path.abspath(__file__))
    if png_h is None:
        png_h = os.path.join(base_dir, "png.h")
    if base_h is None:
        base_h = os.path.join(base_dir, "libpng-api-document-base.h")
    if generated_h is None:
        if args.overwrite_loader:
            generated_h = os.path.join(os.path.dirname(base_dir), "libpng-api-document.h")
        else:
            generated_h = os.path.join(base_dir, "libpng-api-document-generated.h")

    # Generate libpng-api-document.h
    generator = HeaderGenerator(remove_keywords, remove_functions)
    generator.read_png_h(png_h)
    generator.write_loader_h(base_h, generated_h)
    print("done!")
