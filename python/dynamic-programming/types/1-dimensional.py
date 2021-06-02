"""Number of ways to n as the sum of 1,3,4
Example: for n = 5, the answer is 6
    5 = 1 + 1 + 1 + 1 + 1
    = 1 + 1 + 3
    = 1 + 3 + 1
    = 3 + 1 + 1
    = 1 + 4
    = 4 + 1
hint:
Find sub problems
Dn
find recurrence:
Dn = Dn-1 + Dn-3+Dn-4
solve base cases
D0 = D1 = D2 = 1
D3 = 2
"""
n = 5
D = [0]*(n+1)
D[0] = D[1] =D[2] = 1
D[3] = 2

for i in range(4,n+1):
    D[i] = D[i-1] + D[i-3] + D[i-4]
print(D[n])