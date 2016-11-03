set(PROGS harmonic_euler harmonic_rk2 harmonic_rk3 harmonic_rk4)
foreach(name ${PROGS})
  add_executable(${name} ${name}.cpp)
endforeach(name)
