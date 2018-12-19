// Copyright (C) 1997-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <iostream>
#include <standards/triangular.hpp>

int main(int argc, char** argv) {
  unsigned int L = 6;
  unsigned int M = 3;
  if (argc == 2) {
    L = M = std::atoi(argv[1]);
  } else if (argc >= 3) {
    L = std::atoi(argv[1]);
    M = std::atoi(argv[2]);
  }

  standards::triangular lat(L, M);
  std::cout << "Triangular lattice with L = " << L << " and M = " << M << std::endl
            << "Number of sites = " << lat.num_sites() << std::endl
            << "Number of bonds = " << lat.num_bonds() << std::endl
            << "Number of triangles = " << lat.num_triangles() << std::endl;

  std::cout << "[sublattice and phase of sites]\n";
  for (unsigned int s = 0; s < lat.num_sites(); ++s) {
    std::cout << s << ": " << lat.sublattice(s) << ' ' << lat.phase(s) << std::endl;
  }
  std::cout << "[neighboring sites]\n";
  for (unsigned int s = 0; s < lat.num_sites(); ++s) {
    std::cout << s << ":";
    for (unsigned int k = 0; k < lat.num_neighbors(); ++k) {
      std::cout << " " << lat.neighbor(s, k);
    }
    std::cout << std::endl;
  }
  std::cout << "[neighboring bonds]\n";
  for (unsigned int s = 0; s < lat.num_sites(); ++s) {
    std::cout << s << ":";
    for (unsigned int k = 0; k < lat.num_neighbors(); ++k) {
      std::cout << " " << lat.neighbor_bond(s, k);
    }
    std::cout << std::endl;
  }
  std::cout << "[source and target of bonds]\n";
  for (unsigned int b = 0; b < lat.num_bonds(); ++b) {
    std::cout << b << ": " << lat.source(b) << " -- " << lat.target(b) << std::endl;
  }
  std::cout << "[neighboring triangles]\n";
  for (unsigned int s = 0; s < lat.num_sites(); ++s) {
    std::cout << s << ":";
    for (unsigned int k = 0; k < lat.num_neighbors(); ++k) {
      std::cout << " " << lat.neighbor_triangle(s, k);
    }
    std::cout << std::endl;
  }
  std::cout << "[sites of triangles]\n";
  for (unsigned int p = 0; p < lat.num_triangles(); ++p) {
    std::cout << p << ": " << lat.triangle_site(p, 0) << " -- " << lat.triangle_site(p, 1) << " -- " << lat.triangle_site(p, 2) << std::endl;
  }
  return 0;
}
