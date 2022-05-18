#!/usr/bin/env python
# -*- coding: utf-8 -*-

import socket

# setsockopt(level, optname, value)
# getsockopt(level, optnam)
# 发送和接收缓冲区大小需要分开设定，修改之前先检查缓冲区大小

SEND_BUFF_SIZE = 4096 
RECV_BUFF_SIZE = 8192

def modifyBufferSize():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # get send buffer size
    buff_size = sock.getsockopt(socket.SOL_SOCKET, socket.SO_SNDBUF)
    print "Send buffer size[before]: %s" % buff_size
    buff_size = sock.getsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF)
    print "Recv buffer size[before]: %s" % buff_size

    sock.setsockopt(socket.SOL_TCP, socket.TCP_NODELAY, 1)
    sock.setsockopt(
            socket.SOL_SOCKET,
            socket.SO_SNDBUF,
            SEND_BUFF_SIZE)
    sock.setsockopt(
            socket.SOL_SOCKET,
            socket.SO_RCVBUF,
            RECV_BUFF_SIZE)

    buff_size = sock.getsockopt(socket.SOL_SOCKET, socket.SO_SNDBUF)
    print "Send buffer size[after]: %s" % buff_size
    buff_size = sock.getsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF)
    print "Recv buffer size[after]: %s" % buff_size

def test():
    print __name__
    modifyBufferSize()

if __name__ == '__main__':
    test()
