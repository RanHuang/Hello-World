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
	movl $250, %ebx #将返回给操作系统的状态码
				  #
	int $0x80 #唤醒内核，运行退出命令
