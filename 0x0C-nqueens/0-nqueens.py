#!/usr/bin/python3

import sys

if len(sys.argv) != 2:
    print("Usage: nqueens N")
    sys.exit(1)

else:
    try:
        num = eval(sys.argv[1])
    except NameError:
        print("N must be a number")
        sys.exit(1)

    if (type(num) != int):
        print("N must be a number")
        sys.exit(1)
    elif num < 4:
        print("N must be at least 4")
        sys.exit(1)
    else:
        myList = []
        j=0
        for i in range(num):
            newList = [i, j]
            myList.append(newList)
            j += 1
        print(myList)
