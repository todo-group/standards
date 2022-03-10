cmake_minimum_required(VERSION 3.14)
include(cmake/prefix.cmake)
project(standards CXX)
include(cmake/postfix.cmake)

include_directories(${PROJECT_SOURCE_DIR})

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  include(googletest)
  FetchContent_MakeAvailable(${FetchContents})
  add_subdirectory(standards)
  add_subdirectory(test)
  add_subdirectory(example)
endif()
