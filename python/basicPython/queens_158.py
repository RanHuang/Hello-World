#!/usr/bin/env python
# -*- coding: utf-8 -*-

import random

"""
def conflict(pos, state):
    nextY = len(state)
    for i in range(nextY):
        if pos == state[i] or abs(pos-state[i]) == nextY-i:
            return True 
    return False

def queens(num=8, state=()):
    if len(state) == num-1:
        for pos in range(num):
            if not conflict(pos, state):
                yield (pos,)
    else:
        for pos in range(num):
            if not conflict(pos, state):
                for result in queens(num, state + (pos,)):
                    yield (pos,) + result
"""

def conflict(pos, state):
    nextY = len(state)
    for i in range(nextY):
        if abs(pos-state[i]) in (0, nextY-i):
            return True 
    return False

def queens(num=8, state=()):
    for pos in range(num):
        if not conflict(pos, state):
            if len(state) == num-1:
                yield (pos,)
            else:
                for result in queens(num, state + (pos,)):
                    yield (pos,) + result

def prettyprint(solution):
    for pos in solution:
        length=len(solution)
        print '. '*pos + 'x' + ' .'*(length-pos-1)

if __name__ == '__main__':
    solutions = list(queens(8))
    print "8 queens:", len(solutions)
    prettyprint(random.choice(solutions))
    
    print "state:(1,3,0) :", list(queens(4, (1,3,0)))

    print "4 queens:", list(queens(4))
