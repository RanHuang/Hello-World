# 目的： 
#	将输入文件的所有字母转换为大写字母
#	然后输出到输出文件
# Input：
#
# Otput:  
#
# 处理过程:
#	1.打开输入、输出文件
#	2.读取文件，字符串转换，写入文件
#
.section .data
######%%CONSTANTS%%#####
#文件操作系统调用号
.equ SYS_OPEN, 5
.equ SYS_READ, 3
.equ SYS_WRITE, 4
.equ SYS_CLOSE, 6
.equ SYS_EXIT, 1
#系统调用中断
.equ LINUX_SYSCALL, 0x80
#标准文件描述符
.equ STDIN, 0
.equ STDOUT, 1
.equ STDERR, 2
#文件打开选项(/usr/linclude/asm/fcntl.h)
.equ O_RDONLY, 0
.equ O_CREAT_WRONLY_TRUNC, 03101
#文件结束符，读操作返回值
.equ END_OF_FILE, 0

#缓冲区
.section .bss
.equ BUFFER_SIZE, 500
.lcomm buffer, BUFFER_SIZE

.section .text

###Stack State###
.equ ST_ARGV_2, 12 #output file
.equ ST_ARGV_1, 8  #input file
.equ ST_ARGV_0, 4 #program name
.equ ST_ARGC, 0	   #参数个数

.equ ST_SIZE_RESERVE, 8
.equ ST_FD_IN, -4
.equ ST_FD_OUT, -8

.globl _start
_start:
	movl %esp, %ebp #保存栈指针，作为访问参数的基址指针
	subl $ST_SIZE_RESERVE, %esp

	#打开文件input file
	movl $SYS_OPEN, %eax       #系统调用号
	movl ST_ARGV_1(%ebp), %ebx #文件名
	movl $O_RDONLY, %ecx	   #读写标识
	movl $0644, %edx		   #读写权限
	int $LINUX_SYSCALL	

	movl %eax, ST_FD_IN(%ebp) #保存文件描述符
	
	#打开文件output file
	movl $SYS_OPEN, %eax       #系统调用号
	movl ST_ARGV_2(%ebp), %ebx #文件名
	movl $O_CREAT_WRONLY_TRUNC, %ecx	   #读写标识
	movl $0644, %edx		   #读写权限
	int $LINUX_SYSCALL	

	movl %eax, ST_FD_OUT(%ebp) #保存文件描述符
	
loop_file_read:
	#读取文件至字符缓冲区
	movl $SYS_READ, %eax
	movl ST_FD_IN(%ebp), %ebx
	movl $buffer, %ecx
	movl $BUFFER_SIZE, %edx
	int $LINUX_SYSCALL
	#检查文件是否结束
	cmpl $END_OF_FILE, %eax
	jle end_loop_file_read

	#调用转换函数处理
	pushl $buffer
	pushl %eax
	call convert2upper
	popl %eax
	addl $4, %esp
	#将缓冲区内容写入文件
	movl %eax, %edx  #缓冲区大小
	movl $SYS_WRITE, %eax
	movl ST_FD_OUT(%ebp), %ebx
	movl $buffer, %ecx
	int $LINUX_SYSCALL

	jmp loop_file_read

end_loop_file_read:
#close file
	movl $SYS_CLOSE, %eax
	movl ST_FD_OUT(%ebp), %ebx
	int $LINUX_SYSCALL

	movl $SYS_CLOSE, %eax
	movl ST_FD_IN(%ebp), %ebx
	int $LINUX_SYSCALL
#exit
	movl $SYS_EXIT, %eax 
	movl $0, %ebx 
	int $LINUX_SYSCALL 
#######################################################################
# 目的： 
#	将字符块内容转换为大写	
# Input：
#	第一个参数为缓存地址
#	第二个参数为缓冲区长度
# Otput:  
#	以大写字符覆盖当前缓冲区
#
#	%eax -- 缓冲区地址
#	%ebx -- 缓冲区长度
#	%edi -- 当前缓冲区偏移量
#	%cl  -- 当前正在检测的字节

######%%CONSTANTS%%#######
#搜索的字符边界
.equ LOWERCASE_A, 'a'
.equ LOWERCASE_Z, 'z'

.equ UPPER_CONVERSION, 'A' - 'a'
#Stack
.equ ST_BUFFER, 12 #缓冲区地址
.equ ST_BUFFER_LEN, 8 #缓冲区长度

.type convert2upper, @function
convert2upper:
	pushl %ebp
	movl %esp, %ebp

	movl ST_BUFFER(%ebp), %eax
	movl ST_BUFFER_LEN(%ebp), %ebx
	movl $0, %edi

	cmpl $0, %ebx #如果缓冲区大小为0,则无数据处理，退出
	je end_convert2upper

loop_convert:
	movb (%eax, %edi, 1), %cl
	#仅处理位于'a'-'z'之间的字符
	cmpb $LOWERCASE_A, %cl
	jl next_byte
	cmpb $LOWERCASE_Z, %cl
	jg next_byte

	addb $UPPER_CONVERSION, %cl #字符转换
	movb %cl, (%eax, %edi, 1) #缓冲区覆盖

next_byte:
	incl %edi
	cmpl %edi, %ebx
	jne loop_convert

end_convert2upper:
	movl %ebp, %esp
	popl %ebp
	ret

#@@汇编代码
#‘as program.s -o program.o` 生成目标文件
#`ld program.o -o program`  链接目标文件生成可执行文件
#`./program`  执行程序	
#`echo $?`	
####%%%--特别说明--%%%####	
#@@UNIX文件作为连续字节流进行访问
#文件操作 系统调用号 参数和寄存器说明
# open	  5			 %eax-5;%ebx-文件名地址;%ecx-读/写模式;%edx-权限集合
#	文件描述符返回至%eax
# read	  3			 %eax-3;%ebx-文件描述符;%ecx-数据缓冲区地址;%edx-大小
#	返回从文件中读取的字符数或者错误代码至%eax
# write	  4			 %eax-4;...
#	返回写入的字节数和错误代码至%eax
#@@.bss段，不占用可执行程序空间，保留存储位置；
#	.section .bss
#	.lcomm buffer, 500

#@@调试程序
# as --gstabs program.s -o program.o  使用STAB调试格式
# gdb ./program
