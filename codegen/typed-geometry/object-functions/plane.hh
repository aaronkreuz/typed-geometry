#pragma once

#include <typed-geometry/object_functions.hh>

template <int D, class ScalarT>
struct object_functions<plane<D, ScalarT>>
{
    static constexpr auto aabb_of(plane<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
};
