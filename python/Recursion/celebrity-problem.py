##!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
celebrity problem
"""
__author__ = "prakashsellathurai"
__copyright__ = "Copyright 2021"
__version__ = "1.0.1"
__email__ = "prakashsellathurai@gmail.com"


from random import randrange

def celeb(G):
    n = len(G)
    
    u,v = 0,1
    for c in range(2,n+1):
        if G[u][v]: u=c
        else: v=c
    
    if u==n: c=v
    else:   c=u
    
    for v in range(n):
        if c==v: continue
        if G[c][v]: break
        if not G[v][c]: break
    else:
        return c
    return None

if __name__ == "__main__":
    n = 100
    G  = [[randrange(2) for i in range(n)] for i in range(n)]
    
    c = randrange(n)
    
    for i in range(n):
        G[i][c] = True
        G[c][i] = False
    
    print(celeb(G))