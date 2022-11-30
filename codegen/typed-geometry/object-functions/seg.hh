#pragma once

#include <typed-geometry/object_functions.hh>

template <int D, class ScalarT>
struct object_functions<seg<D, ScalarT>>
{
    static constexpr aabb<D,ScalarT> aabb_of(seg<D, ScalarT> const& s)
    {
        return aabb_of_segment(s);
    }
    
};
