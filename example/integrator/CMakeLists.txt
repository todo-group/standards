set(PROGS harmonic_euler harmonic_rk2 harmonic_rk3 harmonic_rk4 harmonic_verlet harmonic_yoshida)
foreach(name ${PROGS})
  add_executable(${name} ${name}.cpp)
  target_link_libraries(${name} standards)
  add_test(${name} ${name})
endforeach(name)
