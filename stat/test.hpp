// Copyright (C) 2016 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <stat/accumulator.hpp>
#include <iostream>

struct test {
  template<typename DIST, typename RNG>
  static void run(DIST const& dist, RNG& rng, unsigned long count, unsigned long mmax) {
    std::cout << "[[series of random numbers]]\n";
    stat::accumulator accum;
    for (unsigned int n = 0; n < count; ++n) {
      double x = rng();
      std::cout << x << std::endl;
      accum << x;
    }
    std::cout << "[[statistics]]\n";
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
              << "average = " << accum.average()
              << " [exact: " << dist.mean() << "]" << std::endl
              << "error = " << accum.error()
              << " [exact: " << std::sqrt(dist.variance() / count) << "]" << std::endl;
    
    std::cout << "[[bias test]]\n";
    for (unsigned long m = 4; m <= mmax; m *= 2) {
      stat::accumulator cumulant1_s, cumulant2_s, cumulant3_s, cumulant4_s,
        cumulant1, cumulant2, cumulant3, cumulant4;
      for (unsigned int n = 0; n < count; ++n) {
        stat::accumulator accum;
        for (unsigned int i = 0; i < m; ++i) accum << rng();
        cumulant1_s << (accum.cumulant1_s() - dist.cumulant1());
        cumulant2_s << (accum.cumulant2_s() - dist.cumulant2());
        cumulant3_s << (accum.cumulant3_s() - dist.cumulant3());
        cumulant4_s << (accum.cumulant4_s() - dist.cumulant4());
        cumulant1 << (accum.cumulant1() - dist.cumulant1());
        cumulant2 << (accum.cumulant2() - dist.cumulant2());
        cumulant3 << (accum.cumulant3() - dist.cumulant3());
        cumulant4 << (accum.cumulant4() - dist.cumulant4());
      }
      std::cout << m
                << ' ' << cumulant1_s.average() << ' ' << cumulant1_s.error()
                << ' ' << cumulant2_s.average() << ' ' << cumulant2_s.error()
                << ' ' << cumulant3_s.average() << ' ' << cumulant3_s.error()
                << ' ' << cumulant4_s.average() << ' ' << cumulant4_s.error()
                << ' ' << cumulant1.average() << ' ' << cumulant1.error()
                << ' ' << cumulant2.average() << ' ' << cumulant2.error()
                << ' ' << cumulant3.average() << ' ' << cumulant3.error()
                << ' ' << cumulant4.average() << ' ' << cumulant4.error() << std::endl;
    }
  }
};
