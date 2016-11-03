/*****************************************************************************
*
* Copyright (C) 2014-2016 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
*
* Distributed under the Boost Software License, Version 1.0. (See accompanying
* file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*
*****************************************************************************/

#include <iostream>
#include "golden_section.hpp"

double f(double x) { return 3.293*x*x-5.33*x+3.1; }

int main() {
  optimize::golden_section optimizer;
  int iteration;
  iteration = optimizer.find_minimum(f, 0, 1);
  std::cout << iteration << ' ' << optimizer.minarg() << ' ' << optimizer.minval() << std::endl;
  iteration = optimizer.find_minimum(f, 1, 2);
  std::cout << iteration << ' ' << optimizer.minarg() << ' ' << optimizer.minval() << std::endl;
  iteration = optimizer.find_minimum(f, 2, 3.9034);
  std::cout << iteration << ' ' << optimizer.minarg() << ' ' << optimizer.minval() << std::endl;
}
