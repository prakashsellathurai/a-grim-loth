#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Find first and last position of a targte in list
"""
__author__ = "prakashsellathurai"
__copyright__ = "Copyright 2021"
__version__ = "1.0.1"
__email__ = "prakashsellathurai@gmail.com"

def searchRange(nums, target):
    """
    >>> searchRange([5,7,7,8,8,10],8)
    [3, 4]
    >>> searchRange([5,7,7,8,8,10],6)
    [-1, -1]
    """
    start = 0; end = len(nums)-1
    while start <= end:
        mid = (start+end) // 2
        if nums[start] == nums[end] == target:
            return [start,end]
        
        if nums[mid] < target:
            start = mid+1
        elif nums[mid] > target:
            end = mid-1
        else:
            if nums[start] != target: start += 1
            if nums[end] != target: end -= 1
    return [-1,-1]


if __name__ == "__main__":
    import doctest
    doctest.testmod(verbose=True)