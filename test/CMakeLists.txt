set(PROGS
  timer
  simpson
  exp_number power
  bisection golden_section nelder_mead newton
  chain square triangular cubic
)
foreach(name ${PROGS})
  set(target_name test_${name})
  add_executable(${target_name} ${name}.cpp)
  set_target_properties(${target_name} PROPERTIES OUTPUT_NAME ${name})
  target_link_libraries(${target_name} gtest_main)
  add_test(${target_name} ${name})
endforeach(name)
