#!/usr/bin/python3
"""Module that reads stdin line by line and computes
"""
import sys
from datetime import datetime


def validateData(tmp_list):
    """Function to validate given data

    Args:
        x ([list]): [Listo of arguments]

    Returns:
        [bool]: [True id valid data or false if invalid data]
    """
    tmp = tmp_list.strip("[]")
    tmp = tmp.split()
    del tmp[1]
    tmp[1] += " " + tmp[2]
    del tmp[2]
    tmp[1] = tmp[1].strip("[]")
    tmp[2] += " " + tmp[3] + " " + tmp[4]
    tmp[2] = tmp[2].strip('"')
    del tmp[3]
    del tmp[3]

    for i in range(len(tmp)):
        if i == 0:
            num_tmp = tmp[i].split(".")
            for num in num_tmp:
                if int(num) <= 0 or int(num) > 255:
                    return False
        elif i == 1:
            try:
                tmp[i] = datetime.strptime(tmp[i], '%Y-%m-%d %H:%M:%S.%f')
            except:
                return False
        elif i == 2:
            if tmp[i] != 'GET /projects/260 HTTP/1.1':
                return False
    return True

status_dict = {200: 0, 301: 0, 400: 0, 401: 0,
               403: 0, 404: 0, 405: 0, 500: 0}
suma = 0
counter = 0

try:
    for line in sys.stdin:
        tmp_list = line.split()
        if (validateData(line) is False):
            continue
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
