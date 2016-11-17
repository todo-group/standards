/*****************************************************************************
*
* Copyright (C) 2014-2016 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
*
* Distributed under the Boost Software License, Version 1.0. (See accompanying
* file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*
*****************************************************************************/

#ifndef OPTIMIZE_NELDER_MEAD_HPP
#define OPTIMIZE_NELDER_MEAD_HPP

#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>

namespace optimize {

class nelder_mead {
public:
  template<class FUNC>
  int find_minimum(FUNC& f, std::vector<double> x0, double shift = 0.1,
    double prec = std::sqrt(std::numeric_limits<double>::epsilon())) {
    int n = x0.size();
    x.resize(n+1);
    for (int i = 0; i < n+1; ++i) x[i].resize(n);
    y.resize(n+1);
    xn.resize(n); // newly proposed point
    xg.resize(n); // cener of mass of x[0]...x[n-1]
    // initial condition
    x[0] = x0;
    y[0] = f(x[0]);
    for (int i = 0; i < n; ++i) {
      x[i+1] = x0;
      x[i+1][i] += shift;
      y[i+1] = f(x[i+1]);
    }
    int counter = n+1;
    while (true) {
      // set y[n] as the largest, y[n-1] as the second largest, and y[0] the smallest
      for (int i = 0; i < n; ++i) {
        if (y[i] > y[n]) {
          std::swap(x[i], x[n]);
          std::swap(y[i], y[n]);
        }
      }
      for (int i = 1; i < n; ++i) {
        if (y[i] < y[0]) {
          std::swap(x[i], x[0]);
          std::swap(y[i], y[0]);
        }
      }
      for (int i = 1; i < n-1; ++i) {
        if (y[i] > y[n-1]) {
          std::swap(x[i], x[n-1]);
          std::swap(y[i], y[n-1]);
        }
      }
      // center of mass except for x[n]
      for (int j = 0; j < n; ++j) xg[j] = 0.0;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          xg[j] += x[i][j];
        }
      }
      for (int j = 0; j < n; ++j) xg[j] /= n;
      // refrection
      for (int j = 0; j < n; ++j) xn[j] = xg[j] - (x[n][j] - xg[j]);
      ++counter;
      double yn = f(xn);
      if (yn < y[n]){
        for (int j = 0; j < n; ++j) x[n][j] = xn[j];
        y[n] = yn;
      }
      if (yn < y[0]) {
        // reduction and expansion
        for (int j = 0; j < n; ++j) xn[j] = xg[j] + 2 * (x[n][j] - xg[j]);
        ++counter;
        yn = f(xn);
        if (yn < y[0]) {
          for (int j = 0; j < n; ++j) x[n][j] = xn[j];
          y[n] = yn;
        }
      } else if (y[n] > y[n-1]) {
        // contraction
        for (int j = 0; j < n; ++j) xn[j] = xg[j] + 0.5 * (x[n][j] - xg[j]);
        ++counter;
        yn = f(xn);
        if (yn < y[n]) {
          for (int j = 0; j < n; ++j) x[n][j] = xn[j];
          y[n] = yn;
        } else {
          // contraction in all directions
          for (int i = 1; i <= n; ++i) {
            ++counter;
            for (int j = 0; j < n; ++j) x[i][j] = x[0][j] + 0.5 * (x[i][j] - x[0][j]);
            y[i] = f(x[i]);
          }
        }
      }
      // convergence check
      double diff2 = 0.0;
      for (int j = 0; j < n; ++j) diff2 += (x[n][j] - x[0][j]) * (x[n][j] - x[0][j]);
      if (diff2 < prec && std::abs(y[n] - y[0]) < prec * std::max(std::abs(y[n]), std::abs(y[0]))) {
        return counter;
      }
    }
  }
  std::vector<double> const& minarg() const { return x[0]; }
  double minval() const { return y[0]; }
private:
  std::vector<std::vector<double> > x;
  std::vector<double> y;
  std::vector<double> xn, xg;
};

} // end namespace optimize

#endif // OPTIMIZE_NELDER_MEAD_HPP
