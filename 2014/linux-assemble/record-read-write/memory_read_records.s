.include "linux-system.s"
.include "record-definition.s"
# 目的： 
#	从文件中读取记录并显示	
#	使用自己的内存管理器动态分配缓冲区处理输入输出
# Input：
#
# Otput:  
#
# Variable:
#
.section .data
.equ ST_INPUT_FILEDES, -4
.equ ST_OUTPUT_FILEDES, -8
#要读取的文件名
file_name:
.ascii "write.dat\0"

.section .bss
.lcomm record_buffer, RECORD_SIZE #缓冲区
record_buffer_ptr:
.long 0

.section .text
.globl _start
_start:
	movl %esp, %ebp
	subl $8, %esp #局部变量，存储文件描述符
	
	call allocate_init #初始化内存管理器
	pushl $RECORD_SIZE
	call allocate
	movl %eax, record_buffer_ptr
	
	#Open file
	movl $SYS_OPEN, %eax
	movl $file_name, %ebx
	movl $0, %ecx
	movl $0644, %edx
	int $LINUX_SYSCALL

	movl %eax, ST_INPUT_FILEDES(%ebp) #保存文件描述符
	movl $STDOUT, ST_OUTPUT_FILEDES(%ebp)

loop_read_record:
	pushl ST_INPUT_FILEDES(%ebp)
	#pushl $record_buffer
	pushl record_buffer_ptr
	call read_record
	addl $8, %esp

	cmpl $RECORD_SIZE, %eax
	jne exit

	#统计有效字符串大小，类似于C语言中的 strlen 函数
	#pushl $RECORD_FIRSTNAME + record_buffer
	movl record_buffer_ptr, %eax
	addl $RECORD_FIRSTNAME, %eax
	pushl %eax
	call count_chars
	addl $4, %esp
	movl %eax, %edx		#有效字符串大小
	movl ST_OUTPUT_FILEDES(%ebp), %ebx
	movl $SYS_WRITE,  %eax
	#movl $RECORD_FIRSTNAME + record_buffer, %ecx
	movl record_buffer_ptr, %ecx
	addl $RECORD_FIRSTNAME, %ecx
	int $LINUX_SYSCALL

	pushl ST_OUTPUT_FILEDES(%ebp)
	call print_newline 
	addl $4, %esp

	jmp loop_read_record

exit:
	pushl record_buffer_ptr
	call deallocate

	movl $SYS_EXIT, %eax #(系统调用)退出程序的Linux内核命令号
	movl $0, %ebx #将返回给操作系统的状态码
	int $LINUX_SYSCALL #唤醒内核，运行退出命令

#@@汇编代码
#‘as program.s -o program.o` 生成目标文件
#`ld program.o -o program`  链接目标文件生成可执行文件
#`./program`  执行程序	
#`echo $?`	
####%%%--特别说明--%%%####	
#@@立即寻址方式单个常量入栈 
#.equ 创建直接常数，标签常数	
# pushl $RECORD_FIRSTNAME + record_buffer
