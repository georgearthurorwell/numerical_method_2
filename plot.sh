#!/bin/bash

gnuplot << EOP

datafile = "output.txt"

set terminal jpeg font arial 8 size 1000,1000
set output "plot.jpg"
set grid x y
set xlabel "X"
set ylabel "Y"
set y2tics
set xrange [-1:1]
set yrange [-10:20]

plot abs(x) title "F=" with lines, \
     datafile using 1:2 title "F'" with lines, \
     datafile using 1:3 title "F1'" with lines

EOP
