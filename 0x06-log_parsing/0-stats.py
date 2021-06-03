#!/usr/bin/python3

from datetime import datetime
import sys
import signal


def validateData(x):
    for i in range(len(x)):
        if i == 0:
            tmp = x[i].split(".")
            for num in tmp:
                if int(num) <= 0 or int(num) > 255:
                    return False
        elif i == 1:
            try:
                x[i] = datetime.strptime(x[i], '%Y-%m-%d %H:%M:%S.%f')
            except:
                return False
        elif i == 2:
            if x[i] != 'GET /projects/260 HTTP/1.1':
                print(x[i])
                return False
        elif i == 3:
            if int(x[i]) not in [200, 301, 400, 401, 403, 404, 405, 500]:
                return False
            x[i] = int(x[i])
        elif i == 4:
            try:
                x[i] = int(x[i])
            except:
                return False
    return True


def printResults(list, sum):
    print("File size: {}".format(sum))
    list = sorted(list)
    for j in range(len(list)):
        if list[j] != list[j - 1]:
            print("{:d}: {:d}".format(list[j], list.count(list[j])))


def sigint_handler(signal, frame):
    printResults(list, sum)
    sys.exit(0)


list = []
sum = 0
signal.signal(signal.SIGINT, sigint_handler)

for line in sys.stdin:
    x = line.split()
    x[2] += " " + x[3]
    x[4] += " " + x[5]
    x[4] += " " + x[6]
    del x[1]
    del x[2]
    del x[3]
    del x[3]
    x[1] = x[1].strip("[]")
    x[2] = x[2].strip('"')

    if validateData(x) is True:
        sum += x[4]
        list.append(x[3])
    if(len(list) == 10):
        printResults(list, sum)
        sum = 0
        list = []
