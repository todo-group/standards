// Copyright (C) 1997-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef LATTICE_TRIANGULAR_HPP
#define LATTICE_TRIANGULAR_HPP

#include <vector>
#include <boost/array.hpp>
#include <boost/tuple/tuple.hpp>

namespace lattice {

class triangular {
public:
  explicit triangular(unsigned int L) : length_x_(3 * L), length_y_(L) { init(); }
  triangular(unsigned int Lx, unsigned int Ly) : length_x_(Lx), length_y_(Ly) { init(); }
  void init() {
    if (Lx % 3 != 0 || Ly % 3 != 0) {
      throw std::invalid_argument("Lx and Ly should be multiple of 3");
    }
    neighbors_.resize(num_sites());
    bsites_.resize(num_bonds());
    tsites_.resize(num_triangles());
    phase_.resize(num_sites());
    double qx = 2 * M_PI / 3;
    double qy = qx;
    for (unsigned int s = 0; s < num_sites(); ++s) {
      int x, y;
      boost::tie(x, y) = index2xy(s);
      neighbors_[s][0] = xy2index(x + 1, y    );
      neighbors_[s][1] = xy2index(x - 1, y    );
      neighbors_[s][2] = xy2index(x    , y + 1);
      neighbors_[s][3] = xy2index(x    , y - 1);
      neighbors_[s][4] = xy2index(x - 1, y + 1);
      neighbors_[s][5] = xy2index(x + 1, y - 1);
      double rx, ry;
      boost::tie(rx, ry) = index2coordinate(s);
      phase_[s] = std::exp(std::complex<double>(0.0, qx * rx + qy * ry));
    }
    for (unsigned int b = 0; b < num_bonds(); ++b) {
      unsigned int s = b / 3;
      int x, y;
      boost::tie(x, y) = index2xy(s);
      bsites_[b][0] = s;
      unsigned int t;
      if (b % 3 == 0) {
        bsites_[b][1] = xy2index(x + 1, y     );
      } else if (b % 3 == 1) {
        bsites_[b][1] = xy2index(x    , y + 1);
      } else {
        bsites_[b][1] = xy2index(x - 1, y + 1);
      }
    }
    for (unsigned int t = 0; t < num_triangles(); ++t) {
      unsigned int s0 = t / 2;
      int x, y;
      boost::tie(x, y) = index2xy(s0);
      unsigned int s1, s2;
      if (t % 2 == 0) {
        // upward triangle
        s1 = xy2index(x + 1, y    );
        s2 = xy2index(x    , y + 1);
      } else {
        // downward triangle
        s1 = xy2index(x    , y + 1);
        s2 = xy2index(x - 1, y + 1);
      }
      tsites_[t][index2sublattice(s0)] = s0;
      tsites_[t][index2sublattice(s1)] = s1;
      tsites_[t][index2sublattice(s2)] = s2;
    }
  }
  unsigned int get_length_x() const { return length_x_; }
  unsigned int get_length_y() const { return length_y_; }
  unsigned int num_sites() const { return length_x_ * length_y_; }
  unsigned int num_bonds() const { return 3 * num_sites(); }
  unsigned int num_triangles() const { return 2 * num_sites(); }
  unsigned int source(unsigned int b) const { return bsites_[b][0]; }
  unsigned int target(unsigned int b) const { return bsites_[b][1]; }
  unsigned int asite(unsigned int t) const { return tsites_[t][0]; }
  unsigned int bsite(unsigned int t) const { return tsites_[t][1]; }
  unsigned int csite(unsigned int t) const { return tsites_[t][2]; }
  unsigned int num_neighbors() const { return 6; }
  unsigned int neighbor(unsigned int s, unsigned int k) const { return neighbors_[s][k]; }
  double phase(unsigned int s) const { return phase_[s]; }
protected:
  boost::tuple<int, int> index2xy(unsigned int s) const {
    return boost::make_tuple(s % length_x_, s / length_x_);
  }
  unsigned int xy2index(int x, int y) const {
    x += length_x_;
    y += length_y_;
    return x % length_x_ + (y % length_y_) * length_x_;
  }
  unsigned int index2sublattice(unsigned int s) const {
    int x, y;
    boost::tie(x, y) = index2xy(s);
    return (x + 2 * y) % 3;
  }
  boost::tuple<double, double> index2coordinate(unsigned int s) const {
    int x, y;
    boost::tie(x, y) = index2xy(s);
    return boost::make_tuple(1.0 * x + 0.5 * y, std::sqrt(3.0/4) * y);
  }
private:
  unsigned int length_x_, length_y_;
  std::vector<boost::array<unsigned int, 6> > neighbors_;
  std::vector<boost::array<unsigned int, 2> > bsites_;
  std::vector<boost::array<unsigned int, 3> > tsites_;
  std::vector<double> phase_;
};

} // end namespace lattice

#endif // LATTICE_TRIANGULAR_HPP
