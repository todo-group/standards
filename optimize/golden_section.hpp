/*****************************************************************************
*
* Copyright (C) 2014-2016 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
*
* Distributed under the Boost Software License, Version 1.0. (See accompanying
* file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*
*****************************************************************************/

#ifndef OPTIMIZE_GOLDEN_SECTION_HPP
#define OPTIMIZE_GOLDEN_SECTION_HPP

#include <algorithm>
#include <cmath>
#include <limits>

namespace optimize {

class golden_section {
public:
  template<class FUNC>
  unsigned int find_minimum(FUNC& f, double x0, double x1,
    double prec = std::sqrt(std::numeric_limits<double>::epsilon())) {
    if (x1 < x0) std::swap(x0, x1);
    x1 *= (1 + prec);
    double dx = x1 - x0;
    double y0 = f(x0);
    double y1 = f(x1);
    double x2, y2;
    unsigned int counter = 2;
    // initial enclosure
    if (y0 < y1) {
      // go to the left
      while (y0 < y1) {
        ++counter;
        dx *= 2;
        x2 = x1; y2 = y1;
        x1 = x0; y1 = y0;
        x0 = x1 - dx; y0 = f(x0);
      }
    } else {
      // go to the right
      x2 = x1; y2 = y1;
      x1 = x0; y1 = y0;
      while (y2 < y1) {
        ++counter;
        dx *= 2;
        x0 = x1; y0 = y1;
        x1 = x2; y1 = y2;
        x2 = x1 + dx; y2 = f(x2);
      }
    }
    // start golden section
    double r = (3-std::sqrt(5))/2; // golden ratio
    double prec2 = prec * prec;
    while (((x2-x0) / std::max(std::abs(x0), std::abs(x2))) > prec ||
           ((y0-y1) / std::max(std::abs(y1), std::abs(y0))) > prec2 ||
           ((y2-y1) / std::max(std::abs(y1), std::abs(y2))) > prec2) {
      ++counter;
      if ((x2-x1) > (x1-x0)) {
        double xn = (x2-x1) * r + x1;
        double yn = f(xn);
        if (y1 > yn) {
          x0 = x1; y0 = y1;
          x1 = xn; y1 = yn;
        } else {
          x2 = xn; y2 = yn;
        }
      } else{
        double xn = (x0-x1) * r + x1;
        double yn = f(xn);
        if (y1 > yn) {
          x2 = x1; y2 = y1;
          x1 = xn; y1 = yn;
        } else {
          x0 = xn; y0 = yn;
        }
      }
    }
    minarg_ = x1;
    minval_ = y1;
    return counter;
  }
  double minarg() const { return minarg_; }
  double minval() const { return minval_; }
private:
  double minarg_, minval_;
};

} // end namespace optimize

#endif // OPTIMIZE_GOLDEN_SECTION_HPP
