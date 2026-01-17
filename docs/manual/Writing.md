\page writing 4. Writing

\note
The contents of this page are derived from [libpng-manual.txt](https://github.com/pnggroup/libpng/blob/v1.6.54/libpng-manual.txt). It is released under the libpng license.

[TOC]

Much of this is very similar to reading.  However, everything of
importance is repeated here, so you won't have to constantly look
back up in the reading section to understand writing.

## Setup

You will want to do the I/O initialization before you get into libpng,
so if it doesn't work, you don't have anything to undo. If you are not
using the standard I/O functions, you will need to replace them with
custom writing functions.  See the discussion under Customizing libpng.

```c
    FILE *fp = fopen(file_name, "wb");

    if (!fp)
       return ERROR;
```

Next, png_struct and png_info need to be allocated and initialized.
As these can be both relatively large, you may not want to store these
on the stack, unless you have stack space to spare.  Of course, you
will want to check if they return NULL.  If you are also reading,
you won't want to name your read structure and your write structure
both `png_ptr`; you can call them anything you like, such as
`read_ptr` and `write_ptr`.  Look at `pngtest.c`, for example.

```c
    png_structp png_ptr = png_create_write_struct
       (PNG_LIBPNG_VER_STRING, (png_voidp)user_error_ptr,
        user_error_fn, user_warning_fn);

    if (!png_ptr)
       return ERROR;

    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr)
    {
       png_destroy_write_struct(&png_ptr, NULL);
       return ERROR;
    }
```

If you want to use your own memory allocation routines,
define `PNG_USER_MEM_SUPPORTED` and use
`png_create_write_struct_2()` instead of `png_create_write_struct()`:

```c
    png_structp png_ptr = png_create_write_struct_2
       (PNG_LIBPNG_VER_STRING, (png_voidp)user_error_ptr,
        user_error_fn, user_warning_fn, (png_voidp)
        user_mem_ptr, user_malloc_fn, user_free_fn);
```

After you have these structures, you will need to set up the
error handling.  When libpng encounters an error, it expects to
`longjmp()` back to your routine.  Therefore, you will need to call
`setjmp()` and pass the `png_jmpbuf(png_ptr)`.  If you
write the file from different routines, you will need to update
the `png_jmpbuf(png_ptr)` every time you enter a new routine that will
call a `png_*()` function.  See your documentation of setjmp/longjmp
for your compiler for more information on setjmp/longjmp.  See
the discussion on libpng error handling in the Customizing Libpng
section below for more information on the libpng error handling.

```c
    if (setjmp(png_jmpbuf(png_ptr)))
    {
       png_destroy_write_struct(&png_ptr, &info_ptr);
       fclose(fp);
       return ERROR;
    }
    ...
    return;
```

If you would rather avoid the complexity of setjmp/longjmp issues,
you can compile libpng with `PNG_NO_SETJMP`, in which case
errors will result in a call to `PNG_ABORT()` which defaults to `abort()`.

You can `#define PNG_ABORT()` to a function that does something
more useful than `abort()`, as long as your function does not
return.

Checking for invalid palette index on write was added at libpng
1.5.10.  If a pixel contains an invalid (out-of-range) index libpng issues
a benign error.  This is enabled by default because this condition is an
error according to the PNG specification, Clause 11.3.2, but the error can
be ignored in each png_ptr with

```c
   png_set_check_for_invalid_index(png_ptr, 0);
```

If the error is ignored, or if `png_benign_error()` treats it as a warning,
any invalid pixels are written as-is by the encoder, resulting in an
invalid PNG datastream as output.  In this case the application is
responsible for ensuring that the pixel indexes are in range when it writes
a PLTE chunk with fewer entries than the bit depth would allow.

Now you need to set up the output code.  The default for libpng is to
use the C function `fwrite()`.  If you use this, you will need to pass a
valid `FILE *` in the `function png_init_io()`.  Be sure that the file is
opened in binary mode.  Again, if you wish to handle writing data in
another way, see the discussion on libpng I/O handling in the Customizing
Libpng section below.

```c
    png_init_io(png_ptr, fp);
```

If you are embedding your PNG into a datastream such as MNG, and don't
want libpng to write the 8-byte signature, or if you have already
written the signature in your application, use

```c
    png_set_sig_bytes(png_ptr, 8);
```

to inform libpng that it should not write a signature.

## Write callbacks

At this point, you can set up a callback function that will be
called after each row has been written, which you can use to control
a progress meter or the like.  It's demonstrated in pngtest.c.
You must supply a function

```c
    void write_row_callback(png_structp png_ptr, png_uint_32 row,
       int pass)
    {
       /* put your code here */
    }
```

(You can give it another name that you like instead of `write_row_callback`)

To inform libpng about your function, use

```c
    png_set_write_status_fn(png_ptr, write_row_callback);
```

When this function is called the row has already been completely processed and
it has also been written out.  The 'row' and 'pass' refer to the next row to be
handled.  For the
non-interlaced case the row that was just handled is simply one less than the
passed in row number, and pass will always be 0.  For the interlaced case the
same applies unless the row value is 0, in which case the row just handled was
the last one from one of the preceding passes.  Because interlacing may skip a
pass you cannot be sure that the preceding pass is just 'pass-1', if you really
need to know what the last pass is record (row,pass) from the callback and use
the last recorded value each time.

As with the user transform you can find the output row using the
`PNG_ROW_FROM_PASS_ROW` macro.

You now have the option of modifying how the compression library will
run.  The following functions are mainly for testing, but may be useful
in some cases, like if you need to write PNG files extremely fast and
are willing to give up some compression, or if you want to get the
maximum possible compression at the expense of slower writing.  If you
have no special needs in this area, let the library do what it wants by
not calling this function at all, as it has been tuned to deliver a good
speed/compression ratio. The second parameter to `png_set_filter()` is
the filter method, for which the only valid values are 0 (as of the
July 1999 PNG specification, version 1.2) or 64 (if you are writing
a PNG datastream that is to be embedded in a MNG datastream).  The third
parameter is a flag that indicates which filter type(s) are to be tested
for each scanline.  See the PNG specification for details on the specific
filter types.

```c
    /* turn on or off filtering, and/or choose
       specific filters.  You can use either a single
       PNG_FILTER_VALUE_NAME or the bitwise OR of one
       or more PNG_FILTER_NAME masks.
     */
    png_set_filter(png_ptr, 0,
       PNG_FILTER_NONE  | PNG_FILTER_VALUE_NONE |
       PNG_FILTER_SUB   | PNG_FILTER_VALUE_SUB  |
       PNG_FILTER_UP    | PNG_FILTER_VALUE_UP   |
       PNG_FILTER_AVG   | PNG_FILTER_VALUE_AVG  |
       PNG_FILTER_PAETH | PNG_FILTER_VALUE_PAETH|
       PNG_ALL_FILTERS  | PNG_FAST_FILTERS);
```

If an application wants to start and stop using particular filters during
compression, it should start out with all of the filters (to ensure that
the previous row of pixels will be stored in case it's needed later),
and then add and remove them after the start of compression.

If you are writing a PNG datastream that is to be embedded in a MNG
datastream, the second parameter can be either 0 or 64.

The `png_set_compression_*()` functions interface to the zlib compression
library, and should mostly be ignored unless you really know what you are
doing.  The only generally useful call is `png_set_compression_level()`
which changes how much time zlib spends on trying to compress the image
data.  See the Compression Library (`zlib.h` and algorithm.txt, distributed
with zlib) for details on the compression levels.

```c
    #include zlib.h

    /* Set the zlib compression level */
    png_set_compression_level(png_ptr,
        Z_BEST_COMPRESSION);

    /* Set other zlib parameters for compressing IDAT */
    png_set_compression_mem_level(png_ptr, 8);
    png_set_compression_strategy(png_ptr,
        Z_DEFAULT_STRATEGY);
    png_set_compression_window_bits(png_ptr, 15);
    png_set_compression_method(png_ptr, 8);
    png_set_compression_buffer_size(png_ptr, 8192)

    /* Set zlib parameters for text compression
     * If you don't call these, the parameters
     * fall back on those defined for IDAT chunks
     */
    png_set_text_compression_mem_level(png_ptr, 8);
    png_set_text_compression_strategy(png_ptr,
        Z_DEFAULT_STRATEGY);
    png_set_text_compression_window_bits(png_ptr, 15);
    png_set_text_compression_method(png_ptr, 8);
```

## Setting the contents of info for output

You now need to fill in the png_info structure with all the data you
wish to write before the actual image.  Note that the only thing you
are allowed to write after the image is the text chunks and the time
chunk (as of PNG Specification 1.2, anyway).  See `png_write_end()` and
the latest PNG specification for more information on that.  If you
wish to write them before the image, fill them in now, and flag that
data as being valid.  If you want to wait until after the data, don't
fill them until `png_write_end()`.  For all the fields in png_info and
their data types, see `png.h`.  For explanations of what the fields
contain, see the PNG specification.

Some of the more important parts of the png_info are:

```c
    png_set_IHDR(png_ptr, info_ptr, width, height,
       bit_depth, color_type, interlace_type,
       compression_type, filter_method)

    width          - holds the width of the image
                     in pixels (up to 2^31).

    height         - holds the height of the image
                     in pixels (up to 2^31).

    bit_depth      - holds the bit depth of one of the
                     image channels.
                     (valid values are 1, 2, 4, 8, 16
                     and depend also on the
                     color_type.  See also significant
                     bits (sBIT) below).

    color_type     - describes which color/alpha
                     channels are present.
                     PNG_COLOR_TYPE_GRAY
                        (bit depths 1, 2, 4, 8, 16)
                     PNG_COLOR_TYPE_GRAY_ALPHA
                        (bit depths 8, 16)
                     PNG_COLOR_TYPE_PALETTE
                        (bit depths 1, 2, 4, 8)
                     PNG_COLOR_TYPE_RGB
                        (bit_depths 8, 16)
                     PNG_COLOR_TYPE_RGB_ALPHA
                        (bit_depths 8, 16)

                     PNG_COLOR_MASK_PALETTE
                     PNG_COLOR_MASK_COLOR
                     PNG_COLOR_MASK_ALPHA

    interlace_type - PNG_INTERLACE_NONE or
                     PNG_INTERLACE_ADAM7

    compression_type - (must be
                     PNG_COMPRESSION_TYPE_DEFAULT)

    filter_method  - (must be PNG_FILTER_TYPE_DEFAULT
                     or, if you are writing a PNG to
                     be embedded in a MNG datastream,
                     can also be
                     PNG_INTRAPIXEL_DIFFERENCING)
```

If you call `png_set_IHDR()`, the call must appear before any of the
other `png_set_*()` functions, because they might require access to some of
the IHDR settings.  The remaining `png_set_*()` functions can be called
in any order.

If you wish, you can reset the compression_type, interlace_type, or
filter_method later by calling `png_set_IHDR()` again; if you do this, the
width, height, bit_depth, and color_type must be the same in each call.

```c
    png_set_PLTE(png_ptr, info_ptr, palette,
       num_palette);

    palette        - the palette for the file
                     (array of png_color)
    num_palette    - number of entries in the palette


    png_set_gAMA(png_ptr, info_ptr, file_gamma);
    png_set_gAMA_fixed(png_ptr, info_ptr, int_file_gamma);

    file_gamma     - the gamma at which the image was
                     created (PNG_INFO_gAMA)

    int_file_gamma - 100,000 times the gamma at which
                     the image was created

    png_set_cHRM(png_ptr, info_ptr,  white_x, white_y, red_x, red_y,
                     green_x, green_y, blue_x, blue_y)
    png_set_cHRM_XYZ(png_ptr, info_ptr, red_X, red_Y, red_Z, green_X,
                     green_Y, green_Z, blue_X, blue_Y, blue_Z)
    png_set_cHRM_fixed(png_ptr, info_ptr, int_white_x, int_white_y,
                     int_red_x, int_red_y, int_green_x, int_green_y,
                     int_blue_x, int_blue_y)
    png_set_cHRM_XYZ_fixed(png_ptr, info_ptr, int_red_X, int_red_Y,
                     int_red_Z, int_green_X, int_green_Y, int_green_Z,
                     int_blue_X, int_blue_Y, int_blue_Z)

    {white,red,green,blue}_{x,y}
                     A color space encoding specified using the chromaticities
                     of the end points and the white point.

    {red,green,blue}_{X,Y,Z}
                     A color space encoding specified using the encoding end
                     points - the CIE tristimulus specification of the intended
                     color of the red, green and blue channels in the PNG RGB
                     data.  The white point is simply the sum of the three end
                     points.

    png_set_sRGB(png_ptr, info_ptr, srgb_intent);

    srgb_intent    - the rendering intent
                     (PNG_INFO_sRGB) The presence of
                     the sRGB chunk means that the pixel
                     data is in the sRGB color space.
                     This chunk also implies specific
                     values of gAMA and cHRM.  Rendering
                     intent is the CSS-1 property that
                     has been defined by the International
                     Color Consortium
                     (http://www.color.org).
                     It can be one of
                     PNG_sRGB_INTENT_SATURATION,
                     PNG_sRGB_INTENT_PERCEPTUAL,
                     PNG_sRGB_INTENT_ABSOLUTE, or
                     PNG_sRGB_INTENT_RELATIVE.


    png_set_sRGB_gAMA_and_cHRM(png_ptr, info_ptr,
       srgb_intent);

    srgb_intent    - the rendering intent
                     (PNG_INFO_sRGB) The presence of the
                     sRGB chunk means that the pixel
                     data is in the sRGB color space.
                     This function also causes gAMA and
                     cHRM chunks with the specific values
                     that are consistent with sRGB to be
                     written.

    png_set_iCCP(png_ptr, info_ptr, name, compression_type,
                       profile, proflen);

    name             - The profile name.

    compression_type - The compression type; always
                       PNG_COMPRESSION_TYPE_BASE for PNG 1.0.
                       You may give NULL to this argument to
                       ignore it.

    profile          - International Color Consortium color
                       profile data. May contain NULs.

    proflen          - length of profile data in bytes.

    png_set_sBIT(png_ptr, info_ptr, sig_bit);

    sig_bit        - the number of significant bits for
                     (PNG_INFO_sBIT) each of the gray, red,
                     green, and blue channels, whichever are
                     appropriate for the given color type
                     (png_color_16)

    png_set_tRNS(png_ptr, info_ptr, trans_alpha,
       num_trans, trans_color);

    trans_alpha    - array of alpha (transparency)
                     entries for palette (PNG_INFO_tRNS)

    num_trans      - number of transparent entries
                     (PNG_INFO_tRNS)

    trans_color    - graylevel or color sample values
                     (in order red, green, blue) of the
                     single transparent color for
                     non-paletted images (PNG_INFO_tRNS)

    png_set_eXIf_1(png_ptr, info_ptr, num_exif, exif);

    exif           - Exif profile (array of png_byte)
                     (PNG_INFO_eXIf)

    png_set_hIST(png_ptr, info_ptr, hist);

    hist           - histogram of palette (array of
                     png_uint_16) (PNG_INFO_hIST)

    png_set_tIME(png_ptr, info_ptr, mod_time);

    mod_time       - time image was last modified
                     (PNG_INFO_tIME)

    png_set_bKGD(png_ptr, info_ptr, background);

    background     - background color (of type
                     png_color_16p) (PNG_INFO_bKGD)

    png_set_text(png_ptr, info_ptr, text_ptr, num_text);

    text_ptr       - array of png_text holding image
                     comments

    text_ptr[i].compression - type of compression used
                 on "text" PNG_TEXT_COMPRESSION_NONE
                           PNG_TEXT_COMPRESSION_zTXt
                           PNG_ITXT_COMPRESSION_NONE
                           PNG_ITXT_COMPRESSION_zTXt
    text_ptr[i].key   - keyword for comment.  Must contain
                 1-79 characters.
    text_ptr[i].text  - text comments for current
                         keyword.  Can be NULL or empty.
    text_ptr[i].text_length - length of text string,
                 after decompression, 0 for iTXt
    text_ptr[i].itxt_length - length of itxt string,
                 after decompression, 0 for tEXt/zTXt
    text_ptr[i].lang  - language of comment (NULL or
                         empty for unknown).
    text_ptr[i].translated_keyword  - keyword in UTF-8 (NULL
                         or empty for unknown).

    Note that the itxt_length, lang, and lang_key
    members of the text_ptr structure only exist when the
    library is built with iTXt chunk support.  Prior to
    libpng-1.4.0 the library was built by default without
    iTXt support. Also note that when iTXt is supported,
    they contain NULL pointers when the "compression"
    field contains PNG_TEXT_COMPRESSION_NONE or
    PNG_TEXT_COMPRESSION_zTXt.

    num_text       - number of comments

    png_set_sPLT(png_ptr, info_ptr, &palette_ptr,
       num_spalettes);

    palette_ptr    - array of png_sPLT_struct structures
                     to be added to the list of palettes
                     in the info structure.
    num_spalettes  - number of palette structures to be
                     added.

    png_set_oFFs(png_ptr, info_ptr, offset_x, offset_y,
        unit_type);

    offset_x  - positive offset from the left
                     edge of the screen

    offset_y  - positive offset from the top
                     edge of the screen

    unit_type - PNG_OFFSET_PIXEL, PNG_OFFSET_MICROMETER

    png_set_pHYs(png_ptr, info_ptr, res_x, res_y,
        unit_type);

    res_x       - pixels/unit physical resolution
                  in x direction

    res_y       - pixels/unit physical resolution
                  in y direction

    unit_type   - PNG_RESOLUTION_UNKNOWN,
                  PNG_RESOLUTION_METER

    png_set_sCAL(png_ptr, info_ptr, unit, width, height)

    unit        - physical scale units (an integer)

    width       - width of a pixel in physical scale units

    height      - height of a pixel in physical scale units
                  (width and height are doubles)

    png_set_sCAL_s(png_ptr, info_ptr, unit, width, height)

    unit        - physical scale units (an integer)

    width       - width of a pixel in physical scale units
                  expressed as a string

    height      - height of a pixel in physical scale units
                 (width and height are strings like "2.54")

    png_set_unknown_chunks(png_ptr, info_ptr, &unknowns,
       num_unknowns)

    unknowns          - array of png_unknown_chunk
                        structures holding unknown chunks
    unknowns[i].name  - name of unknown chunk
    unknowns[i].data  - data of unknown chunk
    unknowns[i].size  - size of unknown chunk's data
    unknowns[i].location - position to write chunk in file
                           0: do not write chunk
                           PNG_HAVE_IHDR: before PLTE
                           PNG_HAVE_PLTE: before IDAT
                           PNG_AFTER_IDAT: after IDAT
```

The "location" member is set automatically according to
what part of the output file has already been written.
You can change its value after calling `png_set_unknown_chunks()`
as demonstrated in `pngtest.c`.  Within each of the "locations",
the chunks are sequenced according to their position in the
structure (that is, the value of "i", which is the order in which
the chunk was either read from the input file or defined with
png_set_unknown_chunks).

A quick word about text and num_text.  text is an array of png_text
structures.  num_text is the number of valid structures in the array.
Each png_text structure holds a language code, a keyword, a text value,
and a compression type.

The compression types have the same valid numbers as the compression
types of the image data.  Currently, the only valid number is zero.
However, you can store text either compressed or uncompressed, unlike
images, which always have to be compressed.  So if you don't want the
text compressed, set the compression type to `PNG_TEXT_COMPRESSION_NONE`.
Because tEXt and zTXt chunks don't have a language field, if you
specify `PNG_TEXT_COMPRESSION_NONE` or `PNG_TEXT_COMPRESSION_zTXt`
any language code or translated keyword will not be written out.

Until text gets around a few hundred bytes, it is not worth compressing it.
After the text has been written out to the file, the compression type
is set to `PNG_TEXT_COMPRESSION_NONE_WR` or `PNG_TEXT_COMPRESSION_zTXt_WR`,
so that it isn't written out again at the end (in case you are calling
`png_write_end()` with the same struct).

The keywords that are given in the PNG Specification are:

```c
    Title            Short (one line) title or
                     caption for image

    Author           Name of image's creator

    Description      Description of image (possibly long)

    Copyright        Copyright notice

    Creation Time    Time of original image creation
                     (usually RFC 1123 format, see below)

    Software         Software used to create the image

    Disclaimer       Legal disclaimer

    Warning          Warning of nature of content

    Source           Device used to create the image

    Comment          Miscellaneous comment; conversion
                     from other image format
```

The keyword-text pairs work like this.  Keywords should be short
simple descriptions of what the comment is about.  Some typical
keywords are found in the PNG specification, as is some recommendations
on keywords.  You can repeat keywords in a file.  You can even write
some text before the image and some after.  For example, you may want
to put a description of the image before the image, but leave the
disclaimer until after, so viewers working over modem connections
don't have to wait for the disclaimer to go over the modem before
they start seeing the image.  Finally, keywords should be full
words, not abbreviations.  Keywords and text are in the ISO 8859-1
(Latin-1) character set (a superset of regular ASCII) and can not
contain NUL characters, and should not contain control or other
unprintable characters.  To make the comments widely readable, stick
with basic ASCII, and avoid machine specific character set extensions
like the IBM-PC character set.  The keyword must be present, but
you can leave off the text string on non-compressed pairs.
Compressed pairs must have a text string, as only the text string
is compressed anyway, so the compression would be meaningless.

PNG supports modification time via the png_time structure.  Two
conversion routines are provided, `png_convert_from_time_t()` for
`time_t` and `png_convert_from_struct_tm()` for `struct tm`.  The
`time_t` routine uses `gmtime()`.  You don't have to use either of
these, but if you wish to fill in the png_time structure directly,
you should provide the time in universal time (GMT) if possible
instead of your local time.  Note that the year number is the full
year (e.g. 1998, rather than 98 - PNG is year 2000 compliant!), and
that months start with 1.

If you want to store the time of the original image creation, you should
use a plain tEXt chunk with the "Creation Time" keyword.  This is
necessary because the "creation time" of a PNG image is somewhat vague,
depending on whether you mean the PNG file, the time the image was
created in a non-PNG format, a still photo from which the image was
scanned, or possibly the subject matter itself.  In order to facilitate
machine-readable dates, it is recommended that the "Creation Time"
tEXt chunk use RFC 1123 format dates (e.g. `22 May 1997 18:07:10 GMT`),
although this isn't a requirement.  Unlike the tIME chunk, the
"Creation Time" tEXt chunk is not expected to be automatically changed
by the software.  To facilitate the use of RFC 1123 dates, a function
`png_convert_to_rfc1123_buffer(buffer, png_timep)` is provided to
convert from PNG time to an RFC 1123 format string.  The caller must provide
a writeable buffer of at least 29 bytes.

## Writing unknown chunks

You can use the png_set_unknown_chunks function to queue up private chunks
for writing.  You give it a chunk name, location, raw data, and a size.  You
also must use `png_set_keep_unknown_chunks()` to ensure that libpng will
handle them.  That's all there is to it.  The chunks will be written by the
next following `png_write_info_before_PLTE`, `png_write_info`, or `png_write_end`
function, depending upon the specified location.  Any chunks previously
read into the info structure's unknown-chunk list will also be written out
in a sequence that satisfies the PNG specification's ordering rules.

Here is an example of writing two private chunks, prVt and miNE:

```c
    #ifdef PNG_WRITE_UNKNOWN_CHUNKS_SUPPORTED
    /* Set unknown chunk data */
    png_unknown_chunk unk_chunk[2];
    strcpy((char *) unk_chunk[0].name, "prVt";
    unk_chunk[0].data = (unsigned char *) "PRIVATE DATA";
    unk_chunk[0].size = strlen(unk_chunk[0].data)+1;
    unk_chunk[0].location = PNG_HAVE_IHDR;
    strcpy((char *) unk_chunk[1].name, "miNE";
    unk_chunk[1].data = (unsigned char *) "MY CHUNK DATA";
    unk_chunk[1].size = strlen(unk_chunk[0].data)+1;
    unk_chunk[1].location = PNG_AFTER_IDAT;
    png_set_unknown_chunks(write_ptr, write_info_ptr,
        unk_chunk, 2);
    /* Needed because miNE is not safe-to-copy */
    png_set_keep_unknown_chunks(png, PNG_HANDLE_CHUNK_ALWAYS,
       (png_bytep) "miNE", 1);
    #endif
```

## The high-level write interface

At this point there are two ways to proceed; through the high-level
write interface, or through a sequence of low-level write operations.
You can use the high-level interface if your image data is present
in the info structure.  All defined output
transformations are permitted, enabled by the following masks.

```c
    PNG_TRANSFORM_IDENTITY      No transformation
    PNG_TRANSFORM_PACKING       Pack 1, 2 and 4-bit samples
    PNG_TRANSFORM_PACKSWAP      Change order of packed
                                pixels to LSB first
    PNG_TRANSFORM_INVERT_MONO   Invert monochrome images
    PNG_TRANSFORM_SHIFT         Normalize pixels to the
                                sBIT depth
    PNG_TRANSFORM_BGR           Flip RGB to BGR, RGBA
                                to BGRA
    PNG_TRANSFORM_SWAP_ALPHA    Flip RGBA to ARGB or GA
                                to AG
    PNG_TRANSFORM_INVERT_ALPHA  Change alpha from opacity
                                to transparency
    PNG_TRANSFORM_SWAP_ENDIAN   Byte-swap 16-bit samples
    PNG_TRANSFORM_STRIP_FILLER        Strip out filler
                                      bytes (deprecated).
    PNG_TRANSFORM_STRIP_FILLER_BEFORE Strip out leading
                                      filler bytes
    PNG_TRANSFORM_STRIP_FILLER_AFTER  Strip out trailing
                                      filler bytes
```

If you have valid image data in the info structure (you can use
`png_set_rows()` to put image data in the info structure), simply do this:

```c
    png_write_png(png_ptr, info_ptr, png_transforms, NULL)
```

where png_transforms is an integer containing the bitwise OR of some set of
transformation flags.  This call is equivalent to `png_write_info()`,
followed the set of transformations indicated by the transform mask,
then `png_write_image()`, and finally `png_write_end()`.

(The final parameter of this call is not yet used.  Someday it might point
to transformation parameters required by some future output transform.)

You must use png_transforms and not call any `png_set_transform()` functions
when you use `png_write_png()`.

## The low-level write interface

If you are going the low-level route instead, you are now ready to
write all the file information up to the actual image data.  You do
this with a call to `png_write_info()`.

```c
    png_write_info(png_ptr, info_ptr);
```

Note that there is one transformation you may need to do before
`png_write_info()`.  In PNG files, the alpha channel in an image is the
level of opacity.  If your data is supplied as a level of transparency,
you can invert the alpha channel before you write it, so that 0 is
fully transparent and 255 (in 8-bit or paletted images) or 65535
(in 16-bit images) is fully opaque, with

```c
    png_set_invert_alpha(png_ptr);
```

This must appear before `png_write_info()` instead of later with the
other transformations because in the case of paletted images the tRNS
chunk data has to be inverted before the tRNS chunk is written.  If
your image is not a paletted image, the tRNS data (which in such cases
represents a single color to be rendered as transparent) won't need to
be changed, and you can safely do this transformation after your
`png_write_info()` call.

If you need to write a private chunk that you want to appear before
the PLTE chunk when PLTE is present, you can write the PNG info in
two steps, and insert code to write your own chunk between them:

```c
    png_write_info_before_PLTE(png_ptr, info_ptr);
    png_set_unknown_chunks(png_ptr, info_ptr, ...);
    png_write_info(png_ptr, info_ptr);
```

After you've written the file information, you can set up the library
to handle any special transformations of the image data.  The various
ways to transform the data will be described in the order that they
should occur.  This is important, as some of these change the color
type and/or bit depth of the data, and some others only work on
certain color types and bit depths.  Even though each transformation
checks to see if it has data that it can do something with, you should
make sure to only enable a transformation if it will be valid for the
data.  For example, don't swap red and blue on grayscale data.

PNG files store RGB pixels packed into 3 or 6 bytes.  This code tells
the library to strip input data that has 4 or 8 bytes per pixel down
to 3 or 6 bytes (or strip 2 or 4-byte grayscale+filler data to 1 or 2
bytes per pixel).

```c
    png_set_filler(png_ptr, 0, PNG_FILLER_BEFORE);
```

where the 0 is unused, and the location is either PNG_FILLER_BEFORE or
PNG_FILLER_AFTER, depending upon whether the filler byte in the pixel
is stored XRGB or RGBX.

PNG files pack pixels of bit depths 1, 2, and 4 into bytes as small as
they can, resulting in, for example, 8 pixels per byte for 1 bit files.
If the data is supplied at 1 pixel per byte, use this code, which will
correctly pack the pixels into a single byte:

```c
    png_set_packing(png_ptr);
```

PNG files reduce possible bit depths to 1, 2, 4, 8, and 16.  If your
data is of another bit depth, you can write an sBIT chunk into the
file so that decoders can recover the original data if desired.

```c
    /* Set the true bit depth of the image data */
    if (color_type & PNG_COLOR_MASK_COLOR)
    {
       sig_bit.red = true_bit_depth;
       sig_bit.green = true_bit_depth;
       sig_bit.blue = true_bit_depth;
    }

    else
    {
       sig_bit.gray = true_bit_depth;
    }

    if (color_type & PNG_COLOR_MASK_ALPHA)
    {
       sig_bit.alpha = true_bit_depth;
    }

    png_set_sBIT(png_ptr, info_ptr, &sig_bit);
```

If the data is stored in the row buffer in a bit depth other than
one supported by PNG (e.g. 3 bit data in the range 0-7 for a 4-bit PNG),
this will scale the values to appear to be the correct bit depth as
is required by PNG.

```c
    png_set_shift(png_ptr, &sig_bit);
```

PNG files store 16-bit pixels in network byte order (big-endian,
ie. most significant bits first).  This code would be used if they are
supplied the other way (little-endian, i.e. least significant bits
first, the way PCs store them):

```c
    if (bit_depth > 8)
       png_set_swap(png_ptr);
```

If you are using packed-pixel images (1, 2, or 4 bits/pixel), and you
need to change the order the pixels are packed into bytes, you can use:

```c
    if (bit_depth < 8)
       png_set_packswap(png_ptr);
```

PNG files store 3 color pixels in red, green, blue order.  This code
would be used if they are supplied as blue, green, red:

```c
    png_set_bgr(png_ptr);
```

PNG files describe monochrome as black being zero and white being
one. This code would be used if the pixels are supplied with this reversed
(black being one and white being zero):

```c
    png_set_invert_mono(png_ptr);
```

Finally, you can write your own transformation function if none of
the existing ones meets your needs.  This is done by setting a callback
with

```c
    png_set_write_user_transform_fn(png_ptr,
       write_transform_fn);
```

You must supply the function

```c
    void write_transform_fn(png_structp png_ptr, png_row_infop
       row_info, png_bytep data)
```

See pngtest.c for a working example.  Your function will be called
before any of the other transformations are processed.  If supported
libpng also supplies an information routine that may be called from
your callback:

```c
   png_get_current_row_number(png_ptr);
   png_get_current_pass_number(png_ptr);
```

This returns the current row passed to the transform.  With interlaced
images the value returned is the row in the input sub-image image.  Use
`PNG_ROW_FROM_PASS_ROW(row, pass)` and `PNG_COL_FROM_PASS_COL(col, pass)` to
find the output pixel (x,y) given an interlaced sub-image pixel (row,col,pass).

The discussion of interlace handling above contains more information on how to
use these values.

You can also set up a pointer to a user structure for use by your
callback function.

```c
    png_set_user_transform_info(png_ptr, user_ptr, 0, 0);
```

The user_channels and user_depth parameters of this function are ignored
when writing; you can set them to zero as shown.

You can retrieve the pointer via the function `png_get_user_transform_ptr()`.
For example:

```c
    voidp write_user_transform_ptr =
       png_get_user_transform_ptr(png_ptr);
```

It is possible to have libpng flush any pending output, either manually,
or automatically after a certain number of lines have been written.  To
flush the output stream a single time call:

```c
    png_write_flush(png_ptr);
```

and to have libpng flush the output stream periodically after a certain
number of scanlines have been written, call:

```c
    png_set_flush(png_ptr, nrows);
```

Note that the distance between rows is from the last time `png_write_flush()`
was called, or the first row of the image if it has never been called.
So if you write 50 lines, and then png_set_flush 25, it will flush the
output on the next scanline, and every 25 lines thereafter, unless
`png_write_flush()` is called before 25 more lines have been written.
If nrows is too small (less than about 10 lines for a 640 pixel wide
RGB image) the image compression may decrease noticeably (although this
may be acceptable for real-time applications).  Infrequent flushing will
only degrade the compression performance by a few percent over images
that do not use flushing.

## Writing the image data

That's it for the transformations.  Now you can write the image data.
The simplest way to do this is in one function call.  If you have the
whole image in memory, you can just call `png_write_image()` and libpng
will write the image.  You will need to pass in an array of pointers to
each row.  This function automatically handles interlacing, so you don't
need to call `png_set_interlace_handling()` or call this function multiple
times, or any of that other stuff necessary with `png_write_rows()`.

```c
    png_write_image(png_ptr, row_pointers);
```

where row_pointers is:

```c
    png_byte *row_pointers[height];
```

You can point to void or char or whatever you use for pixels.

If you don't want to write the whole image at once, you can
use `png_write_rows()` instead.  If the file is not interlaced,
this is simple:

```c
    png_write_rows(png_ptr, row_pointers,
       number_of_rows);
```

row_pointers is the same as in the `png_write_image()` call.

If you are just writing one row at a time, you can do this with
a single row_pointer instead of an array of row_pointers:

```c
    png_bytep row_pointer = row;

    png_write_row(png_ptr, row_pointer);
```

When the file is interlaced, things can get a good deal more complicated.
The only currently (as of the PNG Specification version 1.2, dated July
1999) defined interlacing scheme for PNG files is the "Adam7" interlace
scheme, that breaks down an image into seven smaller images of varying
size.  libpng will build these images for you, or you can do them
yourself.  If you want to build them yourself, see the PNG specification
for details of which pixels to write when.

If you don't want libpng to handle the interlacing details, just
use `png_set_interlace_handling()` and call `png_write_rows()` the
correct number of times to write all the sub-images
(`png_set_interlace_handling()` returns the number of sub-images.)

If you want libpng to build the sub-images, call this before you start
writing any rows:

```c
    number_of_passes = png_set_interlace_handling(png_ptr);
```

This will return the number of passes needed.  Currently, this is seven,
but may change if another interlace type is added.

Then write the complete image number_of_passes times.

```c
    png_write_rows(png_ptr, row_pointers, number_of_rows);
```

Think carefully before you write an interlaced image.  Typically code that
reads such images reads all the image data into memory, uncompressed, before
doing any processing.  Only code that can display an image on the fly can
take advantage of the interlacing and even then the image has to be exactly
the correct size for the output device, because scaling an image requires
adjacent pixels and these are not available until all the passes have been
read.

If you do write an interlaced image you will hardly ever need to handle
the interlacing yourself.  Call `png_set_interlace_handling()` and use the
approach described above.

The only time it is conceivable that you will really need to write an
interlaced image pass-by-pass is when you have read one pass by pass and
made some pixel-by-pixel transformation to it, as described in the read
code above.  In this case use the `PNG_PASS_ROWS` and `PNG_PASS_COLS` macros
to determine the size of each sub-image in turn and simply write the rows
you obtained from the read code.

## Finishing a sequential write

After you are finished writing the image, you should finish writing
the file.  If you are interested in writing comments or time, you should
pass an appropriately filled png_info pointer.  If you are not interested,
you can pass NULL.

```c
    png_write_end(png_ptr, info_ptr);
```

When you are done, you can free all memory used by libpng like this:

```c
    png_destroy_write_struct(&png_ptr, &info_ptr);
```

It is also possible to individually free the info_ptr members that
point to libpng-allocated storage with the following function:

```c
    png_free_data(png_ptr, info_ptr, mask, seq)

    mask  - identifies data to be freed, a mask
            containing the bitwise OR of one or
            more of
              PNG_FREE_PLTE, PNG_FREE_TRNS,
              PNG_FREE_HIST, PNG_FREE_ICCP,
              PNG_FREE_PCAL, PNG_FREE_ROWS,
              PNG_FREE_SCAL, PNG_FREE_SPLT,
              PNG_FREE_TEXT, PNG_FREE_UNKN,
            or simply PNG_FREE_ALL

    seq   - sequence number of item to be freed
            (-1 for all items)
```

This function may be safely called when the relevant storage has
already been freed, or has not yet been allocated, or was allocated
by the user  and not by libpng,  and will in those cases do nothing.
The "seq" parameter is ignored if only one item of the selected data
type, such as PLTE, is allowed.  If "seq" is not -1, and multiple items
are allowed for the data type identified in the mask, such as text or
sPLT, only the n'th item in the structure is freed, where n is "seq".

If you allocated data such as a palette that you passed in to libpng
with png_set_*, you must not free it until just before the call to
`png_destroy_write_struct()`.

The default behavior is only to free data that was allocated internally
by libpng.  This can be changed, so that libpng will not free the data,
or so that it will free data that was allocated by the user with `png_malloc()`
or png_calloc() and passed in via a `png_set_*()` function, with

```c
    png_data_freer(png_ptr, info_ptr, freer, mask)

    freer  - one of
               PNG_DESTROY_WILL_FREE_DATA
               PNG_SET_WILL_FREE_DATA
               PNG_USER_WILL_FREE_DATA

    mask   - which data elements are affected
             same choices as in png_free_data()
```

For example, to transfer responsibility for some data from a read structure
to a write structure, you could use

```c
    png_data_freer(read_ptr, read_info_ptr,
       PNG_USER_WILL_FREE_DATA,
       PNG_FREE_PLTE|PNG_FREE_tRNS|PNG_FREE_hIST)

    png_data_freer(write_ptr, write_info_ptr,
       PNG_DESTROY_WILL_FREE_DATA,
       PNG_FREE_PLTE|PNG_FREE_tRNS|PNG_FREE_hIST)
```

thereby briefly reassigning responsibility for freeing to the user but
immediately afterwards reassigning it once more to the write_destroy
function.  Having done this, it would then be safe to destroy the read
structure and continue to use the PLTE, tRNS, and hIST data in the write
structure.

This function only affects data that has already been allocated.
You can call this function before calling after the `png_set_*()` functions
to control whether the user or `png_destroy_*()` is supposed to free the data.
When the user assumes responsibility for libpng-allocated data, the
application must use
`png_free()` to free it, and when the user transfers responsibility to libpng
for data that the user has allocated, the user must have used `png_malloc()`
or `png_calloc()` to allocate it.

If you allocated text_ptr.text, text_ptr.lang, and text_ptr.translated_keyword
separately, do not transfer responsibility for freeing text_ptr to libpng,
because when libpng fills a png_text structure it combines these members with
the key member, and `png_free_data()` will free only text_ptr.key.  Similarly,
if you transfer responsibility for free'ing text_ptr from libpng to your
application, your application must not separately free those members.
For a more compact example of writing a PNG image, see the file example.c.

&larr; Prev | Next &rarr;
---- | ----
\ref reading | \ref simplified_api
