#ifndef INTEGRATOR_HPP
#define INTEGRATOR_HPP

#include <string>
#include <vector>

namespace integrator {

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
  
class rk2 {
public:
  static std::string name() { return "2nd-order Runge-Kutta method"; }
  rk2(unsigned int dim) : dim_(dim), k1_(dim), k2_(dim), yt_(dim) {}
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
  
class rk3 {
public:
  static std::string name() { return "3rd-order Runge-Kutta method"; }
  rk3(unsigned int dim) : dim_(dim), k1_(dim), k2_(dim), k3_(dim), yt_(dim) {}
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

class rk4 {
public:
  static std::string name() { return "4th-order Runge-Kutta method"; }
  rk4(unsigned int dim) : dim_(dim), k1_(dim), k2_(dim), k3_(dim), k4_(dim), yt_(dim) {}
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

} // namespace integrator

#endif // INTEGRATOR_HPP
