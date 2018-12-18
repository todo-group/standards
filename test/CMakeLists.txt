set(PROGS
  simpson
  exp_number
  bisection golden_section nelder_mead
  triangular
)
foreach(name ${PROGS})
  set(target_name test_${name})
  add_executable(${target_name} ${name}.cpp)
  set_target_properties(${target_name} PROPERTIES OUTPUT_NAME ${name})
  target_link_libraries(${target_name} gtest_main)
  add_test(${target_name} ${name})
endforeach(name)

# add_subdirectory(lattice)
# add_subdirectory(ode)
# add_subdirectory(optimize)
# add_subdirectory(stat)
