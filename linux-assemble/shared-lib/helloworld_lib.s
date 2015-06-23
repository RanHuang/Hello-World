.include "linux-system.s"
# 目的： 
#
# Input：
#
# Otput:  
#
# Variable:
#	%eax 保存系统调用号
#	%ebx 保存返回状态
#
.section .data
str_hello:
.ascii "Hello World!\n\0"
str_args:
.ascii "Hello! %s loves %s, and they have been together for %d years.\n\0"
str_name_nick:
.ascii "Nick Huang\0"
str_name_lili:
.ascii "Lili Cao\0"
years:
.long 4

.section .text
.globl _start
_start:
	pushl $str_hello
	call printf

	#多参数打印
	pushl years
	pushl $str_name_lili
	pushl $str_name_nick
	pushl $str_args
	call printf

	pushl $0
	call exit

#@@汇编代码
#‘as program.s -o program.o` 生成目标文件
#`ld program.o -o program`  链接目标文件生成可执行文件
#`./program`  执行程序	
#`echo $?`	
####%%%--特别说明--%%%####	
#@@	int printf(char *string, ...)
#Linux中，函数以C语言描述，由于多数Linux程序都是用C编写的，所以多数文档和二进制兼容用C语言定义
#字符串需要'\0'结束符标识字符串结束处
#总是需要以逆序将函数参数入栈
#printf能大大简化输出，但是也会造成大量开销
#@@ number: .int 4
#int   pushl number
#int * pushl $number
