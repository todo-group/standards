#  Copyright (C) 2016 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
#
#  Distributed under the Boost Software License, Version 1.0. (See accompanying
#  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(standards NONE)
include(config/core.cmake)

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(integral)
add_subdirectory(log_sum_exp)
add_subdirectory(ode)
add_subdirectory(optimize)
add_subdirectory(stat)
