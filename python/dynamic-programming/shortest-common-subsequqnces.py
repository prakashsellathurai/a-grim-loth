# A dynamic programming based python program
# to find length of the shortest supersequence

# Returns length of the shortest supersequence of X and Y


def superSeq(X, Y, m, n):
    dp = [[0] * (n + 2) for i in range(m + 2)]

    # Fill table in bottom up manner
    for i in range(m + 1):
        for j in range(n + 1):

            # Below steps follow above recurrence
            if not i:
                dp[i][j] = j
            elif not j:
                dp[i][j] = i

            elif X[i - 1] == Y[j - 1]:
                dp[i][j] = 1 + dp[i - 1][j - 1]

            else:
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1])

    return dp[m][n]


# Python implementation to find shortest string for
# a combination of two strings
index_a = []
index_b = []


def index(dp, a, b, size_a, size_b):
    if size_a == 0 or size_b == 0:
        return
    if a[size_a - 1] == b[size_b - 1]:
        index(dp, a, b, size_a - 1, size_b - 1)
        index_a.append(size_a - 1)
        index_b.append(size_b - 1)
    else:
        if dp[size_a - 1][size_b] > dp[size_a][size_b - 1]:
            index(dp, a, b, size_a - 1, size_b)
        else:
            index(dp, a, b, size_a, size_b - 1)


def combine(a, b, size_a, size_b):
    dp = [[0 for i in range(100)] for j in range(100)]
    ans = ""
    k = 0

    for i in range(1, size_a + 1):
        for j in range(1, size_b + 1):
            if a[i - 1] == b[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])

    lcs = dp[size_a][size_b]
    index(dp, a, b, size_a, size_b)
    j = i = k
    while k < lcs:
        while i < size_a and i < index_a[k]:
            ans += a[i]
            i += 1
        while j < size_b and j < index_b[k]:
            ans += b[j]
            j += 1
        ans = ans + a[index_a[k]]
        k += 1
        i += 1
        j += 1

    while i < size_a:
        ans += a[i]
        i += 1
    while j < size_b:
        ans += b[j]
        j += 1
    print(ans)


# Driver Code
X = "AGGTAB"
Y = "GXTXAYB"
print("Length of the shortest supersequence is %d" %
      superSeq(X, Y, len(X), len(Y)))

# Driver code
a = "algorithm"
b = "rhythm"
size_a = len(a)
size_b = len(b)
combine(a, b, size_a, size_b)
