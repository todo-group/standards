// Copyright (C) 2016 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <stat/accumulator.hpp>

#include <iostream>
#include <boost/random.hpp>

int main() {
#ifndef BOOST_NO_EXCEPTIONS
try {
#endif

  unsigned long count = 65536;

  std::cout << "[test for +1/-1 with p/(1-p) and p=0.6]\n";

  double p = 0.6;
  unsigned long seed = 12345;
  boost::mt19937 engine(seed);
  boost::variate_generator<boost::mt19937&, boost::uniform_real<> >
    rng(engine, boost::uniform_real<>());
  
  std::cout << "[[series of random numbers]]\n";
  statistics::accumulator accum("Binimoal");
  for (unsigned int n = 0; n < count; ++n) {
    double x = (rng() > p) ? -1.0 : 1.0;
    std::cout << x << std::endl;
    accum << x;
  }
  std::cout << "[[statistic]]\n";
  std::cout << "name = " << accum.name() << std::endl
            << "count = " << accum.count() << std::endl
            << "moment1 = " << accum.moment1()
            << " [exact: (2p-1) = " << 2*p-1 << "]" << std::endl
            << "moment2 = " << accum.moment2()
            << " [exact: 1]" << std::endl
            << "moment3 = " << accum.moment3()
            << " [exact: (2p-1) = " << 2*p-1 << "]" << std::endl
            << "moment4 = " << accum.moment4()
            << " [exact: 1]" << std::endl
            << "cumulant1 = " << accum.cumulant1()
            << " [exact: (2p-1) = " << 2*p-1 << "]" << std::endl
            << "cumulant2 = " << accum.cumulant2()
            << " [exact: 4p(1-p) = " << 4*p*(1-p) << "]" << std::endl
            << "cumulant3 = " << accum.cumulant3()
            << " [exact: (2p-1)(4p^2-4p-1) = " << (2*p-1)*(4*p*p-4*p-1) << "]" << std::endl
            << "cumulant4 = " << accum.cumulant4()
            << " [exact: 16p(1-p)(6p^2-6p+1) = " << 16*p*(1-p)*(6*p*p-6*p+1) << "]" << std::endl
            << "mean = " << accum.mean()
            << " [exact: (2p-1) = " << 2*p-1 << "]"<< std::endl
            << "variance = " << accum.variance()
            << " [exact: 4p(1-p) = " << 4*p*(1-p) << "]" << std::endl
            << "standard_deviation = " << accum.standard_deviation()
            << " [exact: sqrt(4p(1-p)) = " << std::sqrt(4*p*(1-p)) << "]" << std::endl
            << "skewness = " << accum.skewness()
            << " [exact: (2p-1)(4p^2-4p-1)/(4p(1-p))^1.5 = " << (2*p-1)*(4*p*p-4*p-1)/std::pow(4*p*(1-p),1.5) << "]" << std::endl
            << "kurtosis = " << accum.kurtosis()
            << " [exact: 16p(1-p)(6p^2-6p+1)/(4p(1-p))^2 = " << 16*p*(1-p)*(6*p*p-6*p+1)/math::power4(std::sqrt(4*p*(1-p))) << "]" << std::endl
            << "average = " << accum.average()
            << " [exact: (2p-1) = " << 2*p-1 << "]" << std::endl
            << "error = " << accum.error()
            << " [exact: sqrt(4p(1-p)/(n-1)) = " << std::sqrt(4*p*(1-p)/(count-1)) << "]" << std::endl;

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
