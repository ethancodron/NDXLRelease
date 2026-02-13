//----------------------\\
// C/C++ CPU detection  \\
// Ethan Codron 2025	\\
// GNU GPL-3.0			\\
//----------------------\\
// Header file provid-  \\
// ing CPU and feature  \\
// identification.      \\
//----------------------\\

#ifndef _UNICPP_CPU_
#define _UNICPP_CPU_

#include "unicpp_core.h"

#if UNI_COMPILER == UNI_COMPILER_MSVC
	#include <intrin.h>
#endif // MSVC compiler
#include <immintrin.h>

// Advanced Bit Manipulation
#define  CPU_FEATURE_MMX            BIT(0)
#define  CPU_FEATURE_x64            BIT(1)
#define  CPU_FEATURE_ABM            BIT(2)
#define  CPU_FEATURE_RDRAND         BIT(3)
#define  CPU_FEATURE_BMI1           BIT(4)
#define  CPU_FEATURE_BMI2           BIT(5)
#define  CPU_FEATURE_ADX            BIT(6)
#define  CPU_FEATURE_PREFETCHWT1    BIT(7)

// SIMD: 128-bit
#define  CPU_FEATURE_SSE            BIT(8)
#define  CPU_FEATURE_SSE2           BIT(9)
#define  CPU_FEATURE_SSE3           BIT(10)
#define  CPU_FEATURE_SSSE3          BIT(11)
#define  CPU_FEATURE_SSE41          BIT(12)
#define  CPU_FEATURE_SSE42          BIT(13)
#define  CPU_FEATURE_SSE4a          BIT(14)
#define  CPU_FEATURE_AES            BIT(15)
#define  CPU_FEATURE_SHA            BIT(16)

// SIMD: 256-bit
#define  CPU_FEATURE_AVX            BIT(17)
#define  CPU_FEATURE_XOP            BIT(18)
#define  CPU_FEATURE_FMA3           BIT(19)
#define  CPU_FEATURE_FMA4           BIT(20)
#define  CPU_FEATURE_AVX2           BIT(21)

// SIMD: 512-bit
#define  CPU_FEATURE_AVX512F        BIT(22)
#define  CPU_FEATURE_AVX512CD       BIT(23)
#define  CPU_FEATURE_AVX512PF       BIT(24)
#define  CPU_FEATURE_AVX512ER       BIT(25)
#define  CPU_FEATURE_AVX512VL       BIT(26)
#define  CPU_FEATURE_AVX512BW       BIT(27)
#define  CPU_FEATURE_AVX512DQ       BIT(28)
#define  CPU_FEATURE_AVX512IFMA     BIT(29)
#define  CPU_FEATURE_AVX512VBMI     BIT(30)

// CPU Vendor strings and IDs
#define CPU_VENDOR_AuthenticAMD	1
#define CPU_VENDOR_CentaurHauls	2
#define CPU_VENDOR_CyrixInstead	4
#define CPU_VENDOR_GenuineIntel	8
#define CPU_VENDOR_GenuineIotel	16
#define CPU_VENDOR_TransmetaCPU	32
#define CPU_VENDOR_GenuineTMx86	64
#define CPU_VENDOR_Geode_by_NSC	128
#define CPU_VENDOR_NexGenDriven	256
#define CPU_VENDOR_RiseRiseRise	512
#define CPU_VENDOR_SiS_SiS_SiS_	1024
#define CPU_VENDOR_UMC_UMC_UMC_	2048
#define CPU_VENDOR_Vortex86_SoC	4096
#define CPU_VENDOR___Shanghai__	8192
#define CPU_VENDOR_HygonGenuine	16384
#define CPU_VENDOR_Genuine_RDC_	32768
#define CPU_VENDOR_E2K_MACHINE	65536
#define CPU_VENDOR_VIA_VIA_VIA_	131072
#define CPU_VENDOR_AMD_ISBETTER	262144
#define CPU_VENDOR_GenuineAO486	524288
#define CPU_VENDOR_MiSTer_AO486	1048576
#define CPU_VENDOR_MicrosoftXTA	2097152
#define CPU_VENDOR_VirtualApple	4194304

static inline void uniCpuid(int _Info[4], int _Id)
{
#if UNI_COMPILER == UNI_COMPILER_MSVC
	__cpuid(_Info, _Id);
#else
	asm volatile(
        "cpuid"
        : "=a"(_Info[0]), "=b"(_Info[1]), "=c"(_Info[2]), "=d"(_Info[3])
        : "a"(_Id)
    );
#endif // MSVC
}

static inline long uniCPUFeatureSet()
{
    // Algorithm: https://stackoverflow.com/questions/6121792/how-to-check-if-a-cpu-supports-the-sse3-instruction-set (Mystical's answer)
    long _Features = 0;

    int _Info[4];
    uniCpuid(_Info, 0);
    int _Ids = _Info[0];
    uniCpuid(_Info, 0x80000000);
    unsigned _ExIds = _Info[0];

    if (_Ids >= 0x00000001)
    {
        uniCpuid(_Info, 0x00000001);
        _Features |= (_Info[3] & ((int)1 << 23)) != 0;
        _Features |= ((_Info[2] & ((int)1 << 30)) != 0) << 3;
        _Features |= ((_Info[3] & ((int)1 << 25)) != 0) << 8;
        _Features |= ((_Info[3] & ((int)1 << 26)) != 0) << 9;
        _Features |= ((_Info[2] & ((int)1 << 0)) != 0) << 10;
        _Features |= ((_Info[2] & ((int)1 << 9)) != 0) << 11;
        _Features |= ((_Info[2] & ((int)1 << 19)) != 0) << 12;
        _Features |= ((_Info[2] & ((int)1 << 20)) != 0) << 13;
        _Features |= ((_Info[2] & ((int)1 << 25)) != 0) << 15;
        _Features |= ((_Info[2] & ((int)1 << 28)) != 0) << 17;
        _Features |= ((_Info[2] & ((int)1 << 12)) != 0) << 19;
    }

    if (_Ids >= 0x00000007)
    {
        uniCpuid(_Info, 0x00000007);
        _Features |= ((_Info[1] & ((int)1 << 3)) != 0) << 4;
        _Features |= ((_Info[1] & ((int)1 << 8)) != 0) << 5;
        _Features |= ((_Info[1] & ((int)1 << 19)) != 0) << 6;
        _Features |= ((_Info[2] & ((int)1 << 0)) != 0) << 7;
        _Features |= ((_Info[1] & ((int)1 << 29)) != 0) << 16;
        _Features |= ((_Info[1] & ((int)1 << 5)) != 0) << 21;
        _Features |= ((_Info[1] & ((int)1 << 16)) != 0) << 22;
        _Features |= ((_Info[1] & ((int)1 << 28)) != 0) << 23;
        _Features |= ((_Info[1] & ((int)1 << 26)) != 0) << 24;
        _Features |= ((_Info[1] & ((int)1 << 27)) != 0) << 25;
        _Features |= ((_Info[1] & ((int)1 << 31)) != 0) << 26;
        _Features |= ((_Info[1] & ((int)1 << 30)) != 0) << 27;
        _Features |= ((_Info[1] & ((int)1 << 17)) != 0) << 28;
        _Features |= ((_Info[1] & ((int)1 << 21)) != 0) << 29;
        _Features |= ((_Info[2] & ((int)1 << 1)) != 0) << 30;
    }

    if (_ExIds >= 0x80000001)
    {
        uniCpuid(_Info, 0x80000001);
        _Features |= ((_Info[3] & ((int)1 << 29)) != 0) << 1;
        _Features |= ((_Info[2] & ((int)1 << 5)) != 0) << 2;
        _Features |= ((_Info[2] & ((int)1 << 6)) != 0) << 14;
        _Features |= ((_Info[2] & ((int)1 << 11)) != 0) << 18;
        _Features |= ((_Info[2] & ((int)1 << 16)) != 0) << 20;
    }

    return _Features;
}

static inline int uniCPUHasFeature(const long _Feature)
{
    static long _Features;
    _Features = uniCPUFeatureSet();
    return (int)(_Features & _Feature);
}

static inline int uniCPUSupportsAVX512() { return uniCPUHasFeature(CPU_FEATURE_AVX512F); }
static inline int uniCPUSupportsAVX() { return uniCPUHasFeature(CPU_FEATURE_AVX2 | CPU_FEATURE_AVX); }
static inline int uniCPUSupportsSSE() { return uniCPUHasFeature(CPU_FEATURE_SSE42 | CPU_FEATURE_SSE41 | CPU_FEATURE_SSE4a | CPU_FEATURE_SSE3 | CPU_FEATURE_SSSE3 | CPU_FEATURE_SSE2); }

static inline unsigned long uniCPUVendorID()
{
    char _Buf[12];
    int _Info[4];
    uniCpuid(_Info, 0);
    *(int*)(_Buf) = _Info[1];
    *(int*)(_Buf + 4) = _Info[3];
    *(int*)(_Buf + 8) = _Info[2];
    // Why? Because endianness...
    return ((unsigned long)(_Buf[0]) << 24) + ((unsigned long)(_Buf[1]) << 16) + ((unsigned long)(_Buf[2]) << 8) + (unsigned long)(_Buf[3]) +
        ((unsigned long)(_Buf[4]) << 24) + ((unsigned long)(_Buf[5]) << 16) + ((unsigned long)(_Buf[6]) << 8) + (unsigned long)(_Buf[7]) +
        ((unsigned long)(_Buf[8]) << 24) + ((unsigned long)(_Buf[9]) << 16) + ((unsigned long)(_Buf[10]) << 8) + (unsigned long)(_Buf[11]);
}

static inline const char* const uniCPUVendorString()
{
    static long _Id;
    _Id = uniCPUVendorID();
    switch (_Id)
    {
    case CPU_VENDOR_AuthenticAMD:
        return "AuthenticAMD";
    case CPU_VENDOR_CentaurHauls:
        return "CentaurHauls";
    case CPU_VENDOR_CyrixInstead:
        return "CyrixInstead";
    case CPU_VENDOR_GenuineIntel:
        return "GenuineIntel";
    case CPU_VENDOR_GenuineIotel:
        return "GenuineIotel";
    case CPU_VENDOR_TransmetaCPU:
        return "TransmetaCPU";
    case CPU_VENDOR_GenuineTMx86:
        return "GenuineTMx86";
    case CPU_VENDOR_Geode_by_NSC:
        return "Geode by NSC";
    case CPU_VENDOR_NexGenDriven:
        return "NexGenDriven";
    case CPU_VENDOR_RiseRiseRise:
        return "RiseRiseRise";
    case CPU_VENDOR_SiS_SiS_SiS_:
        return "SiS SiS SiS ";
    case CPU_VENDOR_UMC_UMC_UMC_:
        return "UMC UMC UMC ";
    case CPU_VENDOR_Vortex86_SoC:
        return "Vortex86 SoC";
    case CPU_VENDOR___Shanghai__:
        return "  Shanghai  ";
    case CPU_VENDOR_HygonGenuine:
        return "HygonGenuine";
    case CPU_VENDOR_Genuine_RDC_:
        return "Genuine  RDC";
    case CPU_VENDOR_E2K_MACHINE:
        return "E2K MACHINE ";
    case CPU_VENDOR_VIA_VIA_VIA_:
        return "VIA VIA VIA ";
    case CPU_VENDOR_AMD_ISBETTER:
        return "AMD ISBETTER";
    case CPU_VENDOR_GenuineAO486:
        return "GenuineAO486";
    case CPU_VENDOR_MiSTer_AO486:
        return "MiSTer AO486";
    case CPU_VENDOR_MicrosoftXTA:
        return "MicrosoftXTA";
    case CPU_VENDOR_VirtualApple:
        return "VirtualApple";
    default:
        return "Unrecognised";
    }
}

static inline int uniCPUIsAMD()
{
    static unsigned long _Id;
    _Id = uniCPUVendorID();
    return ((_Id == CPU_VENDOR_AMD_ISBETTER) || (_Id == CPU_VENDOR_AuthenticAMD));
}

static inline int uniCPUIsIntel()
{
    static unsigned long _Id;
    _Id = uniCPUVendorID();
    return ((_Id == CPU_VENDOR_GenuineIntel) || (_Id == CPU_VENDOR_GenuineIotel));
}

#ifdef __cplusplus
_UNI_BEGIN
namespace cpu
{
	inline void id(int _Info[4], int _Id) noexcept { uniCpuid(_Info, _Id); }
	inline const int feature_set() noexcept { return uniCPUFeatureSet(); }
	inline const int has_feature(const long _Feature) noexcept { return uniCPUHasFeature(_Feature); }
	inline const int supports_AVX512() noexcept { return uniCPUSupportsAVX512(); }
	inline const int supports_AVX() noexcept { return uniCPUSupportsAVX(); }
	inline const int supports_SSE() noexcept { return uniCPUSupportsSSE(); }
	inline const unsigned long vendor_id() noexcept { return uniCPUVendorID(); }
	inline const char* const vendor_string() noexcept { return uniCPUVendorString(); }
	inline const int is_AMD() noexcept { return uniCPUIsAMD(); }
	inline const int is_Intel() noexcept { return uniCPUIsIntel(); }
}
_UNI_END
#endif // __cplusplus

#endif // _UNICPP_CPU_