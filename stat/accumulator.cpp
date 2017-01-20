// Copyright (C) 2016 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include "accumulator.hpp"
#include <iostream>
#include <boost/math/distributions.hpp>

int main() {
#ifndef BOOST_NO_EXCEPTIONS
try {
#endif

  unsigned long count = 10000;
  
  std::cout << "[[test for N(1.2,3.5)]]\n";
  boost::math::normal_distribution<double> normal(1.2, 3.5);
  statistics::accumulator accum("N(1.2,3.5)");
  for (unsigned int n = 0; n < count; ++n) accum << normal();
  std::cout << "name = " << accum.name() << std::endl
            << "count = " << accum.count() << std::endl
            << "moment1 = " << accum.moment1() << std::endl
            << "moment2 = " << accum.moment2() << std::endl
            << "moment3 = " << accum.moment3() << std::endl
            << "moment4 = " << accum.moment4() << std::endl
            << "cumulant1 = " << accum.cumulant1() << std::endl
            << "cumulant2 = " << accum.cumulant2() << std::endl
            << "cumulant3 = " << accum.cumulant3() << std::endl
            << "cumulant4 = " << accum.cumulant4() << std::endl
            << "mean = " << accum.mean() << std::endl
            << "variance = " << accum.variance() << std::endl
            << "standard_deviation = " << accum.standard_deviation() << std::endl
            << "skewness = " << accum.skewness() << std::endl
            << "kurtosis = " << accum.kurtosis() << std::endl
            << "average = " << accum.average() << std::endl
            << "error = " << accum.error() << std::endl;

#ifndef BOOST_NO_EXCEPTIONS
}
catch (std::exception& exc) {
  std::cerr << exc.what() << "\n";
  return -1;
}
catch (...) {
  std::cerr << "Fatal Error: Unknown Exception!\n";
  return -2;
}
#endif
  return 0;
}
