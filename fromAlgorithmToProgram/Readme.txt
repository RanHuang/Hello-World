1.自定义头文件，创建工具库函数
  1)编译头文件和源码，生成目标文件
	$cd utility
	$gcc -c search.c
  2)包含头文件搜索路径，编译源码，生成目标文件
	$gcc -c linearSerach.c -Iutility
  3)根据各个目标文件生成可执行文件
	$gcc -o linearSearch linearSerach.o ./utility/search.o
2.将自定义工具库创建为静态链接库

