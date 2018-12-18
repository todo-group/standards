/*****************************************************************************
*
* Copyright (C) 2014-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
*
* Distributed under the Boost Software License, Version 1.0. (See accompanying
* file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*
*****************************************************************************/

#include <gtest/gtest.h>
#include <standards/nelder_mead.hpp>
#include <standards/mccormick.hpp>

TEST(NelderMeadTest, NelderMead1) {
  standards::nelder_mead optimizer;
  std::vector<double> x(2);
  x[0] = 1;
  x[1] = -1;
  standards::mccormick f;
  int iteration = optimizer.find_minimum(f, x);
  EXPECT_TRUE(iteration > 0);
  EXPECT_NEAR(-1.91322, optimizer.minval(), 1e-5);
  x = optimizer.minarg();
  EXPECT_NEAR(-0.547198, x[0], 1e-5);
  EXPECT_NEAR(-1.5472, x[1], 1e-5);
}
