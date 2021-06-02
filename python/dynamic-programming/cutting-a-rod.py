# A Dynamic Programming solution for Rod cutting problem
INT_MIN = -32767

# Returns the best obtainable price for a rod of length n and
# price[] as prices of different pieces
def cutRod(price, n):
	val = [0 for x in range(n+1)]
	val[0] = 0

	# Build the table val[] in bottom up manner and return
	# the last entry from the table
	for i in range(1, n+1):
		max_val = INT_MIN
		for j in range(i):
			max_val = max(max_val, price[j] + val[i-j-1])
		val[i] = max_val

	return val[n]

# Driver program to test above functions
arr = [1, 5, 8, 9, 10, 17, 17, 20]
size = len(arr)
print("Maximum Obtainable Value is " + str(cutRod(arr, size)))


def unboundedKnapsack(W, n, val, wt):
 
    # dp[i] is going to store maximum
    # value with knapsack capacity i.
    dp = [0 for i in range(W + 1)]
 
    ans = 0
 
    # Fill dp[] using above recursive formula
    for i in range(W + 1):
        for j in range(n):
            if (wt[j] <= i):
                dp[i] = max(dp[i], dp[i - wt[j]] + val[j])
 
    return dp[W]
 
# Driver program

val = arr
wt = [i+1 for i in range(len(val))]
n = len(val)
W = n
print(unboundedKnapsack(W, n, val, wt))