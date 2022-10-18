#pragma once

#include <typed-geometry/detail/utility.hh>
#include <typed-geometry/types/objects/line.hh>
#include <typed-geometry/types/pos.hh>
#include <typed-geometry/types/quadric.hh>

#include "coordinates.hh"
#include "project.hh"

// closest_points(a, b) returns points {p_a, p_b} such that contains(a, p_a) and contains(b, p_b) and |p_a - p_b| is minimal
// closest_points_parameters(a, b) return parameters {t_a, t_b} such that {a[t_a], b[t_a]} are the closest points

namespace tg
{
// Base case for point/point:
template <int D, class ScalarT>
[[nodiscard]] constexpr pair<pos<D, ScalarT>, pos<D, ScalarT>> closest_points(pos<D, ScalarT> const& a, pos<D, ScalarT> const& b)
{
    return {a, b};
}

// Default implementation for point/object and object/point:
template <int D, class ScalarT, class ObjectT>
[[nodiscard]] constexpr auto closest_points(ObjectT const& o, pos<D, ScalarT> const& p) -> pair<decltype(project(p, o)), pos<D, ScalarT>>
{
    return {project(p, o), p};
}
template <int D, class ScalarT, class ObjectT>
[[nodiscard]] constexpr auto closest_points(pos<D, ScalarT> const& p, ObjectT const& o) -> pair<pos<D, ScalarT>, decltype(project(p, o))>
{
    return {p, project(p, o)};
}


// =========== Object Implementations ===========

template <class ScalarT>
[[nodiscard]] constexpr pair<ScalarT, ScalarT> closest_points_parameters(line<3, ScalarT> const& l0, line<3, ScalarT> const& l1)
{
    auto d0d1 = dot(l0.dir, l1.dir);
    auto b0 = dot(l1.pos - l0.pos, l0.dir);
    auto b1 = dot(l1.pos - l0.pos, l1.dir);
    auto [t0, t1] = inverse(mat<2, 2, ScalarT>::from_cols({ScalarT(1), d0d1}, {-d0d1, ScalarT(-1)})) * vec<2, ScalarT>(b0, b1);
    return {t0, t1};
}

template <class ScalarT>
[[nodiscard]] constexpr pair<pos<3, ScalarT>, pos<3, ScalarT>> closest_points(line<3, ScalarT> const& l0, line<3, ScalarT> const& l1)
{
    auto [t0, t1] = closest_points_parameters(l0, l1);
    return {l0[t0], l1[t1]};
}

template <class ScalarT>
[[nodiscard]] constexpr pair<ScalarT, ScalarT> closest_points_parameters(segment<3, ScalarT> const& s, line<3, ScalarT> const& l)
{
    auto ls = inf_of(s);
    auto len = length(s);

    auto [ts, tl] = closest_points_parameters(ls, l);
    auto tClamped = clamp(ts, ScalarT(0), len);
    return {tClamped / len, coordinates(l, ls[tClamped])};
}

template <int D, class ScalarT>
[[nodiscard]] constexpr pair<pos<3, ScalarT>, pos<3, ScalarT>> closest_points(aabb<D, ScalarT> const& bb0, aabb<D, ScalarT> const& bb1)
{
    auto p1 = project(bb0.min, bb1);
    auto p0 = project(p1, bb0);
    return {p0, p1};
}

template <int D, class ScalarT>
[[nodiscard]] constexpr pair<pos<3, ScalarT>, pos<3, ScalarT>> closest_points(sphere_boundary<D, ScalarT> const& s0, sphere_boundary<D, ScalarT> const& s1)
{
    // sphere inside the other without intersection
    auto d = distance(s0.center, s1.center);
    auto b0 = d + s0.radius < s1.radius;
    auto b1 = d + s1.radius < s0.radius;

    if (b0 || b1)
    {
        dir<D, ScalarT> v;

        if (s0.center == s1.center)
            v = {1.f, 0, 0};


        else if (b0)
            v = normalize(s0.center - s1.center);

        else
            v = normalize(s1.center - s0.center);

        return {s0.center + s0.radius * v, s1.center + s1.radius * v};
    }

    // sphere solids not intersecting
    if (!intersects(solid_of(s0), solid_of(s1)))
    {
        auto p1 = s1.center + normalize(s0.center - s1.center) * s1.radius;
        auto p0 = s0.center + normalize(s1.center - s0.center) * s0.radius;
        return {p0, p1};
    }

    // normal intersection case
    auto n = any_normal(s0.center - s1.center);
    auto s0r2 = s0.radius * s0.radius;
    auto s1r2 = s1.radius * s1.radius;
    auto d2 = distance_sqr(s0.center, s1.center);

    auto t = ScalarT(0.5) + (s0r2 - s1r2) / (ScalarT(2) * d2);

    auto ipos = s0.center + t * (s1.center - s0.center);
    auto irad = sqrt(s0r2 - t * t * d2);

    auto closest_pos = ipos + irad * n;

    return {closest_pos, closest_pos};
}

template <int D, class ScalarT>
[[nodiscard]] constexpr pair<pos<3, ScalarT>, pos<3, ScalarT>> closest_points(sphere<D, ScalarT> const& s0, sphere<D, ScalarT> const& s1)
{
    if (!intersects(s0, s1))
    {
        auto p1 = s1.center + normalize(s0.center - s1.center) * s1.radius;
        auto p0 = s0.center + normalize(s1.center - s0.center) * s0.radius;
        return {p0, p1};
    }

    // intersection case
    auto t = s0.radius / (s0.radius + s1.radius);
    auto cp = tg::mix(s0.center, s1.center, t);

    return {cp, cp};
}

// TODO: Test missing & vice versa
template <class ScalarT>
[[nodiscard]] constexpr pair<pos<3, ScalarT>, pos<3, ScalarT>> closest_points(plane<3, ScalarT> const& plane, segment<3, ScalarT> const& segment)
{
    auto p1 = distance(plane, segment.pos0) < distance(plane, segment.pos1) ? segment.pos0 : segment.pos1;
    auto p0 = project(p1, plane);
    return {p0, p1};
}

// TODO: Test missing & vice versa, Case of intersection?
template <class ScalarT>
[[nodiscard]] constexpr pair<pos<3, ScalarT>, pos<3, ScalarT>> closest_points(plane<3, ScalarT> const& plane, aabb<3, ScalarT> const& bb)
{
    auto vs = vertices_of(bb);
    auto p1 = vs[0];

    for (auto& v : vs)
        p1 = distance(p1, plane) <= distance(v, plane) ? p1 : v;

    auto p0 = project(p1, plane);
    return {p0, p1};
}

// TODO: Test missing & vice versa
template <class ScalarT>
[[nodiscard]] constexpr pair<pos<3, ScalarT>, pos<3, ScalarT>> closest_points(ray<3, ScalarT> const& ray, segment<3, ScalarT> const& segment)
{
    auto lr = tg::line<3, ScalarT>(ray.origin, ray.dir);
    auto ls = inf_of(segment);
    auto len = length(segment);

    auto [tr, ts] = closest_points_parameters(lr, ls);

    auto ts_clamped = clamp(ts, 0, len);
    auto ts_clamped_rel = ts_clamped / len;

    auto proj_r = tg::project(segment[ts_clamped_rel], ray);
    auto proj_s = tg::project(ray.origin, segment);

    tg::pair<pos<3, ScalarT>, pos<3, ScalarT>> pair
        = distance_sqr(proj_r, segment) < distance_sqr(proj_s, ray) ? tg::pair{proj_r, segment[ts_clamped_rel]} : tg::pair{ray.origin, proj_s};
}

// =========== Other Implementations ===========

template <class ScalarT>
[[nodiscard]] constexpr pos<3, ScalarT> closest_point(quadric<3, ScalarT> const& q)
{
    // Returns a point minimizing this quadric
    // (Point is unique if any plane was added with sigma > 0)
    // Solving Ax = r with some common subexpressions precomputed

    auto a = q.A00;
    auto b = q.A01;
    auto c = q.A02;
    auto d = q.A11;
    auto e = q.A12;
    auto f = q.A22;
    auto r0 = q.b0;
    auto r1 = q.b1;
    auto r2 = q.b2;

    auto ad = a * d;
    auto ae = a * e;
    auto af = a * f;
    auto bc = b * c;
    auto be = b * e;
    auto bf = b * f;
    auto df = d * f;
    auto ce = c * e;
    auto cd = c * d;

    auto be_cd = be - cd;
    auto bc_ae = bc - ae;
    auto ce_bf = ce - bf;

    auto denom = 1 / (a * df + 2 * b * ce - ae * e - bf * b - cd * c);
    auto nom0 = r0 * (df - e * e) + r1 * ce_bf + r2 * be_cd;
    auto nom1 = r0 * ce_bf + r1 * (af - c * c) + r2 * bc_ae;
    auto nom2 = r0 * be_cd + r1 * bc_ae + r2 * (ad - b * b);

    return {nom0 * denom, nom1 * denom, nom2 * denom};
}
template <class ScalarT>
[[nodiscard]] constexpr pos<2, ScalarT> closest_point(quadric<2, ScalarT> const& q)
{
    // Returns a point minimizing this quadric
    // (Point is unique if any plane was added with sigma > 0)
    // Solving Ax = r with some common subexpressions precomputed

    auto a = q.A00;
    auto b = q.A01;
    auto c = q.A11;

    auto denom = 1 / (a * c - b * b);
    auto nom0 = q.b0 * c - q.b1 * b;
    auto nom1 = q.b1 * a - q.b0 * b;

    return {nom0 * denom, nom1 * denom};
}

} // namespace tg
