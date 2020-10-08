// Copyright (C) 2016-2020 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 
#include <cmath>
#include <iostream>
#include <standards/newton.hpp>
 
// calculate sqrt(2)

struct my_value {
  my_value(double f, double df) : f_(f), df_(df) {}
  double derivative(std::size_t i) const { return (i == 0) ? f_ : df_; }
  double f_, df_;
};

int main() {
  auto r = standards::newton_1d([](double x) { return my_value(x*x-2, 2*x); }, 1.0);
  std::cout << "sqrt(2) = " << r.first << std::endl;
}
