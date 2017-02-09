set xrange [0:0.26]
set grid
set xlabel "1/n"
mu = 0.75
sigma2 = 0.1875
sx = -0.09375
plot \
x*sx*mu + (1+3*x)*sigma2*mu**2+x*sigma2**2+mu**4 notitle, \
"< tail -10 ../../stat/bernoulli_distribution.op" u (1/$1):4:5 w e notitle pt 4
