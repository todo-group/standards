# Standards -- standard algorithms

* config: standard configuration for CMake

* integral: numerical integration

  * integral::simpson_1d - 1D Integration by Simpson rule
  * integral::simpson_2d - 2D Integration by Simpson rule

* lattice: simple lattices

  * lattice::chain - 1D chain lattice
  * lattice::square - 2D square lattice
  * lattice::cubic - 3D simple cubic lattice
  * lattice::fully_connected - (infinite-D) fully-connected lattice

* lse: basic arithmetic of huge (or tiny) numbers based
  on log-sum-exp technique

* math: mathematical utilities

  * power2, power3, power4, power6 - integral power of 
    a variable

* ode: initial value problem of ordinary differential equations

  * integrator::euler - Euler method
  * integrator::rk2 - 2nd order Runge-Kutta method
  * integrator::rk3 - 3nd order Runge-Kutta method
  * integrator::rk4 - 4nd order Runge-Kutta method

* optimize: optimization problem

  * optimize::bisection - find zero of 1D function by bisection method
  * optimize::golden_section - find (local) minimum of 1D function by golden-secion method
  * optimize::nelder_mead - find (local) minimum of arbitrary dimansional function by Nelder-Mead method

* stat: statics

  * stat::accumulator - estimate central moments and cumulants of random samples

* timer: a simple timer class (similar to boost.timer)
