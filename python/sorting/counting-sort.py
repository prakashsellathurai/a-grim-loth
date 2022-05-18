##!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Counting Sort
"""
__author__ = "prakashsellathurai"
__copyright__ = "Copyright 2021"
__version__ = "1.0.1"
__email__ = "prakashsellathurai@gmail.com"


from collections import defaultdict
import random

def counting_sort(A,key=lambda x:x):
    """
    >>> A = [2,4,5,7,8,96,6]
    >>> counting_sort(A)
    [2, 4, 5, 6, 7, 8, 96]
    """
    B,C = [],defaultdict(list)
    for x in A:
        C[key(x)].append(x)
    for k in range(min(C),max(C)+1):
        B.extend(C[k])
    return B

if __name__ == "__main__":
    import doctest
    doctest.testmod(verbose=1)
