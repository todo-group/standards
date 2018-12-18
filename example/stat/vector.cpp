// Copyright (C) 2016-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/random.hpp>
#include <standards/accumulator.hpp>

int main() {
  unsigned long np = 4;
  unsigned long count = 65536;
  unsigned long seed = 12345;

  double mu = 2.0;
  double sigma = 1.5;

  std::cout << "[test for vector of accumulators]\n";

  boost::mt19937 engine(seed);
  boost::variate_generator<boost::mt19937&, boost::normal_distribution<> >
    rng(engine, boost::normal_distribution<>(mu, sigma));

  std::vector<standards::accumulator> accum(np);
  for (int p = 0; p < np; ++p) {
    accum[p].set_name("accum[" + boost::lexical_cast<std::string>(p) + "]");
  }
  for (int i = 0; i < count; ++i) {
    for (int p = 0; p < np; ++p) accum[p] << rng();
  }
  for (int p = 0; p < np; ++p) {
    std::cout << accum[p] << std::endl;
  }

  return 0;
}
