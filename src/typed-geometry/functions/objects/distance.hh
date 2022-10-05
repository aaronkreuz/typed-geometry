#pragma once

#include <typed-geometry/detail/operators/ops_pos.hh>
#include <typed-geometry/detail/operators/ops_vec.hh>
#include <typed-geometry/detail/special_values.hh>
#include <typed-geometry/detail/tg_traits.hh>
#include <typed-geometry/functions/basic/scalar_math.hh>
#include <typed-geometry/functions/objects/edges.hh>
#include <typed-geometry/functions/objects/vertices.hh>
#include <typed-geometry/functions/vector/distance.hh>
#include <typed-geometry/types/objects/aabb.hh>
#include <typed-geometry/types/objects/box.hh>
#include <typed-geometry/types/objects/halfspace.hh>
#include <typed-geometry/types/objects/line.hh>
#include <typed-geometry/types/objects/plane.hh>
#include <typed-geometry/types/objects/segment.hh>
#include <typed-geometry/types/pos.hh>
#include <typed-geometry/types/quadric.hh>
#include <typed-geometry/types/vec.hh>

#include "closest_points.hh"
#include "intersection.hh"

namespace tg
{
// Default implementation of distance as abs(signed_distance)
// TODO: FIXME via priority_tag<>
// template <class A, class B>
// [[nodiscard]] constexpr auto distance(A const& a, B const& b) -> decltype(abs(signed_distance(a, b)))
// {
//     return abs(signed_distance(a, b));
// }

// Default implementation of distance_sqr as distance_sqr(ca, cb) for closest points ca and cb
template <class A, class B>
[[nodiscard]] constexpr auto distance_sqr(A const& a, B const& b) -> decltype(length_sqr(closest_points(a, b).first - closest_points(a, b).second))
{
    auto cp = closest_points(a, b);
    return length_sqr(cp.first - cp.second);
}

// Convenience for distance to (0,0,0)
template <class Obj>
[[nodiscard]] constexpr auto distance_to_origin(Obj const& o) -> decltype(distance(o, pos_type_for<Obj>::zero))
{
    return distance(o, pos_type_for<Obj>::zero);
}
template <class Obj>
[[nodiscard]] constexpr auto distance_sqr_to_origin(Obj const& o) -> decltype(distance(o, pos_type_for<Obj>::zero))
{
    return distance_sqr(o, pos_type_for<Obj>::zero);
}


// =========== Object Implementations ===========

// signed distance is positive if p lies above pl, 0 if it lies on the plane and negative if below pl
template <int D, class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> signed_distance(pos<D, ScalarT> const& p, plane<D, ScalarT> const& pl)
{
    return dot(p, pl.normal) - pl.dis;
}

template <int D, class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance(pos<D, ScalarT> const& p, plane<D, ScalarT> const& pl)
{
    return abs(signed_distance(p, pl));
}

template <int D, class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> signed_distance(pos<D, ScalarT> const& p, halfspace<D, ScalarT> const& h)
{
    return dot(p, h.normal) - h.dis;
}

template <int D, class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance(pos<D, ScalarT> const& p, halfspace<D, ScalarT> const& h)
{
    return max(ScalarT(0), signed_distance(p, h));
}

template <int D, class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> signed_distance(pos<D, ScalarT> const& p, sphere_boundary<D, ScalarT> const& s)
{
    return distance(p, s.center) - s.radius;
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance(line<3, ScalarT> const& l0, line<3, ScalarT> const& l1)
{
    auto n = cross(l0.dir, l1.dir);
    return abs(dot(l0.pos - l1.pos, n) / length(n));
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(segment<2, ScalarT> const& s0, segment<2, ScalarT> const& s1)
{
    auto l0 = inf_of(s0);
    auto l1 = inf_of(s1);
    auto len0 = length(s0);
    auto len1 = length(s1);

    auto [t0, t1] = intersection_parameters(l0, l1);

    if (ScalarT(0) <= t0 && t0 <= len0 && //
        ScalarT(0) <= t1 && t1 <= len1)
        return ScalarT(0); // intersects

    auto p0 = t0 * ScalarT(2) < len0 ? s0.pos0 : s0.pos1;
    auto p1 = t1 * ScalarT(2) < len1 ? s1.pos0 : s1.pos1;

    return min(distance_sqr(p0, s1), distance_sqr(p1, s0));
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(segment<3, ScalarT> const& s0, segment<3, ScalarT> const& s1)
{
    auto l0 = inf_of(s0);
    auto l1 = inf_of(s1);
    auto len0 = length(s0);
    auto len1 = length(s1);

    auto [t0, t1] = closest_points_parameters(l0, l1);

    if (ScalarT(0) <= t0 && t0 <= len0 && //
        ScalarT(0) <= t1 && t1 <= len1)
        return distance_sqr(l0[t0], l1[t1]); // closest points is inside segments

    auto p0 = t0 * ScalarT(2) < len0 ? s0.pos0 : s0.pos1;
    auto p1 = t1 * ScalarT(2) < len1 ? s1.pos0 : s1.pos1;

    return min(distance_sqr(p0, s1), distance_sqr(p1, s0));
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(segment<2, ScalarT> const& s, line<2, ScalarT> const& l)
{
    auto ls = inf_of(s);
    auto len = length(s);

    auto [ts, tl] = intersection_parameters(ls, l);
    if (ScalarT(0) <= ts && ts <= len)
        return ScalarT(0); // intersects

    auto p = ts * ScalarT(2) < len ? s.pos0 : s.pos1;
    return distance_sqr(p, l);
}
template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(segment<3, ScalarT> const& s, line<3, ScalarT> const& l)
{
    auto ls = inf_of(s);
    auto len = length(s);

    auto [ts, tl] = closest_points_parameters(ls, l);
    auto tClamped = clamp(ts, ScalarT(0), len);
    return distance_sqr(ls[tClamped], l);
}
template <int D, class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(line<D, ScalarT> const& l, segment<D, ScalarT> const& s)
{
    return distance_sqr(s, l);
}

// TODO: use GJK or something?
template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance(aabb<3, ScalarT> const& bb, triangle<3, ScalarT> const& t)
{
    if (intersects(bb, t))
        return fractional_result<ScalarT>(0);

    auto d = tg::max<ScalarT>();

    // tri vertices to bb
    for (auto p : vertices_of(t))
        d = min(d, distance(bb, p));

    // bb vertices to tri
    for (auto p : vertices_of(bb))
        d = min(d, distance(t, p));

    // edges to edges
    for (auto e0 : edges_of(t))
        for (auto e1 : edges_of(bb))
            d = min(d, distance(e0, e1));

    return d;
}
template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance(triangle<3, ScalarT> const& t, aabb<3, ScalarT> const& bb)
{
    return distance(bb, t);
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance(segment<3, ScalarT> const& s, triangle<3, ScalarT> const& t)
{
    if (intersects(s, t))
        return fractional_result<ScalarT>(0);

    auto d = tg::max<ScalarT>();

    // tri vertices to seg
    for (auto v : vertices_of(t))
        d = min(d, distance(v, s));

    // tri edges to seg
    for (auto e : edges_of(t))
        d = min(d, distance(e, s));

    return d;
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance(triangle<3, ScalarT> const& t, segment<3, ScalarT> const& s)
{
    return distance(s, t);
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance(line<3, ScalarT> const& l, triangle<3, ScalarT> const& t)
{
    if (intersects(l, t))
        return fractional_result<ScalarT>(0);

    auto d = tg::max<ScalarT>();

    // tri vertices to line
    for (auto v : vertices_of(t))
        d = min(d, distance(v, l));

    return d;
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance(triangle<3, ScalarT> const& t, line<3, ScalarT> const& l)
{
    return distance(l, t);
}

template <int D, class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance(segment<D, ScalarT> const& seg, sphere<D, ScalarT> const& s)
{
    auto d = distance(seg, s.center);

    if (d <= s.radius)
        return fractional_result<ScalarT>(0);

    return (d - s.radius);
}

template <int D, class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance(sphere<D, ScalarT> const& s, segment<D, ScalarT> const& seg)
{
    return distance(seg, s);
}


template <int D, class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance(line<D, ScalarT> const& l, sphere<D, ScalarT> const& s)
{
    auto d = distance(l, s.center);

    if (d <= s.radius)
        return fractional_result<ScalarT>(0);

    return (d - s.radius);
}

template <int D, class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance(sphere<D, ScalarT> const& s, line<D, ScalarT> const& l)
{
    return distance(l, s);
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance(ray<3, ScalarT> const& r0, ray<3, ScalarT> const& r1)
{
    auto n = cross(r0.dir, r1.dir);
    return abs(dot(r0.pos - r1.pos, n) / length(n));
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance(plane<3, ScalarT> const& p, segment<3, ScalarT> const& s)
{
    if (intersects(s, p))
        return fractional_result<ScalarT>(0);

    return min(distance(s.pos0, p), distance(s.pos1, p));
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance(segment<3, ScalarT> const& s, plane<3, ScalarT> const& p)
{
    return distance(p, s);
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance(plane<3, ScalarT> const& p, box<3, ScalarT> const& b)
{
    auto d = tg::max<ScalarT>();

    // box vertices
    for (auto v : vertices_of(b))
        d = min(d, distance(v, p));

    // box edges
    for (auto e : edges_of(b))
        d = min(d, distance(e, p));

    return d;
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance(box<3, ScalarT> const& b, plane<3, ScalarT> const& p)
{
    return distance(p, b);
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance(triangle<3, ScalarT> const& t1, triangle<3, ScalarT> const& t2)
{
    if (intersects(t1, t2))
        return fractional_result<ScalarT>(0);

    auto d = tg::max<ScalarT>();

    for (auto const& v : vertices_of(t1))
        d = min(d, distance(v, t2));

    for (auto const& v : vertices_of(t2))
        d = min(d, distance(v, t1));

    for (auto const& e1 : edges_of(t1))
        for (auto const& e2 : edges_of(t2))
            d = min(d, distance(e1, e2));

    // TODO: all cases?

    return d;
}

// TODO: TEST MISSING
// template <class ScalarT>
// [[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(line<3, ScalarT> const& l, segment<3, ScalarT> s)
// {
//     if (intersects(l, s))
//         return ScalarT(0);
//
//     // line extension of segment
//     auto l0 = inf_of(s);
//     auto len_s = length(s);
//
//     auto [t0, t1] = closest_points_parameters(l0, l);
//
//     if (t0 >= 0 && t0 <= len_s)
//         return distance_sqr(l0[t0], l[t1]);
//
//     auto p = distance_sqr(s.pos0, l0[t0]) <= distance_sqr(s.pos1, l0[t0]) ? s.pos0 : s.pos1;
//
//     return distance_sqr(p, l);
// }

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(line<3, ScalarT> const& l, segment<3, ScalarT> s)
{
    return distance_sqr(s, l);
}

// error
template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(ray<3, ScalarT> const& r, segment<3, ScalarT> s)
{
    return 0; // distance_sqr(l0, s);
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(segment<3, ScalarT> s, ray<3, ScalarT> const& r)
{
    return distance_sqr(r, s);
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance(ray<3, ScalarT> const& r, sphere<3, ScalarT> const& s)
{
    auto d = distance(r, s.center);
    d = max(0, d - s.radius);

    return d;
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance(sphere<3, ScalarT> const& s, ray<3, ScalarT> const& r)
{
    return distance(r, s);
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(segment<3, ScalarT> const& s, aabb<3, ScalarT> const& bb)
{
    if (intersects(s, bb))
        return ScalarT(0);

    auto d = tg::max<ScalarT>();

    // bb with segment end-points
    d = min(d, distance_sqr(s.pos0, bb));
    d = min(d, distance_sqr(s.pos1, bb));

    // edges of bb with segment
    for (auto& e : edges_of(bb))
        d = min(d, distance_sqr(e, s));

    return d;
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(aabb<3, ScalarT> const& bb, segment<3, ScalarT> const& s)
{
    return distance_sqr(s, bb);
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(line<3, ScalarT> const& l, aabb<3, ScalarT> const& bb)
{
    if (intersects(l, bb))
        return ScalarT(0);

    auto d = tg::max<ScalarT>();

    // edges of bb with segment
    for (auto& e : edges_of(bb))
        d = min(d, distance_sqr(e, l));

    return d;
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(aabb<3, ScalarT> const& bb, line<3, ScalarT> const& l)
{
    return distance_sqr(l, bb);
}

// error
template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(ray<3, ScalarT> const& r, aabb<3, ScalarT> const& bb)
{
    auto l0 = tg::line3(r.origin, r.dir);

    return distance_sqr(l0, bb);
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(aabb<3, ScalarT> const& bb, ray<3, ScalarT> const& r)
{
    return distance_sqr(r, bb);
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(segment<3, ScalarT> const& s, disk<3, ScalarT> const& d)
{
    if (intersects(s, d))
        return ScalarT(0);

    auto plane = tg::plane3(d.normal, d.center);
    auto insec = intersection(s, plane);

    if (!insec.has_value())
    {
        // parallel to disk
        if (dot(d.normal, normalize(s.pos1 - s.pos0)) == 0)
        {
            auto p0 = closest_points(d.center, s);
            return distance_sqr(p0.second, d);
        }

        // one of segment end-points closest to disk
        return min(distance_sqr(s.pos0, d), distance_sqr(s.pos1, d));
    }

    // point on edge of disk closest to segment
    auto edge_v = d.center + d.radius * normalize(insec.value() - d.center);

    return distance_sqr(s, edge_v);
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(disk<3, ScalarT> const& sp, segment<3, ScalarT> const& s)
{
    return distance_sqr(s, sp);
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(line<3, ScalarT> const& l, disk<3, ScalarT> const& d)
{
    if (intersects(l, d))
        return ScalarT(0);

    auto plane = plane_of(d);
    auto insec = intersection(l, plane);

    // parallel to disk
    if (!insec.any())
    {
        auto p0 = closest_points(d.center, l);
        return distance_sqr(p0.second, d);
    }

    // point on edge of disk closest to line
    auto edge_v = d.center + d.radius * tg::normalize(insec[0] - d.center);

    return distance_sqr(l, edge_v);
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(sphere<2, ScalarT, 3> const& s, line<3, ScalarT> const& l)
{
    return distance_sqr(l, s);
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(ray<3, ScalarT> const& r, disk<3, ScalarT> const& s)
{
    auto l0 = tg::line3(r.origin, r.dir);

    return distance_sqr(l0, s);
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(sphere<2, ScalarT, 3> const& s, ray<3, ScalarT> const& r)
{
    return distance_sqr(r, s);
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(segment<3, ScalarT> const& s, cylinder<3, ScalarT> const& c)
{
    // if (intersects(s, c))
    //     return ScalarT(0);

    auto d = tg::max<ScalarT>();

    auto disk0 = tg::disk<3, ScalarT>(c.axis.pos0, c.radius, normalize(c.axis.pos0 - c.axis.pos1));
    auto disk1 = tg::disk<3, ScalarT>(c.axis.pos1, c.radius, normalize(c.axis.pos1 - c.axis.pos0));

    // cylinder disks - segment
    d = min(d, distance_sqr(disk0, s));
    d = min(d, distance_sqr(disk1, s));

    // cylinder - segment end-points
    d = min(d, distance_sqr(s.pos0, c));
    d = min(d, distance_sqr(s.pos1, c));

    return d;
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(cylinder<3, ScalarT> const& c, segment<3, ScalarT> const& s)
{
    return distance_sqr(s, c);
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(line<3, ScalarT> const& l, cylinder<3, ScalarT> const& c)
{
    if (intersects(l, c))
        return ScalarT(0);

    // planes of cylinder disks
    auto plane0 = plane<3, ScalarT>(normalize(c.axis.pos0 - c.axis.pos1), c.axis.pos0);
    auto plane1 = plane<3, ScalarT>(normalize(c.axis.pos1 - c.axis.pos0), c.axis.pos1);

    auto i0 = intersection(l, plane0);
    auto i1 = intersection(l, plane1);

    // line parallel to some cylinder disk
    if (!i0.any() && !i1.any())
        return min(distance_sqr(l, pos<3, ScalarT>(plane0.dis * plane0.normal)), distance_sqr(l, pos<3, ScalarT>(plane1.dis * plane1.normal)));

    // line in plane of a cylinder disk
    if (!i0.any() || !i1.any())
        return ScalarT(0);

    auto seg = segment<3, ScalarT>(i0[0], i1[0]);

    return distance_sqr(seg, c);
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(cylinder<3, ScalarT> const& c, line<3, ScalarT> const& l)
{
    return distance_sqr(l, c);
}

// erroneous
template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(ray<3, ScalarT> const& r, cylinder<3, ScalarT> const& c)
{
    auto l0 = tg::line3(r.origin, r.dir);

    return distance_sqr(l0, c);
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(cylinder<3, ScalarT> const& c, ray<3, ScalarT> const& r)
{
    return distance_sqr(r, c);
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(sphere<3, ScalarT> const& s0, sphere<3, ScalarT> const& s1)
{
    auto s0s1 = s1.center - s0.center;
    return dot(s0s1, s0s1);
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(line<3, ScalarT> const& l, box<3, ScalarT> const& b)
{
    if (intersects(l, b))
        return ScalarT(0);

    auto d = tg::max<ScalarT>();

    // check vertices
    for (auto& v : vertices_of(b))
        d = min(d, distance_sqr(v, l));

    // check edges
    for (auto& e : edges_of(b))
        d = min(d, distance_sqr(e, l));

    return d;
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(box<3, ScalarT> const& b, line<3, ScalarT> const& l)
{
    return distance_sqr(l, b);
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(ray<3, ScalarT> const& r, box<3, ScalarT> const& b)
{
    if (intersects(r, b))
        return ScalarT(0);

    auto d = tg::max<ScalarT>();

    // check vertices
    for (auto& v : vertices_of(b))
        d = min(d, distance_sqr(v, r));

    // check edges
    for (auto& e : edges_of(b))
        d = min(d, distance_sqr(e, r));

    return d;
}

template <class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance_sqr(box<3, ScalarT> const& b, ray<3, ScalarT> const& r)
{
    return distance_sqr(r, b);
}

// =========== Other Implementations ===========

template <class ScalarT, class = enable_if<is_scalar<ScalarT>>>
[[nodiscard]] constexpr ScalarT distance_sqr(ScalarT a, ScalarT b)
{
    auto const d = a - b;
    return d * d;
}

template <class ScalarT>
[[nodiscard]] constexpr ScalarT distance_sqr(pos<2, ScalarT> const& p, quadric<2, ScalarT> const& q)
{
    return q(p);
}

template <class ScalarT>
[[nodiscard]] constexpr ScalarT distance_sqr(pos<3, ScalarT> const& p, quadric<3, ScalarT> const& q)
{
    return q(p);
}

template <int D, class ScalarT>
[[nodiscard]] constexpr ScalarT distance_sqr(quadric<D, ScalarT> const& q, pos<D, ScalarT> const& p)
{
    return distance_sqr(p, q);
}

} // namespace tg
