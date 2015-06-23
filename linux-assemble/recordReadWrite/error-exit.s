.include "linux-system.s"
# 目的： 
#	单个回复点：打印错误信息并退出
# Input：
#
# Otput:  
#
# Variable:
#
.equ ST_ERROR_MSG, 12
.equ ST_ERROR_CODE, 8
.section .data
.section .text
.globl error_exit
error_exit:
	pushl %ebp
	movl %esp, %ebp

	#写错误代码
	movl ST_ERROR_CODE(%ebp), %ecx
	pushl %ecx #字符串首地址
	call count_chars
	popl %ecx
	movl %eax, %edx
	movl $STDERR, %ebx
	movl $SYS_WRITE, %eax
	int $LINUX_SYSCALL

	#写错误信息
	movl ST_ERROR_MSG(%ebp), %ecx
	pushl %ecx #字符串首地址
	call count_chars
	popl %ecx
	movl %eax, %edx
	movl $STDERR, %ebx
	movl $SYS_WRITE, %eax
	int $LINUX_SYSCALL

	pushl $STDERR
	call print_newline
#exit,status code 1
	movl $SYS_EXIT, %eax #(系统调用)退出程序的Linux内核命令号
	movl $1, %ebx #将返回给操作系统的状态码
	int $LINUX_SYSCALL #唤醒内核，运行退出命令

#@@汇编代码
#‘as program.s -o program.o` 生成目标文件
#`ld program.o -o program`  链接目标文件生成可执行文件
#`./program`  执行程序	
#`echo $?`	
####%%%--特别说明--%%%####	
#@@	
