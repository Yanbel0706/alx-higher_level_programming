#!/usr/bin/python3
def multiply_by_2(a_dictionary):
    new_dir = a_dictionary.copy()
    l_keys = list(new_dir.keys())
    for x in l_keys:
        new_dir[x] *= 2
    return new_dir
