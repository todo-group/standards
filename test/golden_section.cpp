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
