\page introduction 1. Introduction

\note
The contents of this page are derived from [libpng-manual.txt](https://github.com/pnggroup/libpng/blob/v1.6.54/libpng-manual.txt). It is released under the libpng license.

This file describes how to use and modify the PNG reference library
(known as libpng) for your own use.  In addition to this
file, example.c is a good starting point for using the library, as
it is heavily commented and should include everything most people
will need.  We assume that libpng is already installed; see the
INSTALL file for instructions on how to configure and install libpng.

For examples of libpng usage, see the files `example.c`, `pngtest.c`,
and the files in the `contrib` directory, all of which are included in
the libpng distribution.

Libpng was written as a companion to the PNG specification, as a way
of reducing the amount of time and effort it takes to support the PNG
file format in application programs.

The PNG specification (Third Edition), June 2025, is available as
a W3C Recommendation at
https://www.w3.org/TR/2025/REC-png-3-20250624/.

The PNG specification (Second Edition), November 2003, is available as
a W3C Recommendation and as an ISO Standard (ISO/IEC 15948:2004 (E)) at
https://www.w3.org/TR/2003/REC-PNG-20031110/.
The W3C and ISO documents have identical technical content.

The PNG-1.2 specification is available at
https://www.libpng.org/pub/png/spec/1.2/.
It is technically equivalent to the PNG specification (Second Edition)
but has some additional material.

The PNG-1.0 specification is available as RFC 2083 at
https://www.libpng.org/pub/png/spec/1.0/ and as a
W3C Recommendation at https://www.w3.org/TR/REC-png-961001.

Some additional chunks are described in the special-purpose public chunks
documents at http://www.libpng.org/pub/png/spec/register/

Other information
about PNG, and the latest version of libpng, can be found at the PNG home
page, http://www.libpng.org/pub/png/.

Most users will not have to modify the library significantly; advanced
users may want to modify it more.  All attempts were made to make it as
complete as possible, while keeping the code easy to understand.
Currently, this library only supports C.  Support for other languages
is being considered.

Libpng has been designed to handle multiple sessions at one time,
to be easily modifiable, to be portable to the vast majority of
machines (ANSI, K&R, 16-, 32-, and 64-bit) available, and to be easy
to use.  The ultimate goal of libpng is to promote the acceptance of
the PNG file format in whatever way possible.  While there is still
work to be done (see the TODO file), libpng should cover the
majority of the needs of its users.

Libpng uses zlib for its compression and decompression of PNG files.
Further information about zlib, and the latest version of zlib, can
be found at the zlib home page, https://zlib.net/.
The zlib compression utility is a general purpose utility that is
useful for more than PNG files, and can be used without libpng.
See the documentation delivered with zlib for more details.
You can usually find the source files for the zlib utility wherever you
find the libpng source files.

Libpng is thread safe, provided the threads are using different
instances of the structures.  Each thread should have its own
png_struct and png_info instances, and thus its own image.
Libpng does not protect itself against two threads using the
same instance of a structure.

&larr; Prev | Next &rarr;
---- | ----
\ref manual | \ref structures
