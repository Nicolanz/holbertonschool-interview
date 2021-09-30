#!/usr/bin/python3
"""Module containing a function to rotate a matrix"""


def rotate_2d_matrix(matrix):
    """Function to rotate the matrix"""
    my_list = []
    for i in range(len(matrix)):
        new_list = []
        for b in range(len(matrix)):
            new_list.insert(0, matrix[b][i])
        my_list.append(new_list)

    for i in range(len(matrix)):
        for b in range(len(matrix)):
            matrix[i][b] = my_list[i][b]

    return matrix
