#pragma once

#include <clean-core/always_false.hh>

template <class T>
struct object_functions
{
    static_assert(cc::always_false<T>
    , "include missing");
};