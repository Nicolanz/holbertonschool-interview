#!/usr/bin/python3
"""Making change module"""


def makeChange(coins, total):
    """make change function"""

    if total <= 0:
        return 0

    new_list = sorted(coins, reverse=True)
    result = 0
    change = 0
    i = 0

    while (i < len(new_list)):
        if result + new_list[i] <= total:
            result = result + new_list[i]
            change += 1
            if result == total:
                return change
        else:
            i += 1
    return -1
