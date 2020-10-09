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
#include <standards/exp_number.hpp>

TEST(ExpNumberTest, ExpNumber1) {
  double xd = 2;
  double yd = 3;
  
  standards::exp_double x = xd;
  standards::exp_double y = yd;

  EXPECT_DOUBLE_EQ(xd, static_cast<double>(x));
  EXPECT_DOUBLE_EQ(yd, static_cast<double>(y));

  EXPECT_DOUBLE_EQ(xd + yd, static_cast<double>(x + y));
  EXPECT_DOUBLE_EQ(xd - yd, static_cast<double>(x - y));
  EXPECT_DOUBLE_EQ(xd * yd, static_cast<double>(x * y));
  EXPECT_DOUBLE_EQ(xd / yd, static_cast<double>(x / y));

  EXPECT_DOUBLE_EQ(xd + 1.2, static_cast<double>(x + 1.2));
  EXPECT_DOUBLE_EQ(xd - 1.2, static_cast<double>(x - 1.2));
  EXPECT_DOUBLE_EQ(xd - 3.5, static_cast<double>(x - 3.5));

  EXPECT_DOUBLE_EQ(xd * 1.2, static_cast<double>(x * 1.2));
  EXPECT_DOUBLE_EQ(xd * 2, static_cast<double>(x * 2));
  EXPECT_DOUBLE_EQ(xd / 1.2, static_cast<double>(x / 1.2));
  EXPECT_DOUBLE_EQ(xd / 3, static_cast<double>(x / 3));

  EXPECT_DOUBLE_EQ(3.5 + xd, static_cast<double>(3.5 + x));
  EXPECT_DOUBLE_EQ(3 + xd, static_cast<double>(3 + x));
  EXPECT_DOUBLE_EQ(3.5 - xd, static_cast<double>(3.5 - x));
  EXPECT_DOUBLE_EQ(5 - xd, static_cast<double>(5 - x));

  EXPECT_DOUBLE_EQ(3.5 * xd, static_cast<double>(3.5 * x));
  EXPECT_DOUBLE_EQ(3 * xd, static_cast<double>(3 * x));
  EXPECT_DOUBLE_EQ(3.5 / xd, static_cast<double>(3.5 / x));
  EXPECT_DOUBLE_EQ(5 / xd, static_cast<double>(5 / x));

  EXPECT_TRUE(x > 1);
  EXPECT_TRUE(x >= 1);
  EXPECT_FALSE(x == 1);
  EXPECT_FALSE(x <= 1);
  EXPECT_FALSE(x < 1);
}

TEST(ExpNumberTest, ExpNumber2) {
  double ve = 10000;
  double we = 9999;
  
  standards::exp_double v = standards::exp_value(ve);
  standards::exp_double w = standards::exp_value(we);

  EXPECT_DOUBLE_EQ(ve, log(v));
  EXPECT_DOUBLE_EQ(we, log(w));
  EXPECT_DOUBLE_EQ(ve * 3, log(pow(v, 3)));
  EXPECT_DOUBLE_EQ(ve + we, log(v * w));
  EXPECT_DOUBLE_EQ(ve - we, log(v / w));

  EXPECT_TRUE(v > w);
  EXPECT_FALSE(v < w);
  EXPECT_TRUE(v >= w);
  EXPECT_FALSE(v <= w);
  EXPECT_TRUE(v == v);
  EXPECT_FALSE(v == w);
  EXPECT_TRUE(v >= v);
  EXPECT_TRUE(v <= v);
  EXPECT_FALSE(v > v);
  EXPECT_FALSE(v < v);

}

TEST(ExpNumberTest, ExpNumber3) {
  double xd = 2;
  double yd = 3;
  double pd = -2.5;
  
  standards::exp_double x = xd;
  standards::exp_double y = yd;
  standards::exp_double p = pd;

  EXPECT_DOUBLE_EQ(pd, static_cast<double>(p));
  EXPECT_DOUBLE_EQ(-pd, static_cast<double>(-p));
  EXPECT_DOUBLE_EQ(pd - pd, static_cast<double>(p - p));

  EXPECT_DOUBLE_EQ(xd + pd, static_cast<double>(x + p));
  EXPECT_DOUBLE_EQ(xd - pd, static_cast<double>(x - p));
  EXPECT_DOUBLE_EQ(xd * pd, static_cast<double>(x * p));
  EXPECT_DOUBLE_EQ(xd / pd, static_cast<double>(x / p));
  
  EXPECT_DOUBLE_EQ(yd + pd, static_cast<double>(y + p));
  EXPECT_DOUBLE_EQ(yd - pd, static_cast<double>(y - p));
  EXPECT_DOUBLE_EQ(yd * pd, static_cast<double>(y * p));
  EXPECT_DOUBLE_EQ(yd / pd, static_cast<double>(y / p));
  
  EXPECT_TRUE(x > p);
  EXPECT_TRUE(x >= p);
  EXPECT_FALSE(x == p);
  EXPECT_FALSE(x <= p);
  EXPECT_FALSE(x < p);
  EXPECT_TRUE(y > p);
  EXPECT_TRUE(y >= p);
  EXPECT_FALSE(y == p);
  EXPECT_FALSE(y <= p);
  EXPECT_FALSE(y < p);

  EXPECT_TRUE(p == p);
  EXPECT_FALSE(p == -p);
}
