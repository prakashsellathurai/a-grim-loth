# A Dynamic Programming based Python Program for the Egg Dropping Puzzle
INT_MAX = 32767

# Function to get minimum number of trials needed in worst
# case with n eggs and k floors
def eggDrop(n, k):
	# A 2D table where entery eggFloor[i][j] will represent minimum
	# number of trials needed for i eggs and j floors.
	eggFloor = [[0 for x in range(k + 1)] for x in range(n + 1)]

	# We need one trial for one floor and0 trials for 0 floors
	for i in range(1, n + 1):
		eggFloor[i][1] = 1
		eggFloor[i][0] = 0

	# We always need j trials for one egg and j floors.
	for j in range(1, k + 1):
		eggFloor[1][j] = j

	# Fill rest of the entries in table using optimal substructure
	# property
	for i in range(2, n + 1):
		for j in range(2, k + 1):
			eggFloor[i][j] = INT_MAX
			for x in range(1, j + 1):
				res = 1 + max(eggFloor[i-1][x-1], eggFloor[i][j-x])
				if res < eggFloor[i][j]:
					eggFloor[i][j] = res

	# eggFloor[n][k] holds the result
	return eggFloor[n][k]


# Python3 program to find minimum
# number of trials in worst case.

# Find sum of binomial coefficients
# xCi (where i varies from 1 to n).
# If the sum becomes more than K
def binomialCoeff(x, n, k):

	sum = 0;
	term = 1;
	i = 1;
	while(i <= n and sum < k):
		term *= x - i + 1;
		term /= i;
		sum += term;
		i += 1;
	return sum;

# Do binary search to find minimum
# number of trials in worst case.
def minTrials(n, k):

	# Initialize low and high as
	# 1st and last floors
	low = 1;
	high = k;

	# Do binary search, for every
	# mid, find sum of binomial
	# coefficients and check if
	# the sum is greater than k or not.
	while (low < high):

		mid = int((low + high) / 2);
		if (binomialCoeff(mid, n, k) < k):
			low = mid + 1;
		else:
			high = mid;

	return int(low);

# Driver program to test to pront printDups
n = 2
k = 10
print("Minimum number of trials in worst case with" + str(n) + "eggs and "
	+ str(k) + " floors is " + str(eggDrop(n, k)))

# Driver Code
print(minTrials(n,k));

