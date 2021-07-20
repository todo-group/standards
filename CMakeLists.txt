cmake_minimum_required(VERSION 3.4)
project(standards NONE)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(core)

include_directories(${PROJECT_SOURCE_DIR})

# Google Test
set(GOOGLETEST_VERSION 1.11.0)
add_subdirectory(googletest/googletest)
include_directories(googletest/googletest/include)
enable_testing()

add_subdirectory(standards)
add_subdirectory(test)
add_subdirectory(example)
