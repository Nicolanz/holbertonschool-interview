#!/usr/bin/python3
"""Module that reads stdin line by line and computes
"""
import sys
from datetime import datetime

status_dict = {200: 0, 301: 0, 400: 0, 401: 0,
               403: 0, 404: 0, 405: 0, 500: 0}
suma = 0
counter = 0


def validateData(line):
    """Validates given data

    Args:
        line ([str]): [line to check]

    Returns:
        [bool]: [True if correct format or false if not]
    """
    line = line.split()
    if len(line) != 9:
        return False
    else:
        for i in range(len(line)):
            if i == 0:
                try:
                    my_tmp_obj = line[i].split(".")
                    if len(my_tmp_obj) != 4:
                        return False
                except:
                    return False
            if i == 2:
                try:
                    my_tmp_obj = line[i]
                    my_tmp_obj += " " + line[i + 1]
                    my_tmp_obj = my_tmp_obj.strip("[]")
                    my_tmp_obj = datetime.strptime(
                        my_tmp_obj,
                        '%Y-%m-%d %H:%M:%S.%f'
                        )
                except:
                    return False
            if i == 4:
                try:
                    my_tmp_obj = line[i]
                    my_tmp_obj += " " + line[i + 1] + " " + line[i + 2]
                    my_tmp_obj = my_tmp_obj.strip('"')
                    if my_tmp_obj != "GET /projects/260 HTTP/1.1":
                        return False
                except:
                    return False
            if i == 7:
                try:
                    my_tmp_obj = int(line[i])
                    if my_tmp_obj not in status_dict.keys():
                        return False
                except:
                    return False
            if i == 8:
                try:
                    my_tmp_obj = int(line[i])
                except:
                    return False
        return True

try:
    for line in sys.stdin:
        if (validateData(line) is False):
            continue
        tmp_list = line.split()
        if int(tmp_list[-2]) in status_dict.keys():
            status_dict[int(tmp_list[-2])] += 1

        counter += 1
        suma += int(tmp_list[-1])

        if (counter == 10):
            counter = 0
            print("File size: {}".format(suma))
            for key, value in sorted(status_dict.items()):
                if value > 0:
                    print("{}: {}".format(key, value))
finally:
    print("File size: {}".format(suma))
    for key, value in sorted(status_dict.items()):
        if value > 0:
            print("{}: {}".format(key, value))
