#!/usr/bin/python3


def check_tail_bytes(n, byte_array):
    """check if n bytes start with 10 in binary"""
    if len(byte_array) < n:
        return False

    while n:
        byte = byte_array.pop(0)
        if byte >> 6 != 0b10:
            return False
        n -= 1

    return True


def validUTF8(data):
    """check if array of UTF-8 is valid"""
    if not data:
        return False

    data_copy = data[:]
    while data_copy:
        byte = data_copy.pop(0)
        if not byte & 0b10000000:
            continue
        if byte >> 4 == 0b1111:
            if not check_tail_bytes(3, data_copy):
                return False
        elif byte >> 5 == 0b111:
            if not check_tail_bytes(2, data_copy):
                return False
        elif byte >> 6 == 0b11:
            if not check_tail_bytes(1, data_copy):
                return False
        else:
            return False

    return True
