// Copyright (C) 2016-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <random>
#include <standards/bernoulli_distribution.hpp>
#include "test.hpp"

int main() {
  std::size_t count = 65536;
  std::size_t mmax = 1024;
  std::size_t seed = 12345;

  double p = 0.75;

  std::cout << "[test for Bernoulli distribution]\n";

  std::bernoulli_distribution dist(p);
  std::mt19937 engine(seed);
  standards::bernoulli_distribution stat(p);

  test1(dist, engine, stat, count);
  test2(dist, engine, stat, count, mmax);
  test3(dist, engine, stat, count, mmax);

  return 0;
}
