/*****************************************************************************
*
* Copyright (C) 2014-2016 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
*
* Distributed under the Boost Software License, Version 1.0. (See accompanying
* file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*
*****************************************************************************/

#include <iostream>
#include "nelder_mead.hpp"

double f(std::vector<double> const& x) {
  double r2 = (x[0]*x[0] + x[1]*x[1]);
  return -10*r2 + r2*r2 - 2*(x[0]+x[1]);
}

int main() {
  optimize::nelder_mead optimizer;
  std::vector<double> x(2);
  x[0] = -15.0;
  x[1] = 3.0;
  int iteration = optimizer.find_minimum(f, x);
  x = optimizer.minarg();
  std::cout << iteration << ' ' << optimizer.minval() << " at [" << x[0] << "," << x[1] << "]\n";
}
