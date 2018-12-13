// Copyright (C) 2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef STAT_HISTOGRAM_HPP
#define STAT_HISTOGRAM_HPP

#include <cstdint>
#include <stdexcept>

namespace stat {

class histogram {
public:
  typedef std::uint64_t count_t;
  histogram(double xmin, double xmax, std::size_t nbins)
    : xmin_(xmin), xmax_(xmax), bins_(nbins, 0) {
    if (xmax <= xmin)
      throw std::invalid_argument("xmax should be larger than xmin");
    if (nbins == 0)
      throw std::invalid_argument("nbins should be non-zero");
    dxinv_ = nbins / (xmax - xmin);
  }
  histogram& operator<<(double x) {
    ++count_;
    if (x >= xmin_) {
      std::size_t k = dxinv_ * (x - xmin_);
      if (k < bins_.size()) {
        ++valid_;
        ++bins_[k];
      }
    }
    return *this;
  }

  std::size_t num_bins() const { return nbins_; }
  count_t count() const { return count_; }
  count_t valid() const { return valid_; }
  double mean(std::size_t k) const {
    if (count_ == 0) std::runtime_error("no measurements");
    if (k >= num_binds()) std::invalid_argument("index out of range");
    return dxinv_ * bins_[k] / count_;
  }
      
private:
  double xmin_, xmax_;
  std::vector<count_t> bins_;
  count_t count_, valid_;
  double dxinv_;
};

inline std::ostream& operator<<(std::ostream& os, histogram const& hist) {
  return os;
}

} // end namespace stat

#endif // STAT_HISTOGRAM_HPP
