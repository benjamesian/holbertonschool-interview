#!/usr/bin/python3
"""Compute minimum number of operations to reach a state."""


def minOperations(n):
    """sum of prime factors"""
    if n <= 1:
        return 0

    ops = 0
    while n > 1:
        for p_factor in range(2, n + 1):
            if n % p_factor == 0:
                ops += p_factor
                n //= p_factor
                break

    return ops
