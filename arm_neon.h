/***
*   arm_neon.h - declarations/definitions for ARM NEON specific intrinsics
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*       This include file contains the declarations for ARM NEON intrinsic functions
*
****/

#pragma once

#include <stdint.h>
#include <sal.h>

#define _M_ARM

#if !defined (_M_ARM)
#error This header is specific to ARM targets
#endif  /* !defined (_M_ARM) */


#if defined (__cplusplus)
extern "C" {
#endif  /* defined (__cplusplus) */


///////////////////////////////////////////////////////////////////////////////
//
#if !defined (_ADVSIMD_ALIGN)
#if defined (__midl)
#define _ADVSIMD_ALIGN(x)
#else  /* defined (__midl) */
#define _ADVSIMD_ALIGN(x) __attribute__((align(x)))
#endif  /* defined (__midl) */
#endif  /* !defined (_ADVSIMD_ALIGN) */

#ifndef DUMMYNEONSTRUCT
#define DUMMYNEONSTRUCT s
#endif  /* DUMMYNEONSTRUCT */

///////////////////////////////////////////////////////////////////////////////
//
// ARM Advanced SIMD 64bit type
//

typedef __attribute__((intrin_type)) _ADVSIMD_ALIGN(8) union __n64
{
    unsigned int64    __attribute__((intrin_type)) _ADVSIMD_ALIGN(8) n64_u64[1];
    unsigned int32    __attribute__((intrin_type)) _ADVSIMD_ALIGN(8) n64_u32[2];
    unsigned int16    __attribute__((intrin_type)) _ADVSIMD_ALIGN(8) n64_u16[4];
    unsigned int8     __attribute__((intrin_type)) _ADVSIMD_ALIGN(8) n64_u8[8];
    int64             __attribute__((intrin_type)) _ADVSIMD_ALIGN(8) n64_i64[1];
    int32             __attribute__((intrin_type)) _ADVSIMD_ALIGN(8) n64_i32[2];
    int16             __attribute__((intrin_type)) _ADVSIMD_ALIGN(8) n64_i16[4];
    int8              __attribute__((intrin_type)) _ADVSIMD_ALIGN(8) n64_i8[8];
    float               __attribute__((intrin_type)) _ADVSIMD_ALIGN(8) n64_f32[2];
} __n64;


///////////////////////////////////////////////////////////////////////////////
//
// ARM Advanced SIMD 128bit type
//
typedef __attribute__((intrin_type)) _ADVSIMD_ALIGN(8) union __n128
{
     unsigned int64   __attribute__((intrin_type)) _ADVSIMD_ALIGN(8) n128_u64[2];
     unsigned int32   __attribute__((intrin_type)) _ADVSIMD_ALIGN(8) n128_u32[4];
     unsigned int16   __attribute__((intrin_type)) _ADVSIMD_ALIGN(8) n128_u16[8];
     unsigned int8    __attribute__((intrin_type)) _ADVSIMD_ALIGN(8) n128_u8[16];
     int64            __attribute__((intrin_type)) _ADVSIMD_ALIGN(8) n128_i64[2];
     int32            __attribute__((intrin_type)) _ADVSIMD_ALIGN(8) n128_i32[4];
     int16            __attribute__((intrin_type)) _ADVSIMD_ALIGN(8) n128_i16[8];
     int8             __attribute__((intrin_type)) _ADVSIMD_ALIGN(8) n128_i8[16];
     float              __attribute__((intrin_type)) _ADVSIMD_ALIGN(8) n128_f32[4];

    struct
    {
        __n64  low64;
        __n64  high64;
    } DUMMYNEONSTRUCT;

} __n128;

typedef struct __n64x2
{
    __n64 val[2];
} __n64x2;

typedef struct __n64x3
{
    __n64 val[3];
} __n64x3;

typedef struct __n64x4
{
    __n64 val[4];
} __n64x4;

typedef struct __n128x2
{
    __n128 val[2];
} __n128x2;

typedef struct __n128x3
{
    __n128 val[3];
} __n128x3;

typedef struct __n128x4
{
    __n128 val[4];
} __n128x4;

///////////////////////////////////////////////////////////////////////////////
//
typedef unsigned int8  poly8_t;
typedef unsigned int16 poly16_t;

typedef float float32_t;

#if !defined(_ARM_USE_NEW_NEON_INTRINSICS)
// Once a version is determined, this should default based on _MSC_FULL_VER
#define _ARM_USE_DEPRECATED_NEON_INTRINSICS
#endif

typedef __n64    float32x2_t;
typedef __n64x2  float32x2x2_t;
typedef __n64x3  float32x2x3_t;
typedef __n64x4  float32x2x4_t;
typedef __n64    int8x8_t;
typedef __n64x2  int8x8x2_t;
typedef __n64x3  int8x8x3_t;
typedef __n64x4  int8x8x4_t;
typedef __n64    int16x4_t;
typedef __n64x2  int16x4x2_t;
typedef __n64x3  int16x4x3_t;
typedef __n64x4  int16x4x4_t;
typedef __n64    int32x2_t;
typedef __n64x2  int32x2x2_t;
typedef __n64x3  int32x2x3_t;
typedef __n64x4  int32x2x4_t;
typedef __n64    int64x1_t;
typedef __n64x2  int64x1x2_t;
typedef __n64x3  int64x1x3_t;
typedef __n64x4  int64x1x4_t;
typedef __n64    poly8x8_t;
typedef __n64x2  poly8x8x2_t;
typedef __n64x3  poly8x8x3_t;
typedef __n64x4  poly8x8x4_t;
typedef __n64    poly16x4_t;
typedef __n64x2  poly16x4x2_t;
typedef __n64x3  poly16x4x3_t;
typedef __n64x4  poly16x4x4_t;
typedef __n64    uint8x8_t;
typedef __n64x2  uint8x8x2_t;
typedef __n64x3  uint8x8x3_t;
typedef __n64x4  uint8x8x4_t;
typedef __n64    uint16x4_t;
typedef __n64x2  uint16x4x2_t;
typedef __n64x3  uint16x4x3_t;
typedef __n64x4  uint16x4x4_t;
typedef __n64    uint32x2_t;
typedef __n64x2  uint32x2x2_t;
typedef __n64x3  uint32x2x3_t;
typedef __n64x4  uint32x2x4_t;
typedef __n64    uint64x1_t;
typedef __n64x2  uint64x1x2_t;
typedef __n64x3  uint64x1x3_t;
typedef __n64x4  uint64x1x4_t;
typedef __n128   float32x4_t;
typedef __n128x2 float32x4x2_t;
typedef __n128x3 float32x4x3_t;
typedef __n128x4 float32x4x4_t;
typedef __n128   int8x16_t;
typedef __n128x2 int8x16x2_t;
typedef __n128x3 int8x16x3_t;
typedef __n128x4 int8x16x4_t;
typedef __n128   int16x8_t;
typedef __n128x2 int16x8x2_t;
typedef __n128x3 int16x8x3_t;
typedef __n128x4 int16x8x4_t;
typedef __n128   int32x4_t;
typedef __n128x2 int32x4x2_t;
typedef __n128x3 int32x4x3_t;
typedef __n128x4 int32x4x4_t;
typedef __n128   int64x2_t;
typedef __n128x2 int64x2x2_t;
typedef __n128x3 int64x2x3_t;
typedef __n128x4 int64x2x4_t;
typedef __n128   poly8x16_t;
typedef __n128x2 poly8x16x2_t;
typedef __n128x3 poly8x16x3_t;
typedef __n128x4 poly8x16x4_t;
typedef __n128   poly16x8_t;
typedef __n128x2 poly16x8x2_t;
typedef __n128x3 poly16x8x3_t;
typedef __n128x4 poly16x8x4_t;
typedef __n128   uint8x16_t;
typedef __n128x2 uint8x16x2_t;
typedef __n128x3 uint8x16x3_t;
typedef __n128x4 uint8x16x4_t;
typedef __n128   uint16x8_t;
typedef __n128x2 uint16x8x2_t;
typedef __n128x3 uint16x8x3_t;
typedef __n128x4 uint16x8x4_t;
typedef __n128   uint32x4_t;
typedef __n128x2 uint32x4x2_t;
typedef __n128x3 uint32x4x3_t;
typedef __n128x4 uint32x4x4_t;
typedef __n128   uint64x2_t;
typedef __n128x2 uint64x2x2_t;
typedef __n128x3 uint64x2x3_t;
typedef __n128x4 uint64x2x4_t;