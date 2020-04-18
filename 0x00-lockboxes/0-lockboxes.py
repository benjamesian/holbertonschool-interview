#!/usr/bin/python3


def canUnlockAll(boxes):
    opened = set()
    to_open = set((0,))
    while len(to_open) > 0:
        key = to_open.pop()
        if key < len(boxes):
            opened.update((key,))
            to_open.update(set(boxes[key]).difference(opened))
    return len(opened) == len(boxes)
