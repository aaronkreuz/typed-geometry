#pragma once

#include <typed-geometry/object_functions.hh>

template <int D, class ScalarT>
struct object_functions<triangle<D, ScalarT>>
{
    static constexpr aabb<D,ScalarT> aabb_of(triangle<D, ScalarT> const& t)
    {
        return aabb_of_triangle(t);
    }
    
};
