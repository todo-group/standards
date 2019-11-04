// Copyright (C) 2019 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once
#include <chrono>

namespace standards {

class timer {
public:
  timer() : start_(std::chrono::system_clock::now()) {}
  void reset() {
    start_ = std::chrono::system_clock::now();
  }
  double elapsed() const {
    auto end = std::chrono::system_clock::now();
    return 1.0e-6 * std::chrono::duration_cast<std::chrono::microseconds>(end - start_).count();
  }
private:
  std::chrono::system_clock::time_point start_;
};

} // end namespace standards
