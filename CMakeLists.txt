cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(standards NONE)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/config)
include(core)

include_directories(${PROJECT_SOURCE_DIR})

# Google Test
set(GOOGLETEST_VERSION 1)
if(EXISTS googletest/include)
  add_subdirectory(googletest)
  include_directories(googletest/include)
else(EXISTS googletest/googletest)
  add_subdirectory(googletest/googletest)
  include_directories(googletest/googletest/include)
endif(EXISTS googletest/include)

# IO Test
include(add_iotest)
enable_testing()

add_subdirectory(standards)
add_subdirectory(test)
add_subdirectory(example)
