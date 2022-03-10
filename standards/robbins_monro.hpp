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

#pragma once

#include <cmath>

namespace standards {

// find a zero of "nondecreasing" function
// for "nonincreasing" function give -1 * val for the 2nd argument of update()

class robbins_monro {
public:
  robbins_monro(double a = 1.0, double kappa = 1.0) : a_(a), kappa_(kappa), n_(0) {}
  double update(double x, double val) const {
    ++n_;
    return x - a_ * std::pow(n_, -kappa_) * val;
  }
private:
  double a_, kappa_;
  mutable int n_;
};

} // end namespace standards
