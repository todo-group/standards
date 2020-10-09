/*
   Copyright (C) 2015-2020 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

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
