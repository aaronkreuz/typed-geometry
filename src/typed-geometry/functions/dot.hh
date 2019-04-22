#pragma once

#include <typed-geometry/detail/scalar_traits.hh>
#include <typed-geometry/types/dir.hh>
#include <typed-geometry/types/vec.hh>

namespace tg
{
template <class ScalarT>
TG_NODISCARD constexpr squared_result<ScalarT> dot(vec<1, ScalarT> const& a, vec<1, ScalarT> const& b)
{
    return a.x * squared_result<ScalarT>(b.x);
}
template <class ScalarT>
TG_NODISCARD constexpr squared_result<ScalarT> dot(vec<2, ScalarT> const& a, vec<2, ScalarT> const& b)
{
    return a.x * squared_result<ScalarT>(b.x) + //
           a.y * squared_result<ScalarT>(b.y);
}
template <class ScalarT>
TG_NODISCARD constexpr squared_result<ScalarT> dot(vec<3, ScalarT> const& a, vec<3, ScalarT> const& b)
{
    return a.x * squared_result<ScalarT>(b.x) + //
           a.y * squared_result<ScalarT>(b.y) + //
           a.z * squared_result<ScalarT>(b.z);
}
template <class ScalarT>
TG_NODISCARD constexpr squared_result<ScalarT> dot(vec<4, ScalarT> const& a, vec<4, ScalarT> const& b)
{
    return a.x * squared_result<ScalarT>(b.x) + //
           a.y * squared_result<ScalarT>(b.y) + //
           a.z * squared_result<ScalarT>(b.z) + //
           a.w * squared_result<ScalarT>(b.w);
}

template <class ScalarT>
TG_NODISCARD constexpr ScalarT dot(dir<1, ScalarT> const& a, dir<1, ScalarT> const& b)
{
    return a.x * b.x;
}
template <class ScalarT>
TG_NODISCARD constexpr ScalarT dot(dir<2, ScalarT> const& a, dir<2, ScalarT> const& b)
{
    return a.x * b.x + //
           a.y * b.y;
}
template <class ScalarT>
TG_NODISCARD constexpr ScalarT dot(dir<3, ScalarT> const& a, dir<3, ScalarT> const& b)
{
    return a.x * b.x + //
           a.y * b.y + //
           a.z * b.z;
}
template <class ScalarT>
TG_NODISCARD constexpr ScalarT dot(dir<4, ScalarT> const& a, dir<4, ScalarT> const& b)
{
    return a.x * b.x + //
           a.y * b.y + //
           a.z * b.z + //
           a.w * b.w;
}
} // namespace tg
