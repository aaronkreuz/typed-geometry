#include <nexus/test.hh>

TG_FUZZ_TEST(Mat4, DecomposeUniform)
{
    auto t0 = uniform_vec(rng, tg::aabb3(-10, 10));
    auto s0 = uniform(rng, .1f, 2.f);
    auto R0 = tg::rotation_around(tg::uniform<tg::dir3>(rng), tg::uniform<tg::angle>(rng));

    auto M = tg::translation(t0) * R0 * tg::scaling<3>(s0);

    auto MM = tg::compose_transformation(t0, tg::mat3(R0), s0);

    auto p = uniform(rng, tg::aabb3(-10, 10));

    tg::vec3 t1;
    tg::mat3 R1;
    float s1;
    tg::decompose_transformation(M, t1, R1, s1);

    CHECK(t1 == approx(t0, 0.01f));
    CHECK(s1 == approx(s0).epsilon(0.01f));

    auto q0 = M * p;
    auto q1 = tg::pos3(R1 * (s1 * tg::vec3(p)) + t1);
    auto q2 = MM * p;

    CHECK(q1 == approx(q0, 0.01f));
    CHECK(q2 == approx(q0, 0.01f));
}

TG_FUZZ_TEST(Mat4, DecomposeNonUniform)
{
    auto t0 = uniform_vec(rng, tg::aabb3(-10, 10));
    auto s0 = tg::size3(uniform(rng, tg::aabb3(0.1f, 2.f)));
    auto R0 = tg::rotation_around(tg::uniform<tg::dir3>(rng), tg::uniform<tg::angle>(rng));

    auto M = tg::translation(t0) * R0 * tg::scaling(s0);

    auto MM = tg::compose_transformation(t0, tg::mat3(R0), s0);

    auto p = uniform(rng, tg::aabb3(-10, 10));

    tg::vec3 t1;
    tg::mat3 R1;
    tg::size3 s1;
    tg::decompose_transformation(M, t1, R1, s1);

    CHECK(t1 == approx(t0, 0.01f));
    CHECK(s1 == approx(s0, 0.01f));

    auto q0 = M * p;
    auto q1 = tg::pos3(R1 * (tg::vec3(p) * s1) + t1);
    auto q2 = MM * p;

    CHECK(q1 == approx(q0, 0.01f));
    CHECK(q2 == approx(q0, 0.01f));
}