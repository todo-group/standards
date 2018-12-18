// Copyright (C) 2016-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <boost/random.hpp>
#include <standards/accumulator.hpp>
#include <standards/bernoulli_distribution.hpp>
#include "test.hpp"

int main() {
  unsigned long count = 65536;
  unsigned long mmax = 1024;
  unsigned long seed = 12345;

  double p = 0.75;

  std::cout << "[test for normal distribution]\n";

  boost::mt19937 engine(seed);
  boost::variate_generator<boost::mt19937&, boost::bernoulli_distribution<> >
    rng(engine, boost::bernoulli_distribution<>(p));

  standards::bernoulli_distribution dist(p);

  std::cout << "[[series of random numbers]]\n";
  for (int i = 0; i < 4; ++i) std::cout << rng() << std::endl;

  test1(dist, rng, count);
  test2(dist, rng, count, mmax);
  test3(dist, rng, count, mmax);

  return 0;
}
