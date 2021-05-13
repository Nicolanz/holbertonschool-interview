#!/usr/bin/python3
"""Module to get the minimum of operations"""


def minOperations(n):
    """Funtion t get the min required operations to get a result
    Args:
        n ([int]): [Number to evaluate]
    Returns:
        [int]: [Number of operations]
    """
    result = 0
    newList = []

    if isinstance(n, (int, float)) is False:
        return result
    elif n <= 1:
        return result

    for i in range(2, n + 1):
        if n % i == 0:
            newList.append(i)

    i = 0

    while (n != 1):
        if n % newList[i] == 0:
            n = n // newList[i]
            result += newList[i]
        else:
            i = i + 1
    return int(result)
