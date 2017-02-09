set xrange [0:0.26]
set grid
set xlabel "1/n"
plot \
"< awk 'NF==17 {print}' ../../stat/bernoulli_distribution.op" u (1/$1):2:3 w e notitle pt 4, \
"< awk 'NF==17 {print}' ../../stat/bernoulli_distribution.op" u (1/$1):4:5 w e notitle pt 4, \
"< awk 'NF==17 {print}' ../../stat/bernoulli_distribution.op" u (1/$1):6:7 w e notitle pt 4, \
"< awk 'NF==17 {print}' ../../stat/bernoulli_distribution.op" u (1/$1):8:9 w e notitle pt 4, \
"< awk 'NF==17 {print}' ../../stat/bernoulli_distribution.op" u (1/$1):10:11 w e notitle pt 4, \
"< awk 'NF==17 {print}' ../../stat/bernoulli_distribution.op" u (1/$1):12:13 w e notitle pt 4, \
"< awk 'NF==17 {print}' ../../stat/bernoulli_distribution.op" u (1/$1):14:15 w e notitle pt 4, \
"< awk 'NF==17 {print}' ../../stat/bernoulli_distribution.op" u (1/$1):16:17 w e notitle pt 4
