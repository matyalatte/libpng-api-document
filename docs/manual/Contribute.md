\page contributing 9. Contributing

\note
The contents of this page are derived from [libpng-manual.txt](https://github.com/pnggroup/libpng/blob/v1.6.54/libpng-manual.txt). It is released under the libpng license.

[TOC]

## I. Source code repository

Since about February 2009, version 1.2.34, libpng has been under "git" source
control.  The git repository was built from old libpng-x.y.z.tar.gz files
going back to version 0.70.  You can access the git repository (read only)
at

```c
    https://github.com/pnggroup/libpng or
    https://git.code.sf.net/p/libpng/code.git
```

or you can browse it with a web browser at

```c
    https://github.com/pnggroup/libpng or
    https://sourceforge.net/p/libpng/code/ci/libpng16/tree/
```

Patches can be sent to png-mng-implement at lists.sourceforge.net or
uploaded to the libpng bug tracker at

```c
    https://libpng.sourceforge.io/
```

or as a "pull request" to

```c
    https://github.com/pnggroup/libpng/pulls
```

We also accept patches built from the tar or zip distributions, and
simple verbal descriptions of bug fixes, reported either to the
SourceForge bug tracker, to the png-mng-implement at lists.sf.net
mailing list, as github issues.

## II. Coding style

Our coding style is similar to the "Allman" style
(See https://en.wikipedia.org/wiki/Indent_style#Allman_style), with curly
braces on separate lines:

```c
    if (condition)
    {
       action;
    }

    else if (another condition)
    {
       another action;
    }
```

The braces can be omitted from simple one-line actions:

```c
    if (condition)
       return 0;
```

We use 3-space indentation, except for continued statements which
are usually indented the same as the first line of the statement
plus four more spaces.

For macro definitions we use 2-space indentation, always leaving the "#"
in the first column.

```c
    #ifndef PNG_NO_FEATURE
    #  ifndef PNG_FEATURE_SUPPORTED
    #    define PNG_FEATURE_SUPPORTED
    #  endif
    #endif
```

Comments appear with the leading `/*` at the same indentation as
the statement that follows the comment:

```c
    /* Single-line comment */
    statement;

    /* This is a multiple-line
     * comment.
     */
    statement;
```

Very short comments can be placed after the end of the statement
to which they pertain:

```c
    statement;    /* comment */
```

We don't use C++ style (`//`) comments. We have, however,
used them in the past in some now-abandoned MMX assembler
code.

Functions and their curly braces are not indented, and
exported functions are marked with PNGAPI:

```c
 /* This is a public function that is visible to
  * application programmers. It does thus-and-so.
  */
 void PNGAPI
 png_exported_function(png_ptr, png_info, foo)
 {
    body;
 }
```

The return type and decorations are placed on a separate line
ahead of the function name, as illustrated above.

The prototypes for all exported functions appear in png.h,
above the comment that says

```c
    /* Maintainer: Put new public prototypes here ... */
```

We mark all non-exported functions with `/* PRIVATE */`:

```c
 void /* PRIVATE */
 png_non_exported_function(png_ptr, png_info, foo)
 {
    body;
 }
```

The prototypes for non-exported functions (except for those in
pngtest) appear in `pngpriv.h` above the comment that says

```c
  /* Maintainer: Put new private prototypes here ^ */
```

To avoid polluting the global namespace, the names of all exported
functions and variables begin with `png_`, and all publicly visible C
preprocessor macros begin with `PNG`.  We request that applications that
use libpng *not* begin any of their own symbols with either of these strings.

We put a space after the `sizeof` operator and we omit the
optional parentheses around its argument when the argument
is an expression, not a type name, and we always enclose the
sizeof operator, with its argument, in parentheses:

```c
  (sizeof (png_uint_32))
  (sizeof array)
```

Prior to libpng-1.6.0 we used a `png_sizeof()` macro, formatted as
though it were a function.

Control keywords if, for, while, and switch are always followed by a space
to distinguish them from function calls, which have no trailing space.

We put a space after each comma and after each semicolon
in `for` statements, and we put spaces before and after each
C binary operator and after `for` or `while`, and before
`?`.  We don't put a space between a typecast and the expression
being cast, nor do we put one between a function name and the
left parenthesis that follows it:

```c
    for (i = 2; i > 0; --i)
       y[i] = a(x) + (int)b;
```

We prefer `#ifdef` and `#ifndef` to `#if defined()` and `#if !defined()`
when there is only one macro being tested.  We always use parentheses
with `defined`.

We express integer constants that are used as bit masks in hex format,
with an even number of lower-case hex digits, and to make them unsigned
(e.g., 0x00U, 0xffU, 0x0100U) and long if they are greater than 0x7fff
(e.g., 0xffffUL).

We prefer to use underscores rather than camelCase in names, except
for a few type names that we inherit from `zlib.h`.

We prefer `if (something != 0)` and `if (something == 0)` over
`if (something)` and `if (!something)`, respectively, and for pointers
we prefer `if (some_pointer != NULL)` or `if (some_pointer == NULL)`.

We do not use the TAB character for indentation in the C sources.

Lines do not exceed 80 characters.

Other rules can be inferred by inspecting the libpng source.

&larr; Prev | Top
---- | ----
\ref changes | \ref manual
