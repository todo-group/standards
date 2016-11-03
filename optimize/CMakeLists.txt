set(PROGS bisection golden_section)
foreach(name ${PROGS})
  add_executable(${name} ${name}.cpp)
endforeach(name)
