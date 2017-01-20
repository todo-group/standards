/*****************************************************************************
*
* Copyright (C) 2016-2016 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
*
* Distributed under the Boost Software License, Version 1.0. (See accompanying
* file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*
*****************************************************************************/

#ifndef OPTIMIZE_MCCORMICK_HPP
#define OPTIMIZE_MCCORMICK_HPP

#include <cmath>

namespace optimize {

// McCormick function, which takes minimum -1.91322 at (-0.547198, -1.5472)
  
class mccormick {
public:
  double operator()(std::vector<double> const& x) const {
    return std::sin(x[0]+x[1]) + (x[0]-x[1]) * (x[0]-x[1])
      - 1.5 * x[0] + 2.5 * x[1] + 1;
  }
};

} // end namespace optimize

#endif // OPTIMIZE_MCCORMICK_HPP
