set xrange [0:0.26]
set grid
set xlabel "1/n"
mu = 0.75
sigma2 = 0.1875
sx = -0.09375
kx = 0.0820312
plot \
sigma2**2 notitle, \
"< tail -10 ../../stat/bernoulli_distribution.op" u (1/$1):10:11 w e notitle pt 4
