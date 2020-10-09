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

#include <cmath>
#include <gtest/gtest.h>
#include <standards/power.hpp>

TEST(PowerTest, Power2) {
  double v = 0.2894;
  EXPECT_DOUBLE_EQ(std::pow(v, 2.0), standards::power2(v));
  EXPECT_DOUBLE_EQ(std::pow(v, 2.0), standards::p2(v));
  EXPECT_DOUBLE_EQ(std::pow(v, 2.0), standards::power2(std::complex<double>(v, 0)));
  EXPECT_DOUBLE_EQ(std::pow(v, 2.0), standards::p2(std::complex<double>(v, 0)));
  EXPECT_DOUBLE_EQ(std::pow(v, 2.0), standards::power2(std::complex<double>(0, v)));
  EXPECT_DOUBLE_EQ(std::pow(v, 2.0), standards::p2(std::complex<double>(0, v)));
}

TEST(PowerTest, Power3) {
  double v = 0.9482;
  EXPECT_DOUBLE_EQ(std::pow(v, 3.0), standards::power3(v));
  EXPECT_DOUBLE_EQ(std::pow(v, 3.0), standards::p3(v));
}

TEST(PowerTest, Power4) {
  double v = 0.1266;
  EXPECT_DOUBLE_EQ(std::pow(v, 4.0), standards::power4(v));
  EXPECT_DOUBLE_EQ(std::pow(v, 4.0), standards::p4(v));
  EXPECT_DOUBLE_EQ(std::pow(v, 4.0), standards::power4(std::complex<double>(v, 0)));
  EXPECT_DOUBLE_EQ(std::pow(v, 4.0), standards::p4(std::complex<double>(v, 0)));
  EXPECT_DOUBLE_EQ(std::pow(v, 4.0), standards::power4(std::complex<double>(0, v)));
  EXPECT_DOUBLE_EQ(std::pow(v, 4.0), standards::p4(std::complex<double>(0, v)));
}

TEST(PowerTest, Power6) {
  double v = 0.9266;
  EXPECT_DOUBLE_EQ(std::pow(v, 6.0), standards::power6(v));
  EXPECT_DOUBLE_EQ(std::pow(v, 6.0), standards::p6(v));
  EXPECT_DOUBLE_EQ(std::pow(v, 6.0), standards::power6(std::complex<double>(v, 0)));
  EXPECT_DOUBLE_EQ(std::pow(v, 6.0), standards::p6(std::complex<double>(v, 0)));
  EXPECT_DOUBLE_EQ(std::pow(v, 6.0), standards::power6(std::complex<double>(0, v)));
  EXPECT_DOUBLE_EQ(std::pow(v, 6.0), standards::p6(std::complex<double>(0, v)));
}
