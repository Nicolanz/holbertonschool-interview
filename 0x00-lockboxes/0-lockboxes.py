#!/usr/bin/python3
"""module containing canUnlockAll(boxes) function"""


def canUnlockAll(boxes):
    """Funtion that determines if all boxes can be opened

    Args:
        boxes ([list]): is a list of lists of ints

    Returns:
        [bool]: [True if all boxes can be opened or false if not]
    """
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
