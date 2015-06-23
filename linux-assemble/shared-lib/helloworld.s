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
begin_str_hello:
.ascii "Hello World!\n"
end_str_hello:
.equ str_len_hello, end_str_hello - begin_str_hello

.section .text
.globl _start
_start:
	movl $SYS_WRITE, %eax
	movl $STDOUT, %ebx
	movl $begin_str_hello, %ecx
	movl $str_len_hello, %edx
	int $LINUX_SYSCALL
	
	movl $SYS_EXIT, %eax #(系统调用)退出程序的Linux内核命令号
	movl $0, %ebx #将返回给操作系统的状态码
	int $LINUX_SYSCALL #唤醒内核，运行退出命令

#@@汇编代码
#‘as program.s -o program.o` 生成目标文件
#`ld program.o -o program`  链接目标文件生成可执行文件
#`./program`  执行程序	
#`echo $?`	
####%%%--特别说明--%%%####	
#@@	
