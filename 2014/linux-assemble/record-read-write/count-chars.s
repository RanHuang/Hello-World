# 目的： 
#	求字符串长度	
# Input：
#	字符串地址
# Otput:  
#	计数值置于%eax中返回
# Variable:
#	%al  --  当前字符
#	%ecx --  字符计数
#	%edx --  当前字符地址
#
.section .text
.equ ST_STR_ADDR, 8
.globl count_chars
.type count_chars, @function
count_chars:
	pushl %ebp
	movl %esp, %ebp

	movl $0, %ecx
	movl ST_STR_ADDR(%ebp), %edx
loop_count:
	movb (%edx), %al
	cmpb $0, %al
	je end_loop_count

	incl %ecx
	incl %edx
	jmp loop_count

end_loop_count:
	movl %ecx, %eax #将计数值放于%eax返回

	popl %ebp
	ret

#@@汇编代码
#‘as program.s -o program.o` 生成目标文件
#`ld program.o -o program`  链接目标文件生成可执行文件
#`./program`  执行程序	
#`echo $?`	
####%%%--特别说明--%%%####	
#@@	
