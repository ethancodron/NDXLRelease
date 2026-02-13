//--------------------------------------\\
// C/C++ common values and functions    \\
// Ethan Codron 2025		            \\
// GNU GPL-3.0				            \\
//--------------------------------------\\
// Header file providing commnly used   \\
// functions and values like PI.        \\
//--------------------------------------\\

#ifndef _UNICPP_VALS_
#define _UNICPP_VALS_

#include "unicpp_core.h"

// Math constants vvvvv

#define PI              3.14159265358979323846264338327950
#define TWO_PI          6.28318530717958647692528676655900
#define PI_OVER_TWO     1.57079632679489661923132169163980
#define ONE_OVER_PI     0.31830988618379067153776752674503
#define ONE_OVER_TWO_PI 0.15915494309189533576888376337251
#define SQRT_PI			1.77245385090551602729816748334110
#define SQRT_2			1.41421356237309504880168872420970
#define EULER           2.71828182845904523536028747135270
#define LN2				0.69314718055994530941723212145818
#define LN10			2.30258509299404568401799145468440
#define ONE_OVER_LN2	1.44269504088896340735992468100190
#define ONE_OVER_LN10	0.43429448190325182765112891891661

#define PIf                 3.14159265358979323846264338327950f
#define TWO_PIf             6.28318530717958647692528676655900f
#define PI_OVER_TWOf        1.57079632679489661923132169163980f
#define ONE_OVER_PIf        0.31830988618379067153776752674503f
#define ONE_OVER_TWO_PIf    0.15915494309189533576888376337251f
#define SQRT_PIf		    1.77245385090551602729816748334110f
#define SQRT_2f 		    1.41421356237309504880168872420970f
#define EULERf              2.71828182845904523536028747135270f
#define LN2f			    0.69314718055994530941723212145818f
#define LN10f			    2.30258509299404568401799145468440f
#define ONE_OVER_LN2f	    1.44269504088896340735992468100190f
#define ONE_OVER_LN10f	    0.43429448190325182765112891891661f

// ^^^^^ Math constants | special values vvvvv

static inline unsigned char uniLsb(const unsigned long long _Val)
{
    unsigned char c = 0;
    unsigned long long n = _Val;
    while (!(n & 1))
    {
        n >>= 1;
        c++;
    }
    return c;
}

static inline unsigned char uniMsb(const unsigned long long _Val)
{
    unsigned char c = 0;
    unsigned long long n = _Val;
    while (n >>= 1) c++;
    return c;
}

static inline char uniIspow2(const unsigned long long _Val) { return BIT(uniMsb(_Val)) == _Val; }

static inline double uniEps(const double _Xx)
{
    unsigned long long _Ll = (*(unsigned long long*) & _Xx) + 1;
    return *(double*)&_Ll - _Xx;
}

static inline float uniEpsf(const float _Xx)
{
    unsigned long _L = (*(unsigned long*)&_Xx) + 1;
    return *(float*)&_L - _Xx;
}

static inline double uniNan()
{
    const long long _Ll = 0x7FF8000000000000ll;
    return *(double*)&_Ll;
}

static inline float uniNanf()
{
    const long _L = 0x7FF80000l;
    return *(float*)&_L;
}

static inline double uniInf()
{
    const long long _Ll = 0x7FF0000000000000ll;
    return *(double*)&_Ll;
}

static inline float uniInff()
{
    const long _L = 0x7FF00000l;
    return *(float*)&_L;
}

static inline double uniDoubleMax()
{
    const long long _Ll = 0x78EFFFFFFFFFFFFFll;
    return *(double*)&_Ll;
}

static inline double uniDoubleMin()
{
    const long long _Ll = 0xF8EFFFFFFFFFFFFFll;
    return *(double*)&_Ll;
}

static inline float uniFloatMax()
{
    const long _L = 0x7F7FFFFFl;
    return *(float*)&_L;
}

static inline float uniFloatMin()
{
    const long _L = 0xFF7FFFFFl;
    return *(float*)&_L;
}

#ifdef __cplusplus
_UNI_BEGIN

inline const unsigned char lsb(const unsigned long long _Val) { return uniLsb(_Val); }
inline const unsigned char msb(const unsigned long long _Val) { return uniMsb(_Val); }
inline const char ispow2(const unsigned long long _Val) { return uniIspow2(_Val); }
inline const double eps(const double _Xx = 1.0) { return uniEps(_Xx); }
inline const float epsf(const float _Xx = 1.0f) { return uniEpsf(_Xx); }
inline const double nan() { return uniNan(); }
inline const float nanf() { return uniNanf(); }
inline const double inf() { return uniInf(); }
inline const float inff() { return uniInff(); }
inline const double dblmax() { return uniDoubleMax(); }
inline const double dblmin() { return uniDoubleMin(); }
inline const float fltmax() { return uniFloatMax(); }
inline const float fltmin() { return uniFloatMin(); }

_UNI_END
#endif // __cplusplus

#endif // _UNICPP_VALS_