cmake_minimum_required(VERSION 3.14)
project(standards NONE)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(core)

# dependencies
include(googletest)
FetchContent_MakeAvailable(googletest)

enable_testing()
include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(standards)
add_subdirectory(test)
add_subdirectory(example)
