cmake_minimum_required(VERSION 3.14)
include(cmake/prefix.cmake)
project(standards CXX)
include(cmake/postfix.cmake)

option(STANDARDS_INSTALL "Install standards." ON)
option(STANDARDS_BUILD_TESTS "Build all standards' tests." ON)
option(STANDARDS_BUILD_EXAMPLES "Build all standards' examples." ON)

include(googletest)
FetchContent_MakeAvailable(googletest)

include_directories(${PROJECT_SOURCE_DIR})

if(STANDARDS_INSTALL)
  add_subdirectory(standards)
endif(STANDARDS_INSTALL)
if(STANDARDS_BUILD_TESTS)
  add_subdirectory(test)
endif(STANDARDS_BUILD_TESTS)
if(STANDARDS_BUILD_EXAMPLES)
  add_subdirectory(example)
endif(STANDARDS_BUILD_EXAMPLES)
