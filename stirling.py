#!/usr/bin/env python3
# stirling.py
# Glenn G. Chappell
# 2019-10-02
#
# For CS 311 Fall 2020
"""Compare factorial & Stirling's approximation
Requires Python 3.x."""


# Note: Lines beginning ">>>" are doctests. If a command-line interface
# is available, then these can be executed by doing the following:
#
#     python3 -m doctest stirling.py
#
# When doing the above, only the results of failing tests are printed.
# Thus, no output is GOOD. To get the results of ALL tests, add "-v"
# (for "verbose"):
#
#     python3 -m doctest stirling.py -v

import math  # For .exp, .sqrt, .pi


def factorial(n):
    """nonneg int n -> n!

    >>> factorial(0)
    1
    >>> factorial(3)
    6
    >>> factorial(12)
    479001600

    Pre:
        n is integer.
        n >= 0.

    """
    assert isinstance(n, int)
    assert n >= 0

    result = 1
    for i in range(1, 1+n):
        result *= i
    return result


def stirling(n):
    """nonneg number n -> Stirling's approximation of n!

    >>> "%.3f" % stirling(6)
    '710.078'
    >>> "%.3f" % stirling(20)
    '2422786846761133568.000'

    Pre:
        n is integer or real number.
        n >= 0.

    """
    assert isinstance(n, (int, float))
    assert n >= 0

    return n**n / math.exp(n) * math.sqrt(2 * math.pi * n)


def print_results(n):
    """Compute n! & Stirling's approximation; print in pretty form."""

    print("n = {}".format(n))
    print("")
    try:
        f = factorial(n)
        s = stirling(n)
    except:
        print("*** Factorial/Stirling's computation failed ***")
        print("")
        print("(Exactly when this happens is system-dependent. On my")
        print("machine, results exceed the limits of Python's float")
        print("type when n >= 144. -GGC-)")
    else:
        print("Factorial:  %d" % f)
        print("Stirling's: %.2f" % s)


# Main program
# If this module is executed as a program (instead of being imported):
# input n, print F(n) in nice format, repeat until blank line input.
if __name__ == "__main__":
    while True:
        print()
        print("Given a nonnegative integer n, ", sep="")
        print("I compute its factorial and Stirling's approximation.")
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

