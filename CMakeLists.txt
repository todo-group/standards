cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(standards NONE)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/config)
include(core)

include_directories(${PROJECT_SOURCE_DIR})

# Google Test
set(GOOGLETEST_VERSION 1)
add_subdirectory(googletest)
include_directories(googletest/include)
enable_testing()

# IO Test (to be removed)
include(add_iotest)

add_subdirectory(standards)
add_subdirectory(test)
add_subdirectory(example)
