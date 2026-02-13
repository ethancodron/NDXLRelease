//--------------------------------------------------\\
// C/C++ version-independent complex type interface	\\
// Ethan Codron 2025								\\
// GNU GPL-3.0										\\
//--------------------------------------------------\\
// Header file providing functions and structs for	\\
// complex type operations.							\\
//--------------------------------------------------\\

#ifndef _UNICPP_COMPLEX_
#define _UNICPP_COMPLEX_

#include "unicpp_vals.h"

// Complex types
typedef struct complex_t complex_t;
typedef struct complexf_t complexf_t;

// Constructors
static inline const complex_t uniComplex(const double _Real, const double _Imag);
static inline const complex_t uniToComplex(const complexf_t _Zz);
static inline const complexf_t uniComplexf(const float _Real, const float _Imag);
static inline const complexf_t uniToComplexf(const complex_t _Zz);

// Special values
static inline const complex_t uniNanz();
static inline const complexf_t uniNanfz();
static inline const complex_t uniInfz();
static inline const complexf_t uniInffz();

// Functions
static inline const complex_t uniConj(const complex_t _ZZ);
static inline const complexf_t uniConjf(const complexf_t _ZZ);
static inline const double uniMag(const complex_t _ZZ);
static inline const float uniMagf(const complexf_t _ZZ);
static inline const double uniArg(const complex_t _ZZ);
static inline const float uniArgf(const complexf_t _ZZ);

// Addition
static inline const complex_t uniAddComplexComplex(const complex_t _Left, const complex_t _Right);
static inline const complex_t uniAddComplexScalar(const complex_t _Left, const double _Right);
static inline const complex_t uniAddScalarComplex(const double _Left, const complex_t _Right);
static inline const complexf_t uniAddComplexfComplexf(const complexf_t _Left, const complexf_t _Right);
static inline const complexf_t uniAddComplexfScalar(const complexf_t _Left, const float _Right);
static inline const complexf_t uniAddScalarComplexf(const float _Left, const complexf_t _Right);

// Subtraction
static inline const complex_t uniSubComplexComplex(const complex_t _Left, const complex_t _Right);
static inline const complex_t uniSubComplexScalar(const complex_t _Left, const double _Right);
static inline const complex_t uniSubScalarComplex(const double _Left, const complex_t _Right);
static inline const complexf_t uniSubComplexfComplexf(const complexf_t _Left, const complexf_t _Right);
static inline const complexf_t uniSubComplexfScalar(const complexf_t _Left, const float _Right);
static inline const complexf_t uniSubScalarComplexf(const float _Left, const complexf_t _Right);

// Multiplication
static inline const complex_t uniMulComplexComplex(const complex_t _Left, const complex_t _Right);
static inline const complex_t uniMulComplexScalar(const complex_t _Left, const double _Right);
static inline const complex_t uniMulScalarComplex(const double _Left, const complex_t _Right);
static inline const complexf_t uniMulComplexfComplexf(const complexf_t _Left, const complexf_t _Right);
static inline const complexf_t uniMulComplexfScalar(const complexf_t _Left, const float _Right);
static inline const complexf_t uniMulScalarComplexf(const float _Left, const complexf_t _Right);

// Division
static inline const complex_t uniDivComplexComplex(const complex_t _Left, const complex_t _Right);
static inline const complex_t uniDivComplexScalar(const complex_t _Left, const double _Right);
static inline const complex_t uniDivScalarComplex(const double _Left, const complex_t _Right);
static inline const complexf_t uniDivComplexfComplexf(const complexf_t _Left, const complexf_t _Right);
static inline const complexf_t uniDivComplexfScalar(const complexf_t _Left, const float _Right);
static inline const complexf_t uniDivScalarComplexf(const float _Left, const complexf_t _Right);

// Sign
static inline const complex_t uniSignz(const complex_t _Z);
static inline const complexf_t uniSignfz(const complexf_t _Z);

// Natural log
static inline const complex_t uniLnz(const complex_t _Z);
static inline const complexf_t uniLnfz(const complexf_t _Z);

// Log base-2
static inline const complex_t uniLog2z(const complex_t _Z);
static inline const complexf_t uniLog2fz(const complexf_t _Z);

// Log base-10
static inline const complex_t uniLog10z(const complex_t _Z);
static inline const complexf_t uniLog10fz(const complexf_t _Z);

// Log base-b
static inline const complex_t uniLogz(const complex_t _Z, const complex_t _B);
static inline const complexf_t uniLogfz(const complexf_t _Z, const complexf_t _B);

// Exponential
static inline const complex_t uniExpz(const complex_t _Z);
static inline const complexf_t uniExpfz(const complexf_t _Z);

// Power
static inline const complex_t uniPowz(const complex_t _Zl, const complex_t _Zr);
static inline const complexf_t uniPowfz(const complexf_t _Zl, const complexf_t _Zr);
static inline const complex_t uniPow2z(const complex_t _Z);
static inline const complexf_t uniPow2fz(const complexf_t _Z);

// Roots
static inline const complex_t uniSqrtz(const complex_t _Z);
static inline const complexf_t uniSqrtfz(const complexf_t _Z);
static inline const complex_t uniCbrtz(const complex_t _Z);
static inline const complexf_t uniCbrtfz(const complexf_t _Z);

// Sin & arcsin
static inline const complex_t uniSinz(const complex_t _Z);
static inline const complexf_t uniSinfz(const complexf_t _Z);
static inline const complex_t uniAsinz(const complex_t _Z);
static inline const complexf_t uniAsinfz(const complexf_t _Z);

// Cos & arccos
static inline const complex_t uniCosz(const complex_t _Z);
static inline const complexf_t uniCosfz(const complexf_t _Z);
static inline const complex_t uniAcosz(const complex_t _Z);
static inline const complexf_t uniAcosfz(const complexf_t _Z);

// Tan & arctan
static inline const complex_t uniTanz(const complex_t _Z);
static inline const complexf_t uniTanfz(const complexf_t _Z);
static inline const complex_t uniAtanz(const complex_t _Z);
static inline const complexf_t uniAtanfz(const complexf_t _Z);

// Csc & arccsc
static inline const complex_t uniCscz(const complex_t _Z);
static inline const complexf_t uniCscfz(const complexf_t _Z);
static inline const complex_t uniAcscz(const complex_t _Z);
static inline const complexf_t uniAcscfz(const complexf_t _Z);

// Sec & arcsec
static inline const complex_t uniSecz(const complex_t _Z);
static inline const complexf_t uniSecfz(const complexf_t _Z);
static inline const complex_t uniAsecz(const complex_t _Z);
static inline const complexf_t uniAsecfz(const complexf_t _Z);

// Cot & arccot
static inline const complex_t uniCotz(const complex_t _Z);
static inline const complexf_t uniCotfz(const complexf_t _Z);
static inline const complex_t uniAcotz(const complex_t _Z);
static inline const complexf_t uniAcotfz(const complexf_t _Z);

// Sinh & arcsinh
static inline const complex_t uniSinhz(const complex_t _Z);
static inline const complexf_t uniSinhfz(const complexf_t _Z);
static inline const complex_t uniAsinhz(const complex_t _Z);
static inline const complexf_t uniAsinhfz(const complexf_t _Z);

// Cosh & arccosh
static inline const complex_t uniCoshz(const complex_t _Z);
static inline const complexf_t uniCoshfz(const complexf_t _Z);
static inline const complex_t uniAcoshz(const complex_t _Z);
static inline const complexf_t uniAcoshfz(const complexf_t _Z);

// Tanh & arctanh
static inline const complex_t uniTanhz(const complex_t _Z);
static inline const complexf_t uniTanhfz(const complexf_t _Z);
static inline const complex_t uniAtanhz(const complex_t _Z);
static inline const complexf_t uniAtanhfz(const complexf_t _Z);

// Csch & arccsch
static inline const complex_t uniCschz(const complex_t _Z);
static inline const complexf_t uniCschfz(const complexf_t _Z);
static inline const complex_t uniAcschz(const complex_t _Z);
static inline const complexf_t uniAcschfz(const complexf_t _Z);

// Sech & arcsech
static inline const complex_t uniSechz(const complex_t _Z);
static inline const complexf_t uniSechfz(const complexf_t _Z);
static inline const complex_t uniAsechz(const complex_t _Z);
static inline const complexf_t uniAsechfz(const complexf_t _Z);

// Coth & arccoth
static inline const complex_t uniCothz(const complex_t _Z);
static inline const complexf_t uniCothfz(const complexf_t _Z);
static inline const complex_t uniAcothz(const complex_t _Z);
static inline const complexf_t uniAcothfz(const complexf_t _Z);

struct complex_t
{
	double real;
	double imag;
#ifdef __cplusplus
	inline constexpr complex_t(const double _Real, const double _Imag) noexcept : real(_Real), imag(_Imag) {}
	inline constexpr complex_t(const double _Val) noexcept : real(_Val), imag(0.0) {}
	inline constexpr complex_t(const complex_t& _Z) noexcept : real(_Z.real), imag(_Z.imag) {}
	inline constexpr complex_t(complex_t&& _Z) noexcept : real(_Z.real), imag(_Z.imag) {}
	inline constexpr complex_t() noexcept : real(0.0), imag(0.0) {}
	inline constexpr complex_t& operator=(const complex_t& _Z) noexcept { this->real = _Z.real; this->imag = _Z.imag; return *this; }
	inline constexpr complex_t& operator=(complex_t&& _Z) noexcept { this->real = _Z.real; this->imag = _Z.imag; return *this; }
	inline complex_t& operator+=(const complex_t& _Right) noexcept { const complex_t _Z = uniAddComplexComplex(*this, _Right); this->real = _Z.real; this->imag = _Z.imag; return *this; }
	inline complex_t& operator+=(const double _Right) noexcept { const complex_t _Z = uniAddComplexScalar(*this, _Right); this->real = _Z.real; this->imag = _Z.imag; return *this; }
	inline complex_t& operator-=(const complex_t& _Right) noexcept { const complex_t _Z = uniSubComplexComplex(*this, _Right); this->real = _Z.real; this->imag = _Z.imag; return *this; }
	inline complex_t& operator-=(const double _Right) noexcept { const complex_t _Z = uniSubComplexScalar(*this, _Right); this->real = _Z.real; this->imag = _Z.imag; return *this; }
	inline complex_t& operator*=(const complex_t& _Right) noexcept { const complex_t _Z = uniMulComplexComplex(*this, _Right); this->real = _Z.real; this->imag = _Z.imag; return *this; }
	inline complex_t& operator*=(const double _Right) noexcept { const complex_t _Z = uniMulComplexScalar(*this, _Right); this->real = _Z.real; this->imag = _Z.imag; return *this; }
	inline complex_t& operator/=(const complex_t& _Right) noexcept { const complex_t _Z = uniDivComplexComplex(*this, _Right); this->real = _Z.real; this->imag = _Z.imag; return *this; }
	inline complex_t& operator/=(const double _Right) noexcept { const complex_t _Z = uniDivComplexScalar(*this, _Right); this->real = _Z.real; this->imag = _Z.imag; return *this; }
	inline const complex_t conj(const complex_t& _Z) const noexcept { return uniConj(_Z); }
	inline const double mag() const noexcept { return uniMag(*this); }
	inline const double arg() const noexcept { return uniArg(*this); }
#endif // __cplusplus
};
#ifdef __cplusplus
	inline const complex_t operator+(const complex_t& _Left, const complex_t& _Right) noexcept { return uniAddComplexComplex(_Left, _Right); }
	inline const complex_t operator+(const complex_t& _Left, const double _Right) noexcept { return uniAddComplexScalar(_Left, _Right); }
	inline const complex_t operator+(const double _Left, const complex_t& _Right) noexcept { return uniAddScalarComplex(_Left, _Right); }
	inline const complex_t operator-(const complex_t& _Left, const complex_t& _Right) noexcept { return uniSubComplexComplex(_Left, _Right); }
	inline const complex_t operator-(const complex_t& _Left, const double _Right) noexcept { return uniSubComplexScalar(_Left, _Right); }
	inline const complex_t operator-(const double _Left, const complex_t& _Right) noexcept { return uniSubScalarComplex(_Left, _Right); }
	inline const complex_t operator*(const complex_t& _Left, const complex_t& _Right) noexcept { return uniMulComplexComplex(_Left, _Right); }
	inline const complex_t operator*(const complex_t& _Left, const double _Right) noexcept { return uniMulComplexScalar(_Left, _Right); }
	inline const complex_t operator*(const double _Left, const complex_t& _Right) noexcept { return uniMulScalarComplex(_Left, _Right); }
	inline const complex_t operator/(const complex_t& _Left, const complex_t& _Right) noexcept { return uniDivComplexComplex(_Left, _Right); }
	inline const complex_t operator/(const complex_t& _Left, const double _Right) noexcept { return uniDivComplexScalar(_Left, _Right); }
	inline const complex_t operator/(const double _Left, const complex_t& _Right) noexcept { return uniDivScalarComplex(_Left, _Right); }
#else
	typedef complex_t complex_t;
#endif // __cplusplus

struct complexf_t
{
	float real;
	float imag;
#ifdef __cplusplus
	inline constexpr complexf_t(const float _Real, const float _Imag) noexcept : real(_Real), imag(_Imag) {}
	inline constexpr complexf_t(const float _Val) noexcept : real(_Val), imag(0.0f) {}
	inline constexpr complexf_t(const complexf_t& _Z) noexcept : real(_Z.real), imag(_Z.imag) {}
	inline constexpr complexf_t(complexf_t&& _Z) noexcept : real(_Z.real), imag(_Z.imag) {}
	inline constexpr complexf_t() noexcept : real(0.0f), imag(0.0f) {}
	inline constexpr complexf_t& operator=(const complexf_t& _Z) noexcept { this->real = _Z.real; this->imag = _Z.imag; return *this; }
	inline constexpr complexf_t& operator=(complexf_t&& _Z) noexcept { this->real = _Z.real; this->imag = _Z.imag; return *this; }
	inline complexf_t& operator+=(const complexf_t& _Right) noexcept { const complexf_t _Z = uniAddComplexfComplexf(*this, _Right); this->real = _Z.real; this->imag = _Z.imag; return *this; }
	inline complexf_t& operator+=(const float _Right) noexcept { const complexf_t _Z = uniAddComplexfScalar(*this, _Right); this->real = _Z.real; this->imag = _Z.imag; return *this; }
	inline complexf_t& operator-=(const complexf_t& _Right) noexcept { const complexf_t _Z = uniSubComplexfComplexf(*this, _Right); this->real = _Z.real; this->imag = _Z.imag; return *this; }
	inline complexf_t& operator-=(const float _Right) noexcept { const complexf_t _Z = uniSubComplexfScalar(*this, _Right); this->real = _Z.real; this->imag = _Z.imag; return *this; }
	inline complexf_t& operator*=(const complexf_t& _Right) noexcept { const complexf_t _Z = uniMulComplexfComplexf(*this, _Right); this->real = _Z.real; this->imag = _Z.imag; return *this; }
	inline complexf_t& operator*=(const float _Right) noexcept { const complexf_t _Z = uniMulComplexfScalar(*this, _Right); this->real = _Z.real; this->imag = _Z.imag; return *this; }
	inline complexf_t& operator/=(const complexf_t& _Right) noexcept { const complexf_t _Z = uniDivComplexfComplexf(*this, _Right); this->real = _Z.real; this->imag = _Z.imag; return *this; }
	inline complexf_t& operator/=(const float _Right) noexcept { const complexf_t _Z = uniDivComplexfScalar(*this, _Right); this->real = _Z.real; this->imag = _Z.imag; return *this; }
	inline const complexf_t conj(const complexf_t& _Z) const noexcept { return uniConjf(_Z); }
	inline const float mag() const noexcept { return uniMagf(*this); }
	inline const float arg() const noexcept { return uniArgf(*this); }
#endif // __cplusplus
};
#ifdef __cplusplus
	inline const complexf_t operator+(const complexf_t& _Left, const complexf_t& _Right) noexcept { return uniAddComplexfComplexf(_Left, _Right); }
	inline const complexf_t operator+(const complexf_t& _Left, const float _Right) noexcept { return uniAddComplexfScalar(_Left, _Right); }
	inline const complexf_t operator+(const float _Left, const complexf_t& _Right) noexcept { return uniAddScalarComplexf(_Left, _Right); }
	inline const complexf_t operator-(const complexf_t& _Left, const complexf_t& _Right) noexcept { return uniSubComplexfComplexf(_Left, _Right); }
	inline const complexf_t operator-(const complexf_t& _Left, const float _Right) noexcept { return uniSubComplexfScalar(_Left, _Right); }
	inline const complexf_t operator-(const float _Left, const complexf_t& _Right) noexcept { return uniSubScalarComplexf(_Left, _Right); }
	inline const complexf_t operator*(const complexf_t& _Left, const complexf_t& _Right) noexcept { return uniMulComplexfComplexf(_Left, _Right); }
	inline const complexf_t operator*(const complexf_t& _Left, const float _Right) noexcept { return uniMulComplexfScalar(_Left, _Right); }
	inline const complexf_t operator*(const float _Left, const complexf_t& _Right) noexcept { return uniMulScalarComplexf(_Left, _Right); }
	inline const complexf_t operator/(const complexf_t& _Left, const complexf_t& _Right) noexcept { return uniDivComplexfComplexf(_Left, _Right); }
	inline const complexf_t operator/(const complexf_t& _Left, const float _Right) noexcept { return uniDivComplexfScalar(_Left, _Right); }
	inline const complexf_t operator/(const float _Left, const complexf_t& _Right) noexcept { return uniDivScalarComplexf(_Left, _Right); }
#else
	typedef complexf_t complexf_t;
#endif // __cplusplus

// Constructors vvvvv

static inline const complex_t uniComplex(const double _Real, const double _Imag)
{
    complex_t _Z;
    _Z.real = _Real;
    _Z.imag = _Imag;
    return _Z;
}

static inline const complex_t uniToComplex(const complexf_t _Zz)
{
	complex_t _Z;
	_Z.real = _Zz.real;
	_Z.imag = _Zz.imag;
	return _Z;
}

static inline const complexf_t uniComplexf(const float _Real, const float _Imag)
{
    complexf_t _Z;
    _Z.real = _Real;
    _Z.imag = _Imag;
    return _Z;
}

static inline const complexf_t uniToComplexf(const complex_t _ZZ)
{
	complexf_t _Z;
	_Z.real = _ZZ.real;
	_Z.imag = _ZZ.imag;
	return _Z;
}

// ^^^^^ Constructors | special values vvvvv

static inline const complex_t uniNanz()
{
    const double _Nan = uniNan();
    complex_t _Z;
    _Z.real = _Nan;
    _Z.imag = _Nan;
    return _Z;
}

static inline const complexf_t uniNanfz()
{
    const float _Nanf = uniNanf();
    complexf_t _Z;
    _Z.real = _Nanf;
    _Z.imag = _Nanf;
    return _Z;
}

static inline const complex_t uniInfz()
{
    const double _Inf = uniInf();
    complex_t _Z;
    _Z.real = _Inf;
    _Z.imag = _Inf;
    return _Z;
}

static inline const complexf_t uniInffz()
{
    const float _Inff = uniInff();
    complexf_t _Z;
    _Z.real = _Inff;
    _Z.imag = _Inff;
    return _Z;
}

// ^^^^^ Special values | functions vvvvv

static inline const complex_t uniConj(const complex_t _ZZ)
{
	complex_t _Z;
	_Z.real = _ZZ.real;
	_Z.imag = -_ZZ.imag;
	return _Z;
}

static inline const complexf_t uniConjf(const complexf_t _Zz)
{
	complexf_t _Z;
	_Z.real = _Zz.real;
	_Z.imag = -_Zz.imag;
	return _Z;
}

static inline const double uniMag(const complex_t _Z) { return sqrt(_Z.real * _Z.real + _Z.imag * _Z.imag); }
static inline const float uniMagf(const complexf_t _Z) { return sqrtf(_Z.real * _Z.real + _Z.imag * _Z.imag); }

static inline const double uniArg(const complex_t _Z) { return atan2(_Z.imag, _Z.real); }
static inline const float uniArgf(const complexf_t _Z) { return atan2f(_Z.imag, _Z.real); }

// ^^^^^ Functions | complex addition vvvvv

static inline const complex_t uniAddComplexComplex(const complex_t _Left, const complex_t _Right)
{
	complex_t _Z;
	_Z.real = _Left.real + _Right.real;
	_Z.imag = _Left.imag + _Right.imag;
	return _Z;
}

static inline const complex_t uniAddComplexScalar(const complex_t _Left, const double _Right)
{
	complex_t _Z;
	_Z.real = _Left.real + _Right;
	_Z.imag = _Left.imag;
	return _Z;
}

static inline const complex_t uniAddScalarComplex(const double _Left, const complex_t _Right)
{
	complex_t _Z;
	_Z.real = _Left + _Right.real;
	_Z.imag = _Right.imag;
	return _Z;
}

// ^^^^^ Complex addition | complexf addition

static inline const complexf_t uniAddComplexfComplexf(const complexf_t _Left, const complexf_t _Right)
{
	complexf_t _Z;
	_Z.real = _Left.real + _Right.real;
	_Z.imag = _Left.imag + _Right.imag;
	return _Z;
}

static inline const complexf_t uniAddComplexfScalar(const complexf_t _Left, const float _Right)
{
	complexf_t _Z;
	_Z.real = _Left.real + _Right;
	_Z.imag = _Left.imag;
	return _Z;
}

static inline const complexf_t uniAddScalarComplexf(const float _Left, const complexf_t _Right)
{
	complexf_t _Z;
	_Z.real = _Left + _Right.real;
	_Z.imag = _Right.imag;
	return _Z;
}

// ^^^^^ Complexf addition | complex subtraction

static inline const complex_t uniSubComplexComplex(const complex_t _Left, const complex_t _Right)
{
	complex_t _Z;
	_Z.real = _Left.real - _Right.real;
	_Z.imag = _Left.imag - _Right.imag;
	return _Z;
}

static inline const complex_t uniSubComplexScalar(const complex_t _Left, const double _Right)
{
	complex_t _Z;
	_Z.real = _Left.real - _Right;
	_Z.imag = _Left.imag;
	return _Z;
}

static inline const complex_t uniSubScalarComplex(const double _Left, const complex_t _Right)
{
	complex_t _Z;
	_Z.real = _Left - _Right.real;
	_Z.imag = _Right.imag;
	return _Z;
}

// ^^^^^ Complex subtraction | complexf subtraction

static inline const complexf_t uniSubComplexfComplexf(const complexf_t _Left, const complexf_t _Right)
{
	complexf_t _Z;
	_Z.real = _Left.real - _Right.real;
	_Z.imag = _Left.imag - _Right.imag;
	return _Z;
}

static inline const complexf_t uniSubComplexfScalar(const complexf_t _Left, const float _Right)
{
	complexf_t _Z;
	_Z.real = _Left.real - _Right;
	_Z.imag = _Left.imag;
	return _Z;
}

static inline const complexf_t uniSubScalarComplexf(const float _Left, const complexf_t _Right)
{
	complexf_t _Z;
	_Z.real = _Left - _Right.real;
	_Z.imag = _Right.imag;
	return _Z;
}

// ^^^^^ Complexf subtraction | complex multiplication vvvvv

static inline const complex_t uniMulComplexComplex(const complex_t _Left, const complex_t _Right)
{
	complex_t _Z;
	_Z.real = _Left.real * _Right.real - _Left.imag * _Right.imag;
	_Z.imag = _Left.real * _Right.imag + _Left.imag * _Right.real;
	return _Z;
}

static inline const complex_t uniMulComplexScalar(const complex_t _Left, const double _Right)
{
	complex_t _Z;
	_Z.real = _Left.real * _Right;
	_Z.imag = _Left.imag * _Right;
	return _Z;
}

static inline const complex_t uniMulScalarComplex(const double _Left, const complex_t _Right)
{
	complex_t _Z;
	_Z.real = _Left * _Right.real;
	_Z.imag = _Left * _Right.imag;
	return _Z;
}

// ^^^^^ Complex multiplication | complexf multiplication vvvvv

static inline const complexf_t uniMulComplexfComplexf(const complexf_t _Left, const complexf_t _Right)
{
	complexf_t _Z;
	_Z.real = _Left.real * _Right.real - _Left.imag * _Right.imag;
	_Z.imag = _Left.real * _Right.imag + _Left.imag * _Right.real;
	return _Z;
}

static inline const complexf_t uniMulComplexfScalar(const complexf_t _Left, const float _Right)
{
	complexf_t _Z;
	_Z.real = _Left.real * _Right;
	_Z.imag = _Left.imag * _Right;
	return _Z;
}

static inline const complexf_t uniMulScalarComplexf(const float _Left, const complexf_t _Right)
{
	complexf_t _Z;
	_Z.real = _Left * _Right.real;
	_Z.imag = _Left * _Right.imag;
	return _Z;
}

// ^^^^^ Complexf multiplication | complex division vvvvv

static inline const complex_t uniDivComplexComplex(const complex_t _Left, const complex_t _Right)
{
	complex_t _Z;
	const double _Coef = 1.0 / (_Right.real * _Right.real + _Right.imag * _Right.imag);
	_Z.real = _Coef * (_Left.real * _Right.real + _Left.imag * _Right.imag);
	_Z.imag = _Coef * (_Left.imag * _Right.real - _Left.real * _Right.imag);
	return _Z;
}

static inline const complex_t uniDivComplexScalar(const complex_t _Left, const double _Right)
{
	complex_t _Z;
	_Z.real = _Left.real / _Right;
	_Z.imag = _Left.imag / _Right;
	return _Z;
}

static inline const complex_t uniDivScalarComplex(const double _Left, const complex_t _Right)
{
	complex_t _Z;
	const double _Coef = 1.0 / (_Right.real * _Right.real + _Right.imag * _Right.imag);
	_Z.real = _Coef * _Left * _Right.real;
	_Z.imag = -_Coef * _Left * _Right.imag;
	return _Z;
}

// ^^^^^ Complex division | complexf division

static inline const complexf_t uniDivComplexfComplexf(const complexf_t _Left, const complexf_t _Right)
{
	complexf_t _Z;
	const float _Coef = 1.0f / (_Right.real * _Right.real + _Right.imag * _Right.imag);
	_Z.real = _Coef * (_Left.real * _Right.real + _Left.imag * _Right.imag);
	_Z.imag = _Coef * (_Left.imag * _Right.real - _Left.real * _Right.imag);
	return _Z;
}

static inline const complexf_t uniDivComplexfScalar(const complexf_t _Left, const float _Right)
{
	complexf_t _Z;
	_Z.real = _Left.real / _Right;
	_Z.imag = _Left.imag / _Right;
	return _Z;
}

static inline const complexf_t uniDivScalarComplexf(const float _Left, const complexf_t _Right)
{
	complexf_t _Z;
	const float _Coef = 1.0f / (_Right.real * _Right.real + _Right.imag * _Right.imag);
	_Z.real = _Coef * _Left * _Right.real;
	_Z.imag = -_Coef * _Left * _Right.imag;
	return _Z;
}

// ^^^^^ Complexf division | functions vvvvv

// Sign
static inline const complex_t uniSignz(const complex_t _Z) { return uniDivComplexScalar(_Z, uniMag(_Z)); }
static inline const complexf_t uniSignfz(const complexf_t _Z) { return uniDivComplexfScalar(_Z, uniMagf(_Z)); }

// Natural log
static inline const complex_t uniLnz(const complex_t _Z) { return uniComplex(log(uniMag(_Z)), uniArg(_Z)); }
static inline const complexf_t uniLnfz(const complexf_t _Z) { return uniComplexf(logf(uniMagf(_Z)), uniArgf(_Z)); }

// Log base-2
static inline const complex_t uniLog2z(const complex_t _Z) { return uniMulComplexScalar(uniLnz(_Z), ONE_OVER_LN2); }
static inline const complexf_t uniLog2fz(const complexf_t _Z) { return uniMulComplexfScalar(uniLnfz(_Z), ONE_OVER_LN2); }

// Log base-10
static inline const complex_t uniLog10z(const complex_t _Z) { return uniMulComplexScalar(uniLnz(_Z), ONE_OVER_LN10); }
static inline const complexf_t uniLog10fz(const complexf_t _Z) { return uniMulComplexfScalar(uniLnfz(_Z), ONE_OVER_LN10); }

// Log base-b
static inline const complex_t uniLogz(const complex_t _Z, const complex_t _B) { return uniDivComplexComplex(uniLnz(_Z), uniLnz(_B)); }
static inline const complexf_t uniLogfz(const complexf_t _Z, const complexf_t _B) { return uniDivComplexfComplexf(uniLnfz(_Z), uniLnfz(_B)); }

// Exponential
static inline const complex_t uniExpz(const complex_t _Z) { return uniMulScalarComplex(exp(_Z.real), uniComplex(cos(_Z.imag), sin(_Z.imag))); }
static inline const complexf_t uniExpfz(const complexf_t _Z) { return uniMulScalarComplexf(expf(_Z.real), uniComplexf(cosf(_Z.imag), sinf(_Z.imag))); }

// Power
static inline const complex_t uniPowz(const complex_t _Zl, const complex_t _Zr) { return uniExpz(uniMulComplexComplex(_Zr, uniLnz(_Zl))); }
static inline const complexf_t uniPowfz(const complexf_t _Zl, const complexf_t _Zr) { return uniExpfz(uniMulComplexfComplexf(_Zr, uniLnfz(_Zl))); }
static inline const complex_t uniPow2z(const complex_t _Z) { return uniPowz(uniComplex(2.0, 0.0), _Z); }
static inline const complexf_t uniPow2fz(const complexf_t _Z) { return uniPowfz(uniComplexf(2.0f, 0.0f), _Z); }

// Roots
static inline const complex_t uniSqrtz(const complex_t _Z) { return uniPowz(_Z, uniComplex(0.5, 0.0)); }
static inline const complexf_t uniSqrtfz(const complexf_t _Z) { return uniPowfz(_Z, uniComplexf(0.5f, 0.0f)); }
static inline const complex_t uniCbrtz(const complex_t _Z) { return uniPowz(_Z, uniComplex(0.33333333333333333333333333333333, 0.0)); }
static inline const complexf_t uniCbrtfz(const complexf_t _Z) { return uniPowfz(_Z, uniComplexf(0.33333333333333333333333333333333f, 0.0f)); }

// Sin & arcsin
static inline const complex_t uniSinz(const complex_t _Z) { const complex_t _Exp = uniExpz(uniMulComplexComplex(uniComplex(0.0, 1.0), _Z)); return uniMulComplexComplex(uniComplex(0.0, -0.5), uniSubComplexComplex(_Exp, uniDivScalarComplex(1.0, _Exp))); }
static inline const complexf_t uniSinfz(const complexf_t _Z) { const complexf_t _Exp = uniExpfz(uniMulComplexfComplexf(uniComplexf(0.0f, 1.0f), _Z)); return uniMulComplexfComplexf(uniComplexf(0.0f, -0.5f), uniSubComplexfComplexf(_Exp, uniDivScalarComplexf(1.0f, _Exp))); }
static inline const complex_t uniAsinz(const complex_t _Z) { return uniMulComplexComplex(uniComplex(0.0, -1.0), uniLnz(uniAddComplexComplex(uniMulComplexComplex(uniComplex(0.0, 1.0), _Z), uniSqrtz(uniSubScalarComplex(1.0, uniMulComplexComplex(_Z, _Z)))))); }
static inline const complexf_t uniAsinfz(const complexf_t _Z) { return uniMulComplexfComplexf(uniComplexf(0.0f, -1.0f), uniLnfz(uniAddComplexfComplexf(uniMulComplexfComplexf(uniComplexf(0.0f, 1.0f), _Z), uniSqrtfz(uniSubScalarComplexf(1.0f, uniMulComplexfComplexf(_Z, _Z)))))); }

// Cos & arccos
static inline const complex_t uniCosz(const complex_t _Z) { const complex_t _Exp = uniExpz(uniMulComplexComplex(uniComplex(0.0, 1.0), _Z)); return uniMulScalarComplex(0.5, uniAddComplexComplex(_Exp, uniDivScalarComplex(1.0, _Exp))); }
static inline const complexf_t uniCosfz(const complexf_t _Z) { const complexf_t _Exp = uniExpfz(uniMulComplexfComplexf(uniComplexf(0.0f, 1.0f), _Z)); return uniMulScalarComplexf(0.5f, uniAddComplexfComplexf(_Exp, uniDivScalarComplexf(1.0f, _Exp))); }
static inline const complex_t uniAcosz(const complex_t _Z) { return uniMulComplexComplex(uniComplex(0.0, -1.0), uniLnz(uniAddComplexComplex(_Z, uniSqrtz(uniSubComplexScalar(uniMulComplexComplex(_Z, _Z), 1.0))))); }
static inline const complexf_t uniAcosfz(const complexf_t _Z) { return uniMulComplexfComplexf(uniComplexf(0.0f, -1.0f), uniLnfz(uniAddComplexfComplexf(_Z, uniSqrtfz(uniSubComplexfScalar(uniMulComplexfComplexf(_Z, _Z), 1.0f))))); }

// Tan & arctan
static inline const complex_t uniTanz(const complex_t _Z) { const double _Denom = 1.0 / (cos(2.0 * _Z.real) + cosh(2.0 * _Z.imag)); return uniMulComplexScalar(uniComplex(sin(2.0 * _Z.real), sinh(2.0 * _Z.imag)), _Denom); }
static inline const complexf_t uniTanfz(const complexf_t _Z) { const float _Denom = 1.0f / (cos(2.0f * _Z.real) + cosh(2.0f * _Z.imag)); return uniMulComplexfScalar(uniComplexf(sinf(2.0f * _Z.real), sinhf(2.0f * _Z.imag)), _Denom); }
static inline const complex_t uniAtanz(const complex_t _Z) { return uniMulComplexComplex(uniComplex(0.0, 0.5), uniLnz(uniDivComplexComplex(uniAddScalarComplex(1.0, _Z), uniSubScalarComplex(1.0, _Z)))); }
static inline const complexf_t uniAtanfz(const complexf_t _Z) { return uniMulComplexfComplexf(uniComplexf(0.0f, 0.5f), uniLnfz(uniDivComplexfComplexf(uniAddScalarComplexf(1.0f, _Z), uniSubScalarComplexf(1.0f, _Z)))); }

// Csc & arccsc
static inline const complex_t uniCscz(const complex_t _Z) { return uniDivScalarComplex(1.0, uniSinz(_Z)); }
static inline const complexf_t uniCscfz(const complexf_t _Z) { return uniDivScalarComplexf(1.0f, uniSinfz(_Z)); }
static inline const complex_t uniAcscz(const complex_t _Z) { return uniAsinz(uniDivScalarComplex(1.0, _Z)); }
static inline const complexf_t uniAcscfz(const complexf_t _Z) { return uniAsinfz(uniDivScalarComplexf(1.0f, _Z)); }

// Sec & arcsec
static inline const complex_t uniSecz(const complex_t _Z) { return uniDivScalarComplex(1.0, uniCosz(_Z)); }
static inline const complexf_t uniSecfz(const complexf_t _Z) { return uniDivScalarComplexf(1.0f, uniCosfz(_Z)); }
static inline const complex_t uniAsecz(const complex_t _Z) { return uniAcosz(uniDivScalarComplex(1.0, _Z)); }
static inline const complexf_t uniAsecfz(const complexf_t _Z) { return uniAcosfz(uniDivScalarComplexf(1.0f, _Z)); }

// Cot & arccot
static inline const complex_t uniCotz(const complex_t _Z) { return uniDivScalarComplex(1.0, uniTanz(_Z)); }
static inline const complexf_t uniCotfz(const complexf_t _Z) { return uniDivScalarComplexf(1.0f, uniTanfz(_Z)); }
static inline const complex_t uniAcotz(const complex_t _Z) { return uniSubScalarComplex(PI_OVER_TWO, uniAtanz(_Z)); }
static inline const complexf_t uniAcotfz(const complexf_t _Z) { return uniSubScalarComplexf(PI_OVER_TWOf, uniAtanfz(_Z)); }

// Sinh & arcsinh
static inline const complex_t uniSinhz(const complex_t _Z) { return uniComplex(sinh(_Z.real) * cos(_Z.imag), cosh(_Z.real) * sin(_Z.imag)); }
static inline const complexf_t uniSinhfz(const complexf_t _Z) { return uniComplexf(sinhf(_Z.real) * cosf(_Z.imag), coshf(_Z.real) * sinf(_Z.imag)); }
static inline const complex_t uniAsinhz(const complex_t _Z) { return uniLnz(uniAddComplexComplex(_Z, uniSqrtz(uniAddComplexScalar(uniMulComplexComplex(_Z, _Z), 1.0)))); }
static inline const complexf_t uniAsinhfz(const complexf_t _Z) { return uniLnfz(uniAddComplexfComplexf(_Z, uniSqrtfz(uniAddComplexfScalar(uniMulComplexfComplexf(_Z, _Z), 1.0f)))); }

// Cosh & arccosh
static inline const complex_t uniCoshz(const complex_t _Z) { return uniComplex(cosh(_Z.real) * cos(_Z.imag), sinh(_Z.real) * sin(_Z.imag)); }
static inline const complexf_t uniCoshfz(const complexf_t _Z) { return uniComplexf(coshf(_Z.real) * cosf(_Z.imag), sinhf(_Z.real) * sinf(_Z.imag)); }
static inline const complex_t uniAcoshz(const complex_t _Z) { return uniLnz(uniAddComplexComplex(_Z, uniSqrtz(uniSubComplexScalar(uniMulComplexComplex(_Z, _Z), 1.0)))); }
static inline const complexf_t uniAcoshfz(const complexf_t _Z) { return uniLnfz(uniAddComplexfComplexf(_Z, uniSqrtfz(uniSubComplexfScalar(uniMulComplexfComplexf(_Z, _Z), 1.0f)))); }

// Tanh & arctanh
static inline const complex_t uniTanhz(const complex_t _Z) { const double _Denom = 1.0 / (cosh(2.0 * _Z.real) + cos(2.0 * _Z.imag)); return uniMulComplexScalar(uniComplex(sinh(2.0 * _Z.real), sin(2.0 * _Z.imag)), _Denom); }
static inline const complexf_t uniTanhfz(const complexf_t _Z) { const float _Denom = 1.0f / (coshf(2.0f * _Z.real) + cosf(2.0f * _Z.imag)); return uniMulComplexfScalar(uniComplexf(sinhf(2.0f * _Z.real), sinf(2.0f * _Z.imag)), _Denom); }
static inline const complex_t uniAtanhz(const complex_t _Z) { return uniMulScalarComplex(0.5, uniLnz(uniDivComplexComplex(uniAddScalarComplex(1.0, _Z), uniSubScalarComplex(1.0, _Z)))); }
static inline const complexf_t uniAtanhfz(const complexf_t _Z) { return uniMulScalarComplexf(0.5f, uniLnfz(uniDivComplexfComplexf(uniAddScalarComplexf(1.0f, _Z), uniSubScalarComplexf(1.0f, _Z)))); }

// Csch & arccsch
static inline const complex_t uniCschz(const complex_t _Z) { return uniDivScalarComplex(1.0, uniSinhz(_Z)); }
static inline const complexf_t uniCschfz(const complexf_t _Z) { return uniDivScalarComplexf(1.0f, uniSinhfz(_Z)); }
static inline const complex_t uniAcschz(const complex_t _Z) { return uniAsinhz(uniDivScalarComplex(1.0, _Z)); }
static inline const complexf_t uniAcschfz(const complexf_t _Z) { return uniAsinhfz(uniDivScalarComplexf(1.0f, _Z)); }

// Sech & arcsech
static inline const complex_t uniSechz(const complex_t _Z) { return uniDivScalarComplex(1.0, uniCoshz(_Z)); }
static inline const complexf_t uniSechfz(const complexf_t _Z) { return uniDivScalarComplexf(1.0f, uniCoshfz(_Z)); }
static inline const complex_t uniAsechz(const complex_t _Z) { return uniAcoshz(uniDivScalarComplex(1.0, _Z)); }
static inline const complexf_t uniAsechfz(const complexf_t _Z) { return uniAcoshfz(uniDivScalarComplexf(1.0f, _Z)); }

// Coth & arccoth
static inline const complex_t uniCothz(const complex_t _Z) { return uniDivScalarComplex(1.0, uniTanhz(_Z)); }
static inline const complexf_t uniCothfz(const complexf_t _Z) { return uniDivScalarComplexf(1.0f, uniTanhfz(_Z)); }
static inline const complex_t uniAcothz(const complex_t _Z) { return uniAtanz(uniDivScalarComplex(1.0, _Z)); }
static inline const complexf_t uniAcothfz(const complexf_t _Z) { return uniAtanfz(uniDivScalarComplexf(1.0f, _Z)); }

// ^^^^^ Functions

#ifdef __cplusplus
_UNI_BEGIN

template<> inline constexpr char get_typeid<complex_t>() { return UNI_COMPLEX; }
template<> inline constexpr char get_typeid<complexf_t>() { return UNI_COMPLEXF; }

inline const complex_t to_complex(const complexf_t& _Z) { return uniToComplex(_Z); }
inline const complexf_t to_complexf(const complex_t& _Z) { return uniToComplexf(_Z); }

inline const complex_t nanz() noexcept { return uniNanz(); }
inline const complexf_t nanfz() noexcept { return uniNanfz(); }
inline const complex_t infz() noexcept { return uniInfz(); }
inline const complexf_t inffz() noexcept { return uniInffz(); }

inline const double absz(const complex_t& _Z) noexcept { return uniMag(_Z); }
inline const float absfz(const complexf_t& _Z) noexcept { return uniMagf(_Z); }
inline const complex_t signz(const complex_t& _Z) noexcept { return uniSignz(_Z); }
inline const complexf_t signfz(const complexf_t& _Z) noexcept { return uniSignfz(_Z); }

inline const complex_t lnz(const complex_t& _Z) noexcept { return uniLnz(_Z); }
inline const complexf_t lnfz(const complexf_t& _Z) noexcept { return uniLnfz(_Z); }
inline const complex_t log2z(const complex_t& _Z) noexcept { return uniLog2z(_Z); }
inline const complexf_t log2fz(const complexf_t& _Z) noexcept { return uniLog2fz(_Z); }
inline const complex_t log10z(const complex_t& _Z) noexcept { return uniLog10z(_Z); }
inline const complexf_t log10fz(const complexf_t& _Z) noexcept { return uniLog10fz(_Z); }
inline const complex_t logz(const complex_t& _Z, const complex_t& _B) noexcept { return uniLogz(_Z, _B); }
inline const complexf_t logfz(const complexf_t& _Z, const complexf_t& _B) noexcept { return uniLogfz(_Z, _B); }

inline const complex_t expz(const complex_t& _Z) noexcept { return uniExpz(_Z); }
inline const complexf_t expfz(const complexf_t& _Z) noexcept { return uniExpfz(_Z); }
inline const complex_t powz(const complex_t& _Zl, const complex_t& _Zr) noexcept { return uniPowz(_Zl, _Zr); }
inline const complexf_t powfz(const complexf_t& _Zl, const complexf_t& _Zr) noexcept { return uniPowfz(_Zl, _Zr); }
inline const complex_t pow2z(const complex_t& _Z) noexcept { return uniPow2z(_Z); }
inline const complexf_t pow2fz(const complexf_t& _Z) noexcept { return uniPow2fz(_Z); }
inline const complex_t sqrtz(const complex_t& _Z) noexcept { return uniSqrtz(_Z); }
inline const complexf_t sqrtfz(const complexf_t& _Z) noexcept { return uniSqrtfz(_Z); }
inline const complex_t cbrtz(const complex_t& _Z) noexcept { return uniCbrtz(_Z); }
inline const complexf_t cbrtfz(const complexf_t& _Z) noexcept { return uniCbrtfz(_Z); }

inline const complex_t sinz(const complex_t& _Z) noexcept { return uniSinz(_Z); }
inline const complexf_t sinfz(const complexf_t& _Z) noexcept { return uniSinfz(_Z); }
inline const complex_t cosz(const complex_t& _Z) noexcept { return uniCosz(_Z); }
inline const complexf_t cosfz(const complexf_t& _Z) noexcept { return uniCosfz(_Z); }
inline const complex_t tanz(const complex_t& _Z) noexcept { return uniTanz(_Z); }
inline const complexf_t tanfz(const complexf_t& _Z) noexcept { return uniTanfz(_Z); }
inline const complex_t cscz(const complex_t& _Z) noexcept { return uniCscz(_Z); }
inline const complexf_t cscfz(const complexf_t& _Z) noexcept { return uniCscfz(_Z); }
inline const complex_t secz(const complex_t& _Z) noexcept { return uniSecz(_Z); }
inline const complexf_t secfz(const complexf_t& _Z) noexcept { return uniSecfz(_Z); }
inline const complex_t cotz(const complex_t& _Z) noexcept { return uniCotz(_Z); }
inline const complexf_t cotfz(const complexf_t& _Z) noexcept { return uniCotfz(_Z); }

inline const complex_t asinz(const complex_t& _Z) noexcept { return uniAsinz(_Z); }
inline const complexf_t asinfz(const complexf_t& _Z) noexcept { return uniAsinfz(_Z); }
inline const complex_t acosz(const complex_t& _Z) noexcept { return uniAcosz(_Z); }
inline const complexf_t acosfz(const complexf_t& _Z) noexcept { return uniAcosfz(_Z); }
inline const complex_t atanz(const complex_t& _Z) noexcept { return uniAtanz(_Z); }
inline const complexf_t atanfz(const complexf_t& _Z) noexcept { return uniAtanfz(_Z); }
inline const complex_t acscz(const complex_t& _Z) noexcept { return uniAcscz(_Z); }
inline const complexf_t acscfz(const complexf_t& _Z) noexcept { return uniAcscfz(_Z); }
inline const complex_t asecz(const complex_t& _Z) noexcept { return uniAsecz(_Z); }
inline const complexf_t asecfz(const complexf_t& _Z) noexcept { return uniAsecfz(_Z); }
inline const complex_t acotz(const complex_t& _Z) noexcept { return uniAcotz(_Z); }
inline const complexf_t acotfz(const complexf_t& _Z) noexcept { return uniAcotfz(_Z); }

inline const complex_t sinhz(const complex_t& _Z) noexcept { return uniSinhz(_Z); }
inline const complexf_t sinhfz(const complexf_t& _Z) noexcept { return uniSinhfz(_Z); }
inline const complex_t coshz(const complex_t& _Z) noexcept { return uniCoshz(_Z); }
inline const complexf_t coshfz(const complexf_t& _Z) noexcept { return uniCoshfz(_Z); }
inline const complex_t tanhz(const complex_t& _Z) noexcept { return uniTanhz(_Z); }
inline const complexf_t tanhfz(const complexf_t& _Z) noexcept { return uniTanhfz(_Z); }
inline const complex_t cschz(const complex_t& _Z) noexcept { return uniCschz(_Z); }
inline const complexf_t cschfz(const complexf_t& _Z) noexcept { return uniCschfz(_Z); }
inline const complex_t sechz(const complex_t& _Z) noexcept { return uniSechz(_Z); }
inline const complexf_t sechfz(const complexf_t& _Z) noexcept { return uniSechfz(_Z); }
inline const complex_t cothz(const complex_t& _Z) noexcept { return uniCothz(_Z); }
inline const complexf_t cothfz(const complexf_t& _Z) noexcept { return uniCothfz(_Z); }

inline const complex_t asinhz(const complex_t& _Z) noexcept { return uniAsinhz(_Z); }
inline const complexf_t asinhfz(const complexf_t& _Z) noexcept { return uniAsinhfz(_Z); }
inline const complex_t acoshz(const complex_t& _Z) noexcept { return uniAcoshz(_Z); }
inline const complexf_t acoshfz(const complexf_t& _Z) noexcept { return uniAcoshfz(_Z); }
inline const complex_t atanhz(const complex_t& _Z) noexcept { return uniAtanhz(_Z); }
inline const complexf_t atanhfz(const complexf_t& _Z) noexcept { return uniAtanhfz(_Z); }
inline const complex_t acschz(const complex_t& _Z) noexcept { return uniAcschz(_Z); }
inline const complexf_t acschfz(const complexf_t& _Z) noexcept { return uniAcschfz(_Z); }
inline const complex_t asechz(const complex_t& _Z) noexcept { return uniAsechz(_Z); }
inline const complexf_t asechfz(const complexf_t& _Z) noexcept { return uniAsechfz(_Z); }
inline const complex_t acothz(const complex_t& _Z) noexcept { return uniAcothz(_Z); }
inline const complexf_t acothfz(const complexf_t& _Z) noexcept { return uniAcothfz(_Z); }

_UNI_END
#endif // __cplusplus

#endif // _UNICPP_COMPLEX_