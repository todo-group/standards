// Copyright (C) 1997-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <gtest/gtest.h>
#include <standards/chain.hpp>

void test(standards::chain const& lat) {
  EXPECT_EQ(lat.get_length(), lat.num_sites());
  EXPECT_EQ(lat.get_length(), lat.num_bonds());
  EXPECT_EQ(2, lat.num_neighbors());

  std::cout << "[test for sites]\n";
  for (unsigned int s = 0; s < lat.num_sites(); ++s) {
    for (unsigned int k = 0; k < lat.num_neighbors(); ++k) {
      std::cout << s << ' ' << lat.neighbor(s, k) << ' ' << lat.neighbor_bond(s, k) << std::endl;
      EXPECT_FALSE(lat.sublattice(s) == lat.sublattice(lat.neighbor(s, k)));
      EXPECT_TRUE(lat.source(lat.neighbor_bond(s, k)) == s ||
                  lat.target(lat.neighbor_bond(s, k)) == s);
      EXPECT_TRUE(lat.bond_site(lat.neighbor_bond(s, k), 0) == s ||
                  lat.bond_site(lat.neighbor_bond(s, k), 1) == s);
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
                lat.neighbor_bond(s, 1) == b);
    EXPECT_TRUE(lat.neighbor_bond(t, 0) == b ||
                lat.neighbor_bond(t, 1) == b);
  }

  std::vector<unsigned int> count(lat.num_sites(), 0);
  for (unsigned int b = 0; b < lat.num_bonds(); ++b) {
    ++count[lat.source(b)];
    ++count[lat.target(b)];
  }
  for (unsigned int s = 0; s < lat.num_sites(); ++s) {
    EXPECT_EQ(2, count[s]);
  }
}

TEST(ChainTest, Chain16) {
  unsigned int L = 16;
  standards::chain lat(L);
  EXPECT_EQ(L, lat.get_length());
  test(lat);
}
