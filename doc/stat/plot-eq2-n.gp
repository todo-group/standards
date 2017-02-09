set xrange [0:0.26]
set grid
set xlabel "1/n"
mu = 2
sigma2 = 2.25
sx = 0
plot \
x*sx*mu + (1+3*x)*sigma2*mu**2+x*sigma2**2+mu**4 notitle, \
"< tail -10 ../../stat/normal_distribution.op" u (1/$1):4:5 w e notitle pt 4
