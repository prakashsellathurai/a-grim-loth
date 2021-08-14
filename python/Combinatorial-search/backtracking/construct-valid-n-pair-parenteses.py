
def backtrack(res: list, s: str, pos: int, open: int, close: int, n: int):
    """
    >>> n = 4
    >>> backtrack([],"", 0, 0, 0, n/2)
    ['(())', '()()']
    >>> backtrack([],"", 0, 0, 0, 6/2)
    ['((()))', '(()())', '(())()', '()(())', '()()()']
    """
    if n == close:
        res.append(s)
        return res

    if(open < n):
        res = backtrack(
            res, s+"(", pos+1, open+1, close, n)

    if(close < open):
        res = backtrack(
            res, s+")", pos+1, open, close+1, n)
    return res


if __name__ == "__main__":
    import doctest
    doctest.testmod(verbose=True)

