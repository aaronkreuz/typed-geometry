#pragma once

#include "../../types/mat.hh"
#include "../../types/vec.hh"
#include "../scalar_traits.hh"
#include "../scalars/scalar_math.hh"

namespace tg
{
template <class T>
TG_NODISCARD constexpr T norm(vec<1, T> const& v, T p)
{
    static_assert(is_floating_point<T>, "norm only works on f32/f64");
    return tg::pow(tg::abs(tg::pow(v.x, p)), T(1) / p);
}
template <class T>
TG_NODISCARD constexpr T norm(vec<2, T> const& v, T p)
{
    static_assert(is_floating_point<T>, "norm only works on f32/f64");
    return tg::pow(tg::abs(tg::pow(v.x, p)) + tg::abs(tg::pow(v.y, p)), T(1) / p);
}
template <class T>
TG_NODISCARD constexpr T norm(vec<3, T> const& v, T p)
{
    static_assert(is_floating_point<T>, "norm only works on f32/f64");
    return tg::pow(tg::abs(tg::pow(v.x, p)) + tg::abs(tg::pow(v.y, p)) + tg::abs(tg::pow(v.z, p)), T(1) / p);
}
template <class T>
TG_NODISCARD constexpr T norm(vec<4, T> const& v, T p)
{
    static_assert(is_floating_point<T>, "norm only works on f32/f64");
    return tg::pow(tg::abs(tg::pow(v.x, p)) + tg::abs(tg::pow(v.y, p)) + tg::abs(tg::pow(v.z, p)) + tg::abs(tg::pow(v.w, p)), T(1) / p);
}

template <int C, int R, class T>
TG_NODISCARD constexpr T frobenius_norm(mat<C, R, T> const& v)
{
    static_assert(is_floating_point<T>, "frobenius_norm only works on f32/f64");
    auto s = T(0);
    for (auto x = 0; x < C; ++x)
        for (auto y = 0; y < C; ++y)
            s += tg::pow2(v[x][y]);
    return tg::sqrt(s);
}

}
