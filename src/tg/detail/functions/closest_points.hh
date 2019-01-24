#pragma once

#include "../../types/line.hh"
#include "../../types/pos.hh"
#include "../../types/segment.hh"
#include "../utility.hh"
#include "coordinates.hh"
#include "mix.hh"
#include "project.hh"

// closest_points(a, b) returns points {p_a, p_b} such that contains(a, p_a) and contains(b, p_b) and |p_a - p_b| is minimal

namespace tg
{
template <int D, class ScalarT>
constexpr pair<pos<D, ScalarT>, pos<D, ScalarT>> closest_points(pos<D, ScalarT> const& a, pos<D, ScalarT> const& b)
{
    return {a, b};
}

template <int D, class ScalarT>
constexpr pair<pos<D, ScalarT>, pos<D, ScalarT>> closest_points(line<D, ScalarT> const& l, pos<D, ScalarT> const& p)
{
    return {project(p, l), p};
}

template <int D, class ScalarT>
constexpr pair<pos<D, ScalarT>, pos<D, ScalarT>> closest_points(segment<D, ScalarT> const& s, pos<D, ScalarT> const& p)
{
    return {project(p, s), p};
}

template <class ScalarT>
constexpr pair<pos<3, ScalarT>, pos<3, ScalarT>> closest_points(plane const& pl, pos<3, ScalarT> const& p)
{
    return {project(p, pl), p};
}
} // namespace tg