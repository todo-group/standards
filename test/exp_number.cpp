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

  EXPECT_DOUBLE_EQ(xd, x);
  EXPECT_DOUBLE_EQ(yd, y);

  EXPECT_DOUBLE_EQ(xd + yd, x + y);
  EXPECT_DOUBLE_EQ(xd - yd, x - y);
  EXPECT_DOUBLE_EQ(xd * yd, x * y);
  EXPECT_DOUBLE_EQ(xd / yd, x / y);

  EXPECT_DOUBLE_EQ(xd + 1.2, x + 1.2);
  EXPECT_DOUBLE_EQ(xd - 1.2, x - 1.2);
  EXPECT_DOUBLE_EQ(xd - 3.5, x - 3.5);

  EXPECT_DOUBLE_EQ(xd * 1.2, x * 1.2);
  EXPECT_DOUBLE_EQ(xd * 2, x * 2);
  EXPECT_DOUBLE_EQ(xd / 1.2, x / 1.2);
  EXPECT_DOUBLE_EQ(xd / 3, x / 3);

  EXPECT_DOUBLE_EQ(3.5 + xd, 3.5 + x);
  EXPECT_DOUBLE_EQ(3 + xd, 3 + x);
  EXPECT_DOUBLE_EQ(3.5 - xd, 3.5 - x);
  EXPECT_DOUBLE_EQ(5 - xd, 5 - x);

  EXPECT_DOUBLE_EQ(3.5 * xd, 3.5 * x);
  EXPECT_DOUBLE_EQ(3 * xd, 3 * x);
  EXPECT_DOUBLE_EQ(3.5 / xd, 3.5 / x);
  EXPECT_DOUBLE_EQ(5 / xd, 5 / x);

  EXPECT_TRUE(x > 1);
  EXPECT_TRUE(x >= 1);
  EXPECT_FALSE(x == 1);
  EXPECT_FALSE(x <= 1);
  EXPECT_FALSE(x < 1);
}

TEST(ExpNumberTest, ExpNumber2) {
  double ve = 10000;
  double we = 9999;
  
  auto v = standards::exp_value(ve);
  auto w = standards::exp_value(we);

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

  EXPECT_DOUBLE_EQ(pd, p);
  EXPECT_DOUBLE_EQ(-pd, -p);
  EXPECT_DOUBLE_EQ(pd - pd, p - p);

  EXPECT_DOUBLE_EQ(xd + pd, x + p);
  EXPECT_DOUBLE_EQ(xd - pd, x - p);
  EXPECT_DOUBLE_EQ(xd * pd, x * p);
  EXPECT_DOUBLE_EQ(xd / pd, x / p);
  
  EXPECT_DOUBLE_EQ(yd + pd, y + p);
  EXPECT_DOUBLE_EQ(yd - pd, y - p);
  EXPECT_DOUBLE_EQ(yd * pd, y * p);
  EXPECT_DOUBLE_EQ(yd / pd, y / p);
  
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

TEST(ExpNumberTest, ExpNumber4) {
  EXPECT_DOUBLE_EQ(0.0, standards::exp_double::zero());
  EXPECT_DOUBLE_EQ(1.0, standards::exp_double::unity());
}

