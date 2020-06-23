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
            elif byte >> 1 == 0b1111110:
                trailing_bytes = 5
            elif byte >> 2 == 0b111110:
                trailing_bytes = 4
            elif byte >> 3 == 0b11110:
                trailing_bytes = 3
            elif byte >> 4 == 0b1110:
                trailing_bytes = 2
            elif byte >> 5 == 0b110:
                trailing_bytes = 1
            else:
                return False

    return trailing_bytes == 0
