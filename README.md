[![Build Status](https://github.com/todo-group/standards/workflows/build/badge.svg)](https://github.com/todo-group/standards/actions?query=workflow%3Abuild)

# Standards -- standard algorithms

* config: standard configuration for CMake

* numerical integration

  * simpson_1d - 1D Integration by Simpson rule
  * simpson_2d - 2D Integration by Simpson rule

* log-sum-exp: basic arithmetic of huge (or tiny) numbers

  * exp_number

* math: mathematical utilities

  * power2, power3, power4, power6 - integral power of 
    a variable

* integrator: initial value problem of ordinary differential equations

  * euler - Euler method
  * rk2 - 2nd order Runge-Kutta method
  * rk3 - 3nd order Runge-Kutta method
  * rk4 - 4nd order Runge-Kutta method

* optimization:

  * bisection - find zero of 1D function by bisection method
  * golden_section - find (local) minimum of 1D function by golden-secion method
  * nelder_mead - find (local) minimum of arbitrary dimansional function by Nelder-Mead method
  * newton - Newton-Raphson method for finding zero of 1D and higher-D functions
  * mccormick - McCormick function
  * rastrigin - Rastrigin function

* statics

  * accumulator - estimate central moments and cumulants of random samples
  * moment
  * histogram - basic histogram
  * bernoulli_distribution - Bernoulli distribution
  * normal_distribution - Normal distribution

* timer: a simple timer class (similar to boost.timer)
