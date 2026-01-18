\page customizing 6. Modifying/Customizing libpng

\note
The contents of this page are derived from [libpng-manual.txt](https://github.com/pnggroup/libpng/blob/v1.6.54/libpng-manual.txt). It is released under the libpng license.

[TOC]

There are two issues here.  The first is changing how libpng does
standard things like memory allocation, input/output, and error handling.
The second deals with more complicated things like adding new chunks,
adding new transformations, and generally changing how libpng works.
Both of those are compile-time issues; that is, they are generally
determined at the time the code is written, and there is rarely a need
to provide the user with a means of changing them.

\subsection manual_err_and_mem Memory allocation, input/output, and error handling

All of the memory allocation, input/output, and error handling in libpng
goes through callbacks that are user-settable.  The default routines are
in `pngmem.c`, `pngrio.c`, `pngwio.c`, and `pngerror.c`, respectively.  To change
these functions, call the appropriate `png_set_*_fn()` function.

Memory allocation is done through the functions `png_malloc()`, `png_calloc()`,
and `png_free()`.  The `png_malloc()` and `png_free()` functions currently just
call the standard C functions and `png_calloc()` calls `png_malloc()` and then
clears the newly allocated memory to zero; note that `png_calloc(png_ptr, size)`
is not the same as the `calloc(number, size)` function provided by `stdlib.h`.
There is limited support for certain systems with segmented memory
architectures and the types of pointers declared by `png.h` match this; you
will have to use appropriate pointers in your application.  If you prefer
to use a different method of allocating and freeing data, you can use
`png_create_read_struct_2()` or `png_create_write_struct_2()` to register your
own functions as described above.  These functions also provide a void
pointer that can be retrieved via

```c
    mem_ptr = png_get_mem_ptr(png_ptr);
```

Your replacement memory functions must have prototypes as follows:

```c
    png_voidp malloc_fn(png_structp png_ptr,
       png_alloc_size_t size);

    void free_fn(png_structp png_ptr, png_voidp ptr);
```

Your `malloc_fn()` must return NULL in case of failure.  The `png_malloc()`
function will normally call `png_error()` if it receives a NULL from the
system memory allocator or from your replacement `malloc_fn()`.

Your `free_fn()` will never be called with a NULL ptr, since libpng's
`png_free()` checks for NULL before calling `free_fn()`.

Input/Output in libpng is done through `png_read()` and `png_write()`,
which currently just call `fread()` and `fwrite()`.  The `FILE *` is stored in
png_struct and is initialized via `png_init_io()`.  If you wish to change
the method of I/O, the library supplies callbacks that you can set
through the function `png_set_read_fn()` and `png_set_write_fn()` at run
time, instead of calling the `png_init_io()` function.  These functions
also provide a void pointer that can be retrieved via the function
`png_get_io_ptr()`.  For example:

```c
    png_set_read_fn(png_structp read_ptr,
        voidp read_io_ptr, png_rw_ptr read_data_fn)

    png_set_write_fn(png_structp write_ptr,
        voidp write_io_ptr, png_rw_ptr write_data_fn,
        png_flush_ptr output_flush_fn);

    voidp read_io_ptr = png_get_io_ptr(read_ptr);
    voidp write_io_ptr = png_get_io_ptr(write_ptr);
```

The replacement I/O functions must have prototypes as follows:

```c
    void user_read_data(png_structp png_ptr,
        png_bytep data, size_t length);

    void user_write_data(png_structp png_ptr,
        png_bytep data, size_t length);

    void user_flush_data(png_structp png_ptr);
```

The `user_read_data()` function is responsible for detecting and
handling end-of-data errors.

Supplying NULL for the read, write, or flush functions sets them back
to using the default C stream functions, which expect the io_ptr to
point to a standard `*FILE` structure.  It is probably a mistake
to use NULL for one of write_data_fn and output_flush_fn but not both
of them, unless you have built libpng with `PNG_NO_WRITE_FLUSH` defined.
It is an error to read from a write stream, and vice versa.

Error handling in libpng is done through `png_error()` and `png_warning()`.
Errors handled through `png_error()` are fatal, meaning that `png_error()`
should never return to its caller.  Currently, this is handled via
`setjmp()` and `longjmp()` (unless you have compiled libpng with
`PNG_NO_SETJMP`, in which case it is handled via `PNG_ABORT()`),
but you could change this to do things like `exit()` if you should wish,
as long as your function does not return.

On non-fatal errors, `png_warning()` is called
to print a warning message, and then control returns to the calling code.
By default `png_error()` and `png_warning()` print a message on stderr via
`fprintf()` unless the library is compiled with `PNG_NO_CONSOLE_IO` defined
(because you don't want the messages) or `PNG_NO_STDIO` defined (because
`fprintf()` isn't available).  If you wish to change the behavior of the error
functions, you will need to set up your own message callbacks.  These
functions are normally supplied at the time that the png_struct is created.
It is also possible to redirect errors and warnings to your own replacement
functions after `png_create_*_struct()` has been called by calling:

```c
    png_set_error_fn(png_structp png_ptr,
        png_voidp error_ptr, png_error_ptr error_fn,
        png_error_ptr warning_fn);
```

If NULL is supplied for either `error_fn` or `warning_fn`, then the libpng
default function will be used, calling `fprintf()` and/or `longjmp()` if a
problem is encountered.  The replacement error functions should have
parameters as follows:

```c
    void user_error_fn(png_structp png_ptr,
        png_const_charp error_msg);

    void user_warning_fn(png_structp png_ptr,
        png_const_charp warning_msg);
```

Then, within your user_error_fn or `user_warning_fn`, you can retrieve
the error_ptr if you need it, by calling

```c
    png_voidp error_ptr = png_get_error_ptr(png_ptr);
```

The motivation behind using `setjmp()` and `longjmp()` is the C++ throw and
catch exception handling methods.  This makes the code much easier to write,
as there is no need to check every return code of every function call.
However, there are some uncertainties about the status of local variables
after a longjmp, so the user may want to be careful about doing anything
after setjmp returns non-zero besides returning itself.  Consult your
compiler documentation for more details.  For an alternative approach, you
may wish to use the "cexcept" facility (see https://cexcept.sourceforge.io/),
which is illustrated in pngvalid.c and in contrib/visupng.

Beginning in libpng-1.4.0, the `png_set_benign_errors()` API became available.
You can use this to handle certain errors (normally handled as errors)
as warnings.

```c
    png_set_benign_errors (png_ptr, int allowed);

    allowed: 0: treat png_benign_error() as an error.
             1: treat png_benign_error() as a warning.
```

As of libpng-1.6.0, the default condition is to treat benign errors as
warnings while reading and as errors while writing.

\subsection manual_zlib Custom chunks

If you need to read or write custom chunks, you may need to get deeper
into the libpng code.  The library now has mechanisms for storing
and writing chunks of unknown type; you can even declare callbacks
for custom chunks.  However, this may not be good enough if the
library code itself needs to know about interactions between your
chunk and existing `intrinsic' chunks.

If you need to write a new intrinsic chunk, first read the PNG
specification. Acquire a first level of understanding of how it works.
Pay particular attention to the sections that describe chunk names,
and look at how other chunks were designed, so you can do things
similarly.  Second, check out the sections of libpng that read and
write chunks.  Try to find a chunk that is similar to yours and use
it as a template.  More details can be found in the comments inside
the code.  It is best to handle private or unknown chunks in a generic method,
via callback functions, instead of by modifying libpng functions. This
is illustrated in pngtest.c, which uses a callback function to handle a
private "vpAg" chunk and the new "sTER" chunk, which are both unknown to
libpng.

If you wish to write your own transformation for the data, look through
the part of the code that does the transformations, and check out some of
the simpler ones to get an idea of how they work.  Try to find a similar
transformation to the one you want to add and copy off of it.  More details
can be found in the comments inside the code itself.

Configuring for gui/windowing platforms:

You will need to write new error and warning functions that use the GUI
interface, as described previously, and set them to be the error and
warning functions at the time that `png_create_*_struct()` is called,
in order to have them available during the structure initialization.
They can be changed later via `png_set_error_fn()`.  On some compilers,
you may also have to change the memory allocators (`png_malloc`, etc.).

Configuring zlib:

There are special functions to configure the compression.  Perhaps the
most useful one changes the compression level, which currently uses
input compression values in the range 0 - 9.  The library normally
uses the default compression level (`Z_DEFAULT_COMPRESSION = 6`).  Tests
have shown that for a large majority of images, compression values in
the range 3-6 compress nearly as well as higher levels, and do so much
faster.  For online applications it may be desirable to have maximum speed
(`Z_BEST_SPEED = 1`).  With versions of zlib after v0.99, you can also
specify no compression (`Z_NO_COMPRESSION = 0`), but this would create
files larger than just storing the raw bitmap.  You can specify the
compression level by calling:

```c
    #include zlib.h
    png_set_compression_level(png_ptr, level);
```

Another useful one is to reduce the memory level used by the library.
The memory level defaults to 8, but it can be lowered if you are
short on memory (running DOS, for example, where you only have 640K).
Note that the memory level does have an effect on compression; among
other things, lower levels will result in sections of incompressible
data being emitted in smaller stored blocks, with a correspondingly
larger relative overhead of up to 15% in the worst case.

```c
    #include zlib.h
    png_set_compression_mem_level(png_ptr, level);
```

The other functions are for configuring zlib.  They are not recommended
for normal use and may result in writing an invalid PNG file.  See
zlib.h for more information on what these mean.

```c
    #include zlib.h
    png_set_compression_strategy(png_ptr,
        strategy);

    png_set_compression_window_bits(png_ptr,
        window_bits);

    png_set_compression_method(png_ptr, method);
```

This controls the size of the IDAT chunks (default 8192):

```c
    png_set_compression_buffer_size(png_ptr, size);
```

As of libpng version 1.5.4, additional APIs became
available to set these separately for non-IDAT
compressed chunks such as zTXt, iTXt, and iCCP:

```c
    #include zlib.h
    #if PNG_LIBPNG_VER >= 10504
    png_set_text_compression_level(png_ptr, level);

    png_set_text_compression_mem_level(png_ptr, level);

    png_set_text_compression_strategy(png_ptr,
        strategy);

    png_set_text_compression_window_bits(png_ptr,
        window_bits);

    png_set_text_compression_method(png_ptr, method);
    #endif
```

## Controlling row filtering

If you want to control whether libpng uses filtering or not, which
filters are used, and how it goes about picking row filters, you
can call one of these functions.  The selection and configuration
of row filters can have a significant impact on the size and
encoding speed and a somewhat lesser impact on the decoding speed
of an image.  Filtering is enabled by default for RGB and grayscale
images (with and without alpha), but not for paletted images nor
for any images with bit depths less than 8 bits/pixel.

The 'method' parameter sets the main filtering method, which is
currently only '0' in the PNG 1.2 specification.  The 'filters'
parameter sets which filter(s), if any, should be used for each
scanline.  Possible values are `PNG_ALL_FILTERS`, `PNG_NO_FILTERS`,
or `PNG_FAST_FILTERS` to turn filtering on and off, or to turn on
just the fast-decoding subset of filters, respectively.

Individual filter types are `PNG_FILTER_NONE`, `PNG_FILTER_SUB`,
`PNG_FILTER_UP`, `PNG_FILTER_AVG`, `PNG_FILTER_PAETH`, which can be bitwise
ORed together with '|' to specify one or more filters to use.
These filters are described in more detail in the PNG specification.
If you intend to change the filter type during the course of writing
the image, you should start with flags set for all of the filters
you intend to use so that libpng can initialize its internal
structures appropriately for all of the filter types.  (Note that this
means the first row must always be adaptively filtered, because libpng
currently does not allocate the filter buffers until `png_write_row()`
is called for the first time.)

```c
    filters = PNG_NO_FILTERS;
    filters = PNG_ALL_FILTERS;
    filters = PNG_FAST_FILTERS;

    or

    filters = PNG_FILTER_NONE | PNG_FILTER_SUB |
              PNG_FILTER_UP | PNG_FILTER_AVG |
              PNG_FILTER_PAETH;

    png_set_filter(png_ptr, PNG_FILTER_TYPE_BASE,
       filters);

              The second parameter can also be
              PNG_INTRAPIXEL_DIFFERENCING if you are
              writing a PNG to be embedded in a MNG
              datastream.  This parameter must be the
              same as the value of filter_method used
              in png_set_IHDR().
```

## Requesting debug printout

The macro definition `PNG_DEBUG` can be used to request debugging
printout.  Set it to an integer value in the range 0 to 3.  Higher
numbers result in increasing amounts of debugging information.  The
information is printed to the `stderr` file, unless another file
name is specified in the `PNG_DEBUG_FILE` macro definition.

When `PNG_DEBUG > 0`, the following functions (macros) become available:

```c
   png_debug(level, message)
   png_debug1(level, message, p1)
   png_debug2(level, message, p1, p2)
```

in which "level" is compared to `PNG_DEBUG` to decide whether to print
the message, "message" is the formatted string to be printed,
and p1 and p2 are parameters that are to be embedded in the string
according to printf-style formatting directives.  For example,

```c
   png_debug1(2, "foo=%d", foo);
```

is expanded to

```c
   if (PNG_DEBUG > 2)
      fprintf(PNG_DEBUG_FILE, "foo=%d\n", foo);
```

When `PNG_DEBUG` is defined but is zero, the macros aren't defined, but you
can still use `PNG_DEBUG` to control your own debugging:

```c
   #ifdef PNG_DEBUG
       fprintf(stderr, ...);
   #endif
```

When `PNG_DEBUG = 1`, the macros are defined, but only png_debug statements
having level = 0 will be printed.  There aren't any such statements in
this version of libpng, but if you insert some they will be printed.

&larr; Prev | Next &rarr;
---- | ----
\ref simplified_api | \ref mng
