// Copyright (C) 1997-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <gtest/gtest.h>
#include <standards/triangular.hpp>

void test(standards::triangular const& lat) {
  EXPECT_EQ(lat.get_length_x() * lat.get_length_y(), lat.num_sites());
  EXPECT_EQ(3 * lat.get_length_x() * lat.get_length_y(), lat.num_bonds());
  EXPECT_EQ(2 * lat.get_length_x() * lat.get_length_y(), lat.num_triangles());
  EXPECT_EQ(6, lat.num_neighbors());

  std::cout << "[test for sites]\n";
  for (unsigned int s = 0; s < lat.num_sites(); ++s) {
    for (unsigned int k = 0; k < lat.num_neighbors(); ++k) {
      std::cout << s << ' ' << lat.neighbor(s, k) << ' ' << lat.neighbor_bond(s, k) << std::endl;
      EXPECT_FALSE(lat.sublattice(s) == lat.sublattice(lat.neighbor(s, k)));
      EXPECT_TRUE(lat.source(lat.neighbor_bond(s, k)) == s ||
                  lat.target(lat.neighbor_bond(s, k)) == s);
      EXPECT_TRUE(lat.bond_site(lat.neighbor_bond(s, k), 0) == s ||
                  lat.bond_site(lat.neighbor_bond(s, k), 1) == s);
      EXPECT_TRUE(lat.triangle_site(lat.neighbor_triangle(s, k), lat.sublattice(s)) == s);
    }
  }

  std::cout << "[test for bonds]\n";
  for (unsigned int b = 0; b < lat.num_bonds(); ++b) {
    unsigned int s = lat.source(b);
    unsigned int t = lat.target(b);
    std::cout << b << ' ' << s << ' ' << t << std::endl;
    EXPECT_FALSE(s == t);
    EXPECT_FALSE(lat.sublattice(s) == lat.sublattice(t));
    EXPECT_TRUE(lat.neighbor_bond(s, 0) == b ||
                lat.neighbor_bond(s, 1) == b ||
                lat.neighbor_bond(s, 2) == b ||
                lat.neighbor_bond(s, 3) == b ||
                lat.neighbor_bond(s, 4) == b ||
                lat.neighbor_bond(s, 5) == b);
    EXPECT_TRUE(lat.neighbor_bond(t, 0) == b ||
                lat.neighbor_bond(t, 1) == b ||
                lat.neighbor_bond(t, 2) == b ||
                lat.neighbor_bond(t, 3) == b ||
                lat.neighbor_bond(t, 4) == b ||
                lat.neighbor_bond(t, 5) == b);
  }

  std::vector<unsigned int> count(lat.num_sites(), 0);
  for (unsigned int b = 0; b < lat.num_bonds(); ++b) {
    ++count[lat.source(b)];
    ++count[lat.target(b)];
  }
  for (unsigned int s = 0; s < lat.num_sites(); ++s) {
    EXPECT_EQ(6, count[s]);
  }

  std::cout << "[test for triangles]\n";
  for (unsigned int p = 0; p < lat.num_triangles(); ++p) {
    unsigned int sa = lat.triangle_site(p, 0);
    unsigned int sb = lat.triangle_site(p, 1);
    unsigned int sc = lat.triangle_site(p, 2);
    std::cout << p << ' ' << sa << ' ' << sb << ' ' << sc << std::endl;
    EXPECT_FALSE(sa == sb);
    EXPECT_FALSE(sb == sc);
    EXPECT_FALSE(sc == sa);
    EXPECT_EQ(0, lat.sublattice(sa));
    EXPECT_EQ(1, lat.sublattice(sb));
    EXPECT_EQ(2, lat.sublattice(sc));
    EXPECT_TRUE(lat.neighbor_triangle(sa, 0) == p ||
                lat.neighbor_triangle(sa, 1) == p ||
                lat.neighbor_triangle(sa, 2) == p ||
                lat.neighbor_triangle(sa, 3) == p ||
                lat.neighbor_triangle(sa, 4) == p ||
                lat.neighbor_triangle(sa, 5) == p);
    EXPECT_TRUE(lat.neighbor_triangle(sb, 0) == p ||
                lat.neighbor_triangle(sb, 1) == p ||
                lat.neighbor_triangle(sb, 2) == p ||
                lat.neighbor_triangle(sb, 3) == p ||
                lat.neighbor_triangle(sb, 4) == p ||
                lat.neighbor_triangle(sb, 5) == p);
    EXPECT_TRUE(lat.neighbor_triangle(sc, 0) == p ||
                lat.neighbor_triangle(sc, 1) == p ||
                lat.neighbor_triangle(sc, 2) == p ||
                lat.neighbor_triangle(sc, 3) == p ||
                lat.neighbor_triangle(sc, 4) == p ||
                lat.neighbor_triangle(sc, 5) == p);
  }

  for (unsigned int p = 0; p < lat.num_triangles(); ++p) {
    ++count[lat.triangle_site(p, 0)];
    ++count[lat.triangle_site(p, 1)];
    ++count[lat.triangle_site(p, 2)];
  }
  for (unsigned int s = 0; s < lat.num_sites(); ++s) {
    EXPECT_EQ(12, count[s]);
  }
}

TEST(TriangularTest, Triangular33) {
  unsigned int L = 3;
  unsigned int M = 3;
  standards::triangular lat(L, M);
  EXPECT_EQ(L, lat.get_length_x());
  EXPECT_EQ(M, lat.get_length_y());
  test(lat);
}

TEST(TriangularTest, Triangular93) {
  unsigned int L = 9;
  unsigned int M = 3;
  standards::triangular lat(L, M);
  EXPECT_EQ(L, lat.get_length_x());
  EXPECT_EQ(M, lat.get_length_y());
  test(lat);
}

TEST(TriangularTest, Triangular96) {
  unsigned int L = 9;
  unsigned int M = 6;
  standards::triangular lat(L, M);
  EXPECT_EQ(L, lat.get_length_x());
  EXPECT_EQ(M, lat.get_length_y());
  test(lat);
}
