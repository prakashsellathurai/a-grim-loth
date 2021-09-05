#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
fibonacci sequence
"""
__author__ = "prakashsellathurai"
__copyright__ = "Copyright 2021"
__version__ = "1.0.1"
__email__ = "prakashsellathurai@gmail.com"

import time


def fib_recursive(n: int):
    if n <= 1:
        return n
    return fib_recursive(n - 1) + fib_recursive(n - 2)


def fib_dp(n: int):
    dp = [0] * (n + 1)

    dp[0] = 0
    dp[1] = 1

    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]
    return dp[n]


def fib_ultimate(n: int):
    next = 0
    back2 = 0
    back1 = 1

    if n == 0:
        return 0

    for i in range(2, n + 1):
        next = back1 + back2
        back2 = back1
        back1 = next
    return next


if __name__ == "__main__":
    start = time.time()
    fib_recursive(35)
    end = time.time()
    print(" recursive took ", end - start)

    start = time.time()
    fib_dp(35)
    end = time.time()
    print(" dp took ", end - start)

    start = time.time()
    fib_ultimate(35)
    end = time.time()
    print(" dp ultimate took ", end - start)
