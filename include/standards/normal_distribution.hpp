// Copyright (C) 2016-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef STANDARDS_NORMAL_DISTRIBUTION_HPP
#define STANDARDS_NORMAL_DISTRIBUTION_HPP

#include <stdexcept>
#include <string>
#include "power.hpp"
#include "moment.hpp"

namespace standards {

class normal_distribution : public moment<normal_distribution> {
private:
  typedef moment<normal_distribution> super_type;
public:
  normal_distribution(double mu = 0, double sigma = 1) : super_type(*this), mu_(mu), sigma_(sigma) {
    if (sigma_ <= 0)
      throw std::invalid_argument("standards::normal_distribution");
  }
  std::string name() const {
    return "Normal Distribution: N(" + std::to_string(mu_) + ","
      + std::to_string(sigma_) + ")";
  }
  double moment1() const { return mu_; }
  double moment2() const { return p2(mu_) + p2(sigma_); }
  double moment3() const { return p3(mu_) + 3 * mu_ * p2(sigma_); }
  double moment4() const { return p4(mu_) + 6 * p2(mu_) * p2(sigma_) + 3 * p4(sigma_); }
private:
  double mu_, sigma_;
};

} // end namespace standards

#endif // STANDARDS_NORMAL_DISTRIBUTION_HPP
