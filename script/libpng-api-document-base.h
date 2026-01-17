// generate.py uses this file to generate libpng-api-document.h from png.h
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
 * @defgroup reader Reading
 * @defgroup writer Writing
 * @defgroup setter Setter
 * @defgroup getter Getter
 * @defgroup progressive Progressive Read
 * @defgroup error Error Handling
 * @defgroup memory Memory Management
 * @defgroup zlib Zlib Options
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

// ------ Macros ------

#ifdef __cplusplus
}
#endif

#endif  // LIBPNG_API_DOCUMENT_H
