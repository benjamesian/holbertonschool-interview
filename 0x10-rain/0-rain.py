#!/usr/bin/python3
"""rain collection problem"""

def rain(walls):
    """rain collected in cups challenge"""
    out = 0
    for i in range(1, len(walls) - 1):
        left = max(walls[j] for j in range(i + 1))
        right = max(walls[j] for j in range(i, len(walls)))
        out += min(left, right) - walls[i]
    return out
