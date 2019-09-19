#pragma once

#include "../detail/comp_traits.hh"
#include "../detail/macros.hh"
#include "../detail/scalar_traits.hh"
#include "../detail/utility.hh"
#include "fwd.hh"
#include "scalar.hh"
#include "vec.hh"

namespace tg
{
template <int D, class ScalarT>
struct size;

// Common size types

using size1 = size<1, f32>;
using size2 = size<2, f32>;
using size3 = size<3, f32>;
using size4 = size<4, f32>;

using fsize1 = size<1, f32>;
using fsize2 = size<2, f32>;
using fsize3 = size<3, f32>;
using fsize4 = size<4, f32>;

using dsize1 = size<1, f64>;
using dsize2 = size<2, f64>;
using dsize3 = size<3, f64>;
using dsize4 = size<4, f64>;

using isize1 = size<1, i32>;
using isize2 = size<2, i32>;
using isize3 = size<3, i32>;
using isize4 = size<4, i32>;

using usize1 = size<1, u32>;
using usize2 = size<2, u32>;
using usize3 = size<3, u32>;
using usize4 = size<4, u32>;


// ======== IMPLEMENTATION ========

template <class ScalarT>
struct size<1, ScalarT>
{
    static const size zero;
    static const size ones;
    static const size unit;

    ScalarT width = static_cast<ScalarT>(0);

    constexpr ScalarT& operator[](int i) { return (&width)[i]; }
    constexpr ScalarT const& operator[](int i) const { return (&width)[i]; }

    constexpr size() = default;
    constexpr size(size const&) = default;
    constexpr size(size&&) = default;
    constexpr size(ScalarT v) : width(v) {}

    template <class Obj, class = enable_if<is_comp_convertible<Obj, ScalarT>>>
    explicit constexpr size(Obj const& v, ScalarT fill = ScalarT(0))
    {
        auto s = detail::get_dynamic_comp_size(v);
        width = detail::comp_get(v, 0, s, fill);
    }

    constexpr size& operator=(size const&) & = default;
    constexpr size& operator=(size const&) && = delete;
    constexpr size& operator=(size&&) & = default;
    constexpr size& operator=(size&&) && = delete;
};

template <class ScalarT>
struct size<2, ScalarT>
{
    static const size zero;
    static const size ones;
    static const size unit;

    ScalarT width = static_cast<ScalarT>(0);
    ScalarT height = static_cast<ScalarT>(0);

    constexpr ScalarT& operator[](int i) { return (&width)[i]; }
    constexpr ScalarT const& operator[](int i) const { return (&width)[i]; }

    constexpr size() = default;
    constexpr size(size const&) = default;
    constexpr size(size&&) = default;
    constexpr explicit size(ScalarT v) : width(v), height(v) {}
    constexpr size(ScalarT width, ScalarT height) : width(width), height(height) {}

    template <class Obj, class = enable_if<is_comp_convertible<Obj, ScalarT>>>
    explicit constexpr size(Obj const& v, ScalarT fill = ScalarT(0))
    {
        auto s = detail::get_dynamic_comp_size(v);
        width = detail::comp_get(v, 0, s, fill);
        height = detail::comp_get(v, 1, s, fill);
    }

    constexpr size& operator=(size const&) & = default;
    constexpr size& operator=(size const&) && = delete;
    constexpr size& operator=(size&&) & = default;
    constexpr size& operator=(size&&) && = delete;
};

template <class ScalarT>
struct size<3, ScalarT>
{
    static const size zero;
    static const size ones;
    static const size unit;

    ScalarT width = static_cast<ScalarT>(0);
    ScalarT height = static_cast<ScalarT>(0);
    ScalarT depth = static_cast<ScalarT>(0);

    constexpr ScalarT& operator[](int i) { return (&width)[i]; }
    constexpr ScalarT const& operator[](int i) const { return (&width)[i]; }

    constexpr size() = default;
    constexpr size(size const&) = default;
    constexpr size(size&&) = default;
    constexpr explicit size(ScalarT v) : width(v), height(v), depth(v) {}
    constexpr size(ScalarT width, ScalarT height, ScalarT depth) : width(width), height(height), depth(depth) {}

    template <class Obj, class = enable_if<is_comp_convertible<Obj, ScalarT>>>
    explicit constexpr size(Obj const& v, ScalarT fill = ScalarT(0))
    {
        auto s = detail::get_dynamic_comp_size(v);
        width = detail::comp_get(v, 0, s, fill);
        height = detail::comp_get(v, 1, s, fill);
        depth = detail::comp_get(v, 2, s, fill);
    }

    constexpr size& operator=(size const&) & = default;
    constexpr size& operator=(size const&) && = delete;
    constexpr size& operator=(size&&) & = default;
    constexpr size& operator=(size&&) && = delete;
};

template <class ScalarT>
struct size<4, ScalarT>
{
    static const size zero;
    static const size ones;
    static const size unit;

    ScalarT width = static_cast<ScalarT>(0);
    ScalarT height = static_cast<ScalarT>(0);
    ScalarT depth = static_cast<ScalarT>(0);
    ScalarT w = static_cast<ScalarT>(0);

    constexpr ScalarT& operator[](int i) { return (&width)[i]; }
    constexpr ScalarT const& operator[](int i) const { return (&width)[i]; }

    constexpr size() = default;
    constexpr size(size const&) = default;
    constexpr size(size&&) = default;
    constexpr explicit size(ScalarT v) : width(v), height(v), depth(v), w(v) {}
    constexpr size(ScalarT width, ScalarT height, ScalarT depth, ScalarT w) : width(width), height(height), depth(depth), w(w) {}

    template <class Obj, class = enable_if<is_comp_convertible<Obj, ScalarT>>>
    explicit constexpr size(Obj const& v, ScalarT fill = ScalarT(0))
    {
        auto s = detail::get_dynamic_comp_size(v);
        width = detail::comp_get(v, 0, s, fill);
        height = detail::comp_get(v, 1, s, fill);
        depth = detail::comp_get(v, 2, s, fill);
        w = detail::comp_get(v, 3, s, fill);
    }

    constexpr size& operator=(size const&) & = default;
    constexpr size& operator=(size const&) && = delete;
    constexpr size& operator=(size&&) & = default;
    constexpr size& operator=(size&&) && = delete;
};

// comparison operators
TG_IMPL_DEFINE_REDUCTION_OP_BINARY(size, size, bool, operator==, &&, ==);
TG_IMPL_DEFINE_REDUCTION_OP_BINARY(size, size, bool, operator!=, ||, !=);

// deduction guides
TG_IMPL_COMP_DEDUCTION_GUIDES(size);

} // namespace tg
