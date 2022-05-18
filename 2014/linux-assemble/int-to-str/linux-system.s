######%%CONSTANTS%%#####
#文件操作系统调用号
#%eax保存系统调用号，返回值与错误代码也保存在%eax中
.equ SYS_EXIT, 1
.equ SYS_READ, 3
.equ SYS_WRITE, 4
.equ SYS_OPEN, 5
.equ SYS_CLOSE, 6
.equ SYS_CHDIR, 12
.equ SYS_LSEEK, 19
.equ SYS_GETPID, 20
.equ SYS_MKDIR, 39
.equ SYS_RMDIR, 40
.equ SYS_DUP, 41
.equ SYS_PIPE, 42
.equ SYS_BRK, 45
.equ SYS_IOCTL, 54

#系统调用中断
.equ LINUX_SYSCALL, 0x80

#标准文件描述符
.equ STDIN, 0
.equ STDOUT, 1
.equ STDERR, 2

#文件打开选项(/usr/linclude/asm/fcntl.h)
.equ O_RDONLY, 0
.equ O_CREAT_WRONLY_TRUNC, 03101

#文件结束符，读操作返回值
.equ END_OF_FILE, 0
