# 目的： show how a recursion works.
#	Factorial: 4 4*3*2*1 -> 24
#
# Input：
#
# Otput: 
#
# Variable:
#	%eax 保存系统调用号
#	%ebx	store the result 
#
.section .data
.section .text
.globl _start
_start:
	pushl $4
	call factorial
	addl $4, %esp #release the stack memory of the used local value
	movl %eax, %ebx

	movl $1, %eax #(系统调用)退出程序的Linux内核命令号
	int $0x80 #唤醒内核，运行退出命令

.type factorial, @function
factorial:
	pushl %ebp
	movl %esp, %ebp

	movl 8(%ebp), %eax #Get the argument
	cmpl $1, %eax
	je end_factorial

	decl %eax
	pushl %eax	#Set the argument
	call factorial	#recursion

	movl 8(%ebp), %ebx
	imull %ebx, %eax	#the return value was in %eax

end_factorial:
	movl %ebp, %esp
	popl %ebp
	ret
