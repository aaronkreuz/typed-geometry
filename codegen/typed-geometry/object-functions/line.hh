#pragma once

#include <typed-geometry/object_functions.hh>

template <int D, class ScalarT>
struct object_functions<line<D, ScalarT>>
{
    static constexpr auto aabb_of(line<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
};
