\page simplified_api 5. Simplified API

\note
The contents of this page are derived from [libpng-manual.txt](https://github.com/pnggroup/libpng/blob/v1.6.54/libpng-manual.txt). It is released under the libpng license.

[TOC]

The simplified API, which became available in libpng-1.6.0, hides the details
of both libpng and the PNG file format itself.
It allows PNG files to be read into a very limited number of
in-memory bitmap formats or to be written from the same formats.  If these
formats do not accommodate your needs then you can, and should, use the more
sophisticated APIs above - these support a wide variety of in-memory formats
and a wide variety of sophisticated transformations to those formats as well
as a wide variety of APIs to manipulate ancillary information.

To read a PNG file using the simplified API:

  1. Declare a png_image structure (see below) on the stack, set the
     version field to `PNG_IMAGE_VERSION` and the 'opaque' pointer to NULL
     (this is REQUIRED, your program may crash if you don't do it.)

  2. Call the appropriate `png_image_begin_read...` function.

  3. Set the png_image 'format' member to the required sample format.

  4. Allocate a buffer for the image and, if required, the color-map.

  5. Call `png_image_finish_read` to read the image and, if required, the
     color-map into your buffers.


There are no restrictions on the format of the PNG input itself; all valid
color types, bit depths, and interlace methods are acceptable, and the
input image is transformed as necessary to the requested in-memory format
during the `png_image_finish_read()` step.  The only caveat is that if you
request a color-mapped image from a PNG that is full-color or makes
complex use of an alpha channel the transformation is extremely lossy and the
result may look terrible.

To write a PNG file using the simplified API:

  1. Declare a png_image structure on the stack and `memset()`
     it to all zero.

  2. Initialize the members of the structure that describe the
     image, setting the 'format' member to the format of the
     image samples.

  3. Call the appropriate `png_image_write...` function with a
     pointer to the image and, if necessary, the color-map to write
     the PNG data.

png_image is a structure that describes the in-memory format of an image
when it is being read or defines the in-memory format of an image that you
need to write.  The png_image structure contains the following members:

```c
   png_controlp opaque  Initialize to NULL, free with png_image_free
   png_uint_32  version Set to PNG_IMAGE_VERSION
   png_uint_32  width   Image width in pixels (columns)
   png_uint_32  height  Image height in pixels (rows)
   png_uint_32  format  Image format as defined below
   png_uint_32  flags   A bit mask containing informational flags
   png_uint_32  colormap_entries; Number of entries in the color-map
   png_uint_32  warning_or_error;
   char         message[64];
```

In the event of an error or warning the "warning_or_error"
field will be set to a non-zero value and the 'message' field will contain
a '\0' terminated string with the libpng error or warning message.  If both
warnings and an error were encountered, only the error is recorded.  If there
are multiple warnings, only the first one is recorded.

The upper 30 bits of the "warning_or_error" value are reserved; the low two
bits contain a two bit code such that a value more than 1 indicates a failure
in the API just called:

```
   0 - no warning or error
   1 - warning
   2 - error
   3 - error preceded by warning
```

The pixels (samples) of the image have one to four channels whose components
have original values in the range 0 to 1.0:

```
  1: A single gray or luminance channel (G).
  2: A gray/luminance channel and an alpha channel (GA).
  3: Three red, green, blue color channels (RGB).
  4: Three color channels and an alpha channel (RGBA).
```

The channels are encoded in one of two ways:

  a) As a small integer, value 0..255, contained in a single byte.  For the
alpha channel the original value is simply value/255.  For the color or
luminance channels the value is encoded according to the sRGB specification
and matches the 8-bit format expected by typical display devices.

The color/gray channels are not scaled (pre-multiplied) by the alpha
channel and are suitable for passing to color management software.

  b) As a value in the range 0..65535, contained in a 2-byte integer, in
the native byte order of the platform on which the application is running.
All channels can be converted to the original value by dividing by 65535; all
channels are linear.  Color channels use the RGB encoding (RGB end-points) of
the sRGB specification.  This encoding is identified by the
PNG_FORMAT_FLAG_LINEAR flag below.

When the simplified API needs to convert between sRGB and linear colorspaces,
the actual sRGB transfer curve defined in the sRGB specification (see the
article at https://en.wikipedia.org/wiki/SRGB) is used, not the gamma=1/2.2
approximation used elsewhere in libpng.

When an alpha channel is present it is expected to denote pixel coverage
of the color or luminance channels and is returned as an associated alpha
channel: the color/gray channels are scaled (pre-multiplied) by the alpha
value.

The samples are either contained directly in the image data, between 1 and 8
bytes per pixel according to the encoding, or are held in a color-map indexed
by bytes in the image data.  In the case of a color-map the color-map entries
are individual samples, encoded as above, and the image data has one byte per
pixel to select the relevant sample from the color-map.

## PNG_FORMAT_*

The #defines to be used in `png_image::format`.  Each `#define` identifies a
particular layout of channel data and, if present, alpha values.  There are
separate defines for each of the two component encodings.

A format is built up using single bit flag values.  All combinations are
valid.  Formats can be built up from the flag values or you can use one of
the predefined values below.  When testing formats always use the `FORMAT_FLAG`
macros to test for individual features - future versions of the library may
add new flags.

When reading or writing color-mapped images the format should be set to the
format of the entries in the color-map then png_image_{read,write}_colormap
called to read or write the color-map and set the format correctly for the
image data.  Do not set the `PNG_FORMAT_FLAG_COLORMAP` bit directly!

```c
   PNG_FORMAT_FLAG_ALPHA    format with an alpha channel
   PNG_FORMAT_FLAG_COLOR    color format: otherwise grayscale
   PNG_FORMAT_FLAG_LINEAR   2-byte channels else 1-byte
   PNG_FORMAT_FLAG_COLORMAP image data is color-mapped
   PNG_FORMAT_FLAG_BGR      BGR colors, else order is RGB
   PNG_FORMAT_FLAG_AFIRST   alpha channel comes first
```

\note
libpng can be built with particular features disabled. If you see
compiler errors because the definition of one of the following flags has been
compiled out it is because libpng does not have the required support.  It is
possible, however, for the libpng configuration to enable the format on just
read or just write; in that case you may see an error at run time.
You can guard against this by checking for the definition of the
appropriate `_SUPPORTED` macro, one of:
```c
   PNG_SIMPLIFIED_{READ,WRITE}_{BGR,AFIRST}_SUPPORTED
```

Supported formats are as follows.  Future versions of libpng may support more
formats; for compatibility with older versions simply check if the format
macro is defined using #ifdef.  These defines describe the in-memory layout
of the components of the pixels of the image.

First the single byte (sRGB) formats:

```c
   PNG_FORMAT_GRAY
   PNG_FORMAT_GA
   PNG_FORMAT_AG
   PNG_FORMAT_RGB
   PNG_FORMAT_BGR
   PNG_FORMAT_RGBA
   PNG_FORMAT_ARGB
   PNG_FORMAT_BGRA
   PNG_FORMAT_ABGR
```

Then the linear 2-byte formats.  When naming these "Y" is used to
indicate a luminance (gray) channel.  The component order within the pixel
is always the same - there is no provision for swapping the order of the
components in the linear format.  The components are 16-bit integers in
the native byte order for your platform, and there is no provision for
swapping the bytes to a different endian condition.

```c
   PNG_FORMAT_LINEAR_Y
   PNG_FORMAT_LINEAR_Y_ALPHA
   PNG_FORMAT_LINEAR_RGB
   PNG_FORMAT_LINEAR_RGB_ALPHA
```

With color-mapped formats the image data is one byte for each pixel. The byte
is an index into the color-map which is formatted as above.  To obtain a
color-mapped format it is sufficient just to add the `PNG_FOMAT_FLAG_COLORMAP`
to one of the above definitions, or you can use one of the definitions below.

```c
   PNG_FORMAT_RGB_COLORMAP
   PNG_FORMAT_BGR_COLORMAP
   PNG_FORMAT_RGBA_COLORMAP
   PNG_FORMAT_ARGB_COLORMAP
   PNG_FORMAT_BGRA_COLORMAP
   PNG_FORMAT_ABGR_COLORMAP
```

## PNG_IMAGE macros

These are convenience macros to derive information from a png_image
structure.  The `PNG_IMAGE_SAMPLE_` macros return values appropriate to the
actual image sample values - either the entries in the color-map or the
pixels in the image.  The `PNG_IMAGE_PIXEL_` macros return corresponding values
for the pixels and will always return 1 for color-mapped formats.  The
remaining macros return information about the rows in the image and the
complete image.

\note
All the macros that take a `png_image::format` parameter are compile time
constants if the format parameter is, itself, a constant.  Therefore these
macros can be used in array declarations and case labels where required.
Similarly the macros are also pre-processor constants (sizeof is not used) so
they can be used in #if tests.

```c
  PNG_IMAGE_SAMPLE_CHANNELS(fmt)
    Returns the total number of channels in a given format: 1..4

  PNG_IMAGE_SAMPLE_COMPONENT_SIZE(fmt)
    Returns the size in bytes of a single component of a pixel or color-map
    entry (as appropriate) in the image: 1 or 2.

  PNG_IMAGE_SAMPLE_SIZE(fmt)
    This is the size of the sample data for one sample.  If the image is
    color-mapped it is the size of one color-map entry (and image pixels are
    one byte in size), otherwise it is the size of one image pixel.

  PNG_IMAGE_MAXIMUM_COLORMAP_COMPONENTS(fmt)
    The maximum size of the color-map required by the format expressed in a
    count of components.  This can be used to compile-time allocate a
    color-map:

    png_uint_16 colormap[PNG_IMAGE_MAXIMUM_COLORMAP_COMPONENTS(linear_fmt)];

    png_byte colormap[PNG_IMAGE_MAXIMUM_COLORMAP_COMPONENTS(sRGB_fmt)];

    Alternatively use the PNG_IMAGE_COLORMAP_SIZE macro below to use the
    information from one of the png_image_begin_read_ APIs and dynamically
    allocate the required memory.

  PNG_IMAGE_COLORMAP_SIZE(fmt)
   The size of the color-map required by the format; this is the size of the
   color-map buffer passed to the png_image_{read,write}_colormap APIs. It is
   a fixed number determined by the format so can easily be allocated on the
   stack if necessary.
```

Corresponding information about the pixels

```c
  PNG_IMAGE_PIXEL_CHANNELS(fmt)
   The number of separate channels (components) in a pixel; 1 for a
   color-mapped image.

  PNG_IMAGE_PIXEL_COMPONENT_SIZE(fmt)\
   The size, in bytes, of each component in a pixel; 1 for a color-mapped
   image.

  PNG_IMAGE_PIXEL_SIZE(fmt)
   The size, in bytes, of a complete pixel; 1 for a color-mapped image.
```

Information about the whole row, or whole image

```c
  PNG_IMAGE_ROW_STRIDE(image)
   Returns the total number of components in a single row of the image; this
   is the minimum 'row stride', the minimum count of components between each
   row.  For a color-mapped image this is the minimum number of bytes in a
   row.

   If you need the stride measured in bytes, row_stride_bytes is
   PNG_IMAGE_ROW_STRIDE(image) * PNG_IMAGE_PIXEL_COMPONENT_SIZE(fmt)
   plus any padding bytes that your application might need, for example
   to start the next row on a 4-byte boundary.

  PNG_IMAGE_BUFFER_SIZE(image, row_stride)
   Return the size, in bytes, of an image buffer given a png_image and a row
   stride - the number of components to leave space for in each row.

  PNG_IMAGE_SIZE(image)
   Return the size, in bytes, of the image in memory given just a png_image;
   the row stride is the minimum stride required for the image.

  PNG_IMAGE_COLORMAP_SIZE(image)
   Return the size, in bytes, of the color-map of this image.  If the image
   format is not a color-map format this will return a size sufficient for
   256 entries in the given format; check PNG_FORMAT_FLAG_COLORMAP if
   you don't want to allocate a color-map in this case.
```

PNG_IMAGE_FLAG_*

Flags containing additional information about the image are held in
the 'flags' field of png_image.

```c
  PNG_IMAGE_FLAG_COLORSPACE_NOT_sRGB == 0x01
    This indicates that the RGB values of the in-memory bitmap do not
    correspond to the red, green and blue end-points defined by sRGB.

  PNG_IMAGE_FLAG_FAST == 0x02
   On write emphasise speed over compression; the resultant PNG file will be
   larger but will be produced significantly faster, particular for large
   images.  Do not use this option for images which will be distributed, only
   used it when producing intermediate files that will be read back in
   repeatedly.  For a typical 24-bit image the option will double the read
   speed at the cost of increasing the image size by 25%, however for many
   more compressible images the PNG file can be 10 times larger with only a
   slight speed gain.

  PNG_IMAGE_FLAG_16BIT_sRGB == 0x04
    On read if the image is a 16-bit per component image and there is no gAMA
    or sRGB chunk assume that the components are sRGB encoded.  Notice that
    images output by the simplified API always have gamma information; setting
    this flag only affects the interpretation of 16-bit images from an
    external source.  It is recommended that the application expose this flag
    to the user; the user can normally easily recognize the difference between
    linear and sRGB encoding.  This flag has no effect on write - the data
    passed to the write APIs must have the correct encoding (as defined
    above.)

    If the flag is not set (the default) input 16-bit per component data is
    assumed to be linear.

    NOTE: the flag can only be set after the png_image_begin_read_ call,
    because that call initializes the 'flags' field.
```

## READ APIs

   The png_image passed to the read APIs must have been initialized by setting
   the png_controlp field 'opaque' to NULL (or, better, memset the whole thing.)

```c
   int png_image_begin_read_from_file( png_imagep image,
     const char *file_name)

     The named file is opened for read and the image header
     is filled in from the PNG header in the file.
```

```c
   int png_image_begin_read_from_stdio (png_imagep image,
     FILE *file)

      The PNG header is read from the stdio FILE object.
```

```c
   int png_image_begin_read_from_memory(png_imagep image,
      png_const_voidp memory, size_t size)

      The PNG header is read from the given memory buffer.
```

```c
   int png_image_finish_read(png_imagep image,
      png_colorp background, void *buffer,
      png_int_32 row_stride, void *colormap));

      Finish reading the image into the supplied buffer and
      clean up the png_image structure.

      row_stride is the step, in png_byte or png_uint_16 units
      as appropriate, between adjacent rows.  A positive stride
      indicates that the top-most row is first in the buffer -
      the normal top-down arrangement.  A negative stride
      indicates that the bottom-most row is first in the buffer.

      background need only be supplied if an alpha channel must
      be removed from a png_byte format and the removal is to be
      done by compositing on a solid color; otherwise it may be
      NULL and any composition will be done directly onto the
      buffer.  The value is an sRGB color to use for the
      background, for grayscale output the green channel is used.

      For linear output removing the alpha channel is always done
      by compositing on black.
```

```c
   void png_image_free(png_imagep image)

      Free any data allocated by libpng in image->opaque,
      setting the pointer to NULL.  May be called at any time
      after the structure is initialized.
```

When the simplified API needs to convert between sRGB and linear colorspaces,
the actual sRGB transfer curve defined in the sRGB specification (see the
article at https://en.wikipedia.org/wiki/SRGB) is used, not the gamma=1/2.2
approximation used elsewhere in libpng.

## WRITE APIS

For write you must initialize a png_image structure to describe the image to
be written:

```c
   version: must be set to PNG_IMAGE_VERSION
   opaque: must be initialized to NULL
   width: image width in pixels
   height: image height in rows
   format: the format of the data you wish to write
   flags: set to 0 unless one of the defined flags applies; set
      PNG_IMAGE_FLAG_COLORSPACE_NOT_sRGB for color format images
      where the RGB values do not correspond to the colors in sRGB.
   colormap_entries: set to the number of entries in the color-map (0 to 256)
```

```c
   int png_image_write_to_file, (png_imagep image,
      const char *file, int convert_to_8bit, const void *buffer,
      png_int_32 row_stride, const void *colormap));

      Write the image to the named file.
```

```c
   int png_image_write_to_memory (png_imagep image, void *memory,
      png_alloc_size_t * PNG_RESTRICT memory_bytes,
      int convert_to_8_bit, const void *buffer, ptrdiff_t row_stride,
      const void *colormap));

      Write the image to memory.
```

```c
   int png_image_write_to_stdio(png_imagep image, FILE *file,
      int convert_to_8_bit, const void *buffer,
      png_int_32 row_stride, const void *colormap)

      Write the image to the given FILE object.
```

With all write APIs if image is in one of the linear formats with
(`png_uint_16`) data then setting `convert_to_8_bit` will cause the output to be
a (`png_byte`) PNG gamma encoded according to the sRGB specification, otherwise
a 16-bit linear encoded PNG file is written.

With all APIs row_stride is handled as in the read APIs - it is the spacing
from one row to the next in component sized units (float) and if negative
indicates a bottom-up row layout in the buffer.  If you pass zero, libpng will
calculate the row_stride for you from the width and number of channels.

Note that the write API does not support interlacing, sub-8-bit pixels,
indexed (paletted) images, or most ancillary chunks.

&larr; Prev | Next &rarr;
---- | ----
\ref writing | \ref customizing
