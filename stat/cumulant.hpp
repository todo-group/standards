// Copyright (C) 2016 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef STAT_CUMULANT_DISTRIBUTION_HPP
#define STAT_CUMULANT_DISTRIBUTION_HPP

#include <math/power.hpp>

#include <cmath>

namespace stat {

using math::power2;
using math::power3;
using math::power4;
  
template<typename DIST>
class cumulant {
private:
  typedef DIST dist_type;
public:
  cumulant(dist_type const& dist) : dist_(dist) {}
  double cumulant1() const { return dist_.moment1(); }
  double cumulant2() const { return dist_.moment2() - power2(dist_.moment1()); }
  double cumulant3() const {
    return dist_.moment3() - 3 * dist_.moment2() * dist_.moment1() + 2 * power3(dist_.moment1());
  }
  double cumulant4() const {
    return dist_.moment4() - 4 * dist_.moment3() * dist_.moment1() - 3 * power2(dist_.moment2())
      + 12 * dist_.moment2() * power2(dist_.moment1()) - 6 * power4(dist_.moment1());
  }
  double mean() const { return cumulant1(); }
  double variance() const { return cumulant2(); }
  double standard_deviation() const { return std::sqrt(variance()); }
  double skewness() const { return cumulant3() / power3(standard_deviation()); }
  double kurtosis() const { return cumulant4() / power4(standard_deviation()); }
private:
  dist_type const& dist_;
};

} // end namespace stat

#endif // STAT_CUMULANT_DISTRIBUTION_HPP
