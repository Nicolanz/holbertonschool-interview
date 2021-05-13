#!/usr/bin/python3
"""Module to get the minimum of operations"""


def checkIfPrime(n):
    """Checks if a number is prime or not

    Args:
        n ([int]): [Numbet to compare primes]

    Returns:
        [bool]: [True if prime or false if false]
    """
    if n > 1:
        for i in range(2, n):
            if (n % i) == 0:
                return False
        return True
    else:
        return False


def minOperations(n):
    """Funtions tp get the min needed operations to get a result

    Args:
        n ([int]): [Number to evaluate]

    Returns:
        [int]: [Number of operations]
    """
    if type(n) != int and n <= 1:
        return 0
    elif (checkIfPrime(n) is True):
        return n

    primeList = []
    result = 0
    number = n

    for i in range(0, n):
        if checkIfPrime(i) is True:
            primeList.append(i)

    i = 0

    while number != 1:
        if number % primeList[i] == 0:
            number = number // primeList[i]
            result = result + primeList[i]
        if number % primeList[i] != 0:
            i = i + 1
    return result
