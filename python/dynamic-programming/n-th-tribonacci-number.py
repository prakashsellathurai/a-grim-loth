#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
https://leetcode.com/problems/n-th-tribonacci-number

"""
__author__ = "prakashsellathurai"
__copyright__ = "Copyright 2021"
__version__ = "1.0.1"
__email__ = "prakashsellathurai@gmail.com"

class Solution:
    def tribonacci(self, n: int) -> int:
        a,b,c = 0,1,1
        
        for i in range(n):
            a,b,c = b,c,a+b+c
        return a
        