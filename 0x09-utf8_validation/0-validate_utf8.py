#!/usr/bin/python3
"""
UTF8 checking function
"""


def validUTF8(data):
    """
    check if array of UTF-8 is valid
    """
    if not data:
        return False

    trailing_bytes = 0
    for byte in data:
        if trailing_bytes:
            if byte >> 6 != 0b10:
                return False
            trailing_bytes -= 1
        else:
            if not byte & 0b10000000:
                continue
            elif byte >> 4 == 0b1111:
                trailing_bytes = 3
            elif byte >> 5 == 0b111:
                trailing_bytes = 2
            elif byte >> 6 == 0b11:
                trailing_bytes = 1
            else:
                return False

    return trailing_bytes == 0
