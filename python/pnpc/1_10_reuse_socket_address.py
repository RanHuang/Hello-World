#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 重用套接字地址
# e.g 反复运行服务器程序，可以重复使用同一端口
import sys
import socket

def reuse_socket_address():
    print __name__

    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # get the old state of the SO_REUSEADDR option
    old_state = sock.getsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR)
    print "Old Socket state: %s" % old_state

    # enable SO_REUSEADDR option
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    new_state = sock.getsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR)
    print "New Socket state: %s" % new_state

    local_port = 8282

    serv_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # Reuse the port
    serv_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    serv_sock.bind(('', local_port))
    serv_sock.listen(1)
    print "Listening on port: %s" % local_port

    while True:
        try:
            connection, addr = serv_sock.accept()
            print "Connected by %s: %s" %(addr[0], addr[1])
        except KeyboardInterrupt:
            break;
        except socket.error, msg:
            print '%s' % (msg,)
    
if __name__ == '__main__':
    reuse_socket_address()
