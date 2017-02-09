set xrange [0:0.26]
set grid
set xlabel "1/n"
mu = 2
sigma2 = 2.25
sx = 0
plot \
(2*x**2)*sx*mu + (5*x)*sigma2*mu**2+(2*x**2)*sigma2**2+mu**4 notitle, \
"< tail -10 ../../stat/normal_distribution.op" u (1/$1):2:3 w e notitle pt 4
