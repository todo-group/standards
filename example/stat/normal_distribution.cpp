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

#include <iostream>
#include <random>
#include <standards/normal_distribution.hpp>
#include "test.hpp"

int main() {
  std::size_t count = 65536;
  std::size_t mmax = 1024;
  std::size_t seed = 12345;

  double mu = 2.0;
  double sigma = 1.5;

  std::cout << "[test for normal distribution]\n";

  std::normal_distribution<> dist(mu, sigma);
  std::mt19937 engine(seed);
  standards::normal_distribution stat(mu, sigma);

  test1(dist, engine, stat, count);
  test2(dist, engine, stat, count, mmax);
  test3(dist, engine, stat, count, mmax);

  return 0;
}
