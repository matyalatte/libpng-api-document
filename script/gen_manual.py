# Script to generate MANUAL.md
# Usage:
#   1. Clone libpng.git into the same directory as gen_manual.py
#   2. Run "python gen_manual.py" (requires python 3.10 or later)
#   3. It generates "MANUAL_GENERATED.md" in the same directory as gen_manual.py

import argparse
import os
import re


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

def contain_one_of_items(s, items):
    for i in items:
        if i in s:
            return True
    return False

def is_head_lv2(line):
    return re.match("^[XIV]*\\. ", line)

def is_head_lv4(line):
    return re.match("^[A-Z]*\\. ", line)

def generate_manual(manual_txt, generated_md):
    print(f"reading {manual_txt}...")
    print(f"writing {generated_md}...")
    with (
        open(manual_txt, "r", encoding="utf-8") as infile,
        open(generated_md, "w") as outfile):
        outfile.write("# Manual\n")
        code_block = ""
        in_code_block = False
        last_line_is_empty = False
        while True:
            line = infile.readline()
            if line == "":
                break
            if in_code_block:
                if last_line_is_empty and (
                    not line == "\n" and
                    not line.startswith(" ") and
                    not line.startswith("/*")):
                    in_code_block = False
                    code_block = code_block[:-1] + "```\n\n"
                    if "I. Introduction" in code_block:
                        outfile.write("[TOC]\n")
                    else:
                        outfile.write(code_block)
            if not in_code_block:
                if re.match("^[XVI]*\\. ", line):
                    line = "## " + line
                elif re.match("^[A-Z][a-z]*\n$", line) and last_line_is_empty:
                    line = "### " + line
                elif re.match("^[A-Z]*\\. ", line):
                    line = "#### " + line
                else:
                    if (last_line_is_empty and
                        (line.startswith(" ") or
                        line.startswith("#") or line.startswith("png_structp"))):
                        in_code_block = True
                        code_block = "```c\n"
                    else:
                        line = re.sub('<(http[^ ]*)>', r'\1', line)
                        line = re.sub('""', '"', line)

            last_line_is_empty = line == "\n"
            if in_code_block:
                code_block += line
            elif not line.startswith(" TABLE OF"):
                outfile.write(line)

def get_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("--manual_txt", default=None, type=str, help="path to libpng-manual.txt")
    parser.add_argument("--generated_md", default=None, type=str, help="path to libpng-api-document-generated.h")
    parser.add_argument("--overwrite_manual", action='store_true',
        help="overwrite libpng-api-document.h instead of generating libpng-api-document-generated.h")
    return parser.parse_args()

if __name__ == "__main__":
    # Get args
    args = get_args()
    manual_txt = args.manual_txt
    generated_md = args.generated_md
    # Set default paths
    base_dir = os.path.dirname(os.path.abspath(__file__))
    if manual_txt is None:
        manual_txt = os.path.join(base_dir, "libpng", "libpng-manual.txt")
    if generated_md is None:
        if args.overwrite_manual:
            generated_md = os.path.join(os.path.dirname(base_dir), "docs", "MANUAL.md")
        else:
            generated_md = os.path.join(base_dir, "MANUAL_GENERATED.md")

    # Generate libpng-api-document.h
    generate_manual(manual_txt, generated_md)
    print("done!")
