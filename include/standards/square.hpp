// Copyright (C) 1997-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef STANDARDS_SQUARE_HPP
#define STANDARDS_SQUARE_HPP

#include <array>
#include <tuple>
#include <vector>

namespace standards {

class square {
public:
  square(unsigned int L) : length_x_(L), length_y_(L) { init(); }
  square(unsigned int Lx, unsigned int Ly) : length_x_(Lx), length_y_(Ly) { init(); }
  void init();
  unsigned int get_length_x() const { return length_x_; }
  unsigned int get_length_y() const { return length_y_; }
  unsigned int num_sites() const { return length_x_ * length_y_; }
  unsigned int num_bonds() const { return 2 * num_sites(); }
  unsigned int bond_site(unsigned int b, unsigned int k) const { return bsites_[b][k]; }
  unsigned int source(unsigned int b) const { return bond_site(b, 0); }
  unsigned int target(unsigned int b) const { return bond_site(b, 1); }
  unsigned int num_neighbors() const { return 4; }
  unsigned int neighbor(unsigned int s, unsigned int k) const { return neighbors_[s][k]; }
  unsigned int neighbor_bond(unsigned int s, unsigned int k) const { return neighbor_bonds_[s][k]; }
  unsigned int sublattice(unsigned int s) const { return sublattice_[s]; }
  double phase(unsigned int s) const { return phase_[s]; }
protected:
  std::tuple<int, int> index2xy(unsigned int s) const {
    return std::make_tuple(s % length_x_, s / length_x_);
  }
  unsigned int xy2index(int x, int y) const {
    x += length_x_;
    y += length_y_;
    return x % length_x_ + (y % length_y_) * length_x_;
  }
private:
  unsigned int length_x_, length_y_;
  std::vector<std::array<unsigned int, 4> > neighbors_;
  std::vector<std::array<unsigned int, 4> > neighbor_bonds_;
  std::vector<std::array<unsigned int, 2> > bsites_;
  std::vector<unsigned int> sublattice_;
  std::vector<double> phase_;
};

void square::init() {
  if (length_x_ % 2 != 0 || length_y_ % 2 != 0) {
    throw std::invalid_argument("Lx and Ly should be multiple of 2");
  }
  neighbors_.resize(num_sites());
  neighbor_bonds_.resize(num_sites());
  bsites_.resize(num_bonds());
  sublattice_.resize(num_sites());
  phase_.resize(num_sites());
  for (unsigned int s = 0; s < num_sites(); ++s) {
    int x, y;
    std::tie(x, y) = index2xy(s);
    sublattice_[s] = (x + y) % 2;
    phase_[s] = 1.0 - 2.0 * sublattice_[s];
    for (unsigned int k = 0; k < 4; ++k) {
      int d = 1- int(k & 2);
      neighbors_[s][k] = ((k & 1) == 0) ? xy2index(x + d, y) : xy2index(x, y + d);
    }
  }
  for (unsigned int b = 0; b < num_bonds(); ++b) {
    unsigned int s = b / 2;
    int x, y;
    std::tie(x, y) = index2xy(s);
    bsites_[b][0] = s;
    neighbor_bonds_[s][b % 2] = b;
    unsigned int t;
    if (b % 2 == 0) {
      t = xy2index(x + 1, y); // target right
    } else {
      t = xy2index(x, y + 1); // target below
    }
    bsites_[b][1] = t;
    neighbor_bonds_[t][(b % 2) + 2] = b;
  }
}

} // end namespace standards

#endif // STANDARDS_SQUARE_HPP
