#pragma once

#include "../../types/pos.hh"
#include "../../types/size.hh"
#include "../../types/vec.hh"
#include "../macros.hh"
#include "../scalars/scalar_math.hh"

// Component-wise vectorized versions of scalar math

namespace tg
{
// abs
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(pos, abs);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(vec, abs);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(size, abs);

// min
TG_IMPL_DEFINE_COMPWISE_FUNC_BINARY(pos, min);
TG_IMPL_DEFINE_COMPWISE_FUNC_BINARY(vec, min);
TG_IMPL_DEFINE_COMPWISE_FUNC_BINARY(size, min);

// max
TG_IMPL_DEFINE_COMPWISE_FUNC_BINARY(pos, max);
TG_IMPL_DEFINE_COMPWISE_FUNC_BINARY(vec, max);
TG_IMPL_DEFINE_COMPWISE_FUNC_BINARY(size, max);

// sin
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(pos, sin);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(vec, sin);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(size, sin);

// cos
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(pos, cos);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(vec, cos);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(size, cos);

// sqrt
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(pos, sqrt);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(vec, sqrt);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(size, sqrt);

// cbrt
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(pos, cbrt);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(vec, cbrt);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(size, cbrt);

// pow2
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(pos, pow2);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(vec, pow2);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(size, pow2);

// pow3
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(pos, pow3);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(vec, pow3);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(size, pow3);

// pow4
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(pos, pow4);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(vec, pow4);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(size, pow4);

// pow5
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(pos, pow5);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(vec, pow5);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(size, pow5);

// round
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(pos, round);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(vec, round);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(size, round);

// iround
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(pos, iround);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(vec, iround);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(size, iround);

// floor
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(pos, floor);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(vec, floor);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(size, floor);

// ifloor
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(pos, ifloor);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(vec, ifloor);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(size, ifloor);

// ceil
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(pos, ceil);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(vec, ceil);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(size, ceil);

// iceil
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(pos, iceil);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(vec, iceil);
TG_IMPL_DEFINE_COMPWISE_FUNC_UNARY(size, iceil);

// clamp
TG_IMPL_DEFINE_COMPWISE_FUNC_TERNARY(pos, clamp);
TG_IMPL_DEFINE_COMPWISE_FUNC_TERNARY(vec, clamp);
TG_IMPL_DEFINE_COMPWISE_FUNC_TERNARY(size, clamp);
} // namespace tg
