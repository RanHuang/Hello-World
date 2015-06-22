.include "record-definition.s"
.include "linux-system.s"
# 目的： 
#	将一条记录写入给定文件描述符
# Input：
#	文件描述符和缓冲区
# Otput:  
#	函数状态码
# Variable:
#
.equ ST_FILEDES, 12
.equ ST_BUFFER, 8

.section .text
.globl write_record
.type write_record, @function
write_record:
	pushl %ebp
	movl %esp, %ebp

	pushl %ebx #

	movl $SYS_WRITE, %eax
	movl ST_FILEDES(%ebp), %ebx
	movl ST_BUFFER(%ebp), %ecx
	movl $RECORD_SIZE, %edx
	int $LINUX_SYSCALL
	
	popl %ebx

	movl %ebp, %esp
	popl %ebp
	ret
