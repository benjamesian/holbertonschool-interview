#!/usr/bin/python3
"""
UTF8 checking function
"""


def validUTF8(data):
    """
    check if array of UTF-8 is valid
    """
    trailing_bytes = 0
    for byte in data:
        if trailing_bytes:
            if byte >> 6 != 0b10:
                return False
            trailing_bytes -= 1
        else:
            if byte >> 7 == 0:
                continue

            mask = 0b1000000
            while mask & byte:
                mask >>= 1
                trailing_bytes += 1
            if trailing_bytes == 1:
                return False
            trailing_bytes -= 1

    return trailing_bytes == 0
