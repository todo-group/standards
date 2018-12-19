/*****************************************************************************
*
* Copyright (C) 2016-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
*
* Distributed under the Boost Software License, Version 1.0. (See accompanying
* file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*
*****************************************************************************/

#include <cstdlib>
#include <iostream>

class hamiltonian {
public:
  // z[0]: position, z[1]: momentum
  double energy(double t, std::vector<double> const& z) const {
    return potential_energy(t, z) + kinetic_energy(t, z);
  }
  double potential_energy(double /* t */, std::vector<double> const& z) const {
    return 0.5 * z[0] * z[0];
  }
  double kinetic_energy(double /* t */, std::vector<double> const& z) const {
    return 0.5 * z[1] * z[1];
  }
  // "force" calculation
  void operator()(double /* t */, std::vector<double> const& z, std::vector<double>& force) const {
    force[0] = z[1];
    force[1] = -z[0];
  }
};

int main(int argc, char **argv) {
  double t_init = 0;
  double t_final = 10;
  double dt = 0.1;
  if (argc >= 2) t_final = std::atof(argv[1]);
  if (argc >= 3) dt = std::atof(argv[2]);
  std::cout << "# " << integrator_t::name() << std::endl
            << "# t_init  = " << t_init << std::endl
            << "# t_final = " << t_final << std::endl
            << "# dt      = " << dt << std::endl;
  
  std::vector<double> z(2);
  z[0] = 1;
  z[1] = 0;

  hamiltonian ham;

  integrator_t integrator(2);
  for (double t = t_init; t <= t_final; t += dt) {
    std::cout << t << ' ' << z[0] << ' ' << z[1] << ' ' << ham.energy(t, z) << std::endl;
    integrator.step(t, dt, z, ham);
  }
}
