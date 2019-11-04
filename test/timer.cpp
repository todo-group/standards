/*****************************************************************************
*
* Copyright (C) 2014-2018 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
*
* Distributed under the Boost Software License, Version 1.0. (See accompanying
* file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*
*****************************************************************************/

#include <unistd.h>
#include <gtest/gtest.h>
#include <standards/timer.hpp>

TEST(TimerTest, elapsed) {
  standards::timer timer;
  sleep(1);
  std::cerr << timer.elapsed() << std::endl;
}

TEST(TimerTest, reset) {
  standards::timer timer;
  sleep(1);
  std::cerr << timer.elapsed() << std::endl;
  timer.reset();
  sleep(1);
  std::cerr << timer.elapsed() << std::endl;
}
