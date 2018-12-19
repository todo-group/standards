// Copyright (C) 2016-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cmath>
#include <gtest/gtest.h>
#include <standards/simpson.hpp>

double func1(double x) { return std::sin(x); }

double func2(double x, double y) { return std::sin(x) * std::sin(y); }

TEST(SimpsonTest, Simpson1D) {
  EXPECT_NEAR(2.0, standards::simpson_1d(func1, 0, M_PI, 16), 1e-5);
}

TEST(SimpsonTest, Simpson2D) {
  EXPECT_NEAR(4.0, standards::simpson_2d(func2, 0, 0, M_PI, M_PI, 16, 16), 1e-5);
}
