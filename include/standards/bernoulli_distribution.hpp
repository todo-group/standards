// Copyright (C) 2016-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef STANDARDS_BERNOULLI_DISTRIBUTION_HPP
#define STANDARDS_BERNOULLI_DISTRIBUTION_HPP

#include <cmath>
#include <stdexcept>
#include <string>
#include <boost/lexical_cast.hpp>
#include "moment.hpp"

namespace standards {

class bernoulli_distribution : public moment<bernoulli_distribution> {
private:
  typedef moment<bernoulli_distribution> super_type;
public:
  bernoulli_distribution(double p) : super_type(*this), p_(p) {
    if (p < 0 || p >1)
      throw std::invalid_argument("standards::bernoulli_distribution");
  }
  std::string name() const {
    return "Bernoulli Distribution: Be(" + boost::lexical_cast<std::string>(p_) + ")";
  }
  double moment1() const { return p_; }
  double moment2() const { return p_; }
  double moment3() const { return p_; }
  double moment4() const { return p_; }
private:
  double p_;
};

} // end namespace standards

#endif // STANDARDS_BERNOULLI_DISTRIBUTION_HPP
