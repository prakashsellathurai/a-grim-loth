#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
 https://leetcode.com/problems/coin-change
"""
__author__ = "prakashsellathurai"
__copyright__ = "Copyright 2021"
__version__ = "1.0.1"
__email__ = "prakashsellathurai@gmail.com"


from typing import List


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [0 for _ in range(amount + 1)]
        dp[0] = 0

        for i in range(1, amount + 1):
            dp[i] = amount + 1
            for coin in coins:
                if coin <= i:
                    dp[i] = min(dp[i], 1 + dp[i - coin])
        return dp[amount] > amount and -1 or dp[amount]
