##!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
THE CHECKERBOARD COVERING

"""
__author__ = "prakashsellathurai"
__copyright__ = "Copyright 2021"
__version__ = "1.0.1"
__email__ = "prakashsellathurai@gmail.com"


def cover(board,lab=1,top=0,left=0,side=None):
    
    if side is None: side = len(board)
    
    s = side // 2
    
    offsets = (0,-1),(side-1,0)
    
    for dy_outer,dy_inner in offsets:
        for dx_outer,dx_inner in offsets:

            if not board[top+dy_outer][left+dx_outer]:
                board[top+s+dy_inner][left+s+dx_inner] = lab
    lab+=1
    if s>1:
        for dy in [0,s]:
            for dx in [0,s]:
                lab = cover(board=board,lab=lab,top=top+dy,left=left+dx,side=s)
    return lab
if __name__ == "__main__":
    board = [[0] * 8 for i in range(8)]
    board[7][7] = -1
    cover(board=board)
    for row in board:
        print((" %2i"*8) % tuple(row))
