#!/usr/bin/env python
# Python Network Programming Cookbook -- Chapter 1
# -*- coding: utf-8 -*-

import socket
# Python的socket模块提供类方法和实例方法，二者区别是使用类方法不需要创建套接字对象实例

# 获取主机名和对应IP地址
def print_machine_info():
    host_name = socket.gethostname()
    ip_address = socket.gethostbyname(host_name)
    print "Host Name: %s" % host_name
    print "IP Address: %s" % ip_address

# __name__为Python的内部变量，表示调用程序的进程名
# 在命令行中运行脚本，__name__ 的值为 __main__，因此自动运行 print_machine_info()
if __name__ == "__main__":
    print_machine_info()
