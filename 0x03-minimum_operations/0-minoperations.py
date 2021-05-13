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
    """Funtions tp get the min needed operations to get a result
    Args:
        n ([int]): [Number to evaluate]
    Returns:
        [int]: [Number of operations]
    """
    if type(n) is not int and n <= 1:
        return 0

    primeList = []
    result = 0
    number = n

    for i in range(2, n + 1):
        if checkIfPrime(i) is True:
            primeList.append(i)

    i = 0

    while number != 1:
        if number % primeList[i] == 0:
            number = number // primeList[i]
            result += primeList[i]
        else:
            i += 1
    return result
