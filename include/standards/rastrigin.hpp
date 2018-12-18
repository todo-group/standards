/*****************************************************************************
*
* Copyright (C) 2016-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
*
* Distributed under the Boost Software License, Version 1.0. (See accompanying
* file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*
*****************************************************************************/

#ifndef STANDARDS_RASTRIGIN_HPP
#define STANDARDS_RASTRIGIN_HPP

#include <cmath>

namespace standards {

class rastrigin {
public:
  rastrigin(unsigned int n) : n_(n) {}
  double operator()(std::vector<double> const& x) const {
    const double a = 10;
    const double pi = boost::math::constants::pi<double>();
    double f = a * n_;
    for (unsigned int i = 0; i < n_; ++i) {
      f += x[i] * x[i] - a * std::cos(2 * pi * x[i]);
    }
    return f;
  }
private:
  double n_;
};

} // end namespace standards

#endif // STANDARDS_RASTRIGIN_HPP
