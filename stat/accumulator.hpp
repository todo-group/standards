// Copyright (C) 2015-2016 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// Ref: http://modelingwithdata.org/pdfs/moments.pdf
// Ref: wrn:2017-01-20

#ifndef STAT_ACCUMULATOR_HPP
#define STAT_ACCUMULATOR_HPP

#include <math/power.hpp>
#include <stat/cumulant.hpp>

#include <boost/lexical_cast.hpp>
#include <cmath>
#include <string>

#include <boost/throw_exception.hpp>
#include <stdexcept>

namespace stat {

using math::power2;
using math::power3;
using math::power4;
 
class accumulator {
public:
  accumulator(std::string const& name = "") : name_(name) { reset(); }
  void reset() {
    count_ = 0;
    sum1_ = sum2_ = sum3_ = sum4_ = 0;
  }
  double operator<<(double v) {
    ++count_;
    sum1_ += v;
    sum2_ += power2(v);
    sum3_ += power3(v);
    sum4_ += power4(v);
    return v;
  }

  std::string name() const { return name_; }
  unsigned long count() const { return count_; }
  double moment1() const { return count() ? (sum1_ / count()) : 0; }
  double moment2() const { return count() ? (sum2_ / count()) : 0; }
  double moment3() const { return count() ? (sum3_ / count()) : 0; }
  double moment4() const { return count() ? (sum4_ / count()) : 0; }

  double cumulant1_s() const { return moment1(); }
  double cumulant2_s() const { return moment2() - power2(moment1()); }
  double cumulant3_s() const {
    return moment3() - 3 * moment2() * moment1() + 2 * power3(moment1());
  }
  double cumulant4_s() const {
    return moment4() - 4 * moment3() * moment1() - 3 * power2(moment2())
      + 12 * moment2() * power2(moment1()) - 6 * power4(moment1());
  }
  double cumulant1() const { return cumulant1_s(); }
  double cumulant2() const {
    double n = count();
    return (n > 1) ? (n/(n-1)) * cumulant2_s() : 0;
  }
  double cumulant3() const {
    double n = count();
    return (n > 2) ? (power2(n)/((n-2)*(n-1))) * cumulant3_s() : 0;
  }
  double cumulant4() const {
    double n = count();
    return (n > 1) ?
      // (n/(n-1)) * ((n*n/(n*n-3*n+3)) * cumulant4_s() - ((6*n-9)/(n*n-3*n+3)) * cumulant2_s()) : 0;
      
      (n/(n-1)) * ((n*n/(n*n-3*n+3)) * cumulant4_s()) - ((6*n-9)/((n*n-3*n+3))) * power2(cumulant2()) : 0;
  }
  
  double mean() const { return cumulant1(); }
  double variance() const { return cumulant2(); }
  double standard_deviation() const { return std::sqrt(variance()); }
  double skewness() const { return (count() > 1) ? cumulant3() / power3(standard_deviation()) : 0; }
  double kurtosis() const { return (count() > 1) ? cumulant4() / power4(standard_deviation()) : 0; }
  
  double average() const { return mean(); }
  double error() const { return count() ? std::sqrt(variance() / count()) : 0; }
  
private:
  std::string name_;
  unsigned long count_;
  double sum1_, sum2_, sum3_, sum4_;
};

inline std::string format(accumulator const& accum) {
  return accum.name() + " = "
    + boost::lexical_cast<std::string>(accum.average()) + " +- "
    + boost::lexical_cast<std::string>(accum.error());
}

} // end namespace stat

#endif // STAT_ACCUMULATOR_HPP
