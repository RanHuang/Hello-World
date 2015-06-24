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
.section .text
.globl _start
_start:
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

