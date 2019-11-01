// Copyright (C) 1997-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef STANDARDS_CHAIN_HPP
#define STANDARDS_CHAIN_HPP

namespace standards {

class chain {
public:
  chain(unsigned int L) : length_(L) {}
  unsigned int get_length() const { return length_; }
  unsigned int num_sites() const { return get_length(); }
  unsigned int num_bonds() const { return get_length(); }
  unsigned int bond_site(unsigned int b, unsigned int k) const { return (b + k) % get_length(); }
  unsigned int source(unsigned int b) const { return bond_site(b, 0); }
  unsigned int target(unsigned int b) const { return bond_site(b, 1); }
  unsigned int num_neighbors() const { return 2; }
  unsigned int neighbor(unsigned int s, unsigned int k) const {
    return (get_length() + s + 1 - 2 * k) % get_length();
  }
  unsigned int neighbor_bond(unsigned int s, unsigned int k) const {
    return (get_length() + s - k) % get_length();
  }
  unsigned int sublattice(unsigned int s) const { return s % 2; }
  double phase(unsigned int s) const { return 1.0 - 2.0 * (s % 2); }
private:
  unsigned int length_;
};

} // end namespace standards

#endif // STANDARDS_CHAIN_HPP
