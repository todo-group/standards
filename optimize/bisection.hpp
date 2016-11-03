/*****************************************************************************
*
* Copyright (C) 2014-2016 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
*
* Distributed under the Boost Software License, Version 1.0. (See accompanying
* file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*
*****************************************************************************/

#ifndef OPTIMIZE_BISECTION_HPP
#define OPTIMIZE_BISECTION_HPP

#include <algorithm>
#include <cmath>
#include <limits>
#include <boost/throw_exception.hpp>

namespace optimize {

class bisection {
public:
  template<class FUNC>
  unsigned int find_zero(FUNC& f, double x0, double x1,
    double prec = std::numeric_limits<double>::epsilon()) {
    unsigned int counter = 0;
    ++counter;
    double y0 = f(x0);
    if (y0 == 0) {
      zero_ = x0;
      return counter;
    }
    ++counter;
    double y1 = f(x1);
    if (y1 == 0) {
      zero_ = x1;
      return counter;
    }
    if (y0 * y1 > 0)
      boost::throw_exception(std::invalid_argument("Initial enclosure failure"));
    // start bisection
    while (((x1-x0) / std::max(std::abs(x0), std::abs(x1))) > prec ||
           std::max(std::abs(y1), std::abs(y0)) > prec) {
      ++counter;
      double xn = (x0 + x1) / 2;
      double yn = f(xn);
      if (y0 * yn > 0) {
        x0 = xn; y0 = yn;
      } else{
        x1 = xn; y1 = yn;
      }
    }
    zero_ = x0;
    return counter;
  }
  double zero() const { return zero_; }
private:
  double zero_;
};

} // end namespace optimize

#endif // OPTIMIZE_BISECTION_HPP
