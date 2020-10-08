/*****************************************************************************
*
* Copyright (C) 2014-2020 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
*
* Distributed under the Boost Software License, Version 1.0. (See accompanying
* file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*
*****************************************************************************/

#include <gtest/gtest.h>
#include <standards/newton.hpp>

struct my_value {
  my_value(double f, double df) : f_(f), df_(df) {}
  double derivative(std::size_t i) const { return (i == 0) ? f_ : df_; }
  double f_, df_;
};
  
TEST(NewtonTest, Newton1) {
  auto r = standards::newton_1d([](double x) { return my_value(x*x-2, 2*x); }, 1.0);
  EXPECT_DOUBLE_EQ(std::sqrt(2.0), r.first);
  EXPECT_TRUE(r.second > 0);
}

TEST(NewtonTest, Newton2) {
  auto r = standards::newton_1d([](double x) { return my_value(x*x*x-2, 3*x*x); }, 1.0);
  EXPECT_DOUBLE_EQ(std::pow(2.0, 1/3.0), r.first);
  EXPECT_TRUE(r.second > 0);
}
