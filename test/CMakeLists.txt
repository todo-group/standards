set(PROGS
  timer
  simpson
  exp_number power
  bisection golden_section nelder_mead newton
  robbins_monro polyak_ruppert
)
foreach(name ${PROGS})
  set(target_name test_${name})
  add_executable(${target_name} ${name}.cpp)
  set_target_properties(${target_name} PROPERTIES OUTPUT_NAME ${name})
  target_link_libraries(${target_name} standards gtest_main)
  add_test(${target_name} ${name})
endforeach(name)
