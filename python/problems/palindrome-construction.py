def findLongestPalindromicString(s, k):
    n = len(s)

    for i in range(k):
        print(i, 0)
    print(n, 0)

    for i in range(k + 1):
        print(i)


N, K = 4, 2
S = "abab"
print(findLongestPalindromicString(S, K))
