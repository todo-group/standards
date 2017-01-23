// Copyright (C) 2016 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <stat/accumulator.hpp>
#include <iostream>

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
              << ' ' << cumulant4.average() << ' ' << cumulant4.error() << std::endl;
  }
}
