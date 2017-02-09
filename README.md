# Standard Algorithms

* integral: numerical integration

  * integral::simpson_1d - 1D Integration by Simpson rule
  * integral::simpson_2d - 2D Integration by Simpson rule

* log_sum_exp: basic arithmetic of huge (or tiny) numbers

* math: mathematical utilities

  * power2, power3, power4, power6 - integral power of a variable

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
