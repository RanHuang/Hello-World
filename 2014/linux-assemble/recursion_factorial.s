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
	pushl $5 # N!
	call factorial #call指令在跳转至目标函数之前，先将下一条指令地址入栈

	addl $4, %esp #release the stack memory of the used local value
	movl %eax, %ebx #阶乘的返回值在%eax中，现在希望保持在%ebx中

	movl $1, %eax #(系统调用)退出程序的Linux内核命令号
	int $0x80 #唤醒内核，运行退出命令

.type factorial, @function #除非需要在其它程序中使用该函数，否则该指令非必要
factorial:
	pushl %ebp #创建栈帧
	movl %esp, %ebp

	movl 8(%ebp), %eax #Get the argument
	cmpl $1, %eax
	je end_factorial

	decl %eax
	pushl %eax	#Set the argument
	call factorial	#recursion 递归调用

	movl 8(%ebp), %ebx#函数调用后，除了%esp和%ebp，其它寄存器内容无从得知
	imull %ebx, %eax	#the return value was in %eax

end_factorial:
	movl %ebp, %esp #清楚当前函数栈帧
	popl %ebp

	ret #弹出栈顶值，跳转至该地址
#@@汇编代码
#‘as program.s -o program.o` 生成目标文件
#`ld program.o -o program`  链接目标文件生成可执行文件
#`./program`  执行程序	
#`echo $?`	
####%%%--特别说明--%%%####	
#@@一些概念
#原语：系统函数
#调用约定：不同语言的变量存储以及计算机传输参数和返回值方式
#@@深入学习
#1.编写自己的调用约定：一个示例是用寄存器取代栈进行参数传递
#2.测试用例？
#3.如果不使用栈，调用约定怎么设计？

