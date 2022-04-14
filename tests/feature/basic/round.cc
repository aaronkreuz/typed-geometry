#include <nexus/test.hh>

#include <initializer_list>

TEST("TypedGeometry.Round")
{
    // Test some fix numbers
    for (auto v : {-2.0f, -1.00001f, -1.0f, -0.99999f, -0.7f, -0.5f, -0.3f, 0.0f, 0.3f, 0.5f, 0.7f, 0.99999f, 1.0f, 1.00001f, 2.0f})
    {
        CHECK((int)tg::round(v) == tg::iround(v));
        CHECK((int)tg::floor(v) == tg::ifloor(v));
        CHECK((int)tg::ceil(v) == tg::iceil(v));
    }
}

TG_FUZZ_TEST(TypedGeometry, RoundRand)
{
    auto v = tg::uniform(rng, -10.0f, 10.0f);

    CHECK((int)tg::round(v) == tg::iround(v));
    CHECK((int)tg::floor(v) == tg::ifloor(v));
    CHECK((int)tg::ceil(v) == tg::iceil(v));
}