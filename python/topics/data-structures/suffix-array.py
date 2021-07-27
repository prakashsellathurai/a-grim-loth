# Python3 program for building suffix
# array of a given text
import math

# Class to store information of a suffix
from itertools import zip_longest, islice


def to_int_keys_best(l):
    """
    l: iterable of keys
    returns: a list with integer keys
    """
    seen = set()
    ls = []
    for e in l:
        if not e in seen:
            ls.append(e)
            seen.add(e)
    ls.sort()
    index = {v: i for i, v in enumerate(ls)}
    return [index[v] for v in l]


def suffix_matrix_best(s):
    """
    suffix matrix of s
    O(n * log(n)^2)
    """
    n = len(s)
    k = 1
    line = to_int_keys_best(s)
    ans = [line]
    while max(line) < n - 1:
        line = to_int_keys_best(
            [
                a * (n + 1) + b + 1
                for (a, b) in zip_longest(line, islice(line, k, None), fillvalue=-1)
            ]
        )
        ans.append(line)
        k <<= 1
    return ans


def suffix_array_best(s):
    """
    suffix array of s
    O(n * log(n)^2)
    """
    n = len(s)
    k = 1
    line = to_int_keys_best(s)
    while max(line) < n - 1:
        line = to_int_keys_best(
            [
                a * (n + 1) + b + 1
                for (a, b) in zip_longest(line, islice(line, k, None), fillvalue=-1)
            ]
        )
        k <<= 1
    return line


class Suffix:
    def __init__(self, s):
        self.s = s
        self.L = len(s)
        self.P = [[0] * self.L] * self.L
        self.M = [(0, 0)] * self.L
        self.build_suffix_array()

    def build_suffix_array(self):
        for i in range(self.L):
            self.P[0][i] = ord(self.s[i])
        skip = 1
        for level in range(1, self.L):
            for i in range(self.L):
                self.M[i] = (
                    (
                        self.P[level - 1][i],
                        i +
                        skip < self.L and self.P[level - 1][i + skip] or -1000,
                    ),
                    i,
                )
            self.M = sorted(self.M)

            for i in range(self.L):
                self.P[level][self.M[i][1]] = self.P[level][self.M[i - 1][1]] if (i > 0 and self.M[i][0] == self.M[i - 1][0]) else i
            skip *= 2

    def getSuffixArray(self):
        return self.P[-1]

    def Longest_common_subsequence(self, i, j):
        len = 0
        suffix_matrix = suffix_matrix_best(self.s)
        if i == j:
            return self.L - i
        word = ""
        k = suffix_matrix.__len__() - 1
        while k >= 0 and i < self.L and j < self.L:
            if suffix_matrix[k][i] == suffix_matrix[k][j]:
                word = self.s[i:j]
                i += 1 << k
                j += 1 << k
                len += 1 << k
            k -= 1
        return len, word


if __name__ == "__main__":

    txt = "bobocel"
    n = len(txt)

    suffix = Suffix(txt)
    print(suffix.getSuffixArray())
    print(suffix.Longest_common_subsequence(0, 2))
    suffix = Suffix("banana")
    print(suffix.getSuffixArray())
    print(suffix.Longest_common_subsequence(1, 3))
