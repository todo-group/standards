cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(standards NONE)

include(config/core.cmake)

include_directories(${PROJECT_SOURCE_DIR}/include)

# Boost
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

# Google Test
set(GOOGLETEST_VERSION 1)
add_subdirectory(tool/googletest)
include_directories(tools/googletest/include)

# IO Test
include(add_iotest)
enable_testing()

add_subdirectory(test)
add_subdirectory(example)
