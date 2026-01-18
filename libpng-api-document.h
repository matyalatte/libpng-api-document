#ifndef LIBPNG_API_DOCUMENT_H
#define LIBPNG_API_DOCUMENT_H

#include <setjmp.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

// ------ Pages ------
/**
 * @defgroup simple_api Simplified API
 * @brief PNG IO with hiding the details of libpng and file format.
 * @details See the manual: \ref simplified_api "Simplified API"
 */
/**
 * @defgroup reader Reading
 * @brief Functions to read PNG files
 * @details See the manual: \ref reading "Reading"
 */
/**
 * @defgroup writer Writing
 * @brief Functions to write PNG files
 * @details See the manual: \ref writing "Wrting"
 */
/**
 * @defgroup getter Getter
 * @defgroup setter Setter
 */
/**
 * @defgroup progressive Progressive Read
 * @brief Functions to read PNG files progressively
 * @details See the manual: \ref manual_progressive
 */
/**
 * @defgroup error Error Handling
 * @details See the manual: \ref manual_err_and_mem
 */
/**
 * @defgroup memory Memory Management
 * @details See the manual: \ref manual_err_and_mem
 */
/**
 * @defgroup zlib Zlib Options
 * @brief Functions for Zlib configurations
 * @details See the manual: \ref manual_zlib
 */
/**
 * @defgroup versioning Versioning
 * @defgroup other Others
 * @defgroup macro Macros
 */

// ------ Structs ------

typedef void png_void;
typedef char png_char;
typedef uint8_t png_byte;
typedef int16_t png_int_16;
typedef uint16_t png_uint_16;
typedef int32_t png_int_32;
typedef uint32_t png_uint_32;
typedef size_t png_size_t;
typedef size_t png_alloc_size_t;
typedef png_int_32 png_fixed_point;
typedef double png_double;

typedef struct png_struct {
} png_struct;

typedef struct png_info {
} png_info;

typedef struct png_control {
} png_control;

// deprecated pointer type aliases

typedef void                  * png_voidp;
typedef const void            * png_const_voidp;
typedef png_byte              * png_bytep;
typedef const png_byte        * png_const_bytep;
typedef png_uint_32           * png_uint_32p;
typedef const png_uint_32     * png_const_uint_32p;
typedef png_int_32            * png_int_32p;
typedef const png_int_32      * png_const_int_32p;
typedef png_uint_16           * png_uint_16p;
typedef const png_uint_16     * png_const_uint_16p;
typedef png_int_16            * png_int_16p;
typedef const png_int_16      * png_const_int_16p;
typedef char                  * png_charp;
typedef const char            * png_const_charp;
typedef png_fixed_point       * png_fixed_point_p;
typedef const png_fixed_point * png_const_fixed_point_p;
typedef size_t                * png_size_tp;
typedef const size_t          * png_const_size_tp;
typedef double       *png_doublep;
typedef const double *png_const_doublep;
typedef png_byte        **png_bytepp;
typedef png_uint_32     **png_uint_32pp;
typedef png_int_32      **png_int_32pp;
typedef png_uint_16     **png_uint_16pp;
typedef png_int_16      **png_int_16pp;
typedef const char      **png_const_charpp;
typedef char            **png_charpp;
typedef png_fixed_point **png_fixed_point_pp;
typedef double          **png_doublepp;
typedef char ***png_charppp;
typedef FILE *png_FILE_p;
typedef png_struct *png_structp;
typedef const png_struct *png_const_structp;
typedef png_struct **png_structpp;
typedef png_struct *png_structrp;
typedef const png_struct *png_const_structrp;
typedef png_info *png_infop;
typedef const png_info *png_const_infop;
typedef png_info **png_infopp;
typedef png_info *png_inforp;
typedef const png_info *png_const_inforp;
typedef png_control *png_controlp;

// public structs
/**
 * TODO
 * @struct png_color
 */
typedef struct png_color {
    /**
     * TODO
     */
    png_byte red;
    /**
     * TODO
     */
    png_byte green;
    /**
     * TODO
     */
    png_byte blue;
} png_color;

typedef png_color *png_colorp;  // deprecated

/**
 * TODO
 * @struct png_color_16
 */
typedef struct png_color_16 {
    /**
     * TODO
     */
    png_byte index;
    /**
     * TODO
     */
    png_uint_16 red;
    /**
     * TODO
     */
    png_uint_16 green;
    /**
     * TODO
     */
    png_uint_16 blue;
    /**
     * TODO
     */
    png_uint_16 gray;
} png_color_16;

typedef png_color_16 *png_color_16p;  // deprecated

/**
 * TODO
 * @struct png_color_8
 */
typedef struct png_color_8 {
    /**
     * TODO
     */
    png_byte red;
    /**
     * TODO
     */
    png_byte green;
    /**
     * TODO
     */
    png_byte blue;
    /**
     * TODO
     */
    png_byte gray;
    /**
     * TODO
     */
    png_byte alpha;
} png_color_8;

typedef png_color_8 *png_color_8p;  // deprecated

/**
 * TODO
 * @struct png_sPLT_entry
 */
typedef struct png_sPLT_entry {
    /**
     * TODO
     */
    png_uint_16 red;
    /**
     * TODO
     */
    png_uint_16 green;
    /**
     * TODO
     */
    png_uint_16 blue;
    /**
     * TODO
     */
    png_uint_16 alpha;
    /**
     * TODO
     */
    png_uint_16 frequency;
} png_sPLT_entry;

typedef png_sPLT_entry *png_sPLT_entryp;  // deprecated

/**
 * TODO
 * @struct png_sPLT_t
 */
typedef struct png_sPLT_t {
    /**
     * TODO
     */
    png_char * name;
    /**
     * TODO
     */
    png_byte depth;
    /**
     * TODO
     */
    png_sPLT_entry * entries;
    /**
     * TODO
     */
    png_int_32 nentries;
} png_sPLT_t;

typedef png_sPLT_t *png_sPLT_tp;  // deprecated

/**
 * TODO
 * @struct png_text
 */
typedef struct png_text {
    /**
     * TODO
     */
    int compression;
    /**
     * TODO
     */
    png_char * key;
    /**
     * TODO
     */
    png_char * text;
    /**
     * TODO
     */
    size_t text_length;
    /**
     * TODO
     */
    size_t itxt_length;
    /**
     * TODO
     */
    png_char * lang;
    /**
     * TODO
     */
    png_char * lang_key;
} png_text;

typedef png_text *png_textp;  // deprecated

/**
 * TODO
 * @struct png_time
 */
typedef struct png_time {
    /**
     * TODO
     */
    png_uint_16 year;
    /**
     * TODO
     */
    png_byte month;
    /**
     * TODO
     */
    png_byte day;
    /**
     * TODO
     */
    png_byte hour;
    /**
     * TODO
     */
    png_byte minute;
    /**
     * TODO
     */
    png_byte second;
} png_time;

typedef png_time *png_timep;  // deprecated

/**
 * TODO
 * @struct png_unknown_chunk
 */
typedef struct png_unknown_chunk {
    /**
     * TODO
     */
    png_byte name[5];
    /**
     * TODO
     */
    png_byte *data;
    /**
     * TODO
     */
    size_t size;
    /**
     * TODO
     */
    png_byte location;
} png_unknown_chunk;

typedef png_unknown_chunk *png_unknown_chunkp;  // deprecated

/**
 * TODO
 * @struct png_row_info
 */
typedef struct png_row_info {
    /**
     * TODO
     */
    png_uint_32 width;
    /**
     * TODO
     */
    size_t rowbytes;
    /**
     * TODO
     */
    png_byte color_type;
    /**
     * TODO
     */
    png_byte bit_depth;
    /**
     * TODO
     */
    png_byte channels;
    /**
     * TODO
     */
    png_byte pixel_depth;
} png_row_info;

typedef png_row_info *png_row_infop;  // deprecated

/**
 * TODO
 * @struct png_image
 * @ingroup simple_api
 * @since 1.6.0
 */
typedef struct png_image {
    /**
     * TODO
     */
    png_control * opaque;
    /**
     * TODO
     */
    png_uint_32 version;
    /**
     * TODO
     */
    png_uint_32 width;
    /**
     * TODO
     */
    png_uint_32 height;
    /**
     * TODO
     */
    png_uint_32 format;
    /**
     * TODO
     */
    png_uint_32 flags;
    /**
     * TODO
     */
    png_uint_32 colormap_entries;
    /**
     * TODO
     */
    png_uint_32 warning_or_error;
    /**
     * TODO
     */
    char message[64];
} png_image;

typedef png_image *png_imagep;  // deprecated

// ------ Macros ------

/**
 * TODO
 * @def PNG_LIBPNG_VER_STRING
 * @ingroup versioning
 */
#define PNG_LIBPNG_VER_STRING "1.6.54"
/**
 * TODO
 * @def PNG_HEADER_VERSION_STRING
 * @ingroup versioning
 */
#define PNG_HEADER_VERSION_STRING " libpng version " PNG_LIBPNG_VER_STRING "\n"
/**
 * TODO
 * @def PNG_LIBPNG_VER_SHAREDLIB
 * @ingroup versioning
 */
#define PNG_LIBPNG_VER_SHAREDLIB 16
/**
 * TODO
 * @def PNG_LIBPNG_VER_SONUM
 * @ingroup versioning
 */
#define PNG_LIBPNG_VER_SONUM     PNG_LIBPNG_VER_SHAREDLIB
/**
 * TODO
 * @def PNG_LIBPNG_VER_DLLNUM
 * @ingroup versioning
 */
#define PNG_LIBPNG_VER_DLLNUM    PNG_LIBPNG_VER_SHAREDLIB
/**
 * TODO
 * @def PNG_LIBPNG_VER_MAJOR
 * @ingroup versioning
 */
#define PNG_LIBPNG_VER_MAJOR   1
/**
 * TODO
 * @def PNG_LIBPNG_VER_MINOR
 * @ingroup versioning
 */
#define PNG_LIBPNG_VER_MINOR   6
/**
 * TODO
 * @def PNG_LIBPNG_VER_RELEASE
 * @ingroup versioning
 */
#define PNG_LIBPNG_VER_RELEASE 54
/**
 * TODO
 * @def PNG_LIBPNG_VER_BUILD
 * @ingroup versioning
 */
#define PNG_LIBPNG_VER_BUILD 0
/**
 * TODO
 * @def PNG_LIBPNG_VER
 * @ingroup versioning
 */
#define PNG_LIBPNG_VER 10654
/**
 * TODO
 * @def png_libpng_ver
 * @ingroup versioning
 */
#define png_libpng_ver png_get_header_ver(NULL)
/**
 * TODO
 * @def PNG_TEXT_COMPRESSION_NONE_WR
 * @ingroup macro
 */
#define PNG_TEXT_COMPRESSION_NONE_WR -3
/**
 * TODO
 * @def PNG_TEXT_COMPRESSION_zTXt_WR
 * @ingroup macro
 */
#define PNG_TEXT_COMPRESSION_zTXt_WR -2
/**
 * TODO
 * @def PNG_TEXT_COMPRESSION_NONE
 * @ingroup macro
 */
#define PNG_TEXT_COMPRESSION_NONE    -1
/**
 * TODO
 * @def PNG_TEXT_COMPRESSION_zTXt
 * @ingroup macro
 */
#define PNG_TEXT_COMPRESSION_zTXt     0
/**
 * TODO
 * @def PNG_ITXT_COMPRESSION_NONE
 * @ingroup macro
 */
#define PNG_ITXT_COMPRESSION_NONE     1
/**
 * TODO
 * @def PNG_ITXT_COMPRESSION_zTXt
 * @ingroup macro
 */
#define PNG_ITXT_COMPRESSION_zTXt     2
/**
 * TODO
 * @def PNG_TEXT_COMPRESSION_LAST
 * @ingroup macro
 */
#define PNG_TEXT_COMPRESSION_LAST     3
/**
 * TODO
 * @def PNG_HAVE_IHDR
 * @ingroup macro
 */
#define PNG_HAVE_IHDR  0x01
/**
 * TODO
 * @def PNG_HAVE_PLTE
 * @ingroup macro
 */
#define PNG_HAVE_PLTE  0x02
/**
 * TODO
 * @def PNG_AFTER_IDAT
 * @ingroup macro
 */
#define PNG_AFTER_IDAT 0x08
/**
 * TODO
 * @def PNG_UINT_31_MAX
 * @ingroup macro
 */
#define PNG_UINT_31_MAX ((png_uint_32)0x7fffffffL)
/**
 * TODO
 * @def PNG_UINT_32_MAX
 * @ingroup macro
 */
#define PNG_UINT_32_MAX ((png_uint_32)(-1))
/**
 * TODO
 * @def PNG_SIZE_MAX
 * @ingroup macro
 */
#define PNG_SIZE_MAX ((size_t)(-1))
/**
 * TODO
 * @def PNG_FP_1
 * @ingroup macro
 */
#define PNG_FP_1    100000
/**
 * TODO
 * @def PNG_FP_HALF
 * @ingroup macro
 */
#define PNG_FP_HALF  50000
/**
 * TODO
 * @def PNG_FP_MAX
 * @ingroup macro
 */
#define PNG_FP_MAX  ((png_fixed_point)0x7fffffffL)
/**
 * TODO
 * @def PNG_FP_MIN
 * @ingroup macro
 */
#define PNG_FP_MIN  (-PNG_FP_MAX)
/**
 * TODO
 * @def PNG_COLOR_MASK_PALETTE
 * @ingroup macro
 */
#define PNG_COLOR_MASK_PALETTE    1
/**
 * TODO
 * @def PNG_COLOR_MASK_COLOR
 * @ingroup macro
 */
#define PNG_COLOR_MASK_COLOR      2
/**
 * TODO
 * @def PNG_COLOR_MASK_ALPHA
 * @ingroup macro
 */
#define PNG_COLOR_MASK_ALPHA      4
/**
 * TODO
 * @def PNG_COLOR_TYPE_GRAY
 * @ingroup macro
 */
#define PNG_COLOR_TYPE_GRAY 0
/**
 * TODO
 * @def PNG_COLOR_TYPE_PALETTE
 * @ingroup macro
 */
#define PNG_COLOR_TYPE_PALETTE  (PNG_COLOR_MASK_COLOR | PNG_COLOR_MASK_PALETTE)
/**
 * TODO
 * @def PNG_COLOR_TYPE_RGB
 * @ingroup macro
 */
#define PNG_COLOR_TYPE_RGB        (PNG_COLOR_MASK_COLOR)
/**
 * TODO
 * @def PNG_COLOR_TYPE_RGB_ALPHA
 * @ingroup macro
 */
#define PNG_COLOR_TYPE_RGB_ALPHA  (PNG_COLOR_MASK_COLOR | PNG_COLOR_MASK_ALPHA)
/**
 * TODO
 * @def PNG_COLOR_TYPE_GRAY_ALPHA
 * @ingroup macro
 */
#define PNG_COLOR_TYPE_GRAY_ALPHA (PNG_COLOR_MASK_ALPHA)
/**
 * TODO
 * @def PNG_COLOR_TYPE_RGBA
 * @ingroup macro
 */
#define PNG_COLOR_TYPE_RGBA  PNG_COLOR_TYPE_RGB_ALPHA
/**
 * TODO
 * @def PNG_COLOR_TYPE_GA
 * @ingroup macro
 */
#define PNG_COLOR_TYPE_GA  PNG_COLOR_TYPE_GRAY_ALPHA
/**
 * TODO
 * @def PNG_COMPRESSION_TYPE_BASE
 * @ingroup macro
 */
#define PNG_COMPRESSION_TYPE_BASE 0
/**
 * TODO
 * @def PNG_COMPRESSION_TYPE_DEFAULT
 * @ingroup macro
 */
#define PNG_COMPRESSION_TYPE_DEFAULT PNG_COMPRESSION_TYPE_BASE
/**
 * TODO
 * @def PNG_FILTER_TYPE_BASE
 * @ingroup macro
 */
#define PNG_FILTER_TYPE_BASE      0
/**
 * TODO
 * @def PNG_INTRAPIXEL_DIFFERENCING
 * @ingroup macro
 */
#define PNG_INTRAPIXEL_DIFFERENCING 64
/**
 * TODO
 * @def PNG_FILTER_TYPE_DEFAULT
 * @ingroup macro
 */
#define PNG_FILTER_TYPE_DEFAULT   PNG_FILTER_TYPE_BASE
/**
 * TODO
 * @def PNG_INTERLACE_NONE
 * @ingroup macro
 */
#define PNG_INTERLACE_NONE        0
/**
 * TODO
 * @def PNG_INTERLACE_ADAM7
 * @ingroup macro
 */
#define PNG_INTERLACE_ADAM7       1
/**
 * TODO
 * @def PNG_INTERLACE_LAST
 * @ingroup macro
 */
#define PNG_INTERLACE_LAST        2
/**
 * TODO
 * @def PNG_OFFSET_PIXEL
 * @ingroup macro
 */
#define PNG_OFFSET_PIXEL          0
/**
 * TODO
 * @def PNG_OFFSET_MICROMETER
 * @ingroup macro
 */
#define PNG_OFFSET_MICROMETER     1
/**
 * TODO
 * @def PNG_OFFSET_LAST
 * @ingroup macro
 */
#define PNG_OFFSET_LAST           2
/**
 * TODO
 * @def PNG_EQUATION_LINEAR
 * @ingroup macro
 */
#define PNG_EQUATION_LINEAR       0
/**
 * TODO
 * @def PNG_EQUATION_BASE_E
 * @ingroup macro
 */
#define PNG_EQUATION_BASE_E       1
/**
 * TODO
 * @def PNG_EQUATION_ARBITRARY
 * @ingroup macro
 */
#define PNG_EQUATION_ARBITRARY    2
/**
 * TODO
 * @def PNG_EQUATION_HYPERBOLIC
 * @ingroup macro
 */
#define PNG_EQUATION_HYPERBOLIC   3
/**
 * TODO
 * @def PNG_EQUATION_LAST
 * @ingroup macro
 */
#define PNG_EQUATION_LAST         4
/**
 * TODO
 * @def PNG_SCALE_UNKNOWN
 * @ingroup macro
 */
#define PNG_SCALE_UNKNOWN         0
/**
 * TODO
 * @def PNG_SCALE_METER
 * @ingroup macro
 */
#define PNG_SCALE_METER           1
/**
 * TODO
 * @def PNG_SCALE_RADIAN
 * @ingroup macro
 */
#define PNG_SCALE_RADIAN          2
/**
 * TODO
 * @def PNG_SCALE_LAST
 * @ingroup macro
 */
#define PNG_SCALE_LAST            3
/**
 * TODO
 * @def PNG_RESOLUTION_UNKNOWN
 * @ingroup macro
 */
#define PNG_RESOLUTION_UNKNOWN    0
/**
 * TODO
 * @def PNG_RESOLUTION_METER
 * @ingroup macro
 */
#define PNG_RESOLUTION_METER      1
/**
 * TODO
 * @def PNG_RESOLUTION_LAST
 * @ingroup macro
 */
#define PNG_RESOLUTION_LAST       2
/**
 * TODO
 * @def PNG_sRGB_INTENT_PERCEPTUAL
 * @ingroup macro
 */
#define PNG_sRGB_INTENT_PERCEPTUAL 0
/**
 * TODO
 * @def PNG_sRGB_INTENT_RELATIVE
 * @ingroup macro
 */
#define PNG_sRGB_INTENT_RELATIVE   1
/**
 * TODO
 * @def PNG_sRGB_INTENT_SATURATION
 * @ingroup macro
 */
#define PNG_sRGB_INTENT_SATURATION 2
/**
 * TODO
 * @def PNG_sRGB_INTENT_ABSOLUTE
 * @ingroup macro
 */
#define PNG_sRGB_INTENT_ABSOLUTE   3
/**
 * TODO
 * @def PNG_sRGB_INTENT_LAST
 * @ingroup macro
 */
#define PNG_sRGB_INTENT_LAST       4
/**
 * TODO
 * @def PNG_KEYWORD_MAX_LENGTH
 * @ingroup macro
 */
#define PNG_KEYWORD_MAX_LENGTH     79
/**
 * TODO
 * @def PNG_MAX_PALETTE_LENGTH
 * @ingroup macro
 */
#define PNG_MAX_PALETTE_LENGTH    256
/**
 * TODO
 * @def PNG_INFO_gAMA
 * @ingroup macro
 */
#define PNG_INFO_gAMA 0x0001U
/**
 * TODO
 * @def PNG_INFO_sBIT
 * @ingroup macro
 */
#define PNG_INFO_sBIT 0x0002U
/**
 * TODO
 * @def PNG_INFO_cHRM
 * @ingroup macro
 */
#define PNG_INFO_cHRM 0x0004U
/**
 * TODO
 * @def PNG_INFO_PLTE
 * @ingroup macro
 */
#define PNG_INFO_PLTE 0x0008U
/**
 * TODO
 * @def PNG_INFO_tRNS
 * @ingroup macro
 */
#define PNG_INFO_tRNS 0x0010U
/**
 * TODO
 * @def PNG_INFO_bKGD
 * @ingroup macro
 */
#define PNG_INFO_bKGD 0x0020U
/**
 * TODO
 * @def PNG_INFO_hIST
 * @ingroup macro
 */
#define PNG_INFO_hIST 0x0040U
/**
 * TODO
 * @def PNG_INFO_pHYs
 * @ingroup macro
 */
#define PNG_INFO_pHYs 0x0080U
/**
 * TODO
 * @def PNG_INFO_oFFs
 * @ingroup macro
 */
#define PNG_INFO_oFFs 0x0100U
/**
 * TODO
 * @def PNG_INFO_tIME
 * @ingroup macro
 */
#define PNG_INFO_tIME 0x0200U
/**
 * TODO
 * @def PNG_INFO_pCAL
 * @ingroup macro
 */
#define PNG_INFO_pCAL 0x0400U
/**
 * TODO
 * @def PNG_INFO_sRGB
 * @ingroup macro
 */
#define PNG_INFO_sRGB 0x0800U
/**
 * TODO
 * @def PNG_INFO_iCCP
 * @ingroup macro
 */
#define PNG_INFO_iCCP 0x1000U
/**
 * TODO
 * @def PNG_INFO_sPLT
 * @ingroup macro
 */
#define PNG_INFO_sPLT 0x2000U
/**
 * TODO
 * @def PNG_INFO_sCAL
 * @ingroup macro
 */
#define PNG_INFO_sCAL 0x4000U
/**
 * TODO
 * @def PNG_INFO_IDAT
 * @ingroup macro
 */
#define PNG_INFO_IDAT 0x8000U
/**
 * TODO
 * @def PNG_INFO_eXIf
 * @ingroup macro
 */
#define PNG_INFO_eXIf 0x10000U
/**
 * TODO
 * @def PNG_INFO_cICP
 * @ingroup macro
 */
#define PNG_INFO_cICP 0x20000U
/**
 * TODO
 * @def PNG_INFO_cLLI
 * @ingroup macro
 */
#define PNG_INFO_cLLI 0x40000U
/**
 * TODO
 * @def PNG_INFO_mDCV
 * @ingroup macro
 */
#define PNG_INFO_mDCV 0x80000U
/**
 * TODO
 * @def PNG_INFO_acTL
 * @ingroup macro
 */
#define PNG_INFO_acTL 0x100000U
/**
 * TODO
 * @def PNG_INFO_fcTL
 * @ingroup macro
 */
#define PNG_INFO_fcTL 0x200000U
/**
 * TODO
 * @def PNG_INFO_fdAT
 * @ingroup macro
 */
#define PNG_INFO_fdAT 0x400000U
/**
 * TODO
 * @def PNG_TRANSFORM_IDENTITY
 * @ingroup macro
 */
#define PNG_TRANSFORM_IDENTITY       0x0000
/**
 * TODO
 * @def PNG_TRANSFORM_STRIP_16
 * @ingroup macro
 */
#define PNG_TRANSFORM_STRIP_16       0x0001
/**
 * TODO
 * @def PNG_TRANSFORM_STRIP_ALPHA
 * @ingroup macro
 */
#define PNG_TRANSFORM_STRIP_ALPHA    0x0002
/**
 * TODO
 * @def PNG_TRANSFORM_PACKING
 * @ingroup macro
 */
#define PNG_TRANSFORM_PACKING        0x0004
/**
 * TODO
 * @def PNG_TRANSFORM_PACKSWAP
 * @ingroup macro
 */
#define PNG_TRANSFORM_PACKSWAP       0x0008
/**
 * TODO
 * @def PNG_TRANSFORM_EXPAND
 * @ingroup macro
 */
#define PNG_TRANSFORM_EXPAND         0x0010
/**
 * TODO
 * @def PNG_TRANSFORM_INVERT_MONO
 * @ingroup macro
 */
#define PNG_TRANSFORM_INVERT_MONO    0x0020
/**
 * TODO
 * @def PNG_TRANSFORM_SHIFT
 * @ingroup macro
 */
#define PNG_TRANSFORM_SHIFT          0x0040
/**
 * TODO
 * @def PNG_TRANSFORM_BGR
 * @ingroup macro
 */
#define PNG_TRANSFORM_BGR            0x0080
/**
 * TODO
 * @def PNG_TRANSFORM_SWAP_ALPHA
 * @ingroup macro
 */
#define PNG_TRANSFORM_SWAP_ALPHA     0x0100
/**
 * TODO
 * @def PNG_TRANSFORM_SWAP_ENDIAN
 * @ingroup macro
 */
#define PNG_TRANSFORM_SWAP_ENDIAN    0x0200
/**
 * TODO
 * @def PNG_TRANSFORM_INVERT_ALPHA
 * @ingroup macro
 */
#define PNG_TRANSFORM_INVERT_ALPHA   0x0400
/**
 * TODO
 * @def PNG_TRANSFORM_STRIP_FILLER
 * @ingroup macro
 */
#define PNG_TRANSFORM_STRIP_FILLER   0x0800
/**
 * TODO
 * @def PNG_TRANSFORM_STRIP_FILLER_BEFORE
 * @ingroup macro
 */
#define PNG_TRANSFORM_STRIP_FILLER_BEFORE PNG_TRANSFORM_STRIP_FILLER
/**
 * TODO
 * @def PNG_TRANSFORM_STRIP_FILLER_AFTER
 * @ingroup macro
 */
#define PNG_TRANSFORM_STRIP_FILLER_AFTER 0x1000
/**
 * TODO
 * @def PNG_TRANSFORM_GRAY_TO_RGB
 * @ingroup macro
 */
#define PNG_TRANSFORM_GRAY_TO_RGB   0x2000
/**
 * TODO
 * @def PNG_TRANSFORM_EXPAND_16
 * @ingroup macro
 */
#define PNG_TRANSFORM_EXPAND_16     0x4000
/**
 * TODO
 * @def PNG_TRANSFORM_SCALE_16
 * @ingroup macro
 */
#define PNG_TRANSFORM_SCALE_16      0x8000
/**
 * TODO
 * @def PNG_FLAG_MNG_EMPTY_PLTE
 * @ingroup macro
 */
#define PNG_FLAG_MNG_EMPTY_PLTE     0x01
/**
 * TODO
 * @def PNG_FLAG_MNG_FILTER_64
 * @ingroup macro
 */
#define PNG_FLAG_MNG_FILTER_64      0x04
/**
 * TODO
 * @def PNG_ALL_MNG_FEATURES
 * @ingroup macro
 */
#define PNG_ALL_MNG_FEATURES        0x05
/**
 * TODO
 * @def png_check_sig
 * @ingroup macro
 */
#define png_check_sig(sig, n) (png_sig_cmp((sig), 0, (n)) == 0)
/**
 * TODO
 * @def png_jmpbuf
 * @ingroup error
 */
#define png_jmpbuf(png_ptr) \
    (*png_set_longjmp_fn((png_ptr), longjmp, (sizeof (jmp_buf))))
/**
 * TODO
 * @def PNG_ERROR_ACTION_NONE
 * @ingroup macro
 */
#define PNG_ERROR_ACTION_NONE  1
/**
 * TODO
 * @def PNG_ERROR_ACTION_WARN
 * @ingroup macro
 */
#define PNG_ERROR_ACTION_WARN  2
/**
 * TODO
 * @def PNG_ERROR_ACTION_ERROR
 * @ingroup macro
 */
#define PNG_ERROR_ACTION_ERROR 3
/**
 * TODO
 * @def PNG_RGB_TO_GRAY_DEFAULT
 * @ingroup macro
 */
#define PNG_RGB_TO_GRAY_DEFAULT (-1)
/**
 * TODO
 * @def PNG_ALPHA_PNG
 * @ingroup macro
 */
#define PNG_ALPHA_PNG           0
/**
 * TODO
 * @def PNG_ALPHA_STANDARD
 * @ingroup macro
 */
#define PNG_ALPHA_STANDARD      1
/**
 * TODO
 * @def PNG_ALPHA_ASSOCIATED
 * @ingroup macro
 */
#define PNG_ALPHA_ASSOCIATED    1
/**
 * TODO
 * @def PNG_ALPHA_PREMULTIPLIED
 * @ingroup macro
 */
#define PNG_ALPHA_PREMULTIPLIED 1
/**
 * TODO
 * @def PNG_ALPHA_OPTIMIZED
 * @ingroup macro
 */
#define PNG_ALPHA_OPTIMIZED     2
/**
 * TODO
 * @def PNG_ALPHA_BROKEN
 * @ingroup macro
 */
#define PNG_ALPHA_BROKEN        3
/**
 * TODO
 * @def PNG_DEFAULT_sRGB
 * @ingroup macro
 */
#define PNG_DEFAULT_sRGB -1
/**
 * TODO
 * @def PNG_GAMMA_MAC_18
 * @ingroup macro
 */
#define PNG_GAMMA_MAC_18 -2
/**
 * TODO
 * @def PNG_GAMMA_sRGB
 * @ingroup macro
 */
#define PNG_GAMMA_sRGB   220000
/**
 * TODO
 * @def PNG_GAMMA_LINEAR
 * @ingroup macro
 */
#define PNG_GAMMA_LINEAR PNG_FP_1
/**
 * TODO
 * @def PNG_FILLER_BEFORE
 * @ingroup macro
 */
#define PNG_FILLER_BEFORE 0
/**
 * TODO
 * @def PNG_FILLER_AFTER
 * @ingroup macro
 */
#define PNG_FILLER_AFTER 1
/**
 * TODO
 * @def PNG_BACKGROUND_GAMMA_UNKNOWN
 * @ingroup macro
 */
#define PNG_BACKGROUND_GAMMA_UNKNOWN 0
/**
 * TODO
 * @def PNG_BACKGROUND_GAMMA_SCREEN
 * @ingroup macro
 */
#define PNG_BACKGROUND_GAMMA_SCREEN  1
/**
 * TODO
 * @def PNG_BACKGROUND_GAMMA_FILE
 * @ingroup macro
 */
#define PNG_BACKGROUND_GAMMA_FILE    2
/**
 * TODO
 * @def PNG_BACKGROUND_GAMMA_UNIQUE
 * @ingroup macro
 */
#define PNG_BACKGROUND_GAMMA_UNIQUE  3
/**
 * TODO
 * @def PNG_READ_16_TO_8_SUPPORTED
 * @ingroup macro
 */
#define PNG_READ_16_TO_8_SUPPORTED
/**
 * TODO
 * @def PNG_GAMMA_THRESHOLD
 * @ingroup macro
 */
#define PNG_GAMMA_THRESHOLD (PNG_GAMMA_THRESHOLD_FIXED*.00001)
/**
 * TODO
 * @def PNG_CRC_DEFAULT
 * @ingroup macro
 */
#define PNG_CRC_DEFAULT       0
/**
 * TODO
 * @def PNG_CRC_ERROR_QUIT
 * @ingroup macro
 */
#define PNG_CRC_ERROR_QUIT    1
/**
 * TODO
 * @def PNG_CRC_WARN_DISCARD
 * @ingroup macro
 */
#define PNG_CRC_WARN_DISCARD  2
/**
 * TODO
 * @def PNG_CRC_WARN_USE
 * @ingroup macro
 */
#define PNG_CRC_WARN_USE      3
/**
 * TODO
 * @def PNG_CRC_QUIET_USE
 * @ingroup macro
 */
#define PNG_CRC_QUIET_USE     4
/**
 * TODO
 * @def PNG_CRC_NO_CHANGE
 * @ingroup macro
 */
#define PNG_CRC_NO_CHANGE     5
/**
 * TODO
 * @def PNG_NO_FILTERS
 * @ingroup macro
 */
#define PNG_NO_FILTERS     0x00
/**
 * TODO
 * @def PNG_FILTER_NONE
 * @ingroup macro
 */
#define PNG_FILTER_NONE    0x08
/**
 * TODO
 * @def PNG_FILTER_SUB
 * @ingroup macro
 */
#define PNG_FILTER_SUB     0x10
/**
 * TODO
 * @def PNG_FILTER_UP
 * @ingroup macro
 */
#define PNG_FILTER_UP      0x20
/**
 * TODO
 * @def PNG_FILTER_AVG
 * @ingroup macro
 */
#define PNG_FILTER_AVG     0x40
/**
 * TODO
 * @def PNG_FILTER_PAETH
 * @ingroup macro
 */
#define PNG_FILTER_PAETH   0x80
/**
 * TODO
 * @def PNG_FAST_FILTERS
 * @ingroup macro
 */
#define PNG_FAST_FILTERS (PNG_FILTER_NONE | PNG_FILTER_SUB | PNG_FILTER_UP)
/**
 * TODO
 * @def PNG_ALL_FILTERS
 * @ingroup macro
 */
#define PNG_ALL_FILTERS (PNG_FAST_FILTERS | PNG_FILTER_AVG | PNG_FILTER_PAETH)
/**
 * TODO
 * @def PNG_FILTER_VALUE_NONE
 * @ingroup macro
 */
#define PNG_FILTER_VALUE_NONE  0
/**
 * TODO
 * @def PNG_FILTER_VALUE_SUB
 * @ingroup macro
 */
#define PNG_FILTER_VALUE_SUB   1
/**
 * TODO
 * @def PNG_FILTER_VALUE_UP
 * @ingroup macro
 */
#define PNG_FILTER_VALUE_UP    2
/**
 * TODO
 * @def PNG_FILTER_VALUE_AVG
 * @ingroup macro
 */
#define PNG_FILTER_VALUE_AVG   3
/**
 * TODO
 * @def PNG_FILTER_VALUE_PAETH
 * @ingroup macro
 */
#define PNG_FILTER_VALUE_PAETH 4
/**
 * TODO
 * @def PNG_FILTER_VALUE_LAST
 * @ingroup macro
 */
#define PNG_FILTER_VALUE_LAST  5
/**
 * TODO
 * @def PNG_FILTER_HEURISTIC_DEFAULT
 * @ingroup macro
 */
#define PNG_FILTER_HEURISTIC_DEFAULT    0
/**
 * TODO
 * @def PNG_FILTER_HEURISTIC_UNWEIGHTED
 * @ingroup macro
 */
#define PNG_FILTER_HEURISTIC_UNWEIGHTED 1
/**
 * TODO
 * @def PNG_FILTER_HEURISTIC_WEIGHTED
 * @ingroup macro
 */
#define PNG_FILTER_HEURISTIC_WEIGHTED   2
/**
 * TODO
 * @def PNG_FILTER_HEURISTIC_LAST
 * @ingroup macro
 */
#define PNG_FILTER_HEURISTIC_LAST       3
/**
 * TODO
 * @def PNG_DESTROY_WILL_FREE_DATA
 * @ingroup macro
 */
#define PNG_DESTROY_WILL_FREE_DATA 1
/**
 * TODO
 * @def PNG_SET_WILL_FREE_DATA
 * @ingroup macro
 */
#define PNG_SET_WILL_FREE_DATA     1
/**
 * TODO
 * @def PNG_USER_WILL_FREE_DATA
 * @ingroup macro
 */
#define PNG_USER_WILL_FREE_DATA    2
/**
 * TODO
 * @def PNG_FREE_HIST
 * @ingroup macro
 */
#define PNG_FREE_HIST 0x0008U
/**
 * TODO
 * @def PNG_FREE_ICCP
 * @ingroup macro
 */
#define PNG_FREE_ICCP 0x0010U
/**
 * TODO
 * @def PNG_FREE_SPLT
 * @ingroup macro
 */
#define PNG_FREE_SPLT 0x0020U
/**
 * TODO
 * @def PNG_FREE_ROWS
 * @ingroup macro
 */
#define PNG_FREE_ROWS 0x0040U
/**
 * TODO
 * @def PNG_FREE_PCAL
 * @ingroup macro
 */
#define PNG_FREE_PCAL 0x0080U
/**
 * TODO
 * @def PNG_FREE_SCAL
 * @ingroup macro
 */
#define PNG_FREE_SCAL 0x0100U
/**
 * TODO
 * @def PNG_FREE_UNKN
 * @ingroup macro
 */
#define PNG_FREE_UNKN 0x0200U
/**
 * TODO
 * @def PNG_FREE_PLTE
 * @ingroup macro
 */
#define PNG_FREE_PLTE 0x1000U
/**
 * TODO
 * @def PNG_FREE_TRNS
 * @ingroup macro
 */
#define PNG_FREE_TRNS 0x2000U
/**
 * TODO
 * @def PNG_FREE_TEXT
 * @ingroup macro
 */
#define PNG_FREE_TEXT 0x4000U
/**
 * TODO
 * @def PNG_FREE_EXIF
 * @ingroup macro
 */
#define PNG_FREE_EXIF 0x8000U
/**
 * TODO
 * @def PNG_FREE_ALL
 * @ingroup macro
 */
#define PNG_FREE_ALL  0xffffU
/**
 * TODO
 * @def PNG_FREE_MUL
 * @ingroup macro
 */
#define PNG_FREE_MUL  0x4220U
/**
 * TODO
 * @def PNG_HANDLE_CHUNK_AS_DEFAULT
 * @ingroup macro
 */
#define PNG_HANDLE_CHUNK_AS_DEFAULT   0
/**
 * TODO
 * @def PNG_HANDLE_CHUNK_NEVER
 * @ingroup macro
 */
#define PNG_HANDLE_CHUNK_NEVER        1
/**
 * TODO
 * @def PNG_HANDLE_CHUNK_IF_SAFE
 * @ingroup macro
 */
#define PNG_HANDLE_CHUNK_IF_SAFE      2
/**
 * TODO
 * @def PNG_HANDLE_CHUNK_ALWAYS
 * @ingroup macro
 */
#define PNG_HANDLE_CHUNK_ALWAYS       3
/**
 * TODO
 * @def PNG_HANDLE_CHUNK_LAST
 * @ingroup macro
 */
#define PNG_HANDLE_CHUNK_LAST         4
/**
 * TODO
 * @def PNG_IO_NONE
 * @ingroup macro
 */
#define PNG_IO_NONE        0x0000
/**
 * TODO
 * @def PNG_IO_READING
 * @ingroup macro
 */
#define PNG_IO_READING     0x0001
/**
 * TODO
 * @def PNG_IO_WRITING
 * @ingroup macro
 */
#define PNG_IO_WRITING     0x0002
/**
 * TODO
 * @def PNG_IO_SIGNATURE
 * @ingroup macro
 */
#define PNG_IO_SIGNATURE   0x0010
/**
 * TODO
 * @def PNG_IO_CHUNK_HDR
 * @ingroup macro
 */
#define PNG_IO_CHUNK_HDR   0x0020
/**
 * TODO
 * @def PNG_IO_CHUNK_DATA
 * @ingroup macro
 */
#define PNG_IO_CHUNK_DATA  0x0040
/**
 * TODO
 * @def PNG_IO_CHUNK_CRC
 * @ingroup macro
 */
#define PNG_IO_CHUNK_CRC   0x0080
/**
 * TODO
 * @def PNG_IO_MASK_OP
 * @ingroup macro
 */
#define PNG_IO_MASK_OP     0x000f
/**
 * TODO
 * @def PNG_IO_MASK_LOC
 * @ingroup macro
 */
#define PNG_IO_MASK_LOC    0x00f0
/**
 * TODO
 * @def PNG_INTERLACE_ADAM7_PASSES
 * @ingroup macro
 */
#define PNG_INTERLACE_ADAM7_PASSES 7
/**
 * TODO
 * @def PNG_PASS_START_ROW
 * @ingroup macro
 */
#define PNG_PASS_START_ROW(pass) (((1&~(pass))<<(3-((pass)>>1)))&7)
/**
 * TODO
 * @def PNG_PASS_START_COL
 * @ingroup macro
 */
#define PNG_PASS_START_COL(pass) (((1& (pass))<<(3-(((pass)+1)>>1)))&7)
/**
 * TODO
 * @def PNG_PASS_ROW_OFFSET
 * @ingroup macro
 */
#define PNG_PASS_ROW_OFFSET(pass) ((pass)>2?(8>>(((pass)-1)>>1)):8)
/**
 * TODO
 * @def PNG_PASS_COL_OFFSET
 * @ingroup macro
 */
#define PNG_PASS_COL_OFFSET(pass) (1<<((7-(pass))>>1))
/**
 * TODO
 * @def PNG_PASS_ROW_SHIFT
 * @ingroup macro
 */
#define PNG_PASS_ROW_SHIFT(pass) ((pass)>2?(8-(pass))>>1:3)
/**
 * TODO
 * @def PNG_PASS_COL_SHIFT
 * @ingroup macro
 */
#define PNG_PASS_COL_SHIFT(pass) ((pass)>1?(7-(pass))>>1:3)
/**
 * TODO
 * @def PNG_PASS_ROWS
 * @ingroup macro
 */
#define PNG_PASS_ROWS(height, pass) (((height)+(((1<<PNG_PASS_ROW_SHIFT(pass))\
    -1)-PNG_PASS_START_ROW(pass)))>>PNG_PASS_ROW_SHIFT(pass))
/**
 * TODO
 * @def PNG_PASS_COLS
 * @ingroup macro
 */
#define PNG_PASS_COLS(width, pass) (((width)+(((1<<PNG_PASS_COL_SHIFT(pass))\
    -1)-PNG_PASS_START_COL(pass)))>>PNG_PASS_COL_SHIFT(pass))
/**
 * TODO
 * @def PNG_ROW_FROM_PASS_ROW
 * @ingroup macro
 */
#define PNG_ROW_FROM_PASS_ROW(y_in, pass) \
    (((y_in)<<PNG_PASS_ROW_SHIFT(pass))+PNG_PASS_START_ROW(pass))
/**
 * TODO
 * @def PNG_COL_FROM_PASS_COL
 * @ingroup macro
 */
#define PNG_COL_FROM_PASS_COL(x_in, pass) \
    (((x_in)<<PNG_PASS_COL_SHIFT(pass))+PNG_PASS_START_COL(pass))
/**
 * TODO
 * @def PNG_PASS_MASK
 * @ingroup macro
 */
#define PNG_PASS_MASK(pass,off) ( \
    ((0x110145AF>>(((7-(off))-(pass))<<2)) & 0xF) | \
    ((0x01145AF0>>(((7-(off))-(pass))<<2)) & 0xF0))
/**
 * TODO
 * @def PNG_ROW_IN_INTERLACE_PASS
 * @ingroup macro
 */
#define PNG_ROW_IN_INTERLACE_PASS(y, pass) \
    ((PNG_PASS_MASK(pass,0) >> ((y)&7)) & 1)
/**
 * TODO
 * @def PNG_COL_IN_INTERLACE_PASS
 * @ingroup macro
 */
#define PNG_COL_IN_INTERLACE_PASS(x, pass) \
    ((PNG_PASS_MASK(pass,1) >> ((x)&7)) & 1)
/**
 * TODO
 * @def png_composite
 * @ingroup macro
 */
#define png_composite(composite, fg, alpha, bg)        \
    {                                                     \
    png_uint_16 temp = (png_uint_16)((png_uint_16)(fg) \
    * (png_uint_16)(alpha)                         \
    + (png_uint_16)(bg)*(png_uint_16)(255          \
    - (png_uint_16)(alpha)) + 128);                \
    (composite) = (png_byte)(((temp + (temp >> 8)) >> 8) & 0xff); \
    }
/**
 * TODO
 * @def png_composite_16
 * @ingroup macro
 */
#define png_composite_16(composite, fg, alpha, bg)     \
    {                                                     \
    png_uint_32 temp = (png_uint_32)((png_uint_32)(fg) \
    * (png_uint_32)(alpha)                         \
    + (png_uint_32)(bg)*(65535                     \
    - (png_uint_32)(alpha)) + 32768);              \
    (composite) = (png_uint_16)(0xffff & ((temp + (temp >> 16)) >> 16)); \
    }
/**
 * TODO
 * @def PNG_get_uint_32
 * @ingroup macro
 */
#define PNG_get_uint_32(buf) \
    (((png_uint_32)(*(buf)) << 24) + \
    ((png_uint_32)(*((buf) + 1)) << 16) + \
    ((png_uint_32)(*((buf) + 2)) << 8) + \
    ((png_uint_32)(*((buf) + 3))))
/**
 * TODO
 * @def PNG_get_uint_16
 * @ingroup macro
 */
#define PNG_get_uint_16(buf) \
    ((png_uint_16) \
    (((unsigned int)(*(buf)) << 8) + \
    ((unsigned int)(*((buf) + 1)))))
/**
 * TODO
 * @def PNG_get_int_32
 * @ingroup macro
 */
#define PNG_get_int_32(buf) \
    ((png_int_32)((*(buf) & 0x80) \
    ? -((png_int_32)(((png_get_uint_32(buf)^0xffffffffU)+1U)&0x7fffffffU)) \
    : (png_int_32)png_get_uint_32(buf)))
/**
 * The value of png_image::version
 * @def PNG_IMAGE_VERSION
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_IMAGE_VERSION 1
/**
 * Warning flag for png_image::warning_or_error
 * @def PNG_IMAGE_WARNING
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_IMAGE_WARNING 1
/**
 * Error flag for png_image::warning_or_error
 * @def PNG_IMAGE_ERROR
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_IMAGE_ERROR 2
/**
 * TODO
 * @def PNG_IMAGE_FAILED
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_IMAGE_FAILED(png_cntrl) ((((png_cntrl).warning_or_error)&0x03)>1)
/**
 * TODO
 * @def PNG_FORMAT_FLAG_ALPHA
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_FORMAT_FLAG_ALPHA    0x01U
/**
 * TODO
 * @def PNG_FORMAT_FLAG_COLOR
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_FORMAT_FLAG_COLOR    0x02U
/**
 * TODO
 * @def PNG_FORMAT_FLAG_LINEAR
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_FORMAT_FLAG_LINEAR   0x04U
/**
 * TODO
 * @def PNG_FORMAT_FLAG_COLORMAP
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_FORMAT_FLAG_COLORMAP 0x08U
/**
 * TODO
 * @def PNG_FORMAT_FLAG_BGR
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_FORMAT_FLAG_BGR    0x10U
/**
 * TODO
 * @def PNG_FORMAT_FLAG_AFIRST
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_FORMAT_FLAG_AFIRST 0x20U
/**
 * TODO
 * @def PNG_FORMAT_FLAG_ASSOCIATED_ALPHA
 * @ingroup macro
 * @since 1.6.33
 */
#define PNG_FORMAT_FLAG_ASSOCIATED_ALPHA 0x40U
/**
 * TODO
 * @def PNG_FORMAT_GRAY
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_FORMAT_GRAY 0
/**
 * TODO
 * @def PNG_FORMAT_GA
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_FORMAT_GA   PNG_FORMAT_FLAG_ALPHA
/**
 * TODO
 * @def PNG_FORMAT_AG
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_FORMAT_AG   (PNG_FORMAT_GA|PNG_FORMAT_FLAG_AFIRST)
/**
 * TODO
 * @def PNG_FORMAT_RGB
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_FORMAT_RGB  PNG_FORMAT_FLAG_COLOR
/**
 * TODO
 * @def PNG_FORMAT_BGR
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_FORMAT_BGR  (PNG_FORMAT_FLAG_COLOR|PNG_FORMAT_FLAG_BGR)
/**
 * TODO
 * @def PNG_FORMAT_RGBA
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_FORMAT_RGBA (PNG_FORMAT_RGB|PNG_FORMAT_FLAG_ALPHA)
/**
 * TODO
 * @def PNG_FORMAT_ARGB
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_FORMAT_ARGB (PNG_FORMAT_RGBA|PNG_FORMAT_FLAG_AFIRST)
/**
 * TODO
 * @def PNG_FORMAT_BGRA
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_FORMAT_BGRA (PNG_FORMAT_BGR|PNG_FORMAT_FLAG_ALPHA)
/**
 * TODO
 * @def PNG_FORMAT_ABGR
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_FORMAT_ABGR (PNG_FORMAT_BGRA|PNG_FORMAT_FLAG_AFIRST)
/**
 * TODO
 * @def PNG_FORMAT_LINEAR_Y
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_FORMAT_LINEAR_Y PNG_FORMAT_FLAG_LINEAR
/**
 * TODO
 * @def PNG_FORMAT_LINEAR_Y_ALPHA
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_FORMAT_LINEAR_Y_ALPHA (PNG_FORMAT_FLAG_LINEAR|PNG_FORMAT_FLAG_ALPHA)
/**
 * TODO
 * @def PNG_FORMAT_LINEAR_RGB
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_FORMAT_LINEAR_RGB (PNG_FORMAT_FLAG_LINEAR|PNG_FORMAT_FLAG_COLOR)
/**
 * TODO
 * @def PNG_FORMAT_LINEAR_RGB_ALPHA
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_FORMAT_LINEAR_RGB_ALPHA \
    (PNG_FORMAT_FLAG_LINEAR|PNG_FORMAT_FLAG_COLOR|PNG_FORMAT_FLAG_ALPHA)
/**
 * TODO
 * @def PNG_FORMAT_RGB_COLORMAP
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_FORMAT_RGB_COLORMAP  (PNG_FORMAT_RGB|PNG_FORMAT_FLAG_COLORMAP)
/**
 * TODO
 * @def PNG_FORMAT_BGR_COLORMAP
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_FORMAT_BGR_COLORMAP  (PNG_FORMAT_BGR|PNG_FORMAT_FLAG_COLORMAP)
/**
 * TODO
 * @def PNG_FORMAT_RGBA_COLORMAP
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_FORMAT_RGBA_COLORMAP (PNG_FORMAT_RGBA|PNG_FORMAT_FLAG_COLORMAP)
/**
 * TODO
 * @def PNG_FORMAT_ARGB_COLORMAP
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_FORMAT_ARGB_COLORMAP (PNG_FORMAT_ARGB|PNG_FORMAT_FLAG_COLORMAP)
/**
 * TODO
 * @def PNG_FORMAT_BGRA_COLORMAP
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_FORMAT_BGRA_COLORMAP (PNG_FORMAT_BGRA|PNG_FORMAT_FLAG_COLORMAP)
/**
 * TODO
 * @def PNG_FORMAT_ABGR_COLORMAP
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_FORMAT_ABGR_COLORMAP (PNG_FORMAT_ABGR|PNG_FORMAT_FLAG_COLORMAP)
/**
 * TODO
 * @def PNG_IMAGE_SAMPLE_CHANNELS
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_IMAGE_SAMPLE_CHANNELS(fmt)\
    (((fmt)&(PNG_FORMAT_FLAG_COLOR|PNG_FORMAT_FLAG_ALPHA))+1)
/**
 * TODO
 * @def PNG_IMAGE_SAMPLE_COMPONENT_SIZE
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_IMAGE_SAMPLE_COMPONENT_SIZE(fmt)\
    ((((fmt) & PNG_FORMAT_FLAG_LINEAR) >> 2)+1)
/**
 * TODO
 * @def PNG_IMAGE_SAMPLE_SIZE
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_IMAGE_SAMPLE_SIZE(fmt)\
    (PNG_IMAGE_SAMPLE_CHANNELS(fmt) * PNG_IMAGE_SAMPLE_COMPONENT_SIZE(fmt))
/**
 * TODO
 * @def PNG_IMAGE_MAXIMUM_COLORMAP_COMPONENTS
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_IMAGE_MAXIMUM_COLORMAP_COMPONENTS(fmt)\
    (PNG_IMAGE_SAMPLE_CHANNELS(fmt) * 256)
/**
 * TODO
 * @def PNG_IMAGE_PIXEL_
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_IMAGE_PIXEL_(test,fmt)\
    (((fmt)&PNG_FORMAT_FLAG_COLORMAP)?1:test(fmt))
/**
 * TODO
 * @def PNG_IMAGE_PIXEL_CHANNELS
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_IMAGE_PIXEL_CHANNELS(fmt)\
    PNG_IMAGE_PIXEL_(PNG_IMAGE_SAMPLE_CHANNELS,fmt)
/**
 * TODO
 * @def PNG_IMAGE_PIXEL_COMPONENT_SIZE
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_IMAGE_PIXEL_COMPONENT_SIZE(fmt)\
    PNG_IMAGE_PIXEL_(PNG_IMAGE_SAMPLE_COMPONENT_SIZE,fmt)
/**
 * TODO
 * @def PNG_IMAGE_PIXEL_SIZE
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_IMAGE_PIXEL_SIZE(fmt) PNG_IMAGE_PIXEL_(PNG_IMAGE_SAMPLE_SIZE,fmt)
/**
 * TODO
 * @def PNG_IMAGE_ROW_STRIDE
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_IMAGE_ROW_STRIDE(image)\
    (PNG_IMAGE_PIXEL_CHANNELS((image).format) * (image).width)
/**
 * TODO
 * @def PNG_IMAGE_BUFFER_SIZE
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_IMAGE_BUFFER_SIZE(image, row_stride)\
    (PNG_IMAGE_PIXEL_COMPONENT_SIZE((image).format)*(image).height*(row_stride))
/**
 * TODO
 * @def PNG_IMAGE_SIZE
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_IMAGE_SIZE(image)\
    PNG_IMAGE_BUFFER_SIZE(image, PNG_IMAGE_ROW_STRIDE(image))
/**
 * TODO
 * @def PNG_IMAGE_COLORMAP_SIZE
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_IMAGE_COLORMAP_SIZE(image)\
    (PNG_IMAGE_SAMPLE_SIZE((image).format) * (image).colormap_entries)
/**
 * TODO
 * @def PNG_IMAGE_FLAG_COLORSPACE_NOT_sRGB
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_IMAGE_FLAG_COLORSPACE_NOT_sRGB 0x01
/**
 * TODO
 * @def PNG_IMAGE_FLAG_FAST
 * @ingroup macro
 * @since 1.6.0
 */
#define PNG_IMAGE_FLAG_FAST 0x02
/**
 * TODO
 * @def PNG_IMAGE_FLAG_16BIT_sRGB
 * @ingroup macro
 * @since 1.6.1
 */
#define PNG_IMAGE_FLAG_16BIT_sRGB 0x04
/**
 * TODO
 * @def png_image_write_get_memory_size
 * @memberof png_image
 * @ingroup simple_api
 * @since 1.6.22
 */
#define png_image_write_get_memory_size(image, size, convert_to_8_bit, buffer,\
    row_stride, colormap)\
    png_image_write_to_memory(&(image), 0, &(size), convert_to_8_bit, buffer,\
    row_stride, colormap)
/**
 * TODO
 * @def PNG_IMAGE_DATA_SIZE
 * @ingroup macro
 * @since 1.6.22
 */
#define PNG_IMAGE_DATA_SIZE(image) (PNG_IMAGE_SIZE(image)+(image).height)
/**
 * TODO
 * @def PNG_ZLIB_MAX_SIZE
 * @ingroup 1.6.22
 */
#define PNG_ZLIB_MAX_SIZE(b) ((b)+(((b)+7U)>>3)+(((b)+63U)>>6)+11U)
/**
 * TODO
 * @def PNG_IMAGE_COMPRESSED_SIZE_MAX
 * @ingroup macro
 * @since 1.6.22
 */
#define PNG_IMAGE_COMPRESSED_SIZE_MAX(image)\
    PNG_ZLIB_MAX_SIZE((png_alloc_size_t)PNG_IMAGE_DATA_SIZE(image))
/**
 * TODO
 * @def PNG_IMAGE_PNG_SIZE_MAX_
 * @ingroup macro
 * @since 1.6.22
 */
#define PNG_IMAGE_PNG_SIZE_MAX_(image, image_size)\
    ((8U/*sig*/+25U/*IHDR*/+16U/*gAMA*/+44U/*cHRM*/+12U/*IEND*/+\
    (((image).format&PNG_FORMAT_FLAG_COLORMAP)?/*colormap: PLTE, tRNS*/\
    12U+3U*(image).colormap_entries/*PLTE data*/+\
    (((image).format&PNG_FORMAT_FLAG_ALPHA)?\
    12U/*tRNS*/+(image).colormap_entries:0U):0U)+\
    12U)+(12U*((image_size)/PNG_ZBUF_SIZE))/*IDAT*/+(image_size))
/**
 * TODO
 * @def PNG_IMAGE_PNG_SIZE_MAX
 * @ingroup macro
 * @since unknown
 */
#define PNG_IMAGE_PNG_SIZE_MAX(image)\
    PNG_IMAGE_PNG_SIZE_MAX_(image, PNG_IMAGE_COMPRESSED_SIZE_MAX(image))
/**
 * TODO
 * @def PNG_ARM_NEON
 * @ingroup macro
 */
#define PNG_ARM_NEON 0
/**
 * TODO
 * @def PNG_MAXIMUM_INFLATE_WINDOW
 * @ingroup macro
 */
#define PNG_MAXIMUM_INFLATE_WINDOW 2
/**
 * TODO
 * @def PNG_SKIP_sRGB_CHECK_PROFILE
 * @ingroup macro
 */
#define PNG_SKIP_sRGB_CHECK_PROFILE 4
/**
 * TODO
 * @def PNG_MIPS_MSA
 * @ingroup macro
 */
#define PNG_MIPS_MSA 6
/**
 * TODO
 * @def PNG_IGNORE_ADLER32
 * @ingroup macro
 */
#define PNG_IGNORE_ADLER32 8
/**
 * TODO
 * @def PNG_POWERPC_VSX
 * @ingroup macro
 */
#define PNG_POWERPC_VSX 10
/**
 * TODO
 * @def PNG_MIPS_MMI
 * @ingroup macro
 */
#define PNG_MIPS_MMI 12
/**
 * TODO
 * @def PNG_RISCV_RVV
 * @ingroup macro
 */
#define PNG_RISCV_RVV 14
/**
 * TODO
 * @def PNG_OPTION_NEXT
 * @ingroup macro
 */
#define PNG_OPTION_NEXT 16
/**
 * TODO
 * @def PNG_OPTION_UNSET
 * @ingroup macro
 */
#define PNG_OPTION_UNSET   0
/**
 * TODO
 * @def PNG_OPTION_INVALID
 * @ingroup macro
 */
#define PNG_OPTION_INVALID 1
/**
 * TODO
 * @def PNG_OPTION_OFF
 * @ingroup macro
 */
#define PNG_OPTION_OFF     2
/**
 * TODO
 * @def PNG_OPTION_ON
 * @ingroup macro
 */
#define PNG_OPTION_ON      3

// ------ Callback Types ------

typedef void (*png_error_ptr)(png_struct *, const png_char *);
typedef void (*png_rw_ptr)(png_struct *, png_byte *, size_t);
typedef void (*png_flush_ptr)(png_struct *);
typedef void (*png_read_status_ptr)(png_struct *, png_uint_32, int);
typedef void (*png_write_status_ptr)(png_struct *, png_uint_32, int);
typedef void (*png_progressive_info_ptr)(png_struct *, png_info *);
typedef void (*png_progressive_end_ptr)(png_struct *, png_info *);
typedef void (*png_progressive_row_ptr)(png_struct *, png_byte *, png_uint_32, int);
typedef void (*png_user_transform_ptr)(png_struct *, png_row_info *, png_byte *);
typedef int (*png_user_chunk_ptr)(png_struct *, png_unknown_chunk *);
typedef void (*png_longjmp_ptr)(jmp_buf, int);
typedef png_void * (*png_malloc_ptr)(png_struct *, png_alloc_size_t);
typedef void (*png_free_ptr)(png_struct *, png_void *);

// ------ Functions ------

/**
 * TODO
 * @return TODO
 * @ingroup versioning
 * @since unknown
 */
png_uint_32 png_access_version_number(void );

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param num_bytes TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_sig_bytes(png_struct *png_ptr, int num_bytes);

/**
 * TODO
 * @param sig TODO
 * @param start TODO
 * @param num_to_check TODO
 * @return TODO
 * @ingroup other
 * @since unknown
 */
int png_sig_cmp(const png_byte *sig, size_t start, size_t num_to_check);

/**
 * TODO
 * @param user_png_ver TODO
 * @param error_ptr TODO
 * @param error_fn TODO
 * @param warn_fn TODO
 * @return png_struct instance
 * @memberof png_struct
 * @ingroup reader
 * @since unknown
 */
png_struct *png_create_read_struct(const png_char *user_png_ver, png_void *error_ptr, png_error_ptr error_fn, png_error_ptr warn_fn);

/**
 * TODO
 * @param user_png_ver TODO
 * @param error_ptr TODO
 * @param error_fn TODO
 * @param warn_fn TODO
 * @return png_struct instance
 * @memberof png_struct
 * @ingroup writer
 * @since unknown
 */
png_struct *png_create_write_struct(const png_char *user_png_ver, png_void *error_ptr, png_error_ptr error_fn, png_error_ptr warn_fn);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @return TODO
 * @memberof png_struct
 * @ingroup zlib
 * @since unknown
 */
size_t png_get_compression_buffer_size(const png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param size TODO
 * @memberof png_struct
 * @ingroup zlib
 * @since unknown
 */
void png_set_compression_buffer_size(png_struct *png_ptr, size_t size);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param longjmp_fn TODO
 * @param jmp_buf_size TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup error
 * @since unknown
 */
jmp_buf*png_set_longjmp_fn(png_struct *png_ptr, png_longjmp_ptr longjmp_fn, size_t jmp_buf_size);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param val TODO
 * @memberof png_struct
 * @ingroup error
 * @since unknown
 */
void png_longjmp(const png_struct *png_ptr, int val);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @return TODO
 * @memberof png_struct
 * @ingroup other
 * @since unknown
 */
int png_reset_zstream(png_struct *png_ptr);

/**
 * TODO
 * @param user_png_ver TODO
 * @param error_ptr TODO
 * @param error_fn TODO
 * @param warn_fn TODO
 * @param mem_ptr TODO
 * @param malloc_fn TODO
 * @param free_fn TODO
 * @return png_struct instance
 * @memberof png_struct
 * @ingroup reader
 * @since unknown
 */
png_struct *png_create_read_struct_2(const png_char *user_png_ver, png_void *error_ptr, png_error_ptr error_fn, png_error_ptr warn_fn, png_void *mem_ptr, png_malloc_ptr malloc_fn, png_free_ptr free_fn);

/**
 * TODO
 * @param user_png_ver TODO
 * @param error_ptr TODO
 * @param error_fn TODO
 * @param warn_fn TODO
 * @param mem_ptr TODO
 * @param malloc_fn TODO
 * @param free_fn TODO
 * @return png_struct instance
 * @memberof png_struct
 * @ingroup writer
 * @since unknown
 */
png_struct *png_create_write_struct_2(const png_char *user_png_ver, png_void *error_ptr, png_error_ptr error_fn, png_error_ptr warn_fn, png_void *mem_ptr, png_malloc_ptr malloc_fn, png_free_ptr free_fn);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @memberof png_struct
 * @ingroup writer
 * @since unknown
 */
void png_write_sig(png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param chunk_name TODO
 * @param data TODO
 * @param length TODO
 * @memberof png_struct
 * @ingroup writer
 * @since unknown
 */
void png_write_chunk(png_struct *png_ptr, const png_byte *chunk_name, const png_byte *data, size_t length);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param chunk_name TODO
 * @param length TODO
 * @memberof png_struct
 * @ingroup writer
 * @since unknown
 */
void png_write_chunk_start(png_struct *png_ptr, const png_byte *chunk_name, png_uint_32 length);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param data TODO
 * @param length TODO
 * @memberof png_struct
 * @ingroup writer
 * @since unknown
 */
void png_write_chunk_data(png_struct *png_ptr, const png_byte *data, size_t length);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @memberof png_struct
 * @ingroup writer
 * @since unknown
 */
void png_write_chunk_end(png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @return TODO
 * @memberof png_info
 * @ingroup other
 * @since unknown
 */
png_info *png_create_info_struct(const png_struct *png_ptr);

/**
 * TODO
 * @param info_ptr TODO
 * @param png_info_struct_size TODO
 * @memberof png_info
 * @ingroup other
 * @since unknown
 */
void png_info_init_3(png_info **info_ptr, size_t png_info_struct_size);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @memberof png_info
 * @ingroup writer
 * @since unknown
 */
void png_write_info_before_PLTE(png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @memberof png_struct
 * @ingroup writer
 * @since unknown
 */
void png_write_info(png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @memberof png_struct
 * @ingroup reader
 * @since unknown
 */
void png_read_info(png_struct *png_ptr, png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param ptime TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup other
 * @since unknown
 */
const png_char *png_convert_to_rfc1123(png_struct *png_ptr, const png_time *ptime);

/**
 * TODO
 * @param out TODO
 * @param ptime TODO
 * @return TODO
 * @ingroup other
 * @since unknown
 */
int png_convert_to_rfc1123_buffer(char out[29], const png_time *ptime);

/**
 * TODO
 * @param ptime TODO
 * @param ttime TODO
 * @ingroup other
 * @since unknown
 */
void png_convert_from_struct_tm(png_time *ptime, const struct tm *ttime);

/**
 * TODO
 * @param ptime TODO
 * @param ttime TODO
 * @ingroup other
 * @since unknown
 */
void png_convert_from_time_t(png_time *ptime, time_t ttime);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_expand(png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_expand_gray_1_2_4_to_8(png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_palette_to_rgb(png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_tRNS_to_alpha(png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_expand_16(png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_bgr(png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_gray_to_rgb(png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param error_action TODO
 * @param red TODO
 * @param green TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_rgb_to_gray(png_struct *png_ptr, int error_action, double red, double green);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param error_action TODO
 * @param red TODO
 * @param green TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_rgb_to_gray_fixed(png_struct *png_ptr, int error_action, png_fixed_point red, png_fixed_point green);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_byte png_get_rgb_to_gray_status(const png_struct *png_ptr);

/**
 * TODO
 * @param bit_depth TODO
 * @param palette TODO
 * @ingroup other
 * @since unknown
 */
void png_build_grayscale_palette(int bit_depth, png_color *palette);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param mode TODO
 * @param output_gamma TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_alpha_mode(png_struct *png_ptr, int mode, double output_gamma);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param mode TODO
 * @param output_gamma TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_alpha_mode_fixed(png_struct *png_ptr, int mode, png_fixed_point output_gamma);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_strip_alpha(png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_swap_alpha(png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_invert_alpha(png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param filler TODO
 * @param flags TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_filler(png_struct *png_ptr, png_uint_32 filler, int flags);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param filler TODO
 * @param flags TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_add_alpha(png_struct *png_ptr, png_uint_32 filler, int flags);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_swap(png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_packing(png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_packswap(png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param true_bits TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_shift(png_struct *png_ptr, const png_color_8 *true_bits);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @return TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
int png_set_interlace_handling(png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_invert_mono(png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param background_color TODO
 * @param background_gamma_code TODO
 * @param need_expand TODO
 * @param background_gamma TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_background(png_struct *png_ptr, const png_color_16 *background_color, int background_gamma_code, int need_expand, double background_gamma);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param background_color TODO
 * @param background_gamma_code TODO
 * @param need_expand TODO
 * @param background_gamma TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_background_fixed(png_struct *png_ptr, const png_color_16 *background_color, int background_gamma_code, int need_expand, png_fixed_point background_gamma);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_scale_16(png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_strip_16(png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param palette TODO
 * @param num_palette TODO
 * @param maximum_colors TODO
 * @param histogram TODO
 * @param full_quantize TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_quantize(png_struct *png_ptr, png_color *palette, int num_palette, int maximum_colors, const png_uint_16 *histogram, int full_quantize);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param screen_gamma TODO
 * @param override_file_gamma TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_gamma(png_struct *png_ptr, double screen_gamma, double override_file_gamma);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param screen_gamma TODO
 * @param override_file_gamma TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_gamma_fixed(png_struct *png_ptr, png_fixed_point screen_gamma, png_fixed_point override_file_gamma);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param nrows TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_flush(png_struct *png_ptr, int nrows);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @memberof png_struct
 * @ingroup writer
 * @since unknown
 */
void png_write_flush(png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @memberof png_struct
 * @ingroup reader
 * @since unknown
 */
void png_start_read_image(png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @memberof png_struct
 * @ingroup reader
 * @since unknown
 */
void png_read_update_info(png_struct *png_ptr, png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param row TODO
 * @param display_row TODO
 * @param num_rows TODO
 * @memberof png_struct
 * @ingroup reader
 * @since unknown
 */
void png_read_rows(png_struct *png_ptr, png_byte **row, png_byte **display_row, png_uint_32 num_rows);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param row TODO
 * @param display_row TODO
 * @memberof png_struct
 * @ingroup reader
 * @since unknown
 */
void png_read_row(png_struct *png_ptr, png_byte *row, png_byte *display_row);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param image TODO
 * @memberof png_struct
 * @ingroup reader
 * @since unknown
 */
void png_read_image(png_struct *png_ptr, png_byte **image);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param row TODO
 * @memberof png_struct
 * @ingroup writer
 * @since unknown
 */
void png_write_row(png_struct *png_ptr, const png_byte *row);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param row TODO
 * @param num_rows TODO
 * @memberof png_struct
 * @ingroup writer
 * @since unknown
 */
void png_write_rows(png_struct *png_ptr, png_byte **row, png_uint_32 num_rows);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param image TODO
 * @memberof png_struct
 * @ingroup writer
 * @since unknown
 */
void png_write_image(png_struct *png_ptr, png_byte **image);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @memberof png_struct
 * @ingroup writer
 * @since unknown
 */
void png_write_end(png_struct *png_ptr, png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @memberof png_struct
 * @ingroup reader
 * @since unknown
 */
void png_read_end(png_struct *png_ptr, png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr_ptr TODO
 * @memberof png_info
 * @ingroup other
 * @since unknown
 */
void png_destroy_info_struct(const png_struct *png_ptr, png_info **info_ptr_ptr);

/**
 * TODO
 * @param png_ptr_ptr png_struct instance
 * @param info_ptr_ptr TODO
 * @param end_info_ptr_ptr TODO
 * @memberof png_struct
 * @ingroup reader
 * @since unknown
 */
void png_destroy_read_struct(png_struct **png_ptr_ptr, png_info **info_ptr_ptr, png_info **end_info_ptr_ptr);

/**
 * TODO
 * @param png_ptr_ptr png_struct instance
 * @param info_ptr_ptr TODO
 * @memberof png_struct
 * @ingroup writer
 * @since unknown
 */
void png_destroy_write_struct(png_struct **png_ptr_ptr, png_info **info_ptr_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param crit_action TODO
 * @param ancil_action TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_crc_action(png_struct *png_ptr, int crit_action, int ancil_action);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param method TODO
 * @param filters TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_filter(png_struct *png_ptr, int method, int filters);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param heuristic_method TODO
 * @param num_weights TODO
 * @param filter_weights TODO
 * @param filter_costs TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_filter_heuristics(png_struct *png_ptr, int heuristic_method, int num_weights, const png_double *filter_weights, const png_double *filter_costs);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param heuristic_method TODO
 * @param num_weights TODO
 * @param filter_weights TODO
 * @param filter_costs TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_filter_heuristics_fixed(png_struct *png_ptr, int heuristic_method, int num_weights, const png_fixed_point *filter_weights, const png_fixed_point *filter_costs);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param level TODO
 * @memberof png_struct
 * @ingroup zlib
 * @since unknown
 */
void png_set_compression_level(png_struct *png_ptr, int level);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param mem_level TODO
 * @memberof png_struct
 * @ingroup zlib
 * @since unknown
 */
void png_set_compression_mem_level(png_struct *png_ptr, int mem_level);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param strategy TODO
 * @memberof png_struct
 * @ingroup zlib
 * @since unknown
 */
void png_set_compression_strategy(png_struct *png_ptr, int strategy);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param window_bits TODO
 * @memberof png_struct
 * @ingroup zlib
 * @since unknown
 */
void png_set_compression_window_bits(png_struct *png_ptr, int window_bits);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param method TODO
 * @memberof png_struct
 * @ingroup zlib
 * @since unknown
 */
void png_set_compression_method(png_struct *png_ptr, int method);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param level TODO
 * @memberof png_struct
 * @ingroup zlib
 * @since unknown
 */
void png_set_text_compression_level(png_struct *png_ptr, int level);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param mem_level TODO
 * @memberof png_struct
 * @ingroup zlib
 * @since unknown
 */
void png_set_text_compression_mem_level(png_struct *png_ptr, int mem_level);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param strategy TODO
 * @memberof png_struct
 * @ingroup zlib
 * @since unknown
 */
void png_set_text_compression_strategy(png_struct *png_ptr, int strategy);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param window_bits TODO
 * @memberof png_struct
 * @ingroup zlib
 * @since unknown
 */
void png_set_text_compression_window_bits(png_struct *png_ptr, int window_bits);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param method TODO
 * @memberof png_struct
 * @ingroup zlib
 * @since unknown
 */
void png_set_text_compression_method(png_struct *png_ptr, int method);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param fp TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_init_io(png_struct *png_ptr, FILE *fp);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param error_ptr TODO
 * @param error_fn TODO
 * @param warning_fn TODO
 * @memberof png_struct
 * @ingroup error
 * @since unknown
 */
void png_set_error_fn(png_struct *png_ptr, png_void *error_ptr, png_error_ptr error_fn, png_error_ptr warning_fn);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @return TODO
 * @memberof png_struct
 * @ingroup error
 * @since unknown
 */
png_void *png_get_error_ptr(const png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param io_ptr TODO
 * @param write_data_fn TODO
 * @param output_flush_fn TODO
 * @memberof png_struct
 * @ingroup writer
 * @since unknown
 */
void png_set_write_fn(png_struct *png_ptr, png_void *io_ptr, png_rw_ptr write_data_fn, png_flush_ptr output_flush_fn);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param io_ptr TODO
 * @param read_data_fn TODO
 * @memberof png_struct
 * @ingroup reader
 * @since unknown
 */
void png_set_read_fn(png_struct *png_ptr, png_void *io_ptr, png_rw_ptr read_data_fn);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_void *png_get_io_ptr(const png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param read_row_fn TODO
 * @memberof png_struct
 * @ingroup reader
 * @since unknown
 */
void png_set_read_status_fn(png_struct *png_ptr, png_read_status_ptr read_row_fn);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param write_row_fn TODO
 * @memberof png_struct
 * @ingroup writer
 * @since unknown
 */
void png_set_write_status_fn(png_struct *png_ptr, png_write_status_ptr write_row_fn);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param mem_ptr TODO
 * @param malloc_fn TODO
 * @param free_fn TODO
 * @memberof png_struct
 * @ingroup memory
 * @since unknown
 */
void png_set_mem_fn(png_struct *png_ptr, png_void *mem_ptr, png_malloc_ptr malloc_fn, png_free_ptr free_fn);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @return TODO
 * @memberof png_struct
 * @ingroup memory
 * @since unknown
 */
png_void *png_get_mem_ptr(const png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param read_user_transform_fn TODO
 * @memberof png_struct
 * @ingroup reader
 * @since unknown
 */
void png_set_read_user_transform_fn(png_struct *png_ptr, png_user_transform_ptr read_user_transform_fn);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param write_user_transform_fn TODO
 * @memberof png_struct
 * @ingroup writer
 * @since unknown
 */
void png_set_write_user_transform_fn(png_struct *png_ptr, png_user_transform_ptr write_user_transform_fn);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param user_transform_ptr TODO
 * @param user_transform_depth TODO
 * @param user_transform_channels TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_user_transform_info(png_struct *png_ptr, png_void *user_transform_ptr, int user_transform_depth, int user_transform_channels);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_void *png_get_user_transform_ptr(const png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_current_row_number(const png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_byte png_get_current_pass_number(const png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param user_chunk_ptr TODO
 * @param read_user_chunk_fn TODO
 * @memberof png_struct
 * @ingroup reader
 * @since unknown
 */
void png_set_read_user_chunk_fn(png_struct *png_ptr, png_void *user_chunk_ptr, png_user_chunk_ptr read_user_chunk_fn);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_void *png_get_user_chunk_ptr(const png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param progressive_ptr TODO
 * @param info_fn TODO
 * @param row_fn TODO
 * @param end_fn TODO
 * @memberof png_struct
 * @ingroup progressive
 * @since unknown
 */
void png_set_progressive_read_fn(png_struct *png_ptr, png_void *progressive_ptr, png_progressive_info_ptr info_fn, png_progressive_row_ptr row_fn, png_progressive_end_ptr end_fn);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @return TODO
 * @memberof png_struct
 * @ingroup progressive
 * @since unknown
 */
png_void *png_get_progressive_ptr(const png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param buffer TODO
 * @param buffer_size TODO
 * @memberof png_struct
 * @ingroup progressive
 * @since unknown
 */
void png_process_data(png_struct *png_ptr, png_info *info_ptr, png_byte *buffer, size_t buffer_size);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param save TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup progressive
 * @since unknown
 */
size_t png_process_data_pause(png_struct *png_ptr, int save);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @return TODO
 * @memberof png_struct
 * @ingroup progressive
 * @since unknown
 */
png_uint_32 png_process_data_skip(png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param old_row TODO
 * @param new_row TODO
 * @memberof png_struct
 * @ingroup progressive
 * @since unknown
 */
void png_progressive_combine_row(const png_struct *png_ptr, png_byte *old_row, const png_byte *new_row);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param size TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup memory
 * @since unknown
 */
png_void *png_malloc(const png_struct *png_ptr, png_alloc_size_t size);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param size TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup memory
 * @since unknown
 */
png_void *png_calloc(const png_struct *png_ptr, png_alloc_size_t size);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param size TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup memory
 * @since unknown
 */
png_void *png_malloc_warn(const png_struct *png_ptr, png_alloc_size_t size);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param ptr TODO
 * @memberof png_struct
 * @ingroup memory
 * @since unknown
 */
void png_free(const png_struct *png_ptr, png_void *ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param free_me TODO
 * @param num TODO
 * @memberof png_struct
 * @ingroup memory
 * @since unknown
 */
void png_free_data(const png_struct *png_ptr, png_info *info_ptr, png_uint_32 free_me, int num);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param freer TODO
 * @param mask TODO
 * @memberof png_struct
 * @ingroup memory
 * @since unknown
 */
void png_data_freer(const png_struct *png_ptr, png_info *info_ptr, int freer, png_uint_32 mask);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param size TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup memory
 * @since unknown
 */
png_void *png_malloc_default(const png_struct *png_ptr, png_alloc_size_t size);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param ptr TODO
 * @memberof png_struct
 * @ingroup memory
 * @since unknown
 */
void png_free_default(const png_struct *png_ptr, png_void *ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param error_message TODO
 * @memberof png_struct
 * @ingroup error
 * @since unknown
 */
void png_error(const png_struct *png_ptr, const png_char *error_message);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param error_message TODO
 * @memberof png_struct
 * @ingroup error
 * @since unknown
 */
void png_chunk_error(const png_struct *png_ptr, const png_char *error_message);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param warning_message TODO
 * @memberof png_struct
 * @ingroup error
 * @since unknown
 */
void png_warning(const png_struct *png_ptr, const png_char *warning_message);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param warning_message TODO
 * @memberof png_struct
 * @ingroup error
 * @since unknown
 */
void png_chunk_warning(const png_struct *png_ptr, const png_char *warning_message);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param warning_message TODO
 * @memberof png_struct
 * @ingroup error
 * @since unknown
 */
void png_benign_error(const png_struct *png_ptr, const png_char *warning_message);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param warning_message TODO
 * @memberof png_struct
 * @ingroup error
 * @since unknown
 */
void png_chunk_benign_error(const png_struct *png_ptr, const png_char *warning_message);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param allowed TODO
 * @memberof png_struct
 * @ingroup error
 * @since unknown
 */
void png_set_benign_errors(png_struct *png_ptr, int allowed);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param flag TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_valid(const png_struct *png_ptr, const png_info *info_ptr, png_uint_32 flag);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
size_t png_get_rowbytes(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_byte **png_get_rows(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param row_pointers TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_rows(const png_struct *png_ptr, png_info *info_ptr, png_byte **row_pointers);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_byte png_get_channels(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_image_width(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_image_height(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_byte png_get_bit_depth(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_byte png_get_color_type(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_byte png_get_filter_type(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_byte png_get_interlace_type(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_byte png_get_compression_type(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_pixels_per_meter(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_x_pixels_per_meter(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_y_pixels_per_meter(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
float png_get_pixel_aspect_ratio(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_fixed_point png_get_pixel_aspect_ratio_fixed(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_int_32 png_get_x_offset_pixels(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_int_32 png_get_y_offset_pixels(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_int_32 png_get_x_offset_microns(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_int_32 png_get_y_offset_microns(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
const png_byte *png_get_signature(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param background TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_bKGD(const png_struct *png_ptr, png_info *info_ptr, png_color_16 * *background);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param background TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_bKGD(const png_struct *png_ptr, png_info *info_ptr, const png_color_16 *background);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param white_x TODO
 * @param white_y TODO
 * @param red_x TODO
 * @param red_y TODO
 * @param green_x TODO
 * @param green_y TODO
 * @param blue_x TODO
 * @param blue_y TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_cHRM(const png_struct *png_ptr, const png_info *info_ptr, double *white_x, double *white_y, double *red_x, double *red_y, double *green_x, double *green_y, double *blue_x, double *blue_y);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param red_X TODO
 * @param red_Y TODO
 * @param red_Z TODO
 * @param green_X TODO
 * @param green_Y TODO
 * @param green_Z TODO
 * @param blue_X TODO
 * @param blue_Y TODO
 * @param blue_Z TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_cHRM_XYZ(const png_struct *png_ptr, const png_info *info_ptr, double *red_X, double *red_Y, double *red_Z, double *green_X, double *green_Y, double *green_Z, double *blue_X, double *blue_Y, double *blue_Z);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param int_white_x TODO
 * @param int_white_y TODO
 * @param int_red_x TODO
 * @param int_red_y TODO
 * @param int_green_x TODO
 * @param int_green_y TODO
 * @param int_blue_x TODO
 * @param int_blue_y TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_cHRM_fixed(const png_struct *png_ptr, const png_info *info_ptr, png_fixed_point *int_white_x, png_fixed_point *int_white_y, png_fixed_point *int_red_x, png_fixed_point *int_red_y, png_fixed_point *int_green_x, png_fixed_point *int_green_y, png_fixed_point *int_blue_x, png_fixed_point *int_blue_y);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param int_red_X TODO
 * @param int_red_Y TODO
 * @param int_red_Z TODO
 * @param int_green_X TODO
 * @param int_green_Y TODO
 * @param int_green_Z TODO
 * @param int_blue_X TODO
 * @param int_blue_Y TODO
 * @param int_blue_Z TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_cHRM_XYZ_fixed(const png_struct *png_ptr, const png_info *info_ptr, png_fixed_point *int_red_X, png_fixed_point *int_red_Y, png_fixed_point *int_red_Z, png_fixed_point *int_green_X, png_fixed_point *int_green_Y, png_fixed_point *int_green_Z, png_fixed_point *int_blue_X, png_fixed_point *int_blue_Y, png_fixed_point *int_blue_Z);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param white_x TODO
 * @param white_y TODO
 * @param red_x TODO
 * @param red_y TODO
 * @param green_x TODO
 * @param green_y TODO
 * @param blue_x TODO
 * @param blue_y TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_cHRM(const png_struct *png_ptr, png_info *info_ptr, double white_x, double white_y, double red_x, double red_y, double green_x, double green_y, double blue_x, double blue_y);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param red_X TODO
 * @param red_Y TODO
 * @param red_Z TODO
 * @param green_X TODO
 * @param green_Y TODO
 * @param green_Z TODO
 * @param blue_X TODO
 * @param blue_Y TODO
 * @param blue_Z TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_cHRM_XYZ(const png_struct *png_ptr, png_info *info_ptr, double red_X, double red_Y, double red_Z, double green_X, double green_Y, double green_Z, double blue_X, double blue_Y, double blue_Z);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param int_white_x TODO
 * @param int_white_y TODO
 * @param int_red_x TODO
 * @param int_red_y TODO
 * @param int_green_x TODO
 * @param int_green_y TODO
 * @param int_blue_x TODO
 * @param int_blue_y TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_cHRM_fixed(const png_struct *png_ptr, png_info *info_ptr, png_fixed_point int_white_x, png_fixed_point int_white_y, png_fixed_point int_red_x, png_fixed_point int_red_y, png_fixed_point int_green_x, png_fixed_point int_green_y, png_fixed_point int_blue_x, png_fixed_point int_blue_y);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param int_red_X TODO
 * @param int_red_Y TODO
 * @param int_red_Z TODO
 * @param int_green_X TODO
 * @param int_green_Y TODO
 * @param int_green_Z TODO
 * @param int_blue_X TODO
 * @param int_blue_Y TODO
 * @param int_blue_Z TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_cHRM_XYZ_fixed(const png_struct *png_ptr, png_info *info_ptr, png_fixed_point int_red_X, png_fixed_point int_red_Y, png_fixed_point int_red_Z, png_fixed_point int_green_X, png_fixed_point int_green_Y, png_fixed_point int_green_Z, png_fixed_point int_blue_X, png_fixed_point int_blue_Y, png_fixed_point int_blue_Z);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param colour_primaries TODO
 * @param transfer_function TODO
 * @param matrix_coefficients TODO
 * @param video_full_range_flag TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_cICP(const png_struct *png_ptr, const png_info *info_ptr, png_byte *colour_primaries, png_byte *transfer_function, png_byte *matrix_coefficients, png_byte *video_full_range_flag);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param colour_primaries TODO
 * @param transfer_function TODO
 * @param matrix_coefficients TODO
 * @param video_full_range_flag TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_cICP(const png_struct *png_ptr, png_info *info_ptr, png_byte colour_primaries, png_byte transfer_function, png_byte matrix_coefficients, png_byte video_full_range_flag);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param maximum_content_light_level TODO
 * @param maximum_frame_average_light_level TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_cLLI(const png_struct *png_ptr, const png_info *info_ptr, double *maximum_content_light_level, double *maximum_frame_average_light_level);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param maximum_content_light_level_scaled_by_10000 TODO
 * @param maximum_frame_average_light_level_scaled_by_10000 TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_cLLI_fixed(const png_struct *png_ptr, const png_info *info_ptr, png_uint_32 *maximum_content_light_level_scaled_by_10000, png_uint_32 *maximum_frame_average_light_level_scaled_by_10000);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param maximum_content_light_level TODO
 * @param maximum_frame_average_light_level TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_cLLI(const png_struct *png_ptr, png_info *info_ptr, double maximum_content_light_level, double maximum_frame_average_light_level);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param maximum_content_light_level_scaled_by_10000 TODO
 * @param maximum_frame_average_light_level_scaled_by_10000 TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_cLLI_fixed(const png_struct *png_ptr, png_info *info_ptr, png_uint_32 maximum_content_light_level_scaled_by_10000, png_uint_32 maximum_frame_average_light_level_scaled_by_10000);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param exif TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_eXIf(const png_struct *png_ptr, png_info *info_ptr, png_byte * *exif);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param exif TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_eXIf(const png_struct *png_ptr, png_info *info_ptr, png_byte *exif);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param num_exif TODO
 * @param exif TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_eXIf_1(const png_struct *png_ptr, const png_info *info_ptr, png_uint_32 *num_exif, png_byte * *exif);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param num_exif TODO
 * @param exif TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_eXIf_1(const png_struct *png_ptr, png_info *info_ptr, png_uint_32 num_exif, png_byte *exif);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param file_gamma TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_gAMA(const png_struct *png_ptr, const png_info *info_ptr, double *file_gamma);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param int_file_gamma TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_gAMA_fixed(const png_struct *png_ptr, const png_info *info_ptr, png_fixed_point *int_file_gamma);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param file_gamma TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_gAMA(const png_struct *png_ptr, png_info *info_ptr, double file_gamma);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param int_file_gamma TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_gAMA_fixed(const png_struct *png_ptr, png_info *info_ptr, png_fixed_point int_file_gamma);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param hist TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_hIST(const png_struct *png_ptr, png_info *info_ptr, png_uint_16 * *hist);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param hist TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_hIST(const png_struct *png_ptr, png_info *info_ptr, const png_uint_16 *hist);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param width TODO
 * @param height TODO
 * @param bit_depth TODO
 * @param color_type TODO
 * @param interlace_method TODO
 * @param compression_method TODO
 * @param filter_method TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_IHDR(const png_struct *png_ptr, const png_info *info_ptr, png_uint_32 *width, png_uint_32 *height, int *bit_depth, int *color_type, int *interlace_method, int *compression_method, int *filter_method);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param width TODO
 * @param height TODO
 * @param bit_depth TODO
 * @param color_type TODO
 * @param interlace_method TODO
 * @param compression_method TODO
 * @param filter_method TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_IHDR(const png_struct *png_ptr, png_info *info_ptr, png_uint_32 width, png_uint_32 height, int bit_depth, int color_type, int interlace_method, int compression_method, int filter_method);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param white_x TODO
 * @param white_y TODO
 * @param red_x TODO
 * @param red_y TODO
 * @param green_x TODO
 * @param green_y TODO
 * @param blue_x TODO
 * @param blue_y TODO
 * @param mastering_display_maximum_luminance TODO
 * @param mastering_display_minimum_luminance TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_mDCV(const png_struct *png_ptr, const png_info *info_ptr, double *white_x, double *white_y, double *red_x, double *red_y, double *green_x, double *green_y, double *blue_x, double *blue_y, double *mastering_display_maximum_luminance, double *mastering_display_minimum_luminance);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param int_white_x TODO
 * @param int_white_y TODO
 * @param int_red_x TODO
 * @param int_red_y TODO
 * @param int_green_x TODO
 * @param int_green_y TODO
 * @param int_blue_x TODO
 * @param int_blue_y TODO
 * @param mastering_display_maximum_luminance_scaled_by_10000 TODO
 * @param mastering_display_minimum_luminance_scaled_by_10000 TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_mDCV_fixed(const png_struct *png_ptr, const png_info *info_ptr, png_fixed_point *int_white_x, png_fixed_point *int_white_y, png_fixed_point *int_red_x, png_fixed_point *int_red_y, png_fixed_point *int_green_x, png_fixed_point *int_green_y, png_fixed_point *int_blue_x, png_fixed_point *int_blue_y, png_uint_32 *mastering_display_maximum_luminance_scaled_by_10000, png_uint_32 *mastering_display_minimum_luminance_scaled_by_10000);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param white_x TODO
 * @param white_y TODO
 * @param red_x TODO
 * @param red_y TODO
 * @param green_x TODO
 * @param green_y TODO
 * @param blue_x TODO
 * @param blue_y TODO
 * @param mastering_display_maximum_luminance TODO
 * @param mastering_display_minimum_luminance TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_mDCV(const png_struct *png_ptr, png_info *info_ptr, double white_x, double white_y, double red_x, double red_y, double green_x, double green_y, double blue_x, double blue_y, double mastering_display_maximum_luminance, double mastering_display_minimum_luminance);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param int_white_x TODO
 * @param int_white_y TODO
 * @param int_red_x TODO
 * @param int_red_y TODO
 * @param int_green_x TODO
 * @param int_green_y TODO
 * @param int_blue_x TODO
 * @param int_blue_y TODO
 * @param mastering_display_maximum_luminance_scaled_by_10000 TODO
 * @param mastering_display_minimum_luminance_scaled_by_10000 TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_mDCV_fixed(const png_struct *png_ptr, png_info *info_ptr, png_fixed_point int_white_x, png_fixed_point int_white_y, png_fixed_point int_red_x, png_fixed_point int_red_y, png_fixed_point int_green_x, png_fixed_point int_green_y, png_fixed_point int_blue_x, png_fixed_point int_blue_y, png_uint_32 mastering_display_maximum_luminance_scaled_by_10000, png_uint_32 mastering_display_minimum_luminance_scaled_by_10000);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param offset_x TODO
 * @param offset_y TODO
 * @param unit_type TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_oFFs(const png_struct *png_ptr, const png_info *info_ptr, png_int_32 *offset_x, png_int_32 *offset_y, int *unit_type);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param offset_x TODO
 * @param offset_y TODO
 * @param unit_type TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_oFFs(const png_struct *png_ptr, png_info *info_ptr, png_int_32 offset_x, png_int_32 offset_y, int unit_type);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param purpose TODO
 * @param X0 TODO
 * @param X1 TODO
 * @param type TODO
 * @param nparams TODO
 * @param units TODO
 * @param params TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_pCAL(const png_struct *png_ptr, png_info *info_ptr, png_char * *purpose, png_int_32 *X0, png_int_32 *X1, int *type, int *nparams, png_char * *units, png_char ** *params);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param purpose TODO
 * @param X0 TODO
 * @param X1 TODO
 * @param type TODO
 * @param nparams TODO
 * @param units TODO
 * @param params TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_pCAL(const png_struct *png_ptr, png_info *info_ptr, const png_char *purpose, png_int_32 X0, png_int_32 X1, int type, int nparams, const png_char *units, png_char **params);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param res_x TODO
 * @param res_y TODO
 * @param unit_type TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_pHYs(const png_struct *png_ptr, const png_info *info_ptr, png_uint_32 *res_x, png_uint_32 *res_y, int *unit_type);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param res_x TODO
 * @param res_y TODO
 * @param unit_type TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_pHYs(const png_struct *png_ptr, png_info *info_ptr, png_uint_32 res_x, png_uint_32 res_y, int unit_type);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param palette TODO
 * @param num_palette TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_PLTE(const png_struct *png_ptr, png_info *info_ptr, png_color * *palette, int *num_palette);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param palette TODO
 * @param num_palette TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_PLTE(png_struct *png_ptr, png_info *info_ptr, const png_color *palette, int num_palette);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param sig_bit TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_sBIT(const png_struct *png_ptr, png_info *info_ptr, png_color_8 * *sig_bit);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param sig_bit TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_sBIT(const png_struct *png_ptr, png_info *info_ptr, const png_color_8 *sig_bit);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param file_srgb_intent TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_sRGB(const png_struct *png_ptr, const png_info *info_ptr, int *file_srgb_intent);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param srgb_intent TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_sRGB(const png_struct *png_ptr, png_info *info_ptr, int srgb_intent);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param srgb_intent TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_sRGB_gAMA_and_cHRM(const png_struct *png_ptr, png_info *info_ptr, int srgb_intent);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param name TODO
 * @param compression_type TODO
 * @param profile TODO
 * @param proflen TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_iCCP(const png_struct *png_ptr, png_info *info_ptr, png_char **name, int *compression_type, png_byte **profile, png_uint_32 *proflen);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param name TODO
 * @param compression_type TODO
 * @param profile TODO
 * @param proflen TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_iCCP(const png_struct *png_ptr, png_info *info_ptr, const png_char *name, int compression_type, const png_byte *profile, png_uint_32 proflen);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param entries TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
int png_get_sPLT(const png_struct *png_ptr, png_info *info_ptr, png_sPLT_t **entries);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param entries TODO
 * @param nentries TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_sPLT(const png_struct *png_ptr, png_info *info_ptr, const png_sPLT_t *entries, int nentries);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param text_ptr TODO
 * @param num_text TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
int png_get_text(const png_struct *png_ptr, png_info *info_ptr, png_text * *text_ptr, int *num_text);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param text_ptr TODO
 * @param num_text TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_text(const png_struct *png_ptr, png_info *info_ptr, const png_text *text_ptr, int num_text);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param mod_time TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_tIME(const png_struct *png_ptr, png_info *info_ptr, png_time * *mod_time);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param mod_time TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_tIME(const png_struct *png_ptr, png_info *info_ptr, const png_time *mod_time);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param trans_alpha TODO
 * @param num_trans TODO
 * @param trans_color TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_tRNS(const png_struct *png_ptr, png_info *info_ptr, png_byte * *trans_alpha, int *num_trans, png_color_16 * *trans_color);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param trans_alpha TODO
 * @param num_trans TODO
 * @param trans_color TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_tRNS(png_struct *png_ptr, png_info *info_ptr, const png_byte *trans_alpha, int num_trans, const png_color_16 *trans_color);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param unit TODO
 * @param width TODO
 * @param height TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_sCAL(const png_struct *png_ptr, const png_info *info_ptr, int *unit, double *width, double *height);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param unit TODO
 * @param width TODO
 * @param height TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_sCAL_fixed(const png_struct *png_ptr, const png_info *info_ptr, int *unit, png_fixed_point *width, png_fixed_point *height);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param unit TODO
 * @param swidth TODO
 * @param sheight TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_sCAL_s(const png_struct *png_ptr, const png_info *info_ptr, int *unit, png_char **swidth, png_char **sheight);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param unit TODO
 * @param width TODO
 * @param height TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_sCAL(const png_struct *png_ptr, png_info *info_ptr, int unit, double width, double height);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param unit TODO
 * @param width TODO
 * @param height TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_sCAL_fixed(const png_struct *png_ptr, png_info *info_ptr, int unit, png_fixed_point width, png_fixed_point height);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param unit TODO
 * @param swidth TODO
 * @param sheight TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_sCAL_s(const png_struct *png_ptr, png_info *info_ptr, int unit, const png_char *swidth, const png_char *sheight);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param keep TODO
 * @param chunk_list TODO
 * @param num_chunks TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_keep_unknown_chunks(png_struct *png_ptr, int keep, const png_byte *chunk_list, int num_chunks);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param chunk_name TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup other
 * @since unknown
 */
int png_handle_as_unknown(const png_struct *png_ptr, const png_byte *chunk_name);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param unknowns TODO
 * @param num_unknowns TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_unknown_chunks(const png_struct *png_ptr, png_info *info_ptr, const png_unknown_chunk *unknowns, int num_unknowns);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param chunk TODO
 * @param location TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_unknown_chunk_location(const png_struct *png_ptr, png_info *info_ptr, int chunk, int location);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param entries TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
int png_get_unknown_chunks(const png_struct *png_ptr, png_info *info_ptr, png_unknown_chunk **entries);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param mask TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_invalid(const png_struct *png_ptr, png_info *info_ptr, int mask);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param transforms TODO
 * @param params TODO
 * @memberof png_struct
 * @ingroup reader
 * @since unknown
 */
void png_read_png(png_struct *png_ptr, png_info *info_ptr, int transforms, png_void *params);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param transforms TODO
 * @param params TODO
 * @memberof png_struct
 * @ingroup writer
 * @since unknown
 */
void png_write_png(png_struct *png_ptr, png_info *info_ptr, int transforms, png_void *params);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
const png_char *png_get_copyright(const png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @return TODO
 * @memberof png_struct
 * @ingroup versioning
 * @since unknown
 */
const png_char *png_get_header_ver(const png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @return TODO
 * @memberof png_struct
 * @ingroup versioning
 * @since unknown
 */
const png_char *png_get_header_version(const png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @return TODO
 * @memberof png_struct
 * @ingroup versioning
 * @since unknown
 */
const png_char *png_get_libpng_ver(const png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param mng_features_permitted TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup other
 * @since unknown
 */
png_uint_32 png_permit_mng_features(png_struct *png_ptr, png_uint_32 mng_features_permitted);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param strip_mode TODO
 * @memberof png_struct
 * @ingroup error
 * @since unknown
 */
void png_set_strip_error_numbers(png_struct *png_ptr, png_uint_32 strip_mode);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param user_width_max TODO
 * @param user_height_max TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_user_limits(png_struct *png_ptr, png_uint_32 user_width_max, png_uint_32 user_height_max);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_user_width_max(const png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_user_height_max(const png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param user_chunk_cache_max TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_chunk_cache_max(png_struct *png_ptr, png_uint_32 user_chunk_cache_max);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_chunk_cache_max(const png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param user_chunk_cache_max TODO
 * @memberof png_struct
 * @ingroup memory
 * @since unknown
 */
void png_set_chunk_malloc_max(png_struct *png_ptr, png_alloc_size_t user_chunk_cache_max);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @return TODO
 * @memberof png_struct
 * @ingroup memory
 * @since unknown
 */
png_alloc_size_t png_get_chunk_malloc_max(const png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_pixels_per_inch(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_x_pixels_per_inch(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_y_pixels_per_inch(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
float png_get_x_offset_inches(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_fixed_point png_get_x_offset_inches_fixed(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
float png_get_y_offset_inches(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_fixed_point png_get_y_offset_inches_fixed(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @param res_x TODO
 * @param res_y TODO
 * @param unit_type TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_pHYs_dpi(const png_struct *png_ptr, const png_info *info_ptr, png_uint_32 *res_x, png_uint_32 *res_y, int *unit_type);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_io_state(const png_struct *png_ptr);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_io_chunk_type(const png_struct *png_ptr);

/**
 * TODO
 * @param buf TODO
 * @return TODO
 * @ingroup other
 * @since unknown
 */
png_uint_32 png_get_uint_32(const png_byte *buf);

/**
 * TODO
 * @param buf TODO
 * @return TODO
 * @ingroup other
 * @since unknown
 */
png_uint_16 png_get_uint_16(const png_byte *buf);

/**
 * TODO
 * @param buf TODO
 * @return TODO
 * @ingroup other
 * @since unknown
 */
png_int_32 png_get_int_32(const png_byte *buf);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param buf TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
png_uint_32 png_get_uint_31(const png_struct *png_ptr, const png_byte *buf);

/**
 * TODO
 * @param buf TODO
 * @param i TODO
 * @ingroup other
 * @since unknown
 */
void png_save_uint_32(png_byte *buf, png_uint_32 i);

/**
 * TODO
 * @param buf TODO
 * @param i TODO
 * @ingroup other
 * @since unknown
 */
void png_save_int_32(png_byte *buf, png_int_32 i);

/**
 * TODO
 * @param buf TODO
 * @param i TODO
 * @ingroup other
 * @since unknown
 */
void png_save_uint_16(png_byte *buf, unsigned int i);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param allowed TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
void png_set_check_for_invalid_index(png_struct *png_ptr, int allowed);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param info_ptr TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup getter
 * @since unknown
 */
int png_get_palette_max(const png_struct *png_ptr, const png_info *info_ptr);

/**
 * @brief Read the PNG header from a file.
 * @param image png_image instance
 * @param file_name path to a PNG file
 * @return 1 if PNG header was read successfully, 0 otherwise.
 * @memberof png_image
 * @ingroup simple_api
 * @since 1.6.0
 */
int png_image_begin_read_from_file(png_image *image, const char *file_name);

/**
 * @brief Read the PNG header from a FILE object.
 * @param image png_image instance
 * @param file A pointer of FILE object
 * @return 1 if PNG header was read successfully, 0 otherwise.
 * @memberof png_image
 * @ingroup simple_api
 * @since 1.6.0
 */
int png_image_begin_read_from_stdio(png_image *image, FILE *file);

/**
 * @brief Read the PNG header from a memory buffer
 * @param image png_image instance
 * @param memory buffer to read
 * @param size buffer size
 * @return 1 if PNG header was read successfully, 0 otherwise.
 * @memberof png_image
 * @ingroup simple_api
 * @since 1.6.0
 */
int png_image_begin_read_from_memory(png_image *image, const png_void *memory, size_t size);

/**
 * @brief Read the PNG data and clean up the png_image instance
 * @param image png_image instance
 * @param background TODO
 * @param buffer TODO
 * @param row_stride TODO
 * @param colormap TODO
 * @return TODO
 * @memberof png_image
 * @ingroup simple_api
 * @since 1.6.0
 */
int png_image_finish_read(png_image *image, const png_color *background, void *buffer, png_int_32 row_stride, void *colormap);

/**
 * @brief Free any data allocated by libpng in png_image::opaque.
 * @param image png_image instance
 * @memberof png_image
 * @ingroup simple_api
 * @since 1.6.0
 */
void png_image_free(png_image *image);

/**
 * @brief Write PNG as a file.
 * @param image png_image instance
 * @param file path to a PNG file
 * @param convert_to_8bit TODO
 * @param buffer TODO
 * @param row_stride TODO
 * @param colormap TODO
 * @return 1 if PNG was written successfully, 0 otherwise.
 * @memberof png_image
 * @ingroup simple_api
 * @since 1.6.0
 */
int png_image_write_to_file(png_image *image, const char *file, int convert_to_8bit, const void *buffer, png_int_32 row_stride, const void *colormap);

/**
 * @brief Write PNG to a FILE object.
 * @param image png_image instance
 * @param file A pointer of FILE object
 * @param convert_to_8_bit TODO
 * @param buffer TODO
 * @param row_stride TODO
 * @param colormap TODO
 * @return 1 if PNG was written successfully, 0 otherwise.
 * @memberof png_image
 * @ingroup simple_api
 * @since 1.6.0
 */
int png_image_write_to_stdio(png_image *image, FILE *file, int convert_to_8_bit, const void *buffer, png_int_32 row_stride, const void *colormap);

/**
 * @brief Write PNG to a memory buffer.
 * @param image png_image instance
 * @param memory TODO
 * @param memory_bytes TODO
 * @param convert_to_8_bit TODO
 * @param buffer TODO
 * @param row_stride TODO
 * @param colormap TODO
 * @return 1 if PNG was written successfully, 0 otherwise.
 * @memberof png_image
 * @ingroup simple_api
 * @since 1.6.22
 */
int png_image_write_to_memory(png_image *image, void *memory, png_alloc_size_t *memory_bytes, int convert_to_8_bit, const void *buffer, png_int_32 row_stride, const void *colormap);

/**
 * TODO
 * @param png_ptr png_struct instance
 * @param option TODO
 * @param onoff TODO
 * @return TODO
 * @memberof png_struct
 * @ingroup setter
 * @since unknown
 */
int png_set_option(png_struct *png_ptr, int option, int onoff);



#ifdef __cplusplus
}
#endif

#endif  // LIBPNG_API_DOCUMENT_H
