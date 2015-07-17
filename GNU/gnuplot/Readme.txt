1. Install gnuplot
	$sudo apt-get install gnuplot
	$which gnuplot
	/usr/bin/gnuplot
2. start gnuplot
	$gnuplot
	>
	>set/unset/show all/help <command>/help
3. Termianl
 3.1 show the supported terminal list
	>set terminal
 3.2. show current terminal
	>show terminal
 3.3 set termianl
	>set terminal png
	>set terminal xterm
4. Set output
	>set output "plot.png"
5. Draw
	>plot sin(x)
	>load "script.p"

Example:
1.Draw according to a script
	>set terminal png
	>set output "plot.png"
	>load "script.p"
2.Draw picture according to data from files
	$bash get_proc_stat.sh
	> set terminal png
	>set output "procstat.png"
	>plot 'procstat.txt' using 2:18 with linespoints smooth bezier title "Interrupt Relationships"
	('unique', 'frequency', 'cumulative', 'cnormal', 'kdensity', 'acsplines', 'csplines', 'bezier' or 'sbezier'
3. Draw 3D
	> set terminal png
	> set output "3D.png"
	> splot [x=-2:2] [y=-2:2] sin(x)*cos(y)
4. Draw 3D contour line
	> set terminal png
	> set output "3D-contour.png"
	> set contour
	> set isosamples 40
	> set cntrparam levels 10
	> splot [x=-4:4] [y=-4:4] sin(x)*cos(y)

	clear the hidden line
	gnuplot> set output "3D-contour-hidden.png"
	gnuplot> set hidden
	gnuplot> splot [x=-4:4] [y=-4:4] sin(x)*cos(y)
5. multi plot
	$ gnuplot 

	G N U P L O T
	Version 4.6 patchlevel 4    last modified 2013-10-02 
	Build System: Linux i686

	Copyright (C) 1986-1993, 1998, 2004, 2007-2013
	Thomas Williams, Colin Kelley and many others

	gnuplot home:     http://www.gnuplot.info
	faq, bugs, etc:   type "help FAQ"
	immediate help:   type "help"  (plot window: hit 'h')
	
Terminal type set to 'unknown'
gnuplot> set terminal png
Terminal type set to 'png'
Options are 'nocrop font "/usr/share/fonts/truetype/liberation/LiberationSans-Regular.ttf,12" fontscale 1.0 size 640,480 '
gnuplot> set output "multi-plot.png"
gnuplot> load "multiplot.p"

