// Copyright (C) 2016-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 
#include <cmath>
#include <iostream>
#include <boost/math/constants/constants.hpp>
#include <standards/simpson.hpp>
 
double func(double x) { return std::sin(x); }

constexpr double pi = boost::math::constants::pi<double>();

int main() {
  std::cout << "# n value error\n";
  for (unsigned int n = 2; n <= 16; n += 2) {
    double val = standards::simpson_1d(func, 0, pi, n);
    std::cout << n << ' ' << val << ' ' << (val - 2) << std::endl;
  }
}
