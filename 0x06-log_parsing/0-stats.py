#!/usr/bin/python3
"""Module that reads stdin line by line and computes
"""
import sys

status_dict = {200: 0, 301: 0, 400: 0, 401: 0,
               403: 0, 404: 0, 405: 0, 500: 0}
suma = 0
counter = 0

try:
    for line in sys.stdin:
        tmp_list = line.split()
        if (len(tmp_list) < 2):
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
