#!/usr/bin/python3
""" 0. Rotate 2D Matrix """


def rotate_2d_matrix(matrix):
    if not matrix:
        return
    answer = list(map(lambda x: list(x), zip(*matrix[::-1])))
    n = len(matrix)
    for _ in range(n):
        matrix.pop(0)
        matrix.append(answer.pop(0))
