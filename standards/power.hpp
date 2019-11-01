// Copyright (C) 1996-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef STANDARDS_POWER_HPP
#define STANDARDS_POWER_HPP

#include <complex>

namespace standards {

namespace detail {

template<typename T>
struct power_traits {
  typedef T power_type;
};
  
template<typename T>
struct power_traits<std::complex<T> > {
  typedef T power_type;
};

} // end namespace detail

//
// function power2 and p2
//

template<typename T>
typename detail::power_traits<T>::power_type power2(T const& t) { return t * t; }

template<typename T>
typename detail::power_traits<T>::power_type p2(T const& t) { return power2(t); }

template<typename T>
typename detail::power_traits<std::complex<T> >::power_type
power2(std::complex<T> const& t) { return power2(real(t)) + power2(imag(t)); }

template<typename T>
typename detail::power_traits<std::complex<T> >::power_type
p2(std::complex<T> const& t) { return p2(real(t)) + p2(imag(t)); }

//
// function power3 and p3
//

template<typename T>
typename detail::power_traits<T>::power_type power3(T const& t) { return t * t * t; }

template<typename T>
typename detail::power_traits<T>::power_type p3(T const& t) { return power3(t); }

//
// function power4 and p4
//

template<typename T>
typename detail::power_traits<T>::power_type power4(T const& t) { return power2(power2(t)); }

template<typename T>
typename detail::power_traits<T>::power_type p4(T const& t) { return power4(t); }

//
// function power6 and p6
//

template<typename T>
typename detail::power_traits<T>::power_type power6(T const& t) { return power3(power2(t)); }

template<typename T>
typename detail::power_traits<T>::power_type p6(T const& t) { return power6(t); }

} // end namespace standards

#endif // STANDARDS_POWER_HPP
