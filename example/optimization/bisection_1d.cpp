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
#include <standards/bisection.hpp>

double f(double x) { return 3.293*x*x-5.33*x+1; }

int main() {
  standards::bisection optimizer;
  int iteration;
  iteration = optimizer.find_zero(f, 0, 1);
  if (iteration < 0) {
    std::cout << "Initial enclosure failure\n";
  } else {
    std::cout << iteration << ' ' << optimizer.zero() << std::endl;
  }
}
