/*****************************************************************************
*
* Copyright (C) 2016-2016 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
*
* Distributed under the Boost Software License, Version 1.0. (See accompanying
* file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*
*****************************************************************************/

#ifndef OPTIMIZE_RASTRIGIN_HPP
#define OPTIMIZE_RASTRIGIN_HPP

#include <cmath>

namespace optimize {

class rastrigin {
public:
  rastrigin(unsigned int n) : n_(n) {}
  double operator()(std::vector<double> const& x) const {
    const double a = 10;
    double f = a * n_;
    for (unsigned int i = 0; i < n_; ++i) {
      f += x[i] * x[i] - a * std::cos(2 * M_PI * x[i]);
    }
    return f;
  }
private:
  double n_;
};

} // end namespace optimize

#endif // OPTIMIZE_RASTRIGIN_HPP
