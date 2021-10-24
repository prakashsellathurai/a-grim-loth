# !/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Topological sorting
"""
__author__ = "prakashsellathurai"
__copyright__ = "Copyright 2021"
__version__ = "1.0.1"
__email__ = "prakashsellathurai@gmail.com"


from random import randrange
from collections import defaultdict


def naive_topsort(G, S=None):
    if S is None:
        S = set(G)

    if len(S) == 1:
        return list(S)

    v = S.pop()

    seq = naive_topsort(G, S)

    min_i = 0
    for i, u in enumerate(seq):
        if v in G[u]:
            min_i = i + 1
    seq.insert(min_i, v)
    return seq


def topsort(G):
    count = {u: 0 for u in G}  # The in-degree for each node
    for u in G:
        for v in G[u]:
            count[v] += 1  # Count every in-edge
    Q = [u for u in G if count[u] == 0]  # Valid initial nodes
    S = []  # The result
    while Q:  # While we have start nodes...
        u = Q.pop()  # Pick one
        S.append(u)  # Use it as first of the rest
        for v in G[u]:
            count[v] -= 1  # "Uncount" its out-edges
            if count[v] == 0:  # New valid start nodes?
                Q.append(v)  # Deal with them next
    return S


class randRangesparse(object):
    """docstring for randRangesparse."""

    def __init__(self, n):
        super(randRangesparse, self).__init__()
        self.n = n
        self.weights = self.regenerate_weights()

    def regenerate_weights(self):
        return {i: self.n - i for i in range(self.n)}

    def get_random(self):
        coin = randrange(self.n)

        while self.weights[coin] != 0:
            if self.weights[coin] != 0:
                self.weights[coin] -= 1
                return coin
            else:
                coin = randrange(self.n - 1)

        self.weights = self.regenerate_weights()
        return self.get_random()


if __name__ == "__main__":

    rng = randRangesparse(10)
    G = [[rng.get_random() for _ in range(10)] for _ in range(10)]

    print(naive_topsort(G))
