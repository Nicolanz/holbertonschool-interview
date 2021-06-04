#!/usr/bin/python3
"""Module that reads stdin line by line and computes
"""
import sys

status_list = [200, 301, 400, 401, 403, 404, 405, 500]
new_list = []
suma = 0
counter = 0

try:
    for line in sys.stdin:
        tmp_list = line.split()

        if(len(tmp_list) < 2):
            continue

        if int(tmp_list[len(tmp_list) - 2]) in status_list:
            new_list.append(int(tmp_list[len(tmp_list) - 2]))

        counter += 1
        suma += int(tmp_list[len(tmp_list) - 1])

        if (counter == 10):
            new_list = sorted(new_list)
            print("File size: {}".format(suma))
            for i in range(len(new_list)):
                if new_list[i - 1] != new_list[i]:
                    print("{}: {}".format(
                        new_list[i],
                        new_list.count(new_list[i])
                        ))
            counter = 0
finally:
    new_list = sorted(new_list)
    print("File size: {}".format(suma))
    for i in range(len(new_list)):
                if new_list[i - 1] != new_list[i]:
                    print("{}: {}".format(
                        new_list[i],
                        new_list.count(new_list[i])
                        ))
