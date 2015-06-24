.include "linux-system.s"
# 目的： 
#	调用转换函数，将整数以字符串形式显示
# Input：
#
# Otput:  
#
# Variable:
#
.section .data
buffer:
.ascii "\0\0\0\0\0\0\0\0\0\0\0"
.section .text
.globl _start
_start:
	#数字向字符转换
	pushl $buffer
	pushl $1024
	call integer2string
	addl $8, %esp
	#统计字符串数量
	pushl $buffer
	call count_chars
	addl $4, %esp

	movl %eax, %edx
	#打印字符串
	movl $SYS_WRITE, %eax
	movl $STDOUT, %ebx
	movl $buffer, %ecx
	int $LINUX_SYSCALL
	#打印换行符
	pushl $STDOUT
	call print_newline
	
	movl $SYS_EXIT, %eax 
	movl $0, %ebx 
	int $LINUX_SYSCALL

#####$$Fucntion Begin$$#####
###  ###
#	目的：


#####$$Function End$$#####

#@@汇编代码
#‘as program.s -o program.o` 生成目标文件
#`ld program.o -o program`  链接目标文件生成可执行文件
#`./program`  执行程序	
#`echo $?`	读取函数返回的状态码
####%%%--特别说明--%%%####	
#@@	

#ld integer2string.o print-newline.o count-chars.o conversion.o -o conversion
