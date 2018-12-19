// Copyright (C) 2016-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <iostream>
#include <standards/cubic.hpp>

int main(int argc, char** argv) {
  unsigned int Lx = 4;
  unsigned int Ly = 4;
  unsigned int Lz = 4;
  if (argc == 2) {
    Lx = Ly = std::atoi(argv[1]);
  } else if (argc == 3) {
    Lx = std::atoi(argv[1]);
    Ly = Lz =atoi(argv[2]);
  } else if (argc >= 4) {
    Lx = std::atoi(argv[1]);
    Ly = std::atoi(argv[2]);
    Lz = std::atoi(argv[3]);
  }
  standards::cubic lat(Lx, Ly, Lz);
  std::cout << "Cubic lattice with Lx = " << Lx << ", Ly = " << Ly << " and Lz = "
            << Lz << std::endl
            << "Number of sites = " << lat.num_sites() << std::endl
            << "Number of bonds = " << lat.num_bonds() << std::endl;

  std::cout << "[sublattice and phase of sites]\n";
  for (unsigned int s = 0; s < lat.num_sites(); ++s) {
    std::cout << s << ": " << lat.sublattice(s) << ' ' << lat.phase(s) << std::endl;
  }
  std::cout << "[neighboring sites]\n";
  for (unsigned int s = 0; s < lat.num_sites(); ++s) {
    std::cout << s << ":";
    for (unsigned int n = 0; n < lat.num_neighbors(); ++n) {
      std::cout << " " << lat.neighbor(s, n);
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
  return 0;
}
