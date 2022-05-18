#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 优雅地处理套接字错误(1.尝试连接; 2.网络媒介失效或者其它原因导致无响应)
# USAGE: > python script.py --host=<HOST> --port=<PORT> --file=<FILE>
# types of socket error:
#   1. socket.error
#   2. socket.timeout   套接字超时
#   3. socket.herror    CAPI抛出的异常
#   4. socket.gaierror  地址相关错误

import sys
import argparse
import socket

def main():
    # set up argument parsing
    parser = argparse.ArgumentParser(description = 'Socket Error Example')
    parser.add_argument('--host', action='store', dest='host', required=False)
    parser.add_argument('--port', action='store', dest='port', type=int, required=False)
    parser.add_argument('--file', action='store', dest='file', required=False)
    given_args = parser.parse_args()
    host = given_args.host
    port = given_args.port
    filename = given_args.file

    # create socket
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#        sock.settimeout(10)
    except socket.error, e:
        print "Error--Create Socket: %s" % e
        sys.exit(1)

    # connect to given host/port
    try:
        sock.connect((host, port))
    except socket.gaierror, e:
        print "Address-related error connecting to server: %s" % e
        sys.exit(1)
    except socket.error, e:
        print "Error--Connect to server: %s" % e
        sys.exit(1)

    # send data
    try:
        sock.sendall("GET %s HTTP/1.0\r\n\r\n" % filename)
    except socket.error, e:
        print "Error--send data: %s" % e
        sys.exit(1)

    while True:
        # receive data
        try:
            buff = sock.recv(2048)
        except socket.error, e:
            print "Error--receive data: %s" % e
            sys.exit(1)
        if not len(buff):
            break;
        # write the received data
        sys.stdout.write(buff)

if __name__ == '__main__':
    main()
