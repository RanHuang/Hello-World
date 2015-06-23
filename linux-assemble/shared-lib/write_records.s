.include "linux-system.s"
.include "record-definition.s"
# 目的： 
#	简单地将一些硬编码记录写入磁盘
# Input：
#
# Otput:  
#
# Variable:
#

.section .data
record1:
	.ascii "Fredrick\0"
	.rept 11 #每个数据项以空字节（0）填充到适当长度
	.byte 0
	.endr

	.ascii "Bartlett\0"
	.rept 11 #填充到20字节
	.byte 0
	.endr

	.ascii "4242 S Prairie\nTulsa, OK 55555\0"
	.rept 9 #填充到40字节
	.byte 0
	.endr

	.long 45

record2:
	.ascii "Marilyn\0"
	.rept 12 #每个数据项以空字节（0）填充到适当长度
	.byte 0
	.endr

	.ascii "Taylor\0"
	.rept 13 #填充到20字节
	.byte 0
	.endr

	.ascii "2242 S Johannan St\nChicago, IL 12345\0"
	.rept 3 #填充到40字节
	.byte 0
	.endr

	.long 29

record3:
	.ascii "Nicolas\0"
	.rept 12 #每个数据项以空字节（0）填充到适当长度
	.byte 0
	.endr

	.ascii "McIntire\0"
	.rept 11 #填充到20字节
	.byte 0
	.endr

	.ascii "500 W Oakland\nSan Diego, CA 54321\0"
	.rept 6 #填充到40字节
	.byte 0
	.endr

	.long 36

#要写入的文件名
file_name:
.ascii "write.dat\0"
#栈结构
.equ ST_FILE_DESCRIPTOR, -4

.section .text
.globl _start
_start:
	movl %esp, %ebp
	subl $4, %esp #局部变量，存储文件描述符
	
	#Open file
	movl $SYS_OPEN, %eax
	movl $file_name, %ebx
	movl $0101, %ecx
	movl $0664, %edx
	int $LINUX_SYSCALL

	movl %eax, ST_FILE_DESCRIPTOR(%ebp) #保存文件描述符

	#write the first record
	pushl ST_FILE_DESCRIPTOR(%ebp)
	pushl $record1
	call write_record
	addl $8, %esp
	#write the second record
	pushl ST_FILE_DESCRIPTOR(%ebp)
	pushl $record2
	call write_record
	addl $8, %esp
	#write the third record
	pushl ST_FILE_DESCRIPTOR(%ebp)
	pushl $record3
	call write_record
	addl $8, %esp

	movl $SYS_CLOSE, %eax
	movl ST_FILE_DESCRIPTOR(%ebp), %ebx
	int $LINUX_SYSCALL
#exit
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
