\page mng 7. MNG support

\note
The contents of this page are derived from [libpng-manual.txt](https://github.com/pnggroup/libpng/blob/v1.6.54/libpng-manual.txt). It is released under the libpng license.

The MNG specification (available at http://www.libpng.org/pub/mng) allows
certain extensions to PNG for PNG images that are embedded in MNG datastreams.
Libpng can support some of these extensions.  To enable them, use the
`png_permit_mng_features()` function:

```c
   feature_set = png_permit_mng_features(png_ptr, mask)

   mask is a png_uint_32 containing the bitwise OR of the
        features you want to enable.  These include
        PNG_FLAG_MNG_EMPTY_PLTE
        PNG_FLAG_MNG_FILTER_64
        PNG_ALL_MNG_FEATURES

   feature_set is a png_uint_32 that is the bitwise AND of
      your mask with the set of MNG features that is
      supported by the version of libpng that you are using.
```

It is an error to use this function when reading or writing a standalone
PNG file with the PNG 8-byte signature.  The PNG datastream must be wrapped
in a MNG datastream.  As a minimum, it must have the MNG 8-byte signature
and the MHDR and MEND chunks.  Libpng does not provide support for these
or any other MNG chunks; your application must provide its own support for
them.  You may wish to consider using libmng (available at
https://www.libmng.com/) instead.

&larr; Prev | Next &rarr;
---- | ----
\ref customizing | \ref changes
