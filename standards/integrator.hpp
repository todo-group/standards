/*****************************************************************************
*
* Copyright (C) 2016-2019 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
*
* Distributed under the Boost Software License, Version 1.0. (See accompanying
* file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*
*****************************************************************************/

#ifndef STANDARDS_INTEGRATOR_HPP
#define STANDARDS_INTEGRATOR_HPP

#include <cmath>
#include <string>
#include <vector>

namespace standards {

class euler {
public:
  static std::string name() { return "Euler method"; }
  euler(unsigned int dim) : dim_(dim), k_(dim) {}
  template<class F>
  void step(double t, double h, std::vector<double>& y, F const& f) const {
    f(t, y, k_);
    for (int i = 0; i < dim_; ++i) y[i] += h * k_[i];
  }
private:
  unsigned int dim_;
  mutable std::vector<double> k_;
};
  
class runge_kutta_2 {
public:
  static std::string name() { return "2nd-order Runge-Kutta method"; }
  runge_kutta_2(unsigned int dim) : dim_(dim), k1_(dim), k2_(dim), yt_(dim) {}
  template<class F>
  void step(double t, double h, std::vector<double>& y, F const& f) const {
    double h2 = h / 2;
    f(t, y, k1_);
    for (int i = 0; i < dim_; ++i) yt_[i] = y[i] + h2 * k1_[i];
    f(t + h2, yt_, k2_);
    for (int i = 0; i < dim_; ++i) y[i] += h * k2_[i];
  }
private:
  unsigned int dim_;
  mutable std::vector<double> k1_;
  mutable std::vector<double> k2_;
  mutable std::vector<double> yt_;
};
  
class runge_kutta_3 {
public:
  static std::string name() { return "3rd-order Runge-Kutta method"; }
  runge_kutta_3(unsigned int dim) : dim_(dim), k1_(dim), k2_(dim), k3_(dim), yt_(dim) {}
  template<class F>
  void step(double t, double h, std::vector<double>& y, F const& f) const {
    double h23 = 2 * h / 3;
    f(t, y, k1_);
    for (int i = 0; i < dim_; ++i) yt_[i] = y[i] + h23 * k1_[i];
    f(t + h23, yt_, k2_);
    for (int i = 0; i < dim_; ++i) yt_[i] = y[i] + h23 * k2_[i];
    f(t + h23, yt_, k3_);
    for (int i = 0; i < dim_; ++i)
      y[i] = y[i] + (h / 8) * (2 * k1_[i] + 3 * k2_[i] + 3 * k3_[i]);
  }
private:
  unsigned int dim_;
  mutable std::vector<double> k1_;
  mutable std::vector<double> k2_;
  mutable std::vector<double> k3_;
  mutable std::vector<double> yt_;
};

class runge_kutta_4 {
public:
  static std::string name() { return "4th-order Runge-Kutta method"; }
  runge_kutta_4(unsigned int dim) : dim_(dim), k1_(dim), k2_(dim), k3_(dim), k4_(dim), yt_(dim) {}
  template<class F>
  void step(double t, double h, std::vector<double>& y, F const& f) const {
    double h2 = h / 2;
    f(t, y, k1_);
    for (int i = 0; i < dim_; ++i) yt_[i] = y[i] + h2 * k1_[i];
    f(t + h2, yt_, k2_);
    for (int i = 0; i < dim_; ++i) yt_[i] = y[i] + h2 * k2_[i];
    f(t + h2, yt_, k3_);
    for (int i = 0; i < dim_; ++i) yt_[i] = y[i] + h * k3_[i];
    f(t + h, yt_, k4_);
    for (int i = 0; i < dim_; ++i)
      y[i] = y[i] + (h / 6) * (k1_[i] + 2 * k2_[i] + 2 * k3_[i] + k4_[i]);
  }
private:
  unsigned int dim_;
  mutable std::vector<double> k1_;
  mutable std::vector<double> k2_;
  mutable std::vector<double> k3_;
  mutable std::vector<double> k4_;
  mutable std::vector<double> yt_;
};

class velocity_velret {
public:
  static std::string name() { return "Velocity Verlet method"; }
  velocity_velret(int dim) : dim_(dim), k1_(dim), k2_(dim) {}
  template<class F>
  void step(double t, double h, std::vector<double>& y, F const& f) const {
    const double h22 = h * h / 2;
    const double h2 = h / 2;
    const int  dim2 = dim_ / 2;
    f(t, y, k1_);
    for (int i = 0; i < dim2; ++i) y[i] = y[i] +  h * k1_[i] + h22 * k1_[i + dim2];
    f(t + h, y, k2_);
    for (int i = dim2; i < dim_; ++i) y[i] = y[i] +  h2 * (k2_[i]+k1_[i]);
  }
private:
  int dim_;
  mutable std::vector<double> k1_;
  mutable std::vector<double> k2_;
};

// ref .American Journal of Physics 73, 938 (2005) 
//      or original paper : Phys. Lett. A 150, 262–268 (1990)

class yoshida_symplectic_4 {
public:
  static std::string name() { return "4th-order Yoshida symplectic method"; }
  yoshida_symplectic_4(int dim) : dim_(dim), k1_(dim), k2_(dim), k3_(dim), k4_(dim){}
  template<class F>
  void step(double t, double h, std::vector<double>& y, F const& f) const {
    const int  dim2 = dim_ / 2;
    const double h2 = h * h;
    double b1 = 1.0/(4.0 - 2.0*std::pow(2.0,1.0/3.0));  
    double b2 = (1.0 - std::pow(2.0,1.0/3.0))/(4.0 - 2.0*std::pow(2.0,1.0/3.0));  
    double c1 = 1.0 / (2.0 - std::pow(2.0,1.0/3.0));
    double c2 = 1.0 / (1.0 - std::pow(2.0,2.0/3.0));
    f(t, y, k1_);
    for (int i = 0; i < dim2; ++i){
      y[i] = y[i] +  h * c1 * k1_[i] + h2 * c1 * b1 * k1_[i+dim2];
      y[i + dim2] = y[i + dim2] + h * b1 * k1_[i + dim2];
    }
    f(t, y, k2_);
    for (int i = 0; i < dim2; ++i){
      y[i] = y[i] +  h * c2 * k2_[i] + h2 * c2 * b2 * k2_[i+dim2];
      y[i + dim2] = y[i + dim2] + h * b2 * k2_[i + dim2];
    }
    f(t, y, k3_);
    for (int i = 0; i < dim2; ++i){
      y[i] = y[i] +  h * c1 * k3_[i] + h2 * c1 * b2 * k3_[i+dim2];
      y[i + dim2] = y[i + dim2] + h * b2 * k3_[i + dim2];
    }
    f(t, y, k4_);
    for (int i = dim2; i < dim_; ++i) y[i] = y[i] + h * b1 * k4_[i];
  }
private:
  int dim_;
  mutable std::vector<double> k1_;
  mutable std::vector<double> k2_;
  mutable std::vector<double> k3_;
  mutable std::vector<double> k4_;
};


} // namespace standards

#endif // STANDARDS_INTEGRATOR_HPP
