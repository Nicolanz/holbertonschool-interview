#!/usr/bin/python3
"""Module to get the minimum of operations"""


def minOperations(n):
    """Funtion to calculate the min required operations to get a result
    Args:
        n ([int]): [Number to evaluate]
    Returns:
        [int]: [Number of operations]
    """
    result = 0
    i = 2

    if n <= 1:
        return result

    while (n != 1):
        if n % i == 0:
            n = n / i
            result += i
        else:
            i += 1
    return result
