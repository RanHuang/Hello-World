# 目的：Look up the maximum of an array.
#
# Input：
#
# Otput: 
#
# Variable:
#	data_items - 数据项
#	data_end - 数据数组结尾
#Register
#	%eax - 当前数据项
#	%ebx - 当前maximum
#	%edi - 正在检测的数据项 index
#
.section .data
data_items:
	.long 3,56,8,88,98,74,98,56,252,123,54,1,0
#使用 %ebx 返回最大值，则最大值不能超过255,即汇编的系统调用返回值 <=255
#data_items:
#	.long 3,56,8,1
data_end:

.section .text
.globl _start
_start:
	movl $0, %edi #
	movl data_items(,%edi,4), %eax #第一个数暂时设置为最大值
	movl %eax, %ebx

loop_start:
	cmpl $1, %eax
	je loop_exit #无数据项可比较则退出

	incl %edi
	movl data_items(,%edi,4), %eax #加载下一个数据项,64位系统中 long-4 bytes
	cmpl %ebx, %eax
	jle loop_start # <= 则继续下一个

	movl %eax, %ebx # > 则保存新的最大值

	jmp loop_start # loop continue
loop_exit:
#	movl $55, %ebx
	movl $1, %eax  # %ebx已经存放最大值
	int $0x80 #
