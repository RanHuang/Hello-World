# 目的：Look up the maximum of an array.
#
# Input：
#   a array
#	先确定数据项的个数
# Otput: 
#   maximum of the array
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
	.int 3,56,8,88,98,74,98,56,252,123,54,1
data_end:

.section .text
.globl _start
_start:
	movl $0, %edi #

	leal data_end, %eax #获取内存地址
	leal data_items, %ebx
	subl %ebx, %eax
	movl $0, %edx
	movl $4, %ecx
	idivl %ecx 
	movl %eax, %ecx #计算数组数据项个数并存入%ecx

	movl data_items(,%edi,4), %ebx #第一个数暂时设置为最大值
loop_start:
	incl %edi
	cmpl %edi, %ecx
	je loop_exit #无数据项可比较则退出
	movl data_items(,%edi,4), %eax	#加载下一个数据项
	cmpl %ebx, %eax
	jle loop_start # <= 则继续下一个
	movl %eax, %ebx # > 则保存新的最大值
	jmp loop_start # loop continue
loop_exit:
	movl $1, %eax  # %ebx已经存放最大值
	int $0x80 #
