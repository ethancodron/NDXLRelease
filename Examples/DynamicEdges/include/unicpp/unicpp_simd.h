//------------------------------------------\\
// C/C++ SIMD macros for various compilers	\\
// Ethan Codron 2025						\\
// GNU GPL-3.0								\\
//------------------------------------------\\
// Header file macroising SIMD identifiers	\\
// across compilers.						\\
//------------------------------------------\\

#ifndef _UNICPP_SIMD_
#define _UNICPP_SIMD_

#include "unicpp_compiler.h"
#include "unicpp_cpu.h"

#if UNI_PLATFORM == UNI_PLATFORM_MACOS
	#include <arm_neon.h>
#endif // macOS

#define SIMD_ISA_SSE		b
#define SIMD_ISA_AVX		c
#define SIMD_ISA_AVX2		d
#define SIMD_ISA_AVX512		e

#define SIMD_MASK_MASKED	M
#define SIMD_MASK_UNMASKED	N

#define SIMD_VLEN_M512d		8
#define SIMD_VLEN_M512		16
#define SIMD_VLEN_M512ull	8
#define SIMD_VLEN_M512ll	8
#define SIMD_VLEN_M512ul	16
#define SIMD_VLEN_M512l		16
#define SIMD_VLEN_M512us	32
#define SIMD_VLEN_M512s		32
#define SIMD_VLEN_M512ub	64
#define SIMD_VLEN_M512b		64

#define SIMD_VLEN_M256d		4
#define SIMD_VLEN_M256		8
#define SIMD_VLEN_M256ull	4
#define SIMD_VLEN_M256ll	4
#define SIMD_VLEN_M256ul	8
#define SIMD_VLEN_M256l		8
#define SIMD_VLEN_M256us	16
#define SIMD_VLEN_M256s		16
#define SIMD_VLEN_M256ub	32
#define SIMD_VLEN_M256b		32

#define SIMD_VLEN_M128d		2
#define SIMD_VLEN_M128		4
#define SIMD_VLEN_M128ull	2
#define SIMD_VLEN_M128ll	2
#define SIMD_VLEN_M128ul	4
#define SIMD_VLEN_M128l		4
#define SIMD_VLEN_M128us	8
#define SIMD_VLEN_M128s		8
#define SIMD_VLEN_M128ub	16
#define SIMD_VLEN_M128b		16

#endif // _UNICPP_SIMD_