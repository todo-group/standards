cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(standards NONE)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/config)
include(core)

include_directories(${PROJECT_SOURCE_DIR})

# Google Test
set(GOOGLETEST_VERSION 1)
add_subdirectory(tool/googletest/googletest)
include_directories(tools/googletest/googletest/include)

# IO Test
include(add_iotest)
enable_testing()

add_subdirectory(standards)
add_subdirectory(test)
add_subdirectory(example)
