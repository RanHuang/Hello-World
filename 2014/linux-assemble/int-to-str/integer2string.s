.include "linux-system.s"
# 目的： 
#	将一个二进制整数转换为适合显示的十进制字符串
# Input：
#	待转换整数，存放转换后字符串的足够大缓存区
# Otput:  
#	
# Variable:
#	%eax 保存当前值
#	%ecx 已处理的字符数
#	%edi 保存基数 
#
.equ ST_BUFFER, 12
.equ ST_VALUE, 8

.section .text
.globl integer2string
.type integer2string, @function
integer2string:
	pushl %ebp
	movl %esp, %ebp

	movl ST_VALUE(%ebp), %eax
	xorl %ecx, %ecx
	movl $10, %edi

loop_conversion:
	#除法,被除数位于%eax，结果保存在 %edx(余数):%eax(商)
	xorl %edx, %edx	
	divl %edi
	
	addl $'0', %edx
	pushl %edx
	incl %ecx

	cmpl $0, %eax
	je end_loop_conversion

	jmp loop_conversion
end_loop_conversion:
	movl ST_BUFFER(%ebp), %edx  #获取缓冲区位置
loop_reverse:
	popl %eax
	movb %al, (%edx)
	incl %edx

	decl %ecx
	cmpl $0, %ecx
	je end_loop_reverse
	jmp loop_reverse

end_loop_reverse:
	movb $0, (%edx)

	movl %ebp, %esp
	popl %ebp
	ret

#####$$Fucntion Begin$$#####
###  ###
#	目的：


#####$$Function End$$#####

#@@汇编代码
#‘as program.s -o program.o` 生成目标文件
#`ld program.o -o program`  链接目标文件生成可执行文件
#`./program`  执行程序	
#`echo $?`	读取函数返回的状态码
####%%%--特别说明--%%%####	
#@@	

