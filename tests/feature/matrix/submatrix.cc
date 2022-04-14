#include <nexus/test.hh>

TG_FUZZ_TEST(TypedGeometry, Submatrix)
{
    {
        auto mat = random_matrix<2>(rng);
        auto copy = tg::submatrix<0, 0, 2, 2>(mat);

        CHECK(copy == approx(mat));

        {
            auto sub = tg::submatrix<0, 0, 1, 2>(mat);
            CHECK(sub[0] == approx(mat[0]));
        }

        {
            auto sub = tg::submatrix<1, 0, 1, 2>(mat);
            CHECK(sub[0] == approx(mat[1]));
        }
    }

    {
        auto mat = random_matrix<3>(rng);
        auto copy = tg::submatrix<0, 0, 3, 3>(mat);

        CHECK(copy == approx(mat));

        {
            auto sub = tg::submatrix<0, 0, 1, 3>(mat);
            CHECK(sub[0] == approx(mat[0]));
        }

        {
            auto sub = tg::submatrix<1, 0, 1, 3>(mat);
            CHECK(sub[0] == approx(mat[1]));
        }

        {
            auto sub = tg::submatrix<2, 0, 1, 3>(mat);
            CHECK(sub[0] == approx(mat[2]));
        }
    }
}