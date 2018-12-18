// Copyright (C) 2016-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

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
