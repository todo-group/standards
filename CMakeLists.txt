cmake_minimum_required(VERSION 3.14)
project(standards NONE)

option(STANDARDS_INSTALL "Install standards." ON)
option(STANDARDS_BUILD_TESTS "Build all standards' tests." ON)
option(STANDARDS_BUILD_EXAMPLES "Build all standards' examples." ON)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(core)

include_directories(${standards_SOURCE_DIR})
enable_testing()

include(googletest)
FetchContent_MakeAvailable(googletest)

if(STANDARDS_INSTALL)
  add_subdirectory(standards)
endif(STANDARDS_INSTALL)
if(STANDARDS_BUILD_TESTS)
  add_subdirectory(test)
endif(STANDARDS_BUILD_TESTS)
if(STANDARDS_BUILD_EXAMPLES)
  add_subdirectory(example)
endif(STANDARDS_BUILD_EXAMPLES)
