// Copyright (C) 1997-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef STANDARDS_TRIANGULAR_HPP
#define STANDARDS_TRIANGULAR_HPP

#include <array>
#include <cmath>
#include <complex>
#include <tuple>
#include <vector>

namespace standards {

class triangular {
public:
  explicit triangular(unsigned int L) : length_x_(3 * L), length_y_(L) { init(); }
  triangular(unsigned int Lx, unsigned int Ly) : length_x_(Lx), length_y_(Ly) { init(); }
  void init();
  unsigned int get_length_x() const { return length_x_; }
  unsigned int get_length_y() const { return length_y_; }
  unsigned int num_sites() const { return length_x_ * length_y_; }
  unsigned int num_bonds() const { return 3 * num_sites(); }
  unsigned int num_triangles() const { return 2 * num_sites(); }
  unsigned int bond_site(unsigned int b, unsigned int k) const { return bsites_[b][k]; }
  unsigned int source(unsigned int b) const { return bond_site(b, 0); }
  unsigned int target(unsigned int b) const { return bond_site(b, 1); }
  unsigned int triangle_site(unsigned int p, unsigned int k) const { return tsites_[p][k]; }
  unsigned int num_neighbors() const { return 6; }
  unsigned int neighbor(unsigned int s, unsigned int k) const { return neighbors_[s][k]; }
  unsigned int neighbor_bond(unsigned int s, unsigned int k) const { return neighbor_bonds_[s][k]; }
  unsigned int neighbor_triangle(unsigned int s, unsigned int k) const { return neighbor_triangles_[s][k]; }
  unsigned int sublattice(unsigned int s) const { return sublattice_[s]; }
  std::complex<double> phase(unsigned int s) const { return phase_[s]; }
protected:
  std::tuple<int, int> index2xy(unsigned int s) const {
    return std::make_tuple(s % length_x_, s / length_x_);
  }
  unsigned int xy2index(int x, int y) const {
    x += length_x_;
    y += length_y_;
    return x % length_x_ + (y % length_y_) * length_x_;
  }
  unsigned int index2sublattice(unsigned int s) const {
    int x, y;
    std::tie(x, y) = index2xy(s);
    return (x + 2 * y) % 3;
  }
  std::tuple<double, double> index2coordinate(unsigned int s) const {
    int x, y;
    std::tie(x, y) = index2xy(s);
    return std::make_tuple(1.0 * x + 0.5 * y, std::sqrt(3.0/4) * y);
  }
private:
  unsigned int length_x_, length_y_;
  std::vector<std::array<unsigned int, 6> > neighbors_;
  std::vector<std::array<unsigned int, 6> > neighbor_bonds_;
  std::vector<std::array<unsigned int, 6> > neighbor_triangles_;
  std::vector<std::array<unsigned int, 2> > bsites_;
  std::vector<std::array<unsigned int, 3> > tsites_;
  std::vector<unsigned int> sublattice_;
  std::vector<std::complex<double> > phase_;
};

void triangular::init() {
  if (length_x_ % 3 != 0 || length_y_ % 3 != 0) {
    throw std::invalid_argument("Lx and Ly should be multiple of 3");
  }
  neighbors_.resize(num_sites());
  neighbor_bonds_.resize(num_sites());
  neighbor_triangles_.resize(num_sites());
  bsites_.resize(num_bonds());
  tsites_.resize(num_triangles());
  sublattice_.resize(num_sites());
  phase_.resize(num_sites());
  double q = 2 * M_PI / 3;
  for (unsigned int s = 0; s < num_sites(); ++s) {
    int x, y;
    std::tie(x, y) = index2xy(s);
    neighbors_[s][0] = xy2index(x + 1, y    );
    neighbors_[s][1] = xy2index(x    , y + 1);
    neighbors_[s][2] = xy2index(x - 1, y + 1);
    neighbors_[s][3] = xy2index(x - 1, y    );
    neighbors_[s][4] = xy2index(x    , y - 1);
    neighbors_[s][5] = xy2index(x + 1, y - 1);
    sublattice_[s] = index2sublattice(s);
    phase_[s] = std::exp(std::complex<double>(0.0, q * sublattice_[s]));
  }
  for (unsigned int b = 0; b < num_bonds(); ++b) {
    unsigned int s = b / 3;
    int x, y;
    std::tie(x, y) = index2xy(s);
    bsites_[b][0] = s;
    neighbor_bonds_[s][b % 3] = b;
    unsigned int t;
    if (b % 3 == 0) {
      t = xy2index(x + 1, y);
    } else if (b % 3 == 1) {
      t = xy2index(x, y + 1);
    } else {
      t = xy2index(x - 1, y + 1);
    }
    bsites_[b][1] = t;
    neighbor_bonds_[t][(b % 3) + 3] = b;
  }
  for (unsigned int p = 0; p < num_triangles(); ++p) {
    unsigned int s0 = p / 2;
    int x, y;
    std::tie(x, y) = index2xy(s0);
    unsigned int s1, s2;
    if (p % 2 == 0) {
      // upward triangle
      s1 = xy2index(x + 1, y    );
      s2 = xy2index(x    , y + 1);
    } else {
      // downward triangle
      s1 = xy2index(x    , y + 1);
      s2 = xy2index(x - 1, y + 1);
    }
    tsites_[p][index2sublattice(s0)] = s0;
    tsites_[p][index2sublattice(s1)] = s1;
    tsites_[p][index2sublattice(s2)] = s2;
    neighbor_triangles_[s0][p % 2] = p;
    neighbor_triangles_[s1][p % 2 + 2] = p;
    neighbor_triangles_[s2][p % 2 + 4] = p;
  }
}

} // end namespace standards

#endif // STANDARDS_TRIANGULAR_HPP
