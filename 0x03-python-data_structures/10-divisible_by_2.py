#!/usr/bin/python3
def divisible_by_2(my_list=[]):
    num_list = []
    for i in range(len(my_list)):
        if (my_list[i] % 2) == 0:
            num_list.append(True)
        else:
            num_list.append(False)
    return num_list
