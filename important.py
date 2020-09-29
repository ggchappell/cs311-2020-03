#!/usr/bin/env python3
# important.py
# Glenn G. Chappell
# 2020-09-25
#
# For CS 311 Fall 2020
"""Print the sum from Analysis of Algorithms
Illustrates the most important part of a formula
Requires Python 3.x."""

import math  # for .log


def print_results(n):
    """Given an integer n, print the terms in the sum from the Analysis
    of Algorithms slides, along with the sum itself, each on a separate
    line, rounded to the nearest integer.

    """
    # Terms in sum
    a = n * math.log(n, 10)
    b = 72 * n
    c = 3 * n**2
    d = 945

    # The sum itself
    total = a+b+c+d

    # Print all values
    print(int(a+0.5))
    print(b)
    print(c)
    print(d)
    print(int(total+0.5))


# Main program
# If this module is executed as a program (instead of being imported):
# input n, print numbers in nice format, repeat until blank line input.
if __name__ == "__main__":
    while True:
        print()
        print("Given n, I print the values of the terms in the sum")
        print("from the Analysis of Algorithms slides, along with the")
        print("sum itself. Values are rounded to the nearest integer.")
        print()
        try:
            line = input("Type n [blank line to exit]: ")
            if line == "": break
            n = int(line)
            if n < 0: raise Exception()
        except:
            print()
            print("Please type a nonnegative integer")
        else:
            print()
            print_results(n)
        print()
        print("-" * 60)
    print("Bye!")
    print()

