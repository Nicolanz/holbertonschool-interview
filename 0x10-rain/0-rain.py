#!/usr/bin/python3
"""Module containing the rain() function"""


def rain(walls):
    """Function calculate how many square units of water will\
    be retained after it rains."""

    index = 0
    rain = 0

    for i in range(len(walls)):
        if walls[i] > 0:

            tmp = 0
            index = walls[i]
            i += 1
            diff = 0

            while(tmp == 0):
                try:
                    if walls[i] > 0:
                        tmp = walls[i]
                        break
                    else:
                        diff += 1
                        i += 1
                except IndexError:
                    break

            min_num = min(index, tmp)
            rain += min_num * diff
            i -= 1

    return rain
