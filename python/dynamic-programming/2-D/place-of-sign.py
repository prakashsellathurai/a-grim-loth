from itertools import accumulate

MOD = int(1e9 + 7)
n = int(input())
s = input()
dp = [1] * n
for c in s:
    if c == ">":
        dp = list(reversed(list(accumulate([0] + list(reversed(dp))[:-1]))))
    elif c == "<":
        dp = list(accumulate([0] + dp[:-1]))
    for i in range(n):
        dp[i] %= MOD
print(sum(dp) % MOD)
