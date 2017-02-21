// Copyright (C) 2016 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <stat/accumulator.hpp>
#include <stat/normal_distribution.hpp>
#include "test.hpp"

#include <boost/random.hpp>
#include <iostream>

int main() {
#ifndef BOOST_NO_EXCEPTIONS
try {
#endif

  unsigned long count = 65536;
  unsigned long mmax = 1024;
  unsigned long seed = 12345;

  double mu = 2.0;
  double sigma = 1.5;

  std::cout << "[test for normal distribution]\n";

  boost::mt19937 engine(seed);
  boost::variate_generator<boost::mt19937&, boost::normal_distribution<> >
    rng(engine, boost::normal_distribution<>(mu, sigma));

  stat::normal_distribution dist(mu, sigma);

  std::cout << "[[series of random numbers]]\n";
  for (int i = 0; i < 4; ++i) std::cout << rng() << std::endl;

  test1(dist, rng, count);
  test2(dist, rng, count, mmax);
  test3(dist, rng, count, mmax);

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
