// Copyright (C) 2016 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef STAT_NORMAL_DISTRIBUTION_HPP
#define STAT_NORMAL_DISTRIBUTION_HPP

#include <math/power.hpp>
#include <stat/cumulant.hpp>

#include <boost/throw_exception.hpp>
#include <stdexcept>

namespace stat {

using math::power2;
using math::power3;
using math::power4;
  
class normal_distribution : public cumulant<normal_distribution> {
private:
  typedef cumulant<normal_distribution> super_type;
public:
  normal_distribution(double mu = 0, double sigma = 1) : super_type(*this), mu_(mu), sigma_(sigma) {
    if (sigma_ <= 0)
      boost::throw_exception(std::invalid_argument("stat::normal_distribution"));
  }
  double moment1() const { return mu_; }
  double moment2() const { return power2(mu_) + power2(sigma_); }
  double moment3() const { return power3(mu_) + 3 * mu_ * power2(sigma_); }
  double moment4() const { return power4(mu_) + 6 * power2(mu_) * power2(sigma_) + 3 * power4(sigma_); }
private:
  double mu_, sigma_;
};

} // end namespace stat

#endif // STAT_NORMAL_DISTRIBUTION_HPP
