.include "linux-system.s"
.include "record-definition.s"
# 目的： 
#	读取记录，修改年龄字段，写回文件	
# Input：
#
# Otput:  
#
# Variable:
#

.section .data

#要写入的文件名
input_file_name:
.ascii "test.dat\0"
output_file_name:
.ascii "testout.dat\0"

code_error_no_file_exist:
.ascii "0001: \0"
msg_error_no_file_exist:
.ascii "Can't open input file\0"

.section .bss
.lcomm buffer, RECORD_SIZE
#栈结构
.equ ST_INPUTFILE_DESCRIPTOR, -4
.equ ST_OUTPUTFILE_DESCRIPTOR, -8

.section .text
.globl _start

_start:
	movl %esp, %ebp
	subl $8, %esp #局部变量，存储文件描述符
	
	#Open file
	movl $SYS_OPEN, %eax
	movl $input_file_name, %ebx
	movl $0, %ecx
	movl $0664, %edx
	int $LINUX_SYSCALL
	movl %eax, ST_INPUTFILE_DESCRIPTOR(%ebp) #保存文件描述符

	#####错误检测和处理
	cmpl $0, %eax
	jg no_error

	pushl $msg_error_no_file_exist
	pushl $code_error_no_file_exist
	call error_exit

	#####
no_error:
	movl $SYS_OPEN, %eax
	movl $output_file_name, %ebx
	movl $0101, %ecx
	movl $0664, %edx
	int $LINUX_SYSCALL
	movl %eax, ST_OUTPUTFILE_DESCRIPTOR(%ebp) #保存文件描述符
	#
loop_modify_record:
	#读记录
	pushl ST_INPUTFILE_DESCRIPTOR(%ebp)
	pushl $buffer
	call read_record
	addl $8, %esp

	cmpl $RECORD_SIZE, %eax
	jne end_loop_modify_record

	#递增年龄
	incl buffer + RECORD_AGE

	#写记录
	pushl ST_OUTPUTFILE_DESCRIPTOR(%ebp)
	pushl $buffer
	call write_record
	addl $8, %esp

	jmp loop_modify_record

end_loop_modify_record:
	#关闭文件描述符
	movl $SYS_CLOSE, %eax
	movl ST_INPUTFILE_DESCRIPTOR(%ebp), %ebx
	int $LINUX_SYSCALL

	movl $SYS_CLOSE, %eax
	movl ST_OUTPUTFILE_DESCRIPTOR(%ebp), %ebx
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
#@@开发健壮的程序
#
#@@深入学习	
#尝试在一个开源程序中查找错误，并提交报告或修正错误；
#
