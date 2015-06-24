.include "linux-system.s"
# 目的： 
#	向文件写入一个换行符
# Input：
#
# Otput:  
#
# Variable:
#	%eax 保存系统调用号
#	%ebx 保存返回状态
#
.section .data
newline:
.ascii "\n"
.section .text
.equ ST_FILEDES, 8
.globl print_newline
.type print_newline, @function
print_newline:
	pushl %ebp
	movl %esp, %ebp

	movl $SYS_WRITE, %eax
	movl ST_FILEDES(%ebp), %ebx
	movl $newline, %ecx
	movl $1, %edx
	int $LINUX_SYSCALL

	movl %ebp, %esp
	popl %ebp
	ret

#@@汇编代码
#‘as program.s -o program.o` 生成目标文件
#`ld program.o -o program`  链接目标文件生成可执行文件
#`./program`  执行程序	
#`echo $?`	
####%%%--特别说明--%%%####	
#@@	
