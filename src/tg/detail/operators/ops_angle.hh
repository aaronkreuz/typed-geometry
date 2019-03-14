#pragma once

#include "../../types/angle.hh"
#include "../scalar_traits.hh"

namespace tg
{
template <class A, class B, class R = promoted_scalar<A, B>>
constexpr angle<R> operator+(angle<A> a, angle<B> b)
{
    return radians(a.radians() + b.radians());
}
template <class A, class B, class R = promoted_scalar<A, B>>
constexpr angle<R> operator-(angle<A> a, angle<B> b)
{
    return radians(a.radians() - b.radians());
}

template <class A, class B, class R = promoted_scalar<A, B>>
constexpr angle<R> operator*(angle<A> a, B b)
{
    return radians(a.radians() * b);
}
template <class A, class B, class R = promoted_scalar<A, B>>
constexpr angle<R> operator/(angle<A> a, B b)
{
    return radians(a.radians() / b);
}

template <class A, class B, class R = promoted_scalar<A, B>>
constexpr angle<R> operator*(A a, angle<B> b)
{
    return radians(a * b.radians());
}
} // namespace tg
