#.code32
#ps:Everything is OK in 32bit system. But the execution could not work in 64bit system because of the push and pop instructions. It seems that the call statck in 64bit OS is different from that in 32bit OS. 
# 目的： 
#
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
    pushl $3
    pushl $2
    call power
    addl $8, %esp
    pushl %eax

    pushl $2
    pushl $5
    call power
    addl $8, %esp

    popl %ebx
    addl %eax, %ebx

	movl $1, %eax #(系统调用)退出程序的Linux内核命令号
	int $0x80 #唤醒内核，运行退出命令

# 目的： 
#
# Input：
#
# Otput: 
#
# Variable:
#	%eax 保存系统调用号
#	%ebx 保存返回状态
#
.type power, @function
power:
    pushl %ebp
    movl %esp, %ebp
    subl $4, %esp

	movl 8(%ebp), %ebx #
	movl 12(%ebp), %ecx #
    movl %ebx, -4(%ebp)

start_loop:
    cmpl $1, %ecx
    je end_loop

	movl -4(%ebp), %eax
    imull %ebx, %eax
    movl %eax, -4(%ebp)
    decl %ecx
    jmp start_loop

end_loop:
    movl -4(%ebp), %eax
    movl %ebp, %esp
    popl %ebp
    ret
