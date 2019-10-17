#pragma once

#include <typed-geometry/functions/mix.hh>
#include <typed-geometry/types/array.hh>

namespace tg
{
// fwd
template <int Degree, class ControlPointT>
struct bezier;
// namespace detail
//{
// template <int Degree, class ControlPointT, class ScalarT>
// TG_NODISCARD constexpr ControlPointT deCastlejau(bezier<Degree, ControlPointT> const& bezier, ScalarT const& t);
//}

namespace detail
{
struct default_mix_t
{
    template <class A, class T>
    static constexpr auto mix(A const& a0, A const& a1, T const& t) -> decltype(mix(a0, a1, t))
    {
        return mix(a0, a1, t);
    }
};

template <int Degree, class ControlPointT, class ScalarT, class MixT = default_mix_t>
TG_NODISCARD constexpr auto deCastlejau(bezier<Degree, ControlPointT> const& bezier, ScalarT const& t)
{
    using T = std::decay_t<decltype(MixT::mix(std::declval<ControlPointT>(), std::declval<ControlPointT>(), t))>;

    if constexpr (Degree < 0)
        return T{};
    else if constexpr (Degree == 0)
        return T(bezier.p[0]);
    else
    {
        T controlpoints[Degree + 1];
        for (auto i = 0; i <= Degree; ++i)
            controlpoints[i] = T(bezier.p[i]);
        for (auto d = Degree; d > 1; --d)
            for (auto i = 0; i < d; ++i)
                controlpoints[i] = MixT::mix(controlpoints[i], controlpoints[i + 1], t);
        return controlpoints[0];
    }
}
}

template <int Degree, class ControlPointT>
struct bezier
{
    array<ControlPointT, Degree + 1> control_points;

    //    template <int OtherDegree>
    //    constexpr explicit bezier(bezier<OtherDegree, ControlPointT> const& /*other*/)
    //    {
    //        static_assert(Degree >= OtherDegree, "must have at least the same degree");
    //        // todo
    //    }

    template <class ScalarT>
    TG_NODISCARD constexpr ControlPointT operator()(ScalarT const& t) const
    {
        return detail::deCastlejau(*this, t);
    }

    template <class ScalarT>
    TG_NODISCARD constexpr ControlPointT operator[](ScalarT const& t) const
    {
        return detail::deCastlejau(*this, t);
    }
};

template <class ControlPointT, class... ControlPoints>
TG_NODISCARD constexpr auto make_bezier(ControlPointT const& p0, ControlPoints const&... pts) -> bezier<1 + sizeof...(ControlPoints), ControlPointT>
{
    static_assert((std::is_convertible_v<ControlPoints, ControlPointT> && ...), "incompatible control points");
    return {{{p0, pts...}}};
}

template <int Degree, class ControlPointT>
TG_NODISCARD constexpr bezier<Degree - 1, ControlPointT> derivative(bezier<Degree, ControlPointT> const& c)
{
    bezier<Degree - 1, ControlPointT> res;
    for (auto i = 0; i < Degree; ++i)
        res.control_points[i] = Degree * (c.control_points[i] + c.control_points[i + 1]);
    return res;
}

template <int Degree, class ControlPointT>
TG_NODISCARD constexpr bezier<Degree + 1, ControlPointT> elevate(bezier<Degree, ControlPointT> const& c)
{
    auto const new_degree = Degree + 1;
    bezier<Degree + 1, ControlPointT> res;

    res.control_points[0] = c.control_points[0];
    for (auto i = 1; i < new_degree; ++i)
        res.control_points[i] = ((new_degree - i) * c.control_points[i] + i * c.control_points[i - 1]) / new_degree;

    return res;
}

}
