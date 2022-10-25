#include <nexus/fuzz_test.hh>

#include <typed-geometry/feature/objects.hh>

FUZZ_TEST("ClosestPoints - PosPos")(tg::rng& rng)
{
    auto range1 = tg::aabb1(tg::pos1(-10), tg::pos1(10));
    auto range2 = tg::aabb2(tg::pos2(-10), tg::pos2(10));
    auto range3 = tg::aabb3(tg::pos3(-10), tg::pos3(10));
    auto range4 = tg::aabb4(tg::pos4(-10), tg::pos4(10));

    {
        auto a = uniform(rng, range1);
        auto b = uniform(rng, range1);

        auto cp = tg::closest_points(a, b);
        CHECK(a == cp.first);
        CHECK(b == cp.second);
    }
    {
        auto a = uniform(rng, range2);
        auto b = uniform(rng, range2);

        auto cp = tg::closest_points(a, b);
        CHECK(a == cp.first);
        CHECK(b == cp.second);
    }
    {
        auto a = uniform(rng, range3);
        auto b = uniform(rng, range3);

        auto cp = tg::closest_points(a, b);
        CHECK(a == cp.first);
        CHECK(b == cp.second);
    }
    {
        auto a = uniform(rng, range4);
        auto b = uniform(rng, range4);

        auto cp = tg::closest_points(a, b);
        CHECK(a == cp.first);
        CHECK(b == cp.second);
    }
}


FUZZ_TEST("ClosestPoints - SegmentPos")(tg::rng& rng)
{
    auto range1 = tg::aabb1(tg::pos1(-10), tg::pos1(10));
    auto range2 = tg::aabb2(tg::pos2(-10), tg::pos2(10));
    auto range3 = tg::aabb3(tg::pos3(-10), tg::pos3(10));
    auto range4 = tg::aabb4(tg::pos4(-10), tg::pos4(10));

    auto eps = 1e-5f;

    {
        auto a = uniform(rng, range1);
        auto b = uniform(rng, range1);

        int attempts = 0;
        int maxAttempts = 1000;
        while (tg::distance(a, b) < eps && attempts < maxAttempts)
        {
            b = uniform(rng, range1);
            attempts++;
        }
        CHECK(attempts < maxAttempts);

        auto p = uniform(rng, range1);

        auto seg = tg::segment1(a, b);

        auto cp = tg::closest_points(seg, p).first;
        auto p_a2 = tg::distance(p, a);
        auto p_b2 = tg::distance(p, b);
        auto cp_a2 = tg::distance(cp, a);
        auto cp_b2 = tg::distance(cp, b);

        CHECK(cp_a2 <= p_a2 + eps);
        CHECK(cp_b2 <= p_b2 + eps);
    }

    {
        auto a = uniform(rng, range2);
        auto b = uniform(rng, range2);

        int attempts = 0;
        int maxAttempts = 1000;
        while (tg::distance(a, b) < eps && attempts < maxAttempts)
        {
            b = uniform(rng, range2);
            attempts++;
        }
        CHECK(attempts < maxAttempts);

        auto p = uniform(rng, range2);

        auto seg = tg::segment2(a, b);

        auto cp = tg::closest_points(seg, p).first;
        auto p_a2 = tg::distance(p, a);
        auto p_b2 = tg::distance(p, b);
        auto cp_a2 = tg::distance(cp, a);
        auto cp_b2 = tg::distance(cp, b);

        CHECK(cp_a2 <= p_a2 + eps);
        CHECK(cp_b2 <= p_b2 + eps);
    }

    {
        auto a = uniform(rng, range3);
        auto b = uniform(rng, range3);

        int attempts = 0;
        int maxAttempts = 1000;
        while (tg::distance(a, b) < eps && attempts < maxAttempts)
        {
            b = uniform(rng, range3);
            attempts++;
        }
        CHECK(attempts < maxAttempts);

        auto p = uniform(rng, range3);

        auto seg = tg::segment3(a, b);

        auto cp = tg::closest_points(seg, p).first;
        auto p_a2 = tg::distance(p, a);
        auto p_b2 = tg::distance(p, b);
        auto cp_a2 = tg::distance(cp, a);
        auto cp_b2 = tg::distance(cp, b);

        CHECK(cp_a2 <= p_a2 + eps);
        CHECK(cp_b2 <= p_b2 + eps);
    }

    {
        auto a = uniform(rng, range4);
        auto b = uniform(rng, range4);

        int attempts = 0;
        int maxAttempts = 1000;
        while (tg::distance(a, b) < eps && attempts < maxAttempts)
        {
            b = uniform(rng, range4);
            attempts++;
        }
        CHECK(attempts < maxAttempts);

        auto p = uniform(rng, range4);

        auto seg = tg::segment4(a, b);

        auto cp = tg::closest_points(seg, p).first;
        auto p_a2 = tg::distance(p, a);
        auto p_b2 = tg::distance(p, b);
        auto cp_a2 = tg::distance(cp, a);
        auto cp_b2 = tg::distance(cp, b);

        CHECK(cp_a2 <= p_a2 + eps);
        CHECK(cp_b2 <= p_b2 + eps);
    }
}

FUZZ_TEST("ClosestPoints - LineLine3")(tg::rng& rng)
{
    auto bb = tg::aabb3(-10, 10);
    auto l0 = tg::line3::from_points(uniform(rng, bb), uniform(rng, bb));
    auto l1 = tg::line3::from_points(uniform(rng, bb), uniform(rng, bb));

    auto d = distance(l0, l1);
    auto [p0, p1] = tg::closest_points(l0, l1);
    auto [t0, t1] = tg::closest_points_parameters(l0, l1);

    CHECK(distance(p0, p1) == nx::approx(d).abs(0.001f));
    CHECK(distance(l0[t0], l1[t1]) == nx::approx(d).abs(0.001f));
}


FUZZ_TEST("ClosestPoints - SphereSphere3Bound")(tg::rng& rng)
{
    auto bb = tg::aabb3(-10, 10);
    auto scal_range = tg::aabb1(1.f, 5.f);

    auto s0 = tg::sphere_boundary<3, float>(uniform(rng, bb), uniform(rng, scal_range).x);
    auto s1 = tg::sphere_boundary<3, float>(uniform(rng, bb), uniform(rng, scal_range).x);

    auto cp = tg::closest_points(s0, s1);

    auto d = distance(s0.center, s1.center);

    CHECK(distance_sqr(cp.first, s0) == nx::approx(0.f));
    CHECK(distance_sqr(cp.second, s1) == nx::approx(0.f));

    if (!intersects(solid_of(s0), solid_of(s1)))
        CHECK(distance(s0, s1) == nx::approx(distance(cp.first, cp.second)));

    else if (d + s0.radius < s1.radius)
        CHECK(distance(cp.first, cp.second) < s1.radius);

    else if (d + s1.radius < s0.radius)
        CHECK(distance(cp.first, cp.second) < s0.radius);

    // normal intersection case
    else
        CHECK(cp.first == cp.second);
}

FUZZ_TEST("ClosestPoints - SphereSphere3")(tg::rng& rng)
{
    auto bb = tg::aabb3(-10, 10);
    auto scal_range = tg::aabb1(1.f, 5.f);

    auto s0 = tg::sphere<3, float>(uniform(rng, bb), uniform(rng, scal_range).x);
    auto s1 = tg::sphere<3, float>(uniform(rng, bb), uniform(rng, scal_range).x);

    auto cp = tg::closest_points(s0, s1);

    CHECK(distance_sqr(cp.first, s0) == nx::approx(0.f));
    CHECK(distance_sqr(cp.second, s1) == nx::approx(0.f));

    if (!intersects(s0, s1))
        CHECK(distance(s0, s1) == nx::approx(distance(cp.first, cp.second)));

    else
        CHECK(cp.first == cp.second);
}

FUZZ_TEST("ClosestPoints - SpherePlane3Bound")(tg::rng& rng)
{
    auto bb = tg::aabb3(-10, 10);
    auto scal_range = tg::aabb1{1.f, 5.f};

    auto sphere = tg::sphere_boundary<3, float>(uniform(rng, bb), uniform(rng, scal_range).x);
    auto plane = tg::plane3(tg::uniform<tg::dir3>(rng), uniform(rng, bb));

    auto cp = tg::closest_points(sphere, plane);

    CHECK(distance_sqr(cp.first, sphere) == nx::approx(0.f));
    CHECK(distance_sqr(cp.second, plane) == nx::approx(0.f));

    if (!intersects(tg::solid_of(sphere), plane))
        CHECK(distance(cp.first, cp.second) == nx::approx(distance(sphere, plane)));

    else
        CHECK(cp.first == cp.second);
}

FUZZ_TEST("ClosestPoints - SpherePlane3")(tg::rng& rng)
{
    auto bb = tg::aabb3(-10, 10);
    auto scal_range = tg::aabb1{1.f, 5.f};

    auto sphere = tg::sphere3(uniform(rng, bb), uniform(rng, scal_range).x);
    auto plane = tg::plane3(tg::uniform<tg::dir3>(rng), uniform(rng, bb));

    auto cp = tg::closest_points(sphere, plane);

    CHECK(distance_sqr(cp.first, sphere) == nx::approx(0.f));
    CHECK(distance_sqr(cp.second, plane) == nx::approx(0.f));

    if (!intersects(sphere, plane))
        CHECK(distance(cp.first, cp.second) == nx::approx(distance(sphere, plane)));

    else
        CHECK(cp.first == cp.second);
}

FUZZ_TEST("ClosestPoints - PlaneSegment3")(tg::rng& rng)
{
    auto bb = tg::aabb3(-10, 10);

    auto seg = tg::segment3(uniform(rng, bb), uniform(rng, bb));
    auto plane = tg::plane3(tg::uniform<tg::dir3>(rng), uniform(rng, bb));

    auto cp = tg::closest_points(seg, plane);

    CHECK(distance_sqr(cp.first, seg) == nx::approx(0.f));
    CHECK(distance_sqr(cp.second, plane) == nx::approx(0.f));

    if (!intersects(seg, plane))
        CHECK(distance(cp.first, cp.second) == nx::approx(distance(seg, plane)));

    else
        CHECK(cp.first == cp.second);
}

FUZZ_TEST("ClosestPoints - RaySegment3")(tg::rng& rng)
{
    auto bb = tg::aabb3(-10, 10);
    auto scal_range = tg::aabb1(0.1f, 5.f);

    // Case 1: ray and seg parallel and not intersecting
    auto r0 = tg::ray3(uniform(rng, bb), tg::uniform<tg::dir3>(rng));
    auto s0 = tg::segment3(r0.origin - uniform(rng, scal_range).x * r0.dir, r0.origin - uniform(rng, scal_range).x * r0.dir);

    auto cp_s0 = distance_sqr(s0.pos0, r0.origin) < distance_sqr(s0.pos1, r0.origin) ? s0.pos0 : s0.pos1;

    auto cp0 = closest_points(s0, r0);

    CHECK(distance_sqr(cp0.first, cp_s0) == nx::approx(0.f));
    CHECK(distance_sqr(cp0.second, r0.origin) == nx::approx(0.f));
    CHECK(distance_sqr(cp0.first, cp0.second) == nx::approx(distance_sqr(s0, r0)));

    // Case 2: intersection in ray origin
    auto ort_dir = tg::any_normal(r0.dir);
    auto s1 = tg::segment3(r0.origin + uniform(rng, scal_range).x * ort_dir, r0.origin - uniform(rng, scal_range).x * ort_dir);

    auto cp1 = closest_points(s1, r0);

    CHECK(distance_sqr(cp1.first, cp1.second) == nx::approx(0.f));
    CHECK(distance_sqr(cp1.first, r0.origin) == nx::approx(0.f));
}

FUZZ_TEST("ClosestPoints - PlaneAABB3")(tg::rng& rng)
{
    auto bb = tg::aabb1(1.1f, 10);

    // Case 1: no intersection
    auto aabb0 = tg::aabb3::unit_centered;
    auto diag = tg::normalize(tg::vec3(aabb0.max));

    auto dist = tg::uniform(rng, bb);
    auto plane0 = tg::plane3(diag, aabb0.max + dist.x * diag);

    auto cp0 = tg::closest_points(aabb0, plane0);

    CHECK(distance(cp0.first, cp0.second) == nx::approx(dist.x));
    CHECK(distance_sqr(cp0.first, aabb0.max) == nx::approx(0.f));

    // Case 2: intersection
    auto plane1 = tg::plane3(diag, aabb0.max);

    auto cp1 = tg::closest_points(aabb0, plane1);

    CHECK(distance_sqr(cp1.first, cp1.second) == nx::approx(0.f));
    CHECK(distance_sqr(cp1.first, aabb0.max) == nx::approx(0.f));
}
