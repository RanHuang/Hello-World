#!/usr/bin/env python
# -*- coding: utf-8 -*-

import socket

# 以整数为例，将其转换为网络字节序和主机字节序
def convert_integer():
    number = 1234
    # 32-bit
    print "Original: %s ==> Long host byte order: %s, Network byte order: %s" %(number, socket.ntohl(number), socket.htonl(number))

    # 16-bit 
    print "Original: %s ==> Short host byte order: %s, Network byte order: %s" %(number, socket.ntohs(number), socket.htons(number))

def test():
    print __name__
    convert_integer()

if __name__ == '__main__':
    test()
