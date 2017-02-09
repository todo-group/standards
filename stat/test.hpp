// Copyright (C) 2016 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <math/power.hpp>
#include <stat/accumulator.hpp>
#include <stat/moment.hpp>
#include <iostream>

using math::p2;
using math::p4;

template<typename DIST, typename RNG>
void test1(DIST const& dist, RNG& rng, unsigned long count) {
  std::cout << "[[statistics]]\n";
  stat::accumulator accum(dist.name());
  for (unsigned int n = 0; n < count; ++n) {
    double x = rng();
    accum << x;
  }
  std::cout << "name = " << accum.name() << std::endl
            << "count = " << accum.count() << std::endl
            << "moment1 = " << accum.moment1()
            << " [exact: " << dist.moment1() << "]" << std::endl
            << "moment2 = " << accum.moment2()
            << " [exact: " << dist.moment2() << "]" << std::endl
            << "moment3 = " << accum.moment3()
            << " [exact: " << dist.moment3() << "]" << std::endl
            << "moment4 = " << accum.moment4()
            << " [exact: " << dist.moment4() << "]" << std::endl
            << "central_moment1 = " << accum.central_moment1()
            << " [exact: " << dist.central_moment1() << "]" << std::endl
            << "central_moment2 = " << accum.central_moment2()
            << " [exact: " << dist.central_moment2() << "]" << std::endl
            << "central_moment3 = " << accum.central_moment3()
            << " [exact: " << dist.central_moment3() << "]" << std::endl
            << "central_moment4 = " << accum.central_moment4()
            << " [exact: " << dist.central_moment4() << "]" << std::endl
            << "cumulant1 = " << accum.cumulant1()
            << " [exact: " << dist.cumulant1() << "]" << std::endl
            << "cumulant2 = " << accum.cumulant2()
            << " [exact: " << dist.cumulant2() << "]" << std::endl
            << "cumulant3 = " << accum.cumulant3()
            << " [exact: " << dist.cumulant3() << "]" << std::endl
            << "cumulant4 = " << accum.cumulant4()
            << " [exact: " << dist.cumulant4() << "]" << std::endl
            << "mean = " << accum.mean()
            << " [exact: " << dist.mean() << "]" << std::endl
            << "variance = " << accum.variance()
            << " [exact: " << dist.variance() << "]" << std::endl
            << "standard_deviation = " << accum.standard_deviation()
            << " [exact: " << dist.standard_deviation() << "]" << std::endl
            << "skewness = " << accum.skewness()
            << " [exact: " << dist.skewness() << "]" << std::endl
            << "kurtosis = " << accum.kurtosis()
            << " [exact: " << dist.kurtosis() << "]" << std::endl
            << "kurtosis excess = " << accum.kurtosis_excess()
            << " [exact: " << dist.kurtosis_excess() << "]" << std::endl
            << "average = " << accum.average()
            << " [exact: " << dist.mean() << "]" << std::endl
            << "error = " << accum.error()
            << " [exact: " << std::sqrt(dist.variance() / count) << "]" << std::endl;
}

template<typename DIST, typename RNG>
void test2(DIST const& dist, RNG& rng, unsigned long count, unsigned long mmax) {
  std::cout << "[[bias test]]\n";
  for (unsigned long m = 4; m <= mmax; m *= 2) {
    stat::accumulator central_moment1, central_moment2, central_moment3, central_moment4,
      cumulant1, cumulant2, cumulant3, cumulant4;
    for (unsigned int n = 0; n < count; ++n) {
      stat::accumulator accum;
      for (unsigned int i = 0; i < m; ++i) { accum << rng(); }
      central_moment1 << (accum.central_moment1() - dist.central_moment1());
      central_moment2 << (accum.central_moment2() - dist.central_moment2());
      central_moment3 << (accum.central_moment3() - dist.central_moment3());
      central_moment4 << (accum.central_moment4() - dist.central_moment4());
      cumulant1 << (accum.cumulant1() - dist.cumulant1());
      cumulant2 << (accum.cumulant2() - dist.cumulant2());
      cumulant3 << (accum.cumulant3() - dist.cumulant3());
      cumulant4 << (accum.cumulant4() - dist.cumulant4());
    }
    std::cout << m
              << ' ' << central_moment1.average() << ' ' << central_moment1.error()
              << ' ' << central_moment2.average() << ' ' << central_moment2.error()
              << ' ' << central_moment3.average() << ' ' << central_moment3.error()
              << ' ' << central_moment4.average() << ' ' << central_moment4.error()
              << ' ' << cumulant1.average() << ' ' << cumulant1.error()
              << ' ' << cumulant2.average() << ' ' << cumulant2.error()
              << ' ' << cumulant3.average() << ' ' << cumulant3.error()
              << ' ' << cumulant4.average() << ' ' << cumulant4.error()
              << std::endl;
  }
}

template<typename DIST, typename RNG>
void test3(DIST const& dist, RNG& rng, unsigned long count, unsigned long mmax) {
  std::cout << "[[check for equations in notes on unbiased fourth moment estimator]]\n"
            << "# n, Eqs.(1)-(7)\n";
  for (unsigned long m = 4; m <= mmax; m *= 2) {
    double p = m;
    stat::accumulator eq1, eq2, eq3, eq4, eq5, eq6, eq7;
    for (unsigned int n = 0; n < count; ++n) {
      double x0, x1;
      stat::accumulator accum;
      for (unsigned int i = 0; i < 1; ++i) { x0 = rng(); accum << x0; }
      for (unsigned int i = 1; i < 2; ++i) { x1 = rng(); accum << x1; }
      for (unsigned int i = 2; i < m; ++i) { accum << rng(); }
      eq1 << x0 * x1 * p2(accum.average());
      eq2 << p2(x0) * x1 * accum.average();
      double s = p2(accum.moment2()) - 2 * p2(accum.moment1()) * accum.moment2() + p4(accum.moment1());
      double k = p4(x0 - accum.average());
      eq3 << s;
      eq4 << k;
      eq5 << p/((p-1)*(p-2)*(p-3)) * ((p2(p)-3*p+3)*s - (p-1)*k);
      eq6 << p/((p-1)*(p-2)*(p-3)) * ((p2(p)-2*p+3)*k - (6*p-9)*s);
      eq7 << p2(p)/((p-1)*(p-2)*(p-3)) * ((p+1)*k - 3*(p-1)*s);
    }
    std::cout << m
              << ' ' << eq1.average() << ' ' << eq1.error()
              << ' ' << eq2.average() << ' ' << eq2.error()
              << ' ' << eq3.average() << ' ' << eq3.error()
              << ' ' << eq4.average() << ' ' << eq4.error()
              << ' ' << eq5.average() << ' ' << eq5.error()
              << ' ' << eq6.average() << ' ' << eq6.error()
              << ' ' << eq7.average() << ' ' << eq7.error()
              << std::endl;
  }
}
