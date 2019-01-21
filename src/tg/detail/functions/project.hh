#pragma once

#include "../../types/line.hh"
#include "../../types/segment.hh"
#include "../../types/plane.hh"
#include "../../types/pos.hh"
#include "../../types/vec.hh"
#include "../operators/ops_vec.hh"
#include "coordinates.hh"

namespace tg
{
template <int D, class ScalarT>
constexpr vec<D, ScalarT> project(vec<D, ScalarT> const& a, vec<D, ScalarT> const& b)
{
    return b * (dot(a, b) / dot(b, b));
}

template <int D, class ScalarT>
constexpr pos<D, ScalarT> project(pos<D, ScalarT> const& p, line<D, ScalarT> const& l)
{
    return l.p + project(p - l.p, l.dir);
}

template <int D, class ScalarT>
constexpr pos<D, ScalarT> project(pos<D, ScalarT> const& p, segment<D, ScalarT> const& s)
{
    auto t = coordinates(s, p);
    t = clamp(t, ScalarT(0), ScalarT(1));
    return mix(s.a, s.b, t);
}

template <class ScalarT>
constexpr pos<3, ScalarT> project(pos<3, ScalarT> const& p, plane const& pl)
{
    return p - pl.n * (dot(p - pos<3, ScalarT>::zero, pl.n) - pl.d);
}
} // namespace tg
