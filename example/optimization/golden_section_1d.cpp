/*****************************************************************************
*
* Copyright (C) 2014-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
*
* Distributed under the Boost Software License, Version 1.0. (See accompanying
* file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*
*****************************************************************************/

#include <iostream>
#include <standards/golden_section.hpp>

double f(double x) { return 3.293*x*x-5.33*x+3.1; }

int main() {
  standards::golden_section optimizer;
  int iteration = optimizer.find_minimum(f, 0, 1);
  if (iteration < 0) {
    std::cout << "Initial enclosure failure\n";
  } else {
    std::cout << iteration << ' ' << optimizer.minarg() << ' ' << optimizer.minval() << std::endl;
  }
}
