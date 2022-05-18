# 目的：Look up the minimum of an array.
#
# Input：
#   an array
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
	.int 3,56,8,88,98,74,98,56,252,123,54,1 #.int 占用4个存储位置
data_end:

.section .text
.globl _start
_start:
	leal data_end, %eax #获取内存地址
	leal data_items, %ebx
	subl %ebx, %eax
	movl $0, %edx
	movl $4, %ecx
	idivl %ecx 
	movl %eax, %ecx #计算数组数据项个数并存入%ecx

	movl data_items(,%edi,4), %ebx #第一个数暂时设置为最大值
	movl $0, %edi #
loop_start:
	incl %edi
	cmpl %edi, %ecx
	je loop_exit #无数据项可比较则退出
	movl data_items(,%edi,4), %eax	#加载下一个数据项
	cmpl %ebx, %eax
	jge loop_start # <= 则继续下一个
	movl %eax, %ebx # > 则保存新的最大值
	jmp loop_start # loop continue
loop_exit:
	movl $1, %eax  # %ebx已经存放最大值
	int $0x80 #
	
#@@汇编代码
#‘as program.s -o program.o` 生成目标文件
#`ld program.o -o program`  链接目标文件生成可执行文件
#`./program`  执行程序	
#`echo $?`	
####%%%--特别说明--%%%####	
#@@	将字符输入内存
# .ascii "Hello world\0"  指令字符需用引号括起，并且将占用12个存储位置	

#@@ 参与比较的数字应该<=255，因为255为最大允许的退出码，最后的比较结果是通过退出码表示的

#@@ 索引寻址方式
# movl 起始地址(,%索引寄存器,比例因子)	

#@@条件跳转
# je jl jg jle jge
#@@无条件跳转
# jmp

#@@寻址方式
#内存地址引用通用格式：地址或偏移(%基址寄存器,%索引寄存器,比例因子)	
#结果地址 = 地址或偏移 + %基址或偏移量寄存器 + 比例因子 * %索引寄存器
# 直接寻址 -- movl ADDRESS, %eax
# 索引寻址 -- movl string_start(, %ecx,1), %eax
# 间接寻址 -- movl (%eax), %ebx
# 基址寻址 -- movl 4(%eax), %ebx
# 立即寻址 -- movl $12, %eax  立即寻址方式只能针对源操作数
# 寄存器寻址

#标识列表结束方式：使用特定数字、使用结束地址、使用长度计数, 哪个更好？
