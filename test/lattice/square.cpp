// Copyright (C) 2016-2017 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <boost/lexical_cast.hpp>
#include <lattice/square.hpp>

int main(int argc, char** argv) {
  unsigned int Lx = 4;
  unsigned int Ly = 3;
  if (argc == 2) {
    Lx = Ly = boost::lexical_cast<unsigned int>(argv[1]);
  } else if (argc >= 3) {
    Lx = boost::lexical_cast<unsigned int>(argv[1]);
    Ly = boost::lexical_cast<unsigned int>(argv[2]);
  }
  lattice::square lat(Lx, Ly);
  std::cout << "Square lattice with Lx = " << Lx << " and Ly = " << Ly << std::endl
            << "Number of sites = " << lat.num_sites() << std::endl
            << "Number of bonds = " << lat.num_bonds() << std::endl;

  std::cout << "[phase of sites]\n";
  for (unsigned int s = 0; s < lat.num_sites(); ++s) {
    std::cout << s << ": " << lat.site_phase(s) << std::endl;
  }
  std::cout << "[neighboring sites]\n";
  for (unsigned int s = 0; s < lat.num_sites(); ++s) {
    std::cout << s << ":";
    for (unsigned int n = 0; n < lat.num_neighbors(); ++n) {
      std::cout << " " << lat.neighbor(s, n);
    }
    std::cout << std::endl;
  }
  std::cout << "[phase of bonds]\n";
  for (unsigned int b = 0; b < lat.num_bonds(); ++b) {
    std::cout << b << ": " << lat.bond_phase(b) << std::endl;
  }
  std::cout << "[source and target of bonds]\n";
  for (unsigned int b = 0; b < lat.num_bonds(); ++b) {
    std::cout << b << ": " << lat.source(b) << " -- " << lat.target(b) << std::endl;
  }
  return 0;
}
