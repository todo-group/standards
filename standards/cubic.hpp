// Copyright (C) 1997-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef STANDARDS_CUBIC_HPP
#define STANDARDS_CUBIC_HPP

#include <array>
#include <tuple>
#include <vector>

namespace standards {

class cubic {
public:
  cubic(unsigned int L) : length_x_(L), length_y_(L), length_z_(L) { init(); }
  cubic(unsigned int Lx, unsigned int Ly, unsigned int Lz) :
    length_x_(Lx), length_y_(Ly), length_z_(Lz) { init(); }
  void init();
  unsigned int get_length_x() const { return length_x_; }
  unsigned int get_length_y() const { return length_y_; }
  unsigned int get_length_z() const { return length_z_; }
  unsigned int num_sites() const { return length_x_ * length_y_ * length_z_; }
  unsigned int num_bonds() const { return 3 * num_sites(); }
  unsigned int bond_site(unsigned int b, unsigned int k) const { return bsites_[b][k]; }
  unsigned int source(unsigned int b) const { return bond_site(b, 0); }
  unsigned int target(unsigned int b) const { return bond_site(b, 1); }
  unsigned int num_neighbors() const { return 6; }
  unsigned int neighbor(unsigned int s, unsigned int k) const { return neighbors_[s][k]; }
  unsigned int neighbor_bond(unsigned int s, unsigned int k) const { return neighbor_bonds_[s][k]; }
  unsigned int sublattice(unsigned int s) const { return sublattice_[s]; }
  double phase(unsigned int s) const { return phase_[s]; }
protected:
  std::tuple<int, int, int> index2xyz(unsigned int s) const {
    return std::make_tuple(s % length_x_, (s / length_x_) % length_y_,
                             (s / (length_x_ * length_y_)));
  }
  unsigned int xyz2index(int x, int y, int z) const {
    x += length_x_;
    y += length_y_;
    z += length_z_;
    return x % length_x_ + (y % length_y_) * length_x_ + (z % length_z_) * length_x_ * length_y_;
  }
private:
  unsigned int length_x_, length_y_, length_z_;
  std::vector<std::array<unsigned int, 6> > neighbors_;
  std::vector<std::array<unsigned int, 6> > neighbor_bonds_;
  std::vector<std::array<unsigned int, 2> > bsites_;
  std::vector<unsigned int> sublattice_;
  std::vector<double> phase_;
};

void cubic::init() {
  if (length_x_ % 2 != 0 || length_y_ % 2 != 0 || length_z_ % 2 != 0) {
    throw std::invalid_argument("Lx, Ly, Lz should be multiple of 2");
  }
  neighbors_.resize(num_sites());
  neighbor_bonds_.resize(num_sites());
  bsites_.resize(num_bonds());
  sublattice_.resize(num_sites());
  phase_.resize(num_sites());
  for (unsigned int s = 0; s < num_sites(); ++s) {
    int x, y, z;
    std::tie(x, y, z) = index2xyz(s);
    sublattice_[s] = (x + y + z) % 2;
    phase_[s] = 1.0 - 2.0 * sublattice_[s];
    for (unsigned int k = 0; k < 6; ++k) {
      int d = 1 - 2 * (k / 3);
      if ((k % 3) == 0) {
        neighbors_[s][k] = xyz2index(x + d, y, z);
      } else if ((k % 3) == 1) {
        neighbors_[s][k] = xyz2index(x, y + d, z);
      } else {
        neighbors_[s][k] = xyz2index(x, y, z + d);
      }
    }
  }
  for (unsigned int b = 0; b < num_bonds(); ++b) {
    unsigned int s = b / 3;
    int x, y, z;
    std::tie(x, y, z) = index2xyz(s);
    bsites_[b][0] = s;
    neighbor_bonds_[s][b % 3] = b;
    unsigned int t;
    if (b % 3 == 0) {
      t = xyz2index(x + 1, y, z);
    } else if (b % 3 == 1) {
      t = xyz2index(x, y + 1, z);
    } else {
      t = xyz2index(x, y, z + 1);
    }
    bsites_[b][1] = t;
    neighbor_bonds_[t][(b % 3) + 3] = b;
  }
}

} // end namespace standards

#endif // STANDARDS_CUBIC_HPP
