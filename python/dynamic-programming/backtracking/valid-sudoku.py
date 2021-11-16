#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
 https://leetcode.com/problems/valid-sudoku
"""
__author__ = "prakashsellathurai"
__copyright__ = "Copyright 2021"
__version__ = "1.0.1"
__email__ = "prakashsellathurai@gmail.com"



class Solution:
        
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        
        boardMap = collections.defaultdict(list)
        for x in range(9):
            for y in range(9):
                char = board[x][y]
                if char != '.': 
                    if char in boardMap:
                        for pos in boardMap[char]:
                            if (pos[0]== x) or (pos[1] == y) or (pos[0]//3 == x//3 and pos[1]//3 == y//3):
                                return False
                    boardMap[char].append((x,y))
   
        return True    