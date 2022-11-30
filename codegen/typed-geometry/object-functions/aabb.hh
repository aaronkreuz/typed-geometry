#pragma once

#include <typed-geometry/object_functions.hh>

template <int D, class ScalarT>
struct object_functions<aabb<D, ScalarT>>
{
    static constexpr aabb<D,ScalarT> aabb_of(aabb<D, ScalarT> const& b)
    {
        return aabb_of_aabb(b);
    }
    
};
