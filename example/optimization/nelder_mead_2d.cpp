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
#include <standards/nelder_mead.hpp>
#include <standards/mccormick.hpp>

int main() {
  standards::nelder_mead optimizer;
  std::vector<double> x(2);
  x[0] = 1;
  x[1] = -1;
  standards::mccormick f;
  int iteration = optimizer.find_minimum(f, x);
  if (iteration < 0) {
    std::cerr << "Failed to converge\n";
  } else {
    x = optimizer.minarg();
    std::cout << iteration << ' ' << optimizer.minval()
              << " at [" << x[0] << "," << x[1] << "]\n";
  }
}
