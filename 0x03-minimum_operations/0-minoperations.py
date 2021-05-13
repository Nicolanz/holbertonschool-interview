#!/usr/bin/python3
"""Module to get the minimum of operations"""


def checkIfPrime(n):
    """Checks if a number is prime or not

    Args:
        n ([int]): [Numbet to compare primes]

    Returns:
        [bool]: [True if prime or false if false]
    """
    if (n <= 1):
        return False
    if (n <= 3):
        return True

    if (n % 2 == 0 or n % 3 == 0):
        return False

    i = 5
    while(i * i <= n):
        if (n % i == 0 or n % (i + 2) == 0):
            return False
        i = i + 6

    return True


def minOperations(n):
    """Gets the minimum of operations

    Args:
        n ([int]): [number to get the num of operations]

    Returns:
        [int]: [Number of min oper]
    """
    minDivisor = 0
    maxDivisor = 0

    if (n <= 0 or type(n) != int):
        return 0
    elif (checkIfPrime(n) is True):
        return n

    for i in range(2, n):
        if (n % i == 0):
            minDivisor = i
            break
    for j in range(n - 1, 1, -1):
        if (n % j == 0):
            maxDivisor = j
            break

    for z in range(1, 1000):
        if (n == 2**z):
            return 2*z

    if (minDivisor == maxDivisor):
        return int(minDivisor + n / minDivisor)
    else:
        if (checkIfPrime(maxDivisor) is True):
            return int(n / maxDivisor + maxDivisor)
        else:
            return int(minDivisor + maxDivisor/minDivisor + n/maxDivisor)
