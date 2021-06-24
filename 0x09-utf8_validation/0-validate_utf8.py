#!/usr/bin/python3
"""module to check utf-8 validation"""


def validUTF8(data):
    """Function to check the data

    Args:
        data ([list]): [List of ints]

    Returns:
        [bool]: [True if correct utf-8 or false if not]
    """
    for i in data:
        byte_num = i.to_bytes(8, byteorder="big")
        try:
            byte_num.decode('utf-8')
        except:
            return False
    return True
