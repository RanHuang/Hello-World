set title "Simple Function Plot"
set xrange [-3.1415926:3.1415926]
set yrange [-1.1:1.1]
set xlabel "theta"
set ylabel "sin(theta)"
set label "sin(0.0)" at 0.0, 0.0
plot sin(x)
