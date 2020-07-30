#!/usr/bin/python3
"""0. N queens (N queens problem)"""
from typing import List, Tuple


class NQueens:
    """Solve N-Queens problem"""

    def __init__(self, nqs: int):
        self.nqs = nqs
        self.solutions = None
        self.tracker = [-1] * nqs

    def valid(self, col: int):
        """Check if a queen can be placed in a column"""
        for i in range(col):
            if abs(self.tracker[i] - self.tracker[col]) in {0, col - i}:
                return False
        return True

    def helper(self, index: int, cols: List[int]):
        """Solve N-Queens problem"""
        if index == self.nqs:
            self.solutions.append(cols)
            return
        for i in range(self.nqs):
            self.tracker[index] = i
            if self.valid(index):
                self.helper(index + 1, cols + [i])

    def solve(self) -> List[Tuple[int, int]]:
        """Run recursive helper function"""
        if self.solutions is None:
            self.solutions = []
            self.helper(0, [])
        return [list(enumerate(sol)) for sol in self.solutions]


if __name__ == '__main__':
    import sys

    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solver = NQueens(n)
    solutions = solver.solve()
    for res in solutions:
        out = [list(el) for el in res]
        print(out)
