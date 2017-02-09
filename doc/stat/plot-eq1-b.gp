set xrange [0:0.26]
set grid
set xlabel "1/n"
mu = 0.75
sigma2 = 0.1875
sx = -0.09375
plot \
(2*x**2)*sx*mu + (5*x)*sigma2*mu**2+(2*x**2)*sigma2**2+mu**4 notitle, \
"< tail -10 ../../stat/bernoulli_distribution.op" u (1/$1):2:3 w e notitle pt 4
