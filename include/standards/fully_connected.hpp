// Copyright (C) 1997-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef STANDARDS_FULLY_CONNECTED_HPP
#define STANDARDS_FULLY_CONNECTED_HPP

namespace standards {

class fully_connected {
public:
  fully_connected(unsigned int N) : num_sites_(N) {}
  unsigned int num_sites() const { return num_sites_; }
  unsigned int num_bonds() const { return num_sites_ * (num_sites_ - 1) / 2; }
  unsigned int num_neighbors() const { return num_sites_ - 1; }
  unsigned int neighbor(unsigned int s, unsigned int k) const { return (s + k) % num_sites_; }
private:
  unsigned int num_sites_;
};

} // end namespace standards

#endif // STANDARDS_FULLY_CONNECTED_HPP
