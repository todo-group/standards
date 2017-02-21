/*****************************************************************************
*
* Copyright (C) 2014-2016 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
*
* Distributed under the Boost Software License, Version 1.0. (See accompanying
* file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*
*****************************************************************************/

#include <iostream>
#include <optimize/nelder_mead.hpp>
#include <optimize/mccormick.hpp>

int main() {
  optimize::nelder_mead optimizer;
  std::vector<double> x(2);
  x[0] = 1;
  x[1] = -1;
  optimize::mccormick f;
  int iteration = optimizer.find_minimum(f, x);
  if (iteration < 0) {
    std::cerr << "Failed to converge\n";
  } else {
    x = optimizer.minarg();
    std::cout << iteration << ' ' << optimizer.minval()
              << " at [" << x[0] << "," << x[1] << "]\n";
  }
}
