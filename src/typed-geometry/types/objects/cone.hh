#pragma once

#include "../dir.hh"

#include "pyramid.hh"

namespace tg
{
/**
 * right circular cone
 * apex not stored explicitly, can be deduced from height and normal of base
 * (not yet) can construct cone from given apex and center of base (TODO would require extra functions here, do we want that?)
 */
template <int D, class ScalarT>
using cone = pyramid<sphere<D - 1, ScalarT, D>>;

// Common cone types
using cone3 = cone<3, f32>;
using fcone3 = cone<3, f32>;
using dcone3 = cone<3, f64>;
using icone3 = cone<3, i32>;
using ucone3 = cone<3, u32>;
} // namespace tg
