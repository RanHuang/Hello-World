#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 套接字模式--阻塞或非阻塞式
import socket

def test_socket_mode():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.setblocking(1)
    sock.settimeout(0.5)
    sock.bind(("127.0.0.1", 0))

    socket_address = sock.getsockname()
    print "Trivial Server launched on socket: %s" %str(socket_address)
    while(1):
        sock.listen(1)

if __name__ == '__main__':
    test_socket_mode()
