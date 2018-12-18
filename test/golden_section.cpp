/*****************************************************************************
*
* Copyright (C) 2014-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
*
* Distributed under the Boost Software License, Version 1.0. (See accompanying
* file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*
*****************************************************************************/

#include <gtest/gtest.h>
#include <standards/golden_section.hpp>

double f(double x) { return 3*x*x-5*x+1; }

TEST(GoldenSectionTest, GoldenSection1) {
  standards::golden_section optimizer;
  int iteration = optimizer.find_minimum(f, 0, 1);
  EXPECT_TRUE(iteration > 0);
  EXPECT_NEAR(5.0 / 6.0, optimizer.minarg(), 1e-8);
  EXPECT_DOUBLE_EQ(-13.0 / 12.0, optimizer.minval());
}

TEST(GoldenSectionTest, GoldenSection2) {
  standards::golden_section optimizer;
  int iteration = optimizer.find_minimum(f, 1, 0);
  EXPECT_TRUE(iteration > 0);
  EXPECT_NEAR(5.0 / 6.0, optimizer.minarg(), 1e-8);
  EXPECT_DOUBLE_EQ(-13.0 / 12.0, optimizer.minval());
}

TEST(GoldenSectionTest, GoldenSection3) {
  standards::golden_section optimizer;
  int iteration = optimizer.find_minimum(f, 1, 2);
  EXPECT_FALSE(iteration > 0);
}
