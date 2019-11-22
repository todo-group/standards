// Copyright (C) 2016-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <random>
#include <standards/normal_distribution.hpp>
#include "test.hpp"

int main() {
  std::size_t count = 65536;
  std::size_t mmax = 1024;
  std::size_t seed = 12345;

  double mu = 2.0;
  double sigma = 1.5;

  std::cout << "[test for normal distribution]\n";

  std::normal_distribution<> dist(mu, sigma);
  std::mt19937 engine(seed);
  standards::normal_distribution stat(mu, sigma);

  test1(dist, engine, stat, count);
  test2(dist, engine, stat, count, mmax);
  test3(dist, engine, stat, count, mmax);

  return 0;
}
