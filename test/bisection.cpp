/*****************************************************************************
*
* Copyright (C) 2014-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
*
* Distributed under the Boost Software License, Version 1.0. (See accompanying
* file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*
*****************************************************************************/

#include <gtest/gtest.h>
#include <standards/bisection.hpp>

double f(double x) { return 3*x*x-5*x+1; }

TEST(BisectionTest, Bisection1) {
  standards::bisection optimizer;
  int iteration;
  iteration = optimizer.find_zero(f, 0, 1);
  EXPECT_TRUE(iteration > 0);
  EXPECT_DOUBLE_EQ((5 - std::sqrt(13)) / 6, optimizer.zero());
}

TEST(BisectionTest, Bisection2) {
  standards::bisection optimizer;
  int iteration;
  iteration = optimizer.find_zero(f, 1, 10);
  EXPECT_TRUE(iteration > 0);
  EXPECT_DOUBLE_EQ((5 + std::sqrt(13)) / 6, optimizer.zero());
}

TEST(BisectionTest, Bisection3) {
  standards::bisection optimizer;
  int iteration;
  iteration = optimizer.find_zero(f, 10, 1);
  EXPECT_TRUE(iteration > 0);
  EXPECT_DOUBLE_EQ((5 + std::sqrt(13)) / 6, optimizer.zero());
}

TEST(BisectionTest, Bisection4) {
  standards::bisection optimizer;
  int iteration;
  iteration = optimizer.find_zero(f, 3, 4);
  EXPECT_FALSE(iteration > 0);
}
