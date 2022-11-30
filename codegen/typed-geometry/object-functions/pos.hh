#pragma once

#include <typed-geometry/object_functions.hh>

template <int D, class ScalarT>
struct object_functions<pos<D, ScalarT>>
{
    static constexpr aabb<D,ScalarT> aabb_of(pos<D, ScalarT> const& v)
    {
        return aabb_of_pos(v);
    }
    
};
