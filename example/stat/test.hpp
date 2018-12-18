// Copyright (C) 2016-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <random>
#include <standards/power.hpp>
#include <standards/accumulator.hpp>
#include <standards/moment.hpp>

using standards::p2;
using standards::p4;

template<typename DIST, typename ENGINE, typename STAT>
void test1(DIST& dist, ENGINE& engine, STAT const& stat, unsigned long count) {
  std::cout << "[[statistics]]\n";
  standards::accumulator accum(stat.name());
  for (unsigned int n = 0; n < count; ++n) {
    double x = dist(engine);
    accum << x;
  }
  std::cout << "name = " << accum.name() << std::endl
            << "count = " << accum.count() << std::endl
            << "moment1 = " << accum.moment1()
            << " [exact: " << stat.moment1() << "]" << std::endl
            << "moment2 = " << accum.moment2()
            << " [exact: " << stat.moment2() << "]" << std::endl
            << "moment3 = " << accum.moment3()
            << " [exact: " << stat.moment3() << "]" << std::endl
            << "moment4 = " << accum.moment4()
            << " [exact: " << stat.moment4() << "]" << std::endl
            << "central_moment1 = " << accum.central_moment1()
            << " [exact: " << stat.central_moment1() << "]" << std::endl
            << "central_moment2 = " << accum.central_moment2()
            << " [exact: " << stat.central_moment2() << "]" << std::endl
            << "central_moment3 = " << accum.central_moment3()
            << " [exact: " << stat.central_moment3() << "]" << std::endl
            << "central_moment4 = " << accum.central_moment4()
            << " [exact: " << stat.central_moment4() << "]" << std::endl
            << "cumulant1 = " << accum.cumulant1()
            << " [exact: " << stat.cumulant1() << "]" << std::endl
            << "cumulant2 = " << accum.cumulant2()
            << " [exact: " << stat.cumulant2() << "]" << std::endl
            << "cumulant3 = " << accum.cumulant3()
            << " [exact: " << stat.cumulant3() << "]" << std::endl
            << "cumulant4 = " << accum.cumulant4()
            << " [exact: " << stat.cumulant4() << "]" << std::endl
            << "mean = " << accum.mean()
            << " [exact: " << stat.mean() << "]" << std::endl
            << "variance = " << accum.variance()
            << " [exact: " << stat.variance() << "]" << std::endl
            << "standard_deviation = " << accum.standard_deviation()
            << " [exact: " << stat.standard_deviation() << "]" << std::endl
            << "skewness = " << accum.skewness()
            << " [exact: " << stat.skewness() << "]" << std::endl
            << "kurtosis = " << accum.kurtosis()
            << " [exact: " << stat.kurtosis() << "]" << std::endl
            << "kurtosis excess = " << accum.kurtosis_excess()
            << " [exact: " << stat.kurtosis_excess() << "]" << std::endl
            << "average = " << accum.average()
            << " [exact: " << stat.mean() << "]" << std::endl
            << "error = " << accum.error()
            << " [exact: " << std::sqrt(stat.variance() / count) << "]" << std::endl;
}

template<typename DIST, typename ENGINE, typename STAT>
void test2(DIST& dist, ENGINE& engine, STAT const& stat, unsigned long count, unsigned long mmax) {
  std::cout << "[[bias test]]\n";
  for (unsigned long m = 4; m <= mmax; m *= 2) {
    standards::accumulator central_moment1, central_moment2, central_moment3, central_moment4,
      cumulant1, cumulant2, cumulant3, cumulant4;
    for (unsigned int n = 0; n < count; ++n) {
      standards::accumulator accum;
      for (unsigned int i = 0; i < m; ++i) { accum << dist(engine); }
      central_moment1 << (accum.central_moment1() - stat.central_moment1());
      central_moment2 << (accum.central_moment2() - stat.central_moment2());
      central_moment3 << (accum.central_moment3() - stat.central_moment3());
      central_moment4 << (accum.central_moment4() - stat.central_moment4());
      cumulant1 << (accum.cumulant1() - stat.cumulant1());
      cumulant2 << (accum.cumulant2() - stat.cumulant2());
      cumulant3 << (accum.cumulant3() - stat.cumulant3());
      cumulant4 << (accum.cumulant4() - stat.cumulant4());
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

template<typename DIST, typename ENGINE, typename STAT>
void test3(DIST& dist, ENGINE& engine, STAT const& stat, unsigned long count, unsigned long mmax) {
  std::cout << "[[check for equations in notes on unbiased fourth moment estimator]]\n"
            << "# n, Eqs.(1)-(7)\n";
  for (unsigned long m = 4; m <= mmax; m *= 2) {
    double p = m;
    standards::accumulator eq1, eq2, eq3, eq4, eq5, eq6, eq7;
    for (unsigned int n = 0; n < count; ++n) {
      double x0, x1;
      standards::accumulator accum;
      for (unsigned int i = 0; i < 1; ++i) { x0 = dist(engine); accum << x0; }
      for (unsigned int i = 1; i < 2; ++i) { x1 = dist(engine); accum << x1; }
      for (unsigned int i = 2; i < m; ++i) { accum << dist(engine); }
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
