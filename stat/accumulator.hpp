// Copyright (C) 2015-2016 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// Ref: http://modelingwithdata.org/pdfs/moments.pdf
// Ref: standards/doc/stat/fourth-moment.pdf
// Ref: wrn:2017-01-20, 2017-02-07, 2017-02-09

#ifndef STAT_ACCUMULATOR_HPP
#define STAT_ACCUMULATOR_HPP

#include <math/power.hpp>
#include <stat/moment.hpp>

#include <boost/lexical_cast.hpp>
#include <cmath>
#include <string>

#include <boost/throw_exception.hpp>
#include <stdexcept>

namespace stat {

using math::p2;
using math::p3;
using math::p4;
 
class accumulator : public moment<accumulator> {
private:
  typedef moment<accumulator> super_type;
public:
  accumulator(std::string const& name = "") : super_type(*this), name_(name) { reset(); }
  accumulator(accumulator const& x) : super_type(*this), name_(x.name_),
    count_(x.count_), sum1_(x.sum1_), sum2_(x.sum2_), sum3_(x.sum3_), sum4_(x.sum4_) {}
  void reset() {
    count_ = 0;
    sum1_ = sum2_ = sum3_ = sum4_ = 0;
  }
  double operator<<(double v) {
    ++count_;
    sum1_ += v;
    sum2_ += p2(v);
    sum3_ += p3(v);
    sum4_ += p4(v);
    return v;
  }

  void set_name(std::string const& name) { name_ = name; }
  std::string name() const { return name_; }
  unsigned long count() const { return count_; }
  double moment1() const { return count() ? (sum1_ / count()) : 0; }
  double moment2() const { return count() ? (sum2_ / count()) : 0; }
  double moment3() const { return count() ? (sum3_ / count()) : 0; }
  double moment4() const { return count() ? (sum4_ / count()) : 0; }

  double central_moment1() const { return 0; }
  double central_moment2() const {
    double n = count();
    return (n > 1) ? (n/(n-1)) * super_type::central_moment2() : 0;
  }
  double central_moment3() const {
    double n = count();
    return (n > 2) ? (n*n/((n-1)*(n-2))) * super_type::central_moment3() : 0;
  }
  double central_moment4() const {
    double n = count();
    return (n > 3) ?
      n/((n-1)*(n-2)*(n-3)) *
      ((p2(n)-2*n+3)*super_type::central_moment4() -
       (6*n-9)*(p2(moment2()) - 2 * p2(moment1()) * moment2() + p4(moment1()))) : 0;
  }
  double cumulant4() const {
    double n = count();
    return (n > 3) ?
      p2(n)/((n-1)*(n-2)*(n-3)) *
      ((n+1)*super_type::central_moment4() -
       3*(n-1)*(p2(moment2()) - 2 * p2(moment1()) * moment2() + p4(moment1()))) : 0;
  }
  double average() const { return super_type::mean(); }
  double error() const { return count() ? std::sqrt(super_type::variance() / count()) : 0; }
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

inline std::ostream& operator<<(std::ostream& os, accumulator const& accum) {
  os << accum.name() << " = " << accum.average() << " +- " << accum.error();
  return os;
}

} // end namespace stat

#endif // STAT_ACCUMULATOR_HPP
