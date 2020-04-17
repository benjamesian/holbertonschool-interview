#!/usr/bin/python3


def canUnlockAll(boxes):
    opened = set((0,))
    to_search = set((0,))
    while len(to_search) > 0:
        keys = set((to_search.pop(),))
        for key in keys:
            to_search.update(set(boxes[key]).difference(opened))
        opened.update(keys)
    return len(opened) == len(boxes)
