"""Define subproblems
– Let Dij be the length of the LCS of x1...i and y1...j
◮ Find the recurrence
– If xi = yj , they both contribute to the LCS
◮ Dij = Di−1,j−1 + 1
– Otherwise, either xi or yj does not contribute to the LCS, so
one can be dropped
◮ Dij = max{Di−1,j , Di,j−1}
– Find and solve the base cases: Di0 = D0j = 0

"""

x = "ABCBDAB"
y = "BDCABC"

n = len(x)
m = len(y)

dp = [[0] * m] * n

for i in range(n):
    for j in range(m):
        if x[i] == y[j]:
            dp[i][j] = dp[i][j] + 1
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])


print(dp[n - 1][m - 1])
