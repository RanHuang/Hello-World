# 目的： 退出并向Linux内核返回一个状态码的简单程序
#
# Input：
#
# Otput: 返回一个状态码。运行程序后可以通过'echo $?'读取该状态码
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

#@@汇编代码
#‘as program.s -o program.o` 生成目标文件
#`ld program.o -o program`  链接目标文件生成可执行文件
#`./program`  执行程序	
#`echo $?`	

####%%%--特别说明--%%%####	
#@@x86上通用寄存器
# %eax, %ebx, %ecx, %edx, %esi, %edi
#@@专用寄存器
# %ebp, %esp, %eip, %eflags (%eip与%eflags需用特殊指令访问)	

#@@集中寻址方式
# 立即寻址: movl $1, %eax
# 寄存器寻址
# 直接寻址：movl 1, %eax
# 变址寻址：偏移量存储在寄存器中，指针为常量
# 基址寻址：基址指针保存在寄存器中，偏移量为常数	

#@@系统调用
#操作系统的功能是通过系统调用来访问的；通过以特殊方式设置寄存器并发出`int $0x80`指令调用。系统调用号1是系统调用exit，要求将状态码放在%ebx中，系统调用号放于%eax中。 	
