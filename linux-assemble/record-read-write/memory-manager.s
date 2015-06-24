.include "linux-system.s"
# 目的： 
#	内存管理--按需分配和释放内存
# 注意：例程将请求一定大小内存；实际使用内存更大，但在回传指针之前将之
#放在开始处。增加一个大小字段以及是否可用的标记，内存格式如下：
#############################################################
#    $AVAILABLE标记$内存大小$实际内存位置$
#										  ^ -- 返回指针指向的位置
#############################################################
#	返回指针仅仅指向请求的实际内存位置，无需更改调用程序即可更改程序
#
.section .data  #####全局变量########
#管理的内存起始处
heap_begin:
.long 0
#管理的内存最后位置
current_break:
.long 0

#####结构信息######
# 内存头信息空间大小
.equ HEADER_SIZE, 8
# AVAILABE标识位置
.equ HDR_AVAILABLE_OFFSET, 0
# 指示内存块大小的字段位置
.equ HDR_SIZE_OFFSET, 4

#####常量#######
.equ UNAVAILABLE, 0 #标识内存已分配
.equ AVAILABLE, 1	#标识内存未分配

.section .text
#####$$Begin$$#####
###allocate_init###
#	目的：初始化内存分配函数，设置heap_begin和current_break
.globl allocate_init
.type allocate_init, @function
allocate_init:
	pushl %ebp
	movl %esp, %ebp

	movl $SYS_BRK, %eax #发起brk系统调用
	xorl %ebx, %ebx		# %ebx -- 新系统中断;如果为0，仅仅返回当前系统中断
	int $LINUX_SYSCALL

	incl %eax			#当前最后有效地址之后的内存位置
	movl %eax, current_break	#保存当前中断点
	movl %eax, heap_begin

	movl %ebp, %esp
	popl %ebp
	ret
#####$$End$$#####

#####$$Fucntion Begin$$#####
###allocate###
#	目的：获取一段内存，查看是否存在自由内存块，如果不存在则向Linux系统请求
#Input：
#	内存块大小
#Output:
#	%eax--返回分配到的内存地址，若无可用内存，返回0
#Variable:
#	%ecx -- 保存请求的内存大小
#	%eax -- 检查当前内存区
#	%ebx -- 当前中断点
#	%edx -- 当前内存大小
#检测每个以heap_begin开始的内存区，检查其大小以及是否已经分配；如果符合所
#请求大小且可用，则函数获取此内存去；如果无法找到足够大内存，则向Linux请求
#更多内存，此时current_break会向前移动。
.globl allocate
.type allocate, @function
.equ ST_MEM_SIZE, 8
allocate:
	pushl %ebp
	movl %esp, %ebp

	movl ST_MEM_SIZE(%ebp), %ecx	#保存唯一参数，请求内存大小
	movl heap_begin, %eax
	movl current_break, %ebx

loop_alloc_begin:
	cmpl %ebx, %eax
	jle new_break	#heap_begin和current_break相等，需要申请更多内存
	
	movl HDR_SIZE_OFFSET(%eax), %edx	
	cmpl $UNAVAILABLE, HDR_AVAILABLE_OFFSET(%eax)#测试该块是否可用
	je	next_section #若内存正在使用则UNAVAILABLE
	
	cmpl %edx, %ecx
	jge	alloc_this_section
next_section:
	addl $HEADER_SIZE, %eax
	addl %edx, %eax		#下一个可用内存去位置
	jmp loop_alloc_begin

alloc_this_section:
	#可用内存块头设置，将空间标识为不可用
	movl $UNAVAILABLE, HDR_AVAILABLE_OFFSET(%eax)
	addl $HEADER_SIZE, %eax		#返回值,可用内存位置

	jmp exit
new_break:
	#向系统申请新内存空间，%ebx--当前内存结束处，%ecx请求内存大小
	addl $HEADER_SIZE, %ebx
	addl %ecx, %ebx		#新的想要内存结束的位置
	pushl %eax
	pushl %ecx
	pushl %ebx

	movl $SYS_BRK, %eax
	int $LINUX_SYSCALL
	#错误检查，函数应返回新中断点至%eax，大于等于所请求内存；失败则为0
	cmpl $0, %eax
	je error

	popl %ebx
	popl %ecx
	popl %eax

	movl $UNAVAILABLE, HDR_AVAILABLE_OFFSET(%eax) #设置不可用标记
	movl %ecx, HDR_SIZE_OFFSET(%eax)		#保存实际可用内存大小
	addl $HEADER_SIZE, %eax		#确定实际可用内存位置
	movl %ebx, current_break	#保存新中断点,??小于等于新中断点??

	jmp exit
error:
	movl $0, %eax	#分配内存出错出错，返回0
	movl %ebp, %esp
	popl %ebp
	ret
exit:
	movl %ebp, %esp
	popl %ebp
	ret
#####$$Function End$$#####

#####$$Fucntion Begin$$#####
###deallocate###
#	目的：将使用完毕的内存区域返回内存池
#Input：
#	内存地址
#Output:
#	
.globl deallocate
.type deallocate, @function
.equ ST_MEM_SEG, 4
deallocate:
	movl ST_MEM_SEG(%esp), %eax

	subl $HEADER_SIZE, %eax
	#标识该内存可用，回收内存空间
	movl $AVAILABLE, HDR_AVAILABLE_OFFSET(%eax)

	ret
#####$$Function End$$#####
#@@汇编代码
#‘as program.s -o program.o` 生成目标文件
#`ld program.o -o program`  链接目标文件生成可执行文件
#`./program`  执行程序	
#`echo $?`	
####%%%--特别说明--%%%####	
#@@内存管理器工作方式
#在每个被分配的内存区域之前，有一个描述该内存区的简短记录，以下常量用于描述记录，善加利用这些常量，再将更多信息加到内存区头时，易于扩展
# .equ HEADER_SIZE, 8
# .equ HDR_AVAILABLE_OFFSET, 0
# .equ HDR_SIZE_OFFSET, 4

#@@内存管理器管理的区域堆
#堆由 heap_begin 和 current_break 之间的内存构成，开始时堆大小为0字节，调用分配函数，将堆扩展到所需的大小

#@@讨论
#该内存管理器仅适用于实验，并不实用
#1.性能:速度--多次分配，则需要反复搜索内存去(n^2)；以及可能磁盘加载内存页，检查是否可用;
#2.brk系统调用，切换模式（上下文切换），需要长时间；
#3.没有记录Linux实际设置中断点的位置，实际上中断点可能在请求的内存大小之后；
#4.内存申请和使用会存在碎片化和利用率的问题

#@@为什么需要一个内存分配器?
#@@操作系统如何防止进程覆盖其它进程的内存？
#@@修改内存管理器，当请求内存小于所选区内存时进行拆分
#@@研究垃圾收集和引用计数
