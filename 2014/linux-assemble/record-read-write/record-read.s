.include "linux-system.s"
.include "record-definition.s"
# 目的： 
#	从给定文件描述符读取一条记录
# Input：
#	文件描述符和缓冲区
# Otput:  
#	函数将数据写入缓冲区并返回状态码
# Variable:
#
.equ ST_BUFFER, 8
.equ ST_FILEDES, 12
.section .text
.globl	read_record 
.type read_record, @function
read_record:
	pushl %ebp
	movl %esp, %ebp

	pushl %ebx #

	movl $SYS_READ, %eax
	movl ST_FILEDES(%ebp), %ebx
	movl ST_BUFFER(%ebp), %ecx
	movl $RECORD_SIZE, %edx
	int $LINUX_SYSCALL
	
	popl %ebx

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
