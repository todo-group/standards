/*
   Copyright (C) 2015-2021 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>

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

#include <random>
#include <gtest/gtest.h>
#include <standards/polyak_ruppert.hpp>

double f(double x, double r) { return 2 * std::tanh(x) + 0.1 * r; }

TEST(polyak_ruppert, polyak_ruppert_1) {
  standards::polyak_ruppert optimizer;
  std::mt19937 engine(1234);
  std::normal_distribution<> dist(0, 1);
  double x = 1.0;
  for (int i = 0; i < 100; ++i) {
    double v = f(x, dist(engine));
    x = optimizer.update(x, f(x, dist(engine)));
    std::cout << i << ' ' << x << ' ' << optimizer.solution() << ' ' << v << std::endl;
  }
  EXPECT_TRUE(std::abs(optimizer.solution()) < 0.01);
}
