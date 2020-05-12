#!/usr/bin/python3
"""Compute minimum number of operations to reach a state."""


def minOperations(n):
    if n <= 1:
        return 0

    i = 1
    ops = 0
    while i < n:
        while n % (i * 2) == 0:
            ops += 2
            i *= 2
        if i < n:
            copied = i // 2
            if n % i == 0:
                ops += 1
                copied = i
            while i < n and n % (i * 2) != 0:
                i += copied
                ops += 1

    return ops
