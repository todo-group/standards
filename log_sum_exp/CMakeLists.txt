include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(PROGS exp_number)
foreach(name ${PROGS})
  add_executable(${name} ${name}.cpp)
endforeach(name)
