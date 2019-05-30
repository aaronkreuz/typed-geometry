#pragma once

#include <cmath>

#include <typed-geometry/common/constants.hh>
#include <typed-geometry/detail/scalar_traits.hh>
#include <typed-geometry/detail/utility.hh>
#include <typed-geometry/types/angle.hh>
#include <typed-geometry/types/scalar.hh>

// TODO:
// - proper f8, f16
// - constexpr abs, sqrt, pow, ...
// - asm sqrt
// - floor, ceil, round

namespace tg
{
// ==================================================================
// Classification

[[nodiscard]] inline bool is_nan(f32 x) { return std::isnan(x); }
[[nodiscard]] inline bool is_nan(f64 x) { return std::isnan(x); }

[[nodiscard]] inline bool is_zero(f32 x) { return x == 0; }
[[nodiscard]] inline bool is_zero(f64 x) { return x == 0; }

[[nodiscard]] inline bool is_inf(f32 x) { return std::isinf(x); }
[[nodiscard]] inline bool is_inf(f64 x) { return std::isinf(x); }

[[nodiscard]] inline bool is_finite(f32 x) { return std::isfinite(x); }
[[nodiscard]] inline bool is_finite(f64 x) { return std::isfinite(x); }

[[nodiscard]] inline bool is_normal(f32 x) { return std::isnormal(x); }
[[nodiscard]] inline bool is_normal(f64 x) { return std::isnormal(x); }

[[nodiscard]] inline bool is_subnormal(f32 x) { return is_finite(x) && !is_normal(x); }
[[nodiscard]] inline bool is_subnormal(f64 x) { return is_finite(x) && !is_normal(x); }

enum class fp_class
{
    infinite,
    nan,
    normal,
    subnormal,
    zero
};

[[nodiscard]] inline fp_class fp_classify(f32 x)
{
    if (is_nan(x))
        return fp_class::nan;
    else if (is_inf(x))
        return fp_class::infinite;
    else if (is_zero(x))
        return fp_class::zero;
    else if (is_normal(x))
        return fp_class::normal;
    else
        return fp_class::subnormal;
}
[[nodiscard]] inline fp_class fp_classify(f64 x)
{
    if (is_nan(x))
        return fp_class::nan;
    else if (is_inf(x))
        return fp_class::infinite;
    else if (is_zero(x))
        return fp_class::zero;
    else if (is_normal(x))
        return fp_class::normal;
    else
        return fp_class::subnormal;
}

// ==================================================================
// Basics

// -i8 is i32 consistent with C++
[[nodiscard]] inline i32 abs(i8 v) { return v < 0 ? -v : v; }
[[nodiscard]] inline i32 abs(i16 v) { return v < 0 ? -v : v; }
[[nodiscard]] inline i32 abs(i32 v) { return v < 0 ? -v : v; }
[[nodiscard]] inline i64 abs(i64 v) { return v < 0 ? -v : v; }

[[nodiscard]] inline u8 abs(u8 v) { return v; }
[[nodiscard]] inline u16 abs(u16 v) { return v; }
[[nodiscard]] inline u32 abs(u32 v) { return v; }
[[nodiscard]] inline u64 abs(u64 v) { return v; }

[[nodiscard]] inline f8 abs(f8 v) { return v; }
[[nodiscard]] inline f16 abs(f16 v) { return std::abs(v); }
[[nodiscard]] inline f32 abs(f32 v) { return std::abs(v); }
[[nodiscard]] inline f64 abs(f64 v) { return std::abs(v); }

template <class T>
[[nodiscard]] angle_t<T> abs(angle_t<T> a)
{
    return radians(abs(a.radians()));
}

[[nodiscard]] inline f32 floor(f32 v) { return std::floor(v); }
[[nodiscard]] inline f64 floor(f64 v) { return std::floor(v); }
[[nodiscard]] inline i32 ifloor(f32 v) { return v >= 0 || f32(i32(v)) == v ? i32(v) : i32(v) - 1; }
[[nodiscard]] inline i64 ifloor(f64 v) { return v >= 0 || f64(i64(v)) == v ? i64(v) : i64(v) - 1; }

[[nodiscard]] inline f32 ceil(f32 v) { return std::ceil(v); }
[[nodiscard]] inline f64 ceil(f64 v) { return std::ceil(v); }
[[nodiscard]] inline i32 iceil(f32 v) { return v <= 0 || f32(i32(v)) == v ? i32(v) : i32(v) + 1; }
[[nodiscard]] inline i64 iceil(f64 v) { return v <= 0 || f64(i64(v)) == v ? i64(v) : i64(v) + 1; }

[[nodiscard]] inline f32 round(f32 v) { return std::round(v); }
[[nodiscard]] inline f64 round(f64 v) { return std::round(v); }
[[nodiscard]] inline i32 iround(f32 v) { return v >= 0 ? i32(v + 0.5f) : i32(v - 0.5f); }
[[nodiscard]] inline i64 iround(f64 v) { return v >= 0 ? i64(v + 0.5) : i64(v - 0.5); }

[[nodiscard]] inline f32 fract(f32 v) { return v - floor(v); }
[[nodiscard]] inline f64 fract(f64 v) { return v - floor(v); }

template <class T, class = enable_if<is_scalar<T>>>
[[nodiscard]] constexpr T min(T const& a, T const& b)
{
    return a < b ? a : b;
}
template <class T, class = enable_if<is_scalar<T>>>
[[nodiscard]] constexpr T max(T const& a, T const& b)
{
    return a < b ? b : a;
}

template <class T, class = enable_if<is_scalar<T>>>
[[nodiscard]] constexpr angle_t<T> min(angle_t<T> const& a, angle_t<T> const& b)
{
    return a < b ? a : b;
}
template <class T, class = enable_if<is_scalar<T>>>
[[nodiscard]] constexpr angle_t<T> max(angle_t<T> const& a, angle_t<T> const& b)
{
    return a < b ? b : a;
}

template <class T, class = enable_if<is_scalar<T>>>
[[nodiscard]] constexpr T clamp(T const& a, T const& min_value, T const& max_value)
{
    return min(max(a, min_value), max_value);
}

template <class T, class = enable_if<is_scalar<T>>>
[[nodiscard]] constexpr T saturate(T const& a)
{
    return clamp(a, T(0), T(1));
}

template <class T, class = enable_if<is_scalar<T>>>
[[nodiscard]] constexpr T sign(T const& v)
{
    // TODO: optimize?
    // if constexpr (!is_unsigned_integer<T>)
    if (v < T(0))
        return T(-1);
    if (v > T(0))
        return T(1);
    return T(0);
}

// ==================================================================
// Powers

[[nodiscard]] inline f32 pow(f32 b, f32 e) { return std::pow(b, e); }
[[nodiscard]] inline f32 pow(f32 b, i32 e) { return f32(std::pow(b, e)); }
[[nodiscard]] inline f64 pow(f64 b, f64 e) { return std::pow(b, e); }
[[nodiscard]] inline f64 pow(f64 b, i32 e) { return std::pow(b, e); }

template <class T, class = enable_if<has_multiplication<T>>>
[[nodiscard]] constexpr T pow2(T const& v)
{
    return v * v;
}
template <class T, class = enable_if<has_multiplication<T>>>
[[nodiscard]] constexpr T pow3(T const& v)
{
    return v * v * v;
}
template <class T, class = enable_if<has_multiplication<T>>>
[[nodiscard]] constexpr T pow4(T const& v)
{
    auto v2 = v * v;
    return v2 * v2;
}
template <class T, class = enable_if<has_multiplication<T>>>
[[nodiscard]] constexpr T pow5(T const& v)
{
    auto v2 = v * v;
    return v2 * v2 * v;
}

[[nodiscard]] inline f32 sqrt(f32 v) { return std::sqrt(v); }
[[nodiscard]] inline f64 sqrt(f64 v) { return std::sqrt(v); }

[[nodiscard]] inline f32 cbrt(f32 v) { return std::cbrt(v); }
[[nodiscard]] inline f64 cbrt(f64 v) { return std::cbrt(v); }

// ==================================================================
// Exponentials

[[nodiscard]] inline f32 exp(f32 v) { return std::exp(v); }
[[nodiscard]] inline f64 exp(f64 v) { return std::exp(v); }

[[nodiscard]] inline f32 exp2(f32 v) { return std::exp2(v); }
[[nodiscard]] inline f64 exp2(f64 v) { return std::exp2(v); }

[[nodiscard]] inline f32 log(f32 v) { return std::log(v); }
[[nodiscard]] inline f64 log(f64 v) { return std::log(v); }

[[nodiscard]] inline f32 log2(f32 v) { return std::log2(v); }
[[nodiscard]] inline f64 log2(f64 v) { return std::log2(v); }

[[nodiscard]] inline f32 log10(f32 v) { return std::log10(v); }
[[nodiscard]] inline f64 log10(f64 v) { return std::log10(v); }

// ==================================================================
// Trigonometry

[[nodiscard]] inline f32 sin(angle_t<f32> v) { return std::sin(v.radians()); }
[[nodiscard]] inline f64 sin(angle_t<f64> v) { return std::sin(v.radians()); }
[[nodiscard]] inline f32 cos(angle_t<f32> v) { return std::cos(v.radians()); }
[[nodiscard]] inline f64 cos(angle_t<f64> v) { return std::cos(v.radians()); }
[[nodiscard]] inline f32 tan(angle_t<f32> v) { return std::tan(v.radians()); }
[[nodiscard]] inline f64 tan(angle_t<f64> v) { return std::tan(v.radians()); }

[[nodiscard]] inline angle_t<f32> asin(f32 v) { return radians(std::asin(v)); }
[[nodiscard]] inline angle_t<f64> asin(f64 v) { return radians(std::asin(v)); }
[[nodiscard]] inline angle_t<f32> acos(f32 v) { return radians(std::acos(v)); }
[[nodiscard]] inline angle_t<f64> acos(f64 v) { return radians(std::acos(v)); }
[[nodiscard]] inline angle_t<f32> atan(f32 v) { return radians(std::atan(v)); }
[[nodiscard]] inline angle_t<f64> atan(f64 v) { return radians(std::atan(v)); }

[[nodiscard]] inline angle_t<f32> atan2(f32 y, f32 x) { return radians(std::atan2(y, x)); }
[[nodiscard]] inline angle_t<f64> atan2(f64 y, f64 x) { return radians(std::atan2(y, x)); }

[[nodiscard]] inline f32 sinh(f32 v) { return std::sinh(v); }
[[nodiscard]] inline f64 sinh(f64 v) { return std::sinh(v); }
[[nodiscard]] inline f32 cosh(f32 v) { return std::cosh(v); }
[[nodiscard]] inline f64 cosh(f64 v) { return std::cosh(v); }
[[nodiscard]] inline f32 tanh(f32 v) { return std::tanh(v); }
[[nodiscard]] inline f64 tanh(f64 v) { return std::tanh(v); }

[[nodiscard]] inline f32 asinh(f32 v) { return std::asinh(v); }
[[nodiscard]] inline f64 asinh(f64 v) { return std::asinh(v); }
[[nodiscard]] inline f32 acosh(f32 v) { return std::acosh(v); }
[[nodiscard]] inline f64 acosh(f64 v) { return std::acosh(v); }
[[nodiscard]] inline f32 atanh(f32 v) { return std::atanh(v); }
[[nodiscard]] inline f64 atanh(f64 v) { return std::atanh(v); }

} // namespace tg
