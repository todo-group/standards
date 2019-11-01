// Copyright (C) 1996-2017 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef LATTICE_LATTICE_HPP
#define LATTICE_LATTICE_HPP

namespace lattice {

class simple_lattice {
private:
  struct bond_t {
    unsigned int source;
    unsigned int target;
  };
public:
  simple_lattice(unsigned int dim, unsigned int num_sites) : dim_(dim),
    num_sites_(num_sites), num_bonds_(0) {}
  void add_bond(unsigned int source, unsigned int target) {
    bond_t b;
    b.source = source;
    b.target = target;
    bonds_.push_back(b);
  }
  unsigned int num_sites() const { return num_sites_; }
  unsigned int num_bonds() const { return bonds_.size(); }
  unsigned int source(unsigned int b) const { return bonds_[b].source; }
  unsigned int target(unsigned int b) const { return bonds_[b].target; }
private:
  unsigned int num_sites_;
  std::vector<bond_t> bonds_;
};
  
} // end namespace math

#endif // LATTICE_LATTICE_HPP
