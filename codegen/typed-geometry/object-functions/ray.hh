#pragma once

#include <typed-geometry/object_functions.hh>

template <int D, class ScalarT>
struct object_functions<ray<D, ScalarT>>
{
    static constexpr auto aabb_of(ray<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
};
