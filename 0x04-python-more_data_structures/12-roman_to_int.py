#!/usr/bin/python3
def to_subtract(list_num):
    sub = 0
    max_l = max(list_num)

    for i in list_num:
        if max_l > i:
            sub += i

    return (max_l - sub)


def roman_to_int(roman_string):
    if not roman_string:
        return 0

    if not isinstance(roman_string, str):
        return 0

    rom_char = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
    list_keys = list(rom_char.keys())

    number = 0
    l_rom = 0
    l_num = [0]

    for char in roman_string:
        for roman_num in list_keys:
            if roman_num == char:
                if rom_char.get(char) <= l_rom:
                    number += to_subtract(l_num)
                    l_num = [rom_char.get(char)]
                else:
                    l_num.append(rom_char.get(char))

                l_rom = rom_char.get(char)

    number += to_subtract(l_num)

    return (number)
