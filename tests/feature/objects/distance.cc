#include <nexus/fuzz_test.hh>

#include <iostream>

#include <typed-geometry/tg.hh>

// TEMP
#include <iostream>

FUZZ_TEST("Distance")(tg::rng& rng)
{
    auto rBox1 = tg::aabb1(tg::pos1(-1.0f), tg::pos1(1.0f));
    auto rBox2 = tg::aabb2(tg::pos2(-1.0f, -1.0f), tg::pos2(1.0f, 1.0f));
    auto rBox3 = tg::aabb3(tg::pos3(-1.0f, -1.0f, -1.0f), tg::pos3(1.0f, 1.0f, 1.0f));

    // distance_sqr compared with distance
    {
        // 3D
        auto a = uniform(rng, rBox3);
        auto b = uniform(rng, rBox3);

        auto d2 = distance_sqr(a, b);
        auto d = distance(a, b);
        CHECK(d * d == nx::approx(d2));
        CHECK(d == nx::approx(tg::sqrt(d2)));
        // symmetry
        CHECK(distance(b, a) == d);
        CHECK(distance_sqr(b, a) == d2);
    }
    {
        // 2D
        auto a = uniform(rng, rBox2);
        auto b = uniform(rng, rBox2);

        auto d2 = distance_sqr(a, b);
        auto d = distance(a, b);
        CHECK(d * d == nx::approx(d2));
        CHECK(d == nx::approx(tg::sqrt(d2)));
        // symmetry
        CHECK(distance(b, a) == d);
        CHECK(distance_sqr(b, a) == d2);
    }
    {
        // 1D
        auto a = uniform(rng, rBox1);
        auto b = uniform(rng, rBox1);

        auto d2 = distance_sqr(a, b);
        auto d = distance(a, b);
        CHECK(d * d == nx::approx(d2));
        CHECK(d == nx::approx(tg::sqrt(d2)));
        // symmetry
        CHECK(distance(b, a) == d);
        CHECK(distance_sqr(b, a) == d2);
    }

    // move away from point by random value
    {
        // 3D
        auto a = uniform(rng, rBox3);
        auto dir = normalize(tg::vec3(uniform(rng, rBox3)));
        auto rd = uniform(rng, rBox1).x;

        auto b = a + dir * rd;
        CHECK(distance(a, b) == nx::approx(tg::abs(rd)));

        auto d2 = distance_sqr(a, b);
        auto d = distance(a, b);
        CHECK(d * d == nx::approx(d2));
        CHECK(d == nx::approx(tg::sqrt(d2)));
        // symmetry
        CHECK(distance(b, a) == d);
        CHECK(distance_sqr(b, a) == d2);
    }
    {
        // 2D
        auto a = uniform(rng, rBox2);
        auto dir = normalize(tg::vec2(uniform(rng, rBox2)));
        auto rd = uniform(rng, rBox1).x;

        auto b = a + dir * rd;
        CHECK(distance(a, b) == nx::approx(tg::abs(rd)));

        auto d2 = distance_sqr(a, b);
        auto d = distance(a, b);
        CHECK(d * d == nx::approx(d2));
        CHECK(d == nx::approx(tg::sqrt(d2)));
        // symmetry
        CHECK(distance(b, a) == d);
        CHECK(distance_sqr(b, a) == d2);
    }
    {
        // 1D
        auto a = uniform(rng, rBox1);
        auto dir = normalize(tg::vec1(uniform(rng, rBox1)));
        auto rd = uniform(rng, rBox1).x;

        auto b = a + dir * rd;
        CHECK(distance(a, b) == nx::approx(tg::abs(rd)));

        auto d2 = distance_sqr(a, b);
        auto d = distance(a, b);
        CHECK(d * d == nx::approx(d2));
        CHECK(d == nx::approx(tg::sqrt(d2)));
        // symmetry
        CHECK(distance(b, a) == d);
        CHECK(distance_sqr(b, a) == d2);
    }

    // distance to origin
    {
        auto p = uniform(rng, rBox1);
        auto d = distance_to_origin(p);
        CHECK(d == nx::approx(tg::length(tg::vec1(p))));
    }
    {
        auto p = uniform(rng, rBox2);
        auto d = distance_to_origin(p);
        CHECK(d == nx::approx(tg::length(tg::vec2(p))));
    }
    {
        auto p = uniform(rng, rBox3);
        auto d = distance_to_origin(p);
        CHECK(d == nx::approx(tg::length(tg::vec3(p))));
    }


    // plane and pos
    {
        // random plane
        auto pl = tg::plane(normalize(tg::vec3(uniform(rng, rBox3))), uniform(rng, rBox1).x);
        // random point
        auto pt = uniform(rng, rBox3);

        // symmetry
        auto d2 = distance_sqr(pt, pl);
        auto d = distance(pt, pl);
        CHECK(d == nx::approx(distance(pl, pt)));
        CHECK(d2 == nx::approx(distance_sqr(pl, pt)));

        CHECK(d * d == nx::approx(d2));
        CHECK(d == nx::approx(tg::sqrt(d2)));

        // move point on plane
        auto o = tg::pos3(pl.dis * pl.normal);
        auto t = pl.normal;
        while (dot(t, pl.normal) != 0.0f)
        {
            auto r = normalize(tg::vec3(uniform(rng, rBox3)));
            t = normalize(cross(pl.normal, r));
        }
        pt = o + t; // origin + tangent
        CHECK(distance(pt, pl) == nx::approx(0.0f).abs(0.001f));

        auto l = uniform(rng, rBox1).x;
        pt += pl.normal * l; // move along normal
        CHECK(distance(pt, pl) == nx::approx(tg::abs(l)));
    }


    // inf_cone and pos
    {
        auto icone = tg::inf_cone_boundary<3, float>(tg::pos3(uniform(rng, rBox3)), normalize(tg::vec3(uniform(rng, rBox3))),
                                                     uniform(rng, tg::angle::from_degree(1.f), tg::angle::from_degree(179.f)));
        auto l = uniform(rng, 0.1f, 2.f);
        auto pt = icone.apex - l * icone.opening_dir;
        auto d2 = distance_sqr(pt, icone);
        auto d = distance(pt, icone);
        CHECK(d == nx::approx(l));
        CHECK(d * d == nx::approx(d2));
        CHECK(d == nx::approx(tg::sqrt(d2)));
        l = uniform(rng, 0.f, 10.f);
        pt = icone.apex + l * icone.opening_dir;
        d = distance(pt, icone);
        d2 = distance_sqr(pt, icone);
        CHECK(d > 0);
        CHECK(d2 > 0);
        l = uniform(rng, 0.f, 10.f);
        auto r = tg::tan(icone.opening_angle / 2) * l;
        auto rand_dir = normalize(tg::vec3(uniform(rng, rBox3)));
        auto rand_n = normalize(cross(rand_dir, icone.opening_dir));
        auto ortho_dir = normalize(cross(rand_n, icone.opening_dir));
        pt = icone.apex + l * icone.opening_dir + r * ortho_dir;
        d = distance(pt, icone);
        d2 = distance_sqr(pt, icone);
        CHECK(d == nx::approx(0.f).abs(0.1));
        CHECK(d * d == nx::approx(d2));
        CHECK(d == nx::approx(tg::sqrt(d2)));
        d = distance(icone.apex, icone);
        CHECK(d == nx::approx(0.f).abs(0.1));
        pt = {2, -4, 0};
        icone = tg::inf_cone_boundary<3, float>({0, 0, 0}, {0, 0, 1}, tg::angle::from_degree(90));
        d2 = distance_sqr(pt, icone);
        CHECK(d2 == nx::approx(10.f));
        l = uniform(rng, 0.f, 10.f);
        pt = icone.apex + l * icone.opening_dir;
        d = distance(pt, icone);
        CHECK(d == nx::approx(l / tg::sqrt(2.f)));
    }


    // sphere and pos
    {
        auto sp = tg::sphere_boundary<3, tg::f32>(tg::pos3(uniform(rng, rBox3)), uniform(rng, 0.f, 10.f));
        auto l = uniform(rng, 0.f, 10.f);
        auto rand_dir = normalize(tg::vec3(uniform(rng, rBox3)));
        auto pt = sp.center + l * rand_dir;
        auto d2 = distance_sqr(pt, sp);
        auto d = distance(pt, sp);
        CHECK(d == nx::approx(tg::abs(l - sp.radius)));
        CHECK(d * d == nx::approx(d2));
        CHECK(d == nx::approx(tg::sqrt(d2)));
        sp = tg::sphere_boundary<3, tg::f32>(tg::pos3(uniform(rng, rBox3)), uniform(rng, 0.f, 10.f));
        pt = sp.center + sp.radius * rand_dir;
        d = distance(pt, sp);
        CHECK(d == nx::approx(0.f).abs(0.1));
        auto sp2 = tg::sphere_boundary<2, tg::f32>(tg::pos2(uniform(rng, rBox2)), uniform(rng, 0.f, 10.f));
        l = uniform(rng, 0.f, 10.f);
        auto rand_dir2 = normalize(tg::vec2(uniform(rng, rBox2)));
        auto pt2 = sp2.center + l * rand_dir2;
        d2 = distance_sqr(pt2, sp2);
        d = distance(pt2, sp2);
        CHECK(d == nx::approx(tg::abs(l - sp2.radius)));
        CHECK(d * d == nx::approx(d2));
        CHECK(d == nx::approx(tg::sqrt(d2)));
    }


    // inf_cylinder and pos
    {
        auto itube = tg::inf_cylinder_boundary<3, tg::f32>({tg::pos3(uniform(rng, rBox3)), normalize(tg::vec3(uniform(rng, rBox3)))}, uniform(rng, 0.f, 10.f));
        auto rand_dir = normalize(tg::vec3(uniform(rng, rBox3)));
        auto rand_n = normalize(cross(rand_dir, itube.axis.dir));
        auto ortho_dir = tg::normalize(tg::cross(rand_n, itube.axis.dir));
        auto l = uniform(rng, -10.f, 10.f);
        auto r = uniform(rng, 0.f, 10.f);
        auto pt = itube.axis[l] + r * ortho_dir;
        auto d2 = distance_sqr(pt, itube);
        auto d = distance(pt, itube);
        CHECK(d == nx::approx(tg::abs(r - itube.radius)));
        CHECK(d * d == nx::approx(d2));
        CHECK(d == nx::approx(tg::sqrt(d2)));

        auto itube2 = tg::inf_cylinder_boundary<2, tg::f32>({tg::pos2(uniform(rng, rBox2)), normalize(tg::vec2(uniform(rng, rBox2)))}, uniform(rng, 0.f, 10.f));
        tg::vec2 ortho_dir2 = {-itube2.axis.dir[1], itube2.axis.dir[0]};
        l = uniform(rng, -10.f, 10.f);
        r = uniform(rng, 0.f, 10.f);
        auto pt2 = itube2.axis[l] + r * ortho_dir2;
        d2 = distance_sqr(pt2, itube2);
        d = distance(pt2, itube2);
        CHECK(d == nx::approx(tg::abs(r - itube2.radius)));
        CHECK(d * d == nx::approx(d2));
        CHECK(d == nx::approx(tg::sqrt(d2)));
    }

    // cylinder and pos
    {
        auto c = tg::cylinder_boundary<3, float>({-1, -2, -3}, {5, -2, -3}, 2);
        CHECK(distance(tg::pos3(-1, -2, -3), c) == nx::approx(0.f).abs(0.001f));
        CHECK(distance(tg::pos3(5, -2, -3), c) == nx::approx(0.f).abs(0.001f));
        CHECK(distance(tg::pos3(0, -2, -3), c) == nx::approx(1.f));
        CHECK(distance(tg::pos3(2, -2, -3), c) == nx::approx(2.f));
        CHECK(distance(tg::pos3(-1, -3, -3), c) == nx::approx(0.f).abs(0.001f));
    }

    // box and pos
    {
        auto b = tg::box3::unit_centered;

        CHECK(distance(tg::pos3(1, 0, 0), b) == nx::approx(0.5f));
        CHECK(distance(tg::pos3(1, 1, 0), b) == nx::approx(tg::sqrt(0.5f)));
    }
}

namespace
{
// NOTE: f is (float&, float&) -> float
//       and might clamp its inputs
template <class F>
float minimize_f1(tg::rng& rng, float step_size, F&& f, int steps = 1500)
{
    auto d_min = tg::max<float>();
    auto t0 = uniform(rng, -10.f, 10.f);
    auto t1 = uniform(rng, -10.f, 10.f);

    for (auto i = 0; i < steps; ++i)
    {
        auto tt0 = t0 + uniform(rng, -step_size, step_size);
        auto tt1 = t1 + uniform(rng, -step_size, step_size);

        auto dd = f(tt0, tt1);
        if (dd < d_min)
        {
            t0 = tt0;
            t1 = tt1;
            d_min = dd;
        }
    }

    return d_min;
}
}

FUZZ_TEST("Distance - LineLine3")(tg::rng& rng)
{
    auto bb = tg::aabb3(-10, 10);

    auto l0 = tg::line3::from_points(uniform(rng, bb), uniform(rng, bb));
    auto l1 = tg::line3::from_points(uniform(rng, bb), uniform(rng, bb));

    auto d = distance(l0, l1);

    auto dd = minimize_f1(rng, 2.0f, [&](float a, float b) { return distance(l0[a], l1[b]); });

    CHECK(d == nx::approx(dd).abs(0.7f));
}

FUZZ_TEST("Distance - PosSeg2")(tg::rng& rng)
{
    auto bb = tg::aabb2(-10, 10);

    auto s = tg::segment2(uniform(rng, bb), uniform(rng, bb));
    auto p = uniform(rng, bb);

    auto d = distance(s, p);

    auto dd = minimize_f1(rng, 0.5f,
                          [&](float& a, float)
                          {
                              a = tg::saturate(a);
                              return distance(s[a], p);
                          });

    CHECK(d == nx::approx(dd).abs(0.7f));
}

FUZZ_TEST("Distance - SegSeg2")(tg::rng& rng)
{
    auto bb = tg::aabb2(-10, 10);

    auto s0 = tg::segment2(uniform(rng, bb), uniform(rng, bb));
    auto s1 = tg::segment2(uniform(rng, bb), uniform(rng, bb));

    auto d = distance(s0, s1);

    auto dd = minimize_f1(rng, 0.5f,
                          [&](float& a, float& b)
                          {
                              a = tg::saturate(a);
                              b = tg::saturate(b);
                              return distance(s0[a], s1[b]);
                          });

    if (d > 0)
        CHECK(!intersects(s0, s1));

    CHECK(d == nx::approx(dd).abs(0.7f));
}

FUZZ_TEST("Distance - SegSeg3")(tg::rng& rng)
{
    auto bb = tg::aabb3(-10, 10);

    auto s0 = tg::segment3(uniform(rng, bb), uniform(rng, bb));
    auto s1 = tg::segment3(uniform(rng, bb), uniform(rng, bb));

    auto d = distance(s0, s1);

    auto dd = minimize_f1(rng, 0.5f,
                          [&](float& a, float& b)
                          {
                              a = tg::saturate(a);
                              b = tg::saturate(b);
                              return distance(s0[a], s1[b]);
                          });

    CHECK(d == nx::approx(dd).abs(0.7f));
}

FUZZ_TEST("Distance - PosTri3")(tg::rng& rng)
{
    auto bb = tg::aabb3(-10, 10);

    auto t = tg::triangle3(uniform(rng, bb), uniform(rng, bb), uniform(rng, bb));
    auto p = uniform(rng, bb);

    auto d = distance(t, p);

    auto r = uniform(rng, 0.f, 4.f);

    auto pp = p + tg::uniform<tg::dir3>(rng) * r;

    CHECK(distance(pp, t) >= d - r);
}

FUZZ_TEST("Distance - TriangleAABB3")(tg::rng& rng)
{
    auto bounds = tg::aabb3(-10, 10);
    auto bb = tg::aabb_of(uniform(rng, bounds), uniform(rng, bounds));
    auto tri = tg::triangle3(uniform(rng, bounds), uniform(rng, bounds), uniform(rng, bounds));

    auto d = distance(bb, tri);

    if (intersects(bb, tri))
        CHECK(d == 0);

    for (auto i = 0; i < 100; ++i)
    {
        auto p = uniform(rng, bb);
        CHECK(d <= distance(p, tri));

        auto tp = uniform(rng, tri);
        CHECK(d <= distance(tp, bb));
    }

    if (d > 0)
    {
        auto p = uniform(rng, tri) + tg::uniform<tg::dir3>(rng) * uniform(rng, 0.f, d);
        CHECK(!contains(bb, p));
    }
}

FUZZ_TEST("Distance - AABBAABB3")(tg::rng& rng)
{
    auto bounds = tg::aabb3(-10, 10);
    auto bbA = tg::aabb_of(uniform(rng, bounds), uniform(rng, bounds));
    auto bbB = tg::aabb_of(uniform(rng, bounds), uniform(rng, bounds));

    auto dis = distance(bbA, bbB);
    CHECK(dis >= 0);

    // zero dis means they intersect
    if (dis == 0)
        CHECK(intersects(bbA, bbB));
    else // otherwise they dont
        CHECK(!intersects(bbA, bbB));

    // dis is a lower bound of all point-wise distances
    auto pA = uniform(rng, bbA);
    auto pB = uniform(rng, bbB);
    CHECK(distance(pA, pB) >= nx::approx(dis));
}

FUZZ_TEST("Distance - SegmentTriangle3")(tg::rng& rng)
{
    auto bounds = tg::aabb3(-10, 10);
    auto tri = tg::triangle3(uniform(rng, bounds), uniform(rng, bounds), uniform(rng, bounds));
    auto seg = tg::segment3(uniform(rng, bounds), uniform(rng, bounds));

    auto dis = distance(tri, seg);
    CHECK(dis >= 0);
    CHECK(dis == distance(seg, tri));

    if (dis == 0)
        CHECK(intersects(seg, tri));
    else
        CHECK(!intersects(seg, tri));
}

FUZZ_TEST("Distance - LineTriangle3")(tg::rng& rng)
{
    auto bounds = tg::aabb3(-10, 10);
    auto tri = tg::triangle3(uniform(rng, bounds), uniform(rng, bounds), uniform(rng, bounds));
    auto l = tg::line3(uniform(rng, bounds), tg::uniform<tg::dir3>(rng));

    auto dis = distance(tri, l);

    CHECK(dis >= 0);
    CHECK(dis == distance(l, tri));

    if (dis == 0)
        CHECK(intersects(l, tri));
    else
        CHECK(!intersects(l, tri));
}

FUZZ_TEST("Distance - SegmentSphereD")(tg::rng& rng)
{
    auto bounds2D = tg::aabb2(-10, 10);
    auto bounds3D = tg::aabb3(-10, 10);

    // 2D
    auto seg0 = tg::segment2(uniform(rng, bounds2D), uniform(rng, bounds2D));
    auto sphere0 = tg::sphere2(uniform(rng, bounds2D), 1.f);

    auto dis0 = distance(seg0, sphere0);
    CHECK(dis0 >= 0);
    CHECK(dis0 == distance(sphere0, seg0));

    if (dis0 == 0)
        CHECK(intersects(seg0, sphere0));
    else
        CHECK(!intersects(seg0, sphere0));

    // 3D
    auto seg1 = tg::segment3(uniform(rng, bounds3D), uniform(rng, bounds3D));
    auto sphere1 = tg::sphere3(uniform(rng, bounds3D), 1.f);

    auto dis1 = distance(seg1, sphere1);
    CHECK(dis1 >= 0);
    CHECK(dis1 == distance(sphere1, seg1));

    if (dis1 == 0)
        CHECK(intersects(seg1, sphere1));
    else
        CHECK(!intersects(seg1, sphere1));
}

FUZZ_TEST("Distance - LineSphereD")(tg::rng& rng)
{
    auto bounds2D = tg::aabb2(-10, 10);
    auto bounds3D = tg::aabb3(-10, 10);

    // 2D
    auto l0 = tg::line2(uniform(rng, bounds2D), tg::uniform<tg::dir2>(rng));
    auto sphere0 = tg::sphere2(uniform(rng, bounds2D), 1.f);

    auto dis0 = distance(l0, sphere0);
    CHECK(dis0 >= 0);
    CHECK(dis0 == distance(sphere0, l0));

    if (dis0 == 0)
        CHECK(intersects(l0, sphere0));
    else
        CHECK(!intersects(l0, sphere0));

    // 3D
    auto l1 = tg::line3(uniform(rng, bounds3D), tg::uniform<tg::dir3>(rng));
    auto sphere1 = tg::sphere3(uniform(rng, bounds3D), 1.f);

    auto dis1 = distance(l1, sphere1);
    CHECK(dis1 >= 0);
    CHECK(dis1 == distance(sphere1, l1));

    if (dis1 == 0)
        CHECK(intersects(l1, sphere1));
    else
        CHECK(!intersects(l1, sphere1));
}

FUZZ_TEST("Distance - SegmentPlane3")(tg::rng& rng)
{
    auto bounds = tg::aabb3(-10, 10);

    auto seg = tg::segment3(uniform(rng, bounds), uniform(rng, bounds));
    auto p = tg::plane3(tg::uniform<tg::dir3>(rng), uniform(rng, bounds));

    auto dis = distance(seg, p);
    CHECK(dis >= 0);
    CHECK(dis == distance(p, seg));

    if (dis == 0)
        CHECK(intersects(seg, p));
    else
        CHECK(!intersects(seg, p));
}

FUZZ_TEST("Distance - BoxPlane3")(tg::rng& rng)
{
    auto bounds = tg::aabb3(-10, 10);
    auto scalar_bounds = tg::aabb1(1, 5);

    auto b = tg::box3();
    b.center = uniform(rng, bounds);
    b.half_extents[0] = uniform(rng, scalar_bounds).x * tg::uniform<tg::dir3>(rng);
    b.half_extents[1].x = tg::uniform(rng, scalar_bounds).x;
    b.half_extents[1].y = tg::uniform(rng, scalar_bounds).x;
    b.half_extents[1].z = (-b.half_extents[0].x * b.half_extents[1].x - b.half_extents[0].y * b.half_extents[1].y) / b.half_extents[0].z;
    b.half_extents[2] = tg::cross(b.half_extents[0], b.half_extents[1]);

    auto p = tg::plane3(tg::uniform<tg::dir3>(rng), uniform(rng, bounds));

    auto dis = distance(b, p);
    CHECK(dis >= 0);
    CHECK(dis == distance(p, b));

    if (dis == 0)
        CHECK(intersects(b, p));
    else
        CHECK(!intersects(b, p));
}

FUZZ_TEST("Distance - LineSegment3")(tg::rng& rng)
{
    auto bounds = tg::aabb3(-10, 10);
    auto pos = uniform(rng, bounds);

    // Case 1: line and segment intersecting
    auto s0 = tg::segment3(pos, uniform(rng, bounds));
    auto l0 = tg::line3(pos, tg::uniform<tg::dir3>(rng));

    auto d0 = distance(s0, l0);
    auto d0_sqr = distance_sqr(s0, l0);

    CHECK(d0 == 0);
    CHECK(d0_sqr == 0);

    // Case 2: line and segment not intersection -> parallel
    auto s1 = s0;
    auto offset_pos = pos + 1 * tg::uniform<tg::dir3>(rng);
    auto l1 = tg::line3(offset_pos, normalize(s1.pos1 - s1.pos0));

    auto d1 = distance(s1, l1);

    CHECK(d1 <= nx::approx(1.f));
}

FUZZ_TEST("Distance - RaySegment3")(tg::rng& rng)
{
    auto bounds = tg::aabb3(-10, 10);
    auto pos = uniform(rng, bounds);

    // Case 1: line and segment intersecting
    auto s0 = tg::segment3(pos, uniform(rng, bounds));
    auto r0 = tg::ray3(pos, tg::uniform<tg::dir3>(rng));

    CHECK(distance(s0, r0) == 0);
    CHECK(distance(r0, s0) == 0);

    CHECK(distance_sqr(s0, r0) == 0);
    CHECK(distance_sqr(r0, s0) == 0);

    // Case 2: line and segment not intersection -> parallel
    auto s1 = s0;
    auto offset_pos = pos + 1 * tg::uniform<tg::dir3>(rng);
    auto r1 = tg::ray3(offset_pos, normalize(s1.pos1 - s1.pos0));

    auto d1 = distance(s1, r1);

    CHECK(distance(s1, r1) <= nx::approx(1.f));
    CHECK(distance(r1, s1) <= nx::approx(1.f));
}

FUZZ_TEST("Distance - RaySphere3")(tg::rng& rng)
{
    auto bounds = tg::aabb3(-10, 10);
    auto scalar_bounds = tg::aabb1(1.f, 5.f);

    auto pos = tg::uniform(rng, bounds);
    float rad = tg::uniform(rng, scalar_bounds).x;
    auto s = tg::sphere3(pos, rad);

    // Case 1 : ray through sphere center
    auto dirx = tg::uniform<tg::dir3>(rng);
    auto diry = tg::uniform<tg::dir3>(rng);
    auto r0 = tg::ray3(pos, normalize(cross(dirx, diry)));

    CHECK(distance(s, r0) == nx::approx(0.f));

    // Case 2: ray not intersecting sphere
    auto r1 = tg::ray3(pos + (rad + 1.f) * dirx, r0.dir);
    auto dis1 = distance(s, r1);

    CHECK(dis1 == nx::approx(1.f));
}

FUZZ_TEST("Distance - SegmentAABB3")(tg::rng& rng)
{
    auto bounds = tg::aabb3(-10, 10);

    auto bb = tg::aabb3::unit_centered;

    // Case 1: random segment inside bounds
    auto s0 = tg::segment3(tg::uniform(rng, bounds), tg::uniform(rng, bounds));

    if (intersects(s0, bb))
    {
        CHECK(distance(s0, bb) == nx::approx(0.f));
        CHECK(distance(bb, s0) == nx::approx(0.f));
        CHECK(distance_sqr(s0, bb) == nx::approx(0.f));
        CHECK(distance_sqr(bb, s0) == nx::approx(0.f));
    }

    // Case 2: segment above bb
    auto p = tg::plane3(tg::dir3{0.f, 1.f, 0.f}, tg::pos3(0, 1.1f, 0));

    auto s1 = tg::segment3(tg::project(tg::uniform(rng, bounds), p), {0.f, 0.6f, 0.f});

    CHECK(distance(s1, bb) == nx::approx(0.1f));
    CHECK(distance(bb, s1) == nx::approx(0.1f));
}

FUZZ_TEST("Distance - LineAABB3")(tg::rng& rng)
{
    auto bounds = tg::aabb3(-10, 10);

    auto bb = tg::aabb3::unit_centered;

    // Case 1: line through center of bounding box
    auto l0 = tg::line3(tg::pos3::zero, tg::uniform<tg::dir3>(rng));

    CHECK(distance(bb, l0) == nx::approx(0.f));
    CHECK(distance(l0, bb) == nx::approx(0.f));
    CHECK(distance_sqr(bb, l0) == nx::approx(0.f));
    CHECK(distance_sqr(l0, bb) == nx::approx(0.f));

    // Case 2: line not intersecting bounding box
    auto l1 = tg::line3({-1.f, 0.f, 0.f}, {0.f, 1.f, 0.f});

    CHECK(distance(bb, l1) == nx::approx(.5f));
    CHECK(distance(l1, bb) == nx::approx(.5f));
    CHECK(distance_sqr(bb, l1) >= 0.f);
    CHECK(distance_sqr(l1, bb) >= 0.f);
}

FUZZ_TEST("Distance - RayAABB3")(tg::rng& rng)
{
    auto bounds = tg::aabb3(-10, 10);
    auto bb = tg::aabb3::unit_centered;

    // Case 1: ray through center of bounding box
    auto r0 = tg::ray3(tg::pos3::zero, tg::uniform<tg::dir3>(rng));

    CHECK(distance(bb, r0) == nx::approx(0.f));
    CHECK(distance(r0, bb) == nx::approx(0.f));
    CHECK(distance_sqr(bb, r0) == nx::approx(0.f));
    CHECK(distance_sqr(r0, bb) == nx::approx(0.f));

    // Case 2: ray not intersecting bounding box
    auto r1 = tg::ray3({-1.f, 0.f, 0.f}, {0.f, 1.f, 0.f});

    CHECK(distance(bb, r1) == nx::approx(.5f));
    CHECK(distance(r1, bb) == nx::approx(.5f));
    CHECK(distance_sqr(bb, r1) >= 0.f);
    CHECK(distance_sqr(r1, bb) >= 0.f);
}

FUZZ_TEST("Distance - SegmentDisk3")(tg::rng& rng)
{
    auto bounds = tg::aabb3(-10, 10);

    // Case 1: segment through center of disk
    auto disk0 = tg::disk3(tg::uniform(rng, bounds), 1.f, tg::uniform<tg::dir3>(rng));
    auto s0 = tg::segment3(disk0.center + disk0.normal, disk0.center - disk0.normal);

    CHECK(distance(s0, disk0) == nx::approx(0.f));
    CHECK(distance(disk0, s0) == nx::approx(0.f));
    CHECK(distance_sqr(s0, disk0) == nx::approx(0.f));
    CHECK(distance_sqr(disk0, s0) == nx::approx(0.f));

    // Case 2: segment parallel to disk, not intersecting
    auto disk1 = tg::disk3(tg::pos3::zero, 1.f, {0.f, 1.f, 0.f});

    auto s1 = tg::segment3(tg::project(tg::uniform(rng, bounds), disk1) + 1 * disk1.normal, tg::project(tg::uniform(rng, bounds), disk1) + 1 * disk1.normal);

    CHECK(distance(s1, disk1) == nx::approx(1.f));
    CHECK(distance(disk1, s1) == nx::approx(1.f));
    CHECK(distance_sqr(s1, disk1) == nx::approx(1.f));
    CHECK(distance_sqr(disk1, s1) == nx::approx(1.f));
}

FUZZ_TEST("Distance - LineDisk3")(tg::rng& rng)
{
    auto bounds = tg::aabb3(-10, 10);

    // Case 1: line through center of disk}
    auto disk0 = tg::disk3(tg::uniform(rng, bounds), 1.f, tg::uniform<tg::dir3>(rng));
    auto l0 = tg::line3(disk0.center, disk0.normal);

    CHECK(distance(l0, disk0) == nx::approx(0.f));
    CHECK(distance(disk0, l0) == nx::approx(0.f));
    CHECK(distance_sqr(l0, disk0) == nx::approx(0.f));
    CHECK(distance_sqr(l0, disk0) == nx::approx(0.f));

    auto disk1 = tg::disk3(tg::pos3::zero, 1.f, {0.f, 1.f, 0.f});
    auto l1_pos = disk1.center + 1 * disk1.normal;
    auto proj_disk = tg::project(tg::uniform(rng, bounds), disk1);
    auto l1 = tg::line3(l1_pos, normalize((proj_disk + 1 * disk1.normal) - l1_pos));

    CHECK(distance(l1, disk1) == nx::approx(1.f));
    CHECK(distance(disk1, l1) == nx::approx(1.f));
    CHECK(distance_sqr(l1, disk1) == nx::approx(1.f));
    CHECK(distance_sqr(disk1, l1) == nx::approx(1.f));
}

FUZZ_TEST("Distance - RayDisk3")(tg::rng& rng)
{
    auto bounds = tg::aabb3(-10, 10);

    // Case 1: line through center of disk
    auto disk0 = tg::disk3(tg::uniform(rng, bounds), 1.f, tg::uniform<tg::dir3>(rng));
    auto r0 = tg::ray3(disk0.center, disk0.normal);

    CHECK(distance(r0, disk0) == nx::approx(0.f));
    CHECK(distance(disk0, r0) == nx::approx(0.f));
    CHECK(distance_sqr(r0, disk0) == nx::approx(0.f));
    CHECK(distance_sqr(r0, disk0) == nx::approx(0.f));

    // Case 2: line parallel parallel to disk
    auto disk1 = tg::disk3(tg::pos3::zero, 1.f, {0.f, 1.f, 0.f});
    auto r1_pos = disk1.center + 1 * disk1.normal;
    auto proj_disk = tg::project(tg::uniform(rng, bounds), disk1);
    auto r1 = tg::ray3(r1_pos, normalize((proj_disk + 1 * disk1.normal) - r1_pos));

    CHECK(distance(r1, disk1) == nx::approx(1.f));
    CHECK(distance(disk1, r1) == nx::approx(1.f));
    CHECK(distance_sqr(r1, disk1) == nx::approx(1.f));
    CHECK(distance_sqr(disk1, r1) == nx::approx(1.f));
}

FUZZ_TEST("Distance - SegmentCylinder3")(tg::rng& rng)
{
    auto bounds = tg::aabb3(-10, 10);

    // Case 1: segment intersecting with cylinder
    auto cyl0 = tg::cylinder3(tg::uniform(rng, bounds), tg::uniform(rng, bounds), 1.f);
    auto s0 = tg::segment3(tg::uniform(rng, bounds), cyl0.axis.pos0);

    CHECK(distance(s0, cyl0) == nx::approx(0.f));
    CHECK(distance(cyl0, s0) == nx::approx(0.f));
    CHECK(distance_sqr(s0, cyl0) == nx::approx(0.f));
    CHECK(distance_sqr(cyl0, s0) == nx::approx(0.f));

    // Case 2: segment not intersecting with cylinder
    auto cyl1 = tg::cylinder3({{0.f, -1.f, 0.f}, {0.f, 1.f, 0.f}}, 1.f);
    auto s1 = tg::segment3(cyl1.axis.pos0 + 2 * tg::dir3{1.f, 0.f, 0.f}, cyl1.axis.pos1 + 2 * tg::dir3{1.f, 0.f, 0.f});

    CHECK(distance(s1, cyl1) == nx::approx(1.f));
    CHECK(distance(cyl1, s1) == nx::approx(1.f));
    CHECK(distance_sqr(s1, cyl1) == nx::approx(1.f));
    CHECK(distance_sqr(cyl1, s1) == nx::approx(1.f));
}

FUZZ_TEST("Distance - LineCylinder3 ")(tg::rng& rng)
{
    auto bounds = tg::aabb3(-10, 10);
    auto scalar_bounds = tg::aabb1(0.1f, 0.9f);

    // Case 1: line intersecting with cylinder
    auto cyl0 = tg::cylinder3(tg::uniform(rng, bounds), tg::uniform(rng, bounds), 1.f);
    auto l0 = tg::line3(cyl0.axis.pos0, tg::normalize(cyl0.axis.pos1 - cyl0.axis.pos0));

    CHECK(distance(l0, cyl0) == nx::approx(0.f));
    CHECK(distance(cyl0, l0) == nx::approx(0.f));
    CHECK(distance_sqr(l0, cyl0) == nx::approx(0.f));
    CHECK(distance_sqr(cyl0, l0) == nx::approx(0.f));

    // Case 2: line not intersection with cylinder
    auto cyl_dir = tg::uniform<tg::dir3>(rng);
    auto cyl_pos0 = tg::uniform(rng, bounds);
    auto cyl1 = tg::cylinder3({cyl_pos0, cyl_pos0 + cyl_dir}, 1.f);

    // find orthogonal vector to cylinder axis
    auto cyl_l = tg::line3(cyl1.axis.pos0, normalize(cyl1.axis.pos1 - cyl1.axis.pos0));
    auto orth_vec = tg::vec3(tg::uniform(rng, scalar_bounds).x, tg::uniform(rng, scalar_bounds).x, 0);
    orth_vec.z = (-cyl_l.dir.x * orth_vec.x - cyl_l.dir.y * orth_vec.y) / cyl_l.dir.z;
    orth_vec = normalize(orth_vec);

    float rng_scalar = tg::uniform(rng, scalar_bounds).x;
    auto pos_l1 = cyl1.axis[rng_scalar] + 2.f * orth_vec;
    auto l1 = tg::line3(pos_l1, normalize(cyl1.axis.pos1 - cyl1.axis.pos0));

    CHECK(distance(l1, cyl1) == nx::approx(1.f));
    CHECK(distance(cyl1, l1) == nx::approx(1.f));
    CHECK(distance_sqr(l1, cyl1) == nx::approx(1.f));
    CHECK(distance_sqr(cyl1, l1) == nx::approx(1.f));
}

FUZZ_TEST("Distance - RayCylinder3")(tg::rng& rng)
{
    auto bounds = tg::aabb3(-10, 10);
    auto scalar_bounds = tg::aabb1(0.1f, 0.9f);

    // Case 1: ray intersecting with cylinder
    auto cyl0 = tg::cylinder3(tg::uniform(rng, bounds), tg::uniform(rng, bounds), 1.f);
    auto r0 = tg::ray3(cyl0.axis.pos0, tg::normalize(cyl0.axis.pos1 - cyl0.axis.pos0));

    CHECK(distance(r0, cyl0) == nx::approx(0.f));
    CHECK(distance(cyl0, r0) == nx::approx(0.f));
    CHECK(distance_sqr(r0, cyl0) == nx::approx(0.f));
    CHECK(distance_sqr(cyl0, r0) == nx::approx(0.f));

    // Case 2: ray not intersection with cylinder
    auto cyl_dir = tg::uniform<tg::dir3>(rng);
    auto cyl_pos0 = tg::uniform(rng, bounds);
    auto cyl1 = tg::cylinder3({cyl_pos0, cyl_pos0 + cyl_dir}, 1.f);

    // find orthogonal vector to cylinder axis
    auto cyl_r = tg::line3(cyl1.axis.pos0, normalize(cyl1.axis.pos1 - cyl1.axis.pos0));
    auto orth_vec = tg::vec3(tg::uniform(rng, scalar_bounds).x, tg::uniform(rng, scalar_bounds).x, 0);
    orth_vec.z = (-cyl_r.dir.x * orth_vec.x - cyl_r.dir.y * orth_vec.y) / cyl_r.dir.z;
    orth_vec = normalize(orth_vec);

    float rng_scalar = tg::uniform(rng, scalar_bounds).x;
    auto pos_r1 = cyl1.axis[rng_scalar] + 2.f * orth_vec;
    auto r1 = tg::line3(pos_r1, normalize(cyl1.axis.pos1 - cyl1.axis.pos0));

    CHECK(distance(r1, cyl1) == nx::approx(1.f));
    CHECK(distance(cyl1, r1) == nx::approx(1.f));
    CHECK(distance_sqr(r1, cyl1) == nx::approx(1.f));
    CHECK(distance_sqr(cyl1, r1) == nx::approx(1.f));
}

FUZZ_TEST("Distance - LineBox3")(tg::rng& rng)
{
    auto b = tg::box3::unit_centered;

    // Case 1: line intersecting with box
    auto l0 = tg::line3(tg::pos3::zero, tg::uniform<tg::dir3>(rng));

    CHECK(distance(l0, b) == nx::approx(0.f));
    CHECK(distance(b, l0) == nx::approx(0.f));
    CHECK(distance_sqr(l0, b) == nx::approx(0.f));
    CHECK(distance_sqr(b, l0) == nx::approx(0.f));

    // Case2: line not intersecting with box
    auto v_b = b.center + b.half_extents[0] + b.half_extents[1] - b.half_extents[2];
    tg::dir3 dir_diag = normalize(tg::vec3{1.f, 1.f, 1.f});
    tg::dir3 dir_diag_rev = normalize(v_b - b.center);

    auto pos_l1 = v_b + dir_diag_rev;
    auto l1 = tg::line3(pos_l1, dir_diag);

    // project box vertex closest to line onto line
    auto proj_l1 = tg::project(v_b, l1);

    CHECK(distance(l1, b) == nx::approx(distance(proj_l1, b)));
    CHECK(distance(b, l1) == nx::approx(distance(proj_l1, b)));
    CHECK(distance_sqr(l1, b) > 0.f);
    CHECK(distance_sqr(b, l1) > 0.f);
}

FUZZ_TEST("Distance - RayBox3")(tg::rng& rng)
{
    auto b = tg::box3::unit_centered;

    // Case 1: ray intersecting with box
    auto r0 = tg::line3(tg::pos3::zero, tg::uniform<tg::dir3>(rng));

    CHECK(distance(r0, b) == nx::approx(0.f));
    CHECK(distance(b, r0) == nx::approx(0.f));
    CHECK(distance_sqr(r0, b) == nx::approx(0.f));
    CHECK(distance_sqr(b, r0) == nx::approx(0.f));

    // Case2: line not intersecting with box
    auto v_b = b.center + b.half_extents[0] + b.half_extents[1] - b.half_extents[2];
    tg::dir3 dir_diag = normalize(tg::vec3{1.f, 1.f, 1.f});
    tg::dir3 dir_diag_rev = normalize(v_b - b.center);

    auto pos_r1 = v_b + dir_diag_rev;
    auto r1 = tg::line3(pos_r1, dir_diag);

    auto proj_l1 = tg::project(v_b, r1);

    CHECK(distance(r1, b) == nx::approx(distance(proj_l1, b)));
    CHECK(distance(b, r1) == nx::approx(distance(proj_l1, b)));
    CHECK(distance_sqr(r1, b) > 0.f);
    CHECK(distance_sqr(b, r1) > 0.f);
}
