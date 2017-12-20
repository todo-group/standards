// Copyright (C) 2016-2017 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <boost/lexical_cast.hpp>
#include <lattice/fully_connected.hpp>

int main(int argc, char** argv) {
  unsigned int N = 8;
  if (argc >= 2) {
    N = boost::lexical_cast<unsigned int>(argv[1]);
  }
  lattice::fully_connected lat(N);
  std::cout << "Fully connected lattice with N = " << N << std::endl
            << "Number of sites = " << lat.num_sites() << std::endl
            << "Number of bonds = " << lat.num_bonds() << std::endl;
  std::cout << "[neighboring sites]\n";
  for (unsigned int s = 0; s < lat.num_sites(); ++s) {
    std::cout << s << ":";
    for (unsigned int n = 0; n < lat.num_neighbors(); ++n) {
      std::cout << " " << lat.neighbor(s, n);
    }
    std::cout << std::endl;
  }
  return 0;
}
