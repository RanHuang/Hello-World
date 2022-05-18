#.code32
#ps:Everything is OK in 32bit system. But the execution could not work in 64bit system because of the push and pop instructions. It seems that the call statck in 64bit OS is different from that in 32bit OS. 
# 目的： 
#	函数调用,计算 2^3+5^2
# Input：
#
# Otput: 
#
# Variable:
#	%eax 保存系统调用号
#	%ebx 保存
#
.section .data

.section .text

.globl _start
_start:
    pushl $3 #压入第二个参数
    pushl $2 #压入第一个参数
    call power
    addl $8, %esp #清除函数参数
    pushl %eax #暂存第一次调用结果

    pushl $0
    pushl $5
    call power
    addl $8, %esp

    popl %ebx #第一次调用结果
    addl %eax, %ebx #第二次调用返回值默认在%eax中

	movl $1, %eax #(系统调用)退出程序的Linux内核命令号
	int $0x80 #唤醒内核，运行退出命令

# 目的： 
#	计算一个数的幂
# Input：
#	第一个参数 -- 底数， 第二个参数 -- 指数
#	Attention： 指数必须 >= 1
# Otput: 
#	返回值即为计算结果
# Variable:
#	%eax 保存系统调用号
#	%ebx 保存返回状态
#
.type power, @function  #告诉链接器将符号power作为函数处理
power:
    pushl %ebp
    movl %esp, %ebp
    subl $4, %esp

	movl 8(%ebp), %ebx #函数参数1， 底数
	movl 12(%ebp), %ecx #参数2， 指数
    movl %ebx, -4(%ebp) #当前结果

	cmpl $0, %ecx
	jg start_loop
	movl $1, %eax
	jmp exit

start_loop:
    cmpl $1, %ecx
    je end_loop 

	movl -4(%ebp), %eax
    imull %ebx, %eax
    movl %eax, -4(%ebp)
    decl %ecx
    jmp start_loop

end_loop:
    movl -4(%ebp), %eax #返回值位于%eax中
exit:
    movl %ebp, %esp
    popl %ebp
    ret
#@@汇编代码
#‘as program.s -o program.o` 生成目标文件
#`ld program.o -o program`  链接目标文件生成可执行文件
#`./program`  执行程序	
#`echo $?`	
####%%%--特别说明--%%%####	
#@@函数
#函数名--函数代码起始地址，函数参数--显示给函数进行处理的数据项，局部、全局、静态变量，返回地址--call指令处理返回地址,ret指令按照返回地址回到函数调用的位置，返回值
#@@栈
#栈顶元素--`movl (%esp), %eax`
#栈顶下一个元素--`movl 4(%esp), %eax`
#%ebp -- 栈指针在函数开始时的位置，对栈帧的常量引用，将函数参数作为相对于基址指针的固定索引进行访问
#	参数 #N    <-- N*4+4(%ebp)
#   ...
#	参数 #2    <-- 12(%ebp)
#	参数 #1    <-- 8(%ebp)
#	返回地址   <--4(%ebp)
#	旧%ebp     <--(%ebp)
#	局部变量 1 <-- -4(%ebp)
#	局部变量 2 <-- -8(%ebp) || (%esp)
#@@函数调用
#	pushl %ebp
#	movl %esp, %ebp
#	subl $N, %esp #为函数局部变量分配空间
#@@函数返回
#	movl %ebp, %esp
#	popl %ebp
#	ret
