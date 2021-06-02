# Python program using memoization
import sys


# Function for matrix chain multiplication
def matrixChainMemoised(p, i, j,dp):
	if(i == j):
		return 0
	
	if(dp[i][j] != -1):
		return dp[i][j]
	
	dp[i][j] = sys.maxsize
	
	for k in range(i,j):
		dp[i][j] = min(dp[i][j], matrixChainMemoised(p, i, k,dp) + matrixChainMemoised(p, k + 1, j,dp)+ p[i - 1] * p[k] * p[j])
	
	return dp[i][j]

def MatrixChainOrder(p,n):
    i = 1
    j = n - 1
    dp = [[-1 for i in range(n+1)] for j in range(n+1)]
    return matrixChainMemoised(p, i, j,dp)

# Driver Code
arr = [1, 2, 3, 4]
n = len(arr)
print("Minimum number of multiplications is",MatrixChainOrder(arr, n))
