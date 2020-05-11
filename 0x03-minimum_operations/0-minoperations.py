#!/usr/bin/python3
"""Compute minimum number of operations to reach a state."""


def minOperations(n):
    if n <= 1:
        return 0

    i = 1
    ops = 0
    while i < n:
        while n % (i * 2) == 0:
            i *= 2
            ops += 2
        if i < n:
            temp = i
            ops += 1
            while i < n and n % (i * 2) != 0:
                i += temp
                ops += 1

    return ops
