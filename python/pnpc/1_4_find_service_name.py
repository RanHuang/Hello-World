#!/usr/bin/env python
# -*- coding: utf-8 -*-

import socket

# 根据指定端口和协议获知网络服务的名字
def find_service_name():
    protocol = 'tcp'
    for port in [25, 80]:
        service = socket.getservbyport(port, protocol)
        print "Port: %d ==> Service name: %s" %(port, service)

    port = 53
    print "Port: %d ==> Service name: %s" %(port, socket.getservbyport(port, 'udp'))

def test():
    find_service_name()

if __name__ == '__main__':
    test()
