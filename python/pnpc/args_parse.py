#!/usr/bin/env python
# -*- coding: utf-8 -*-

import argparse

def test():
    parser = argparse.ArgumentParser('Parser Example')
    parser.add_argument('--host', action='store', dest='host', required=False)
    parser.add_argument('--port', action='store', dest='port', type=int, required=False)
    parser.add_argument('--file', action='store', dest='file', required=False)
    given_args = parser.parse_args()

    print "Host: %s, Port: %d, File: %s" %(given_args.host, int(given_args.port), given_args.file) 

if __name__ == '__main__':
    test()

"""
Run the script:
    $python script.py --host=Host --port=Port --file=Filename
"""
