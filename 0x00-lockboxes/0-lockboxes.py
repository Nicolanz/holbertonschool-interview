#!/usr/bin/python3


def canUnlockAll(boxes):
    pos = 0
    newList = []
    for i in boxes:
        for j in i:
            if j != pos and j not in newList:
                newList.append(j)
        pos = pos + 1
    for j in range(1, len(boxes)):
        if j in newList:
            if len(boxes) - 1 == j:
                return True
        else:
            return False
    return True
