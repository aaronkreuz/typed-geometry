#pragma once

#include <typed-geometry/object_functions.hh>

template <int D, class ScalarT>
struct object_functions<sphere<D, ScalarT>>
{
    static constexpr aabb<D,ScalarT> aabb_of(sphere<D, ScalarT> const& s)
    {
        return aabb_of_sphere(s);
    }
    static constexpr aabb<2,ScalarT> aabb_of(sphere<1, ScalarT> const& s)
    {
        return aabb_of_sphere1(s);
    }
    static constexpr aabb<3,ScalarT> aabb_of(sphere<2, ScalarT> const& s)
    {
        return aabb_of_sphere2(s);
    }
    
};
