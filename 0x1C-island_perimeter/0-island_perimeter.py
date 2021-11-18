#!/usr/bin/python3
"""Module containing the island_perimeter(grid) function"""


def island_perimeter(grid):
    """Function that returns the perimeter of the island described in grid"""
    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 0:
                pass
            else:
                try:
                    if grid[i][j - 1] == 0:
                        perimeter += 1
                except IndexError:
                    perimeter += 1
                try:
                    if grid[i][j + 1] == 0:
                        perimeter += 1
                except IndexError:
                    perimeter += 1
                try:
                    if grid[i - 1][j] == 0 or i == 0:
                        perimeter += 1
                except IndexError:
                    perimeter += 1
                try:
                    if grid[i + 1][j] == 0:
                        perimeter += 1
                except IndexError:
                    perimeter += 1
    return perimeter
