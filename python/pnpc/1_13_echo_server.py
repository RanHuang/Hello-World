#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import socket
import argparse

HOST = 'localhost'
DATA_PAYLOAD = 2048
BACKLOG = 5

def echo_server(port):
    # A simple echo server
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    server_addr = (HOST, port)
    print "Set up the echo server on Addr=%s Port=%s" % server_addr
    sock.bind(server_addr)
    sock.listen(BACKLOG)
    while True:
        print "Wating for the message from the client"
        client, address = sock.accept()
        data = client.recv(DATA_PAYLOAD)
        if data:
            print "Data: %s" % data
            client.send(data)
            print "Sent '%s' back to %s" %(data, address)

        client.close()

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description = 'Echo Server Example')
    parser.add_argument('--port', action='store', dest='port', type=int, required=True)
    given_args = parser.parse_args()
    port = given_args.port
    echo_server(port)
