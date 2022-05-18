set multiplot layout 2,2 rowsfirst title "Example Multiplot"

set title "Top Left"
set hidden
set isosamples 30
set xrange [-3:3]
set yrange [-3:3]
splot sin(x*x + y*y) / (x*x + y*y)

set title "Top Right"
set hidden
set isosamples 30
set xrange [-3:3]
set yrange [-3:3]
set pm3d at st
splot sin(x*x + y*y) / (x*x + y*y)

set title "Bottom Left"
set hidden
set isosamples 30
set xrange [-3:3]
set yrange [-3:3]
set pm3d at b
splot sin(x*x + y*y) / (x*x + y*y)

set title "Bottom Right"
set samples 100
set isosamples 100
set xrange [-3:3]
set yrange [-3:3]
set pm3d map
set palette gray
splot sin(x*x + y*y) / (x*x + y*y)

unset multiplot
