#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import socket
import argparse

HOST = 'localhost'

def echo_client(port):
    # A simple echo server
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    server_addr = (HOST, port)
    print "Connect echo server on Addr=%s Port=%s" % server_addr
    sock.connect(server_addr)
    # Send data
    try:
        message = "Test Message.  This message will be echoed."
        print "Send '%s'" % message
        sock.sendall(message)

        len_received = 0
        len_expected = len(message)
        while len_received < len_expected:
            data = sock.recv(16)
            len_received += len(data)
            print "Received: %s" %  data
    except socket.error, e:
        print "Socket error: %s" % e
    except Exception, e:
        print "Other Exception: %s" % str(e)
    finally:
        print "Close the TCP connection to Server."
        sock.close()

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description = 'Echo Client Example')
    parser.add_argument('--port', action='store', dest='port', type=int, required=True)
    given_args = parser.parse_args()
    port = given_args.port
    echo_client(port)
