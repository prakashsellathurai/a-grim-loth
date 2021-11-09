#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
https://leetcode.com/problems/coin-change-2
"""
__author__ = "prakashsellathurai"
__copyright__ = "Copyright 2021"
__version__ = "1.0.1"
__email__ = "prakashsellathurai@gmail.com"

from typing import List

class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [0 for _ in range(amount+1)]
        dp[0] = 1
        for coin in coins:
            for i in range(coin ,amount+1):
                if i-coin>=0:
                    dp[i] +=dp[i-coin]
        return dp[amount]