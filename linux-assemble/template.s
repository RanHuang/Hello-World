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
	movl $1, %eax #(系统调用)退出程序的Linux内核命令号
	movl $0, %ebx #将返回给操作系统的状态码
				  #可以通过`echo $?`读取状态码
	int $0x80 #唤醒内核，运行退出命令

#@@汇编代码
#‘as program.s -o program.o` 生成目标文件
#`ld program.o -o program`  链接目标文件生成可执行文件
#`./program`  执行程序	
#`echo $?`	
####%%%--特别说明--%%%####	
#@@	
