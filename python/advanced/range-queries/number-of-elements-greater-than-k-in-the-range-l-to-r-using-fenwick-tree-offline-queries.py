# Python program to print the number of elements
# greater than k in a subarray of range L-R.

# Structure which will store both
# array elements and queries.
class node:
	def __init__(self):
		self.pos = 0
		self.l = 0
		self.r = 0
		self.val = 0

# Updates the node of BIT array by adding
# 1 to it and its ancestors.
def update(BIT: list, n: int, idx: int):
	while idx <= n:
		BIT[idx] += 1
		idx += idx & -idx

# Returns the count of numbers of elements
# present from starting till idx.
def query(BIT: list, idx: int) -> int:
	ans = 0
	while idx:
		ans += BIT[idx]
		idx -= idx & -idx
	return ans

# Function to solve the queries offline
def solveQuery(arr: list, n: int, QueryL: list,
				QueryR: list, QueryK: list, q: int):

	# create node to store the elements
	# and the queries
	a = [0] * (n + q + 1)
	for i in range(n + q + 1):
		a[i] = node()
	
	# 1-based indexing

	# traverse for all array numbers
	for i in range(1, n + 1):
		a[i].val = arr[i - 1]
		a[i].pos = 0
		a[i].l = 0
		a[i].r = i

	# iterate for all queries
	for i in range(n + 1, n + q + 1):
		a[i].pos = i - n
		a[i].val = QueryK[i - n - 1]
		a[i].l = QueryL[i - n - 1]
		a[i].r = QueryR[i - n - 1]

	# In-built sorted function used to
	# sort node array using comp function.
	a = [a[0]] + sorted(a[1:],
		key = lambda k: (k.val, k.l),
		reverse = True)

	# Binary Indexed tree with
	# initially 0 at all places.
	BIT = [0] * (n + 1)

	# For storing answers for
	# each query( 1-based indexing ).
	ans = [0] * (q + 1)

	# traverse for numbers and query
	for i in range(1, n + q + 1):
		if a[i].pos != 0:

			# call function to returns answer for each query
			cnt = query(BIT, a[i].r) - query(BIT, a[i].l - 1)

			# This will ensure that answer of each query
			# are stored in order it was initially asked.
			ans[a[i].pos] = cnt
		else:

			# a[i].r contains the position of the
			# element in the original array.
			update(BIT, n, a[i].r)

	# Output the answer array
	for i in range(1, q + 1):
		print(ans[i])

# Driver Code
if __name__ == "__main__":

	arr = [7, 3, 9, 13, 5, 4]
	n = len(arr)

	# 1-based indexing
	QueryL = [1, 2]
	QueryR = [4, 6]

	# k for each query
	QueryK = [6, 8]

	# number of queries
	q = len(QueryL)

	# Function call to get
	solveQuery(arr, n, QueryL, QueryR, QueryK, q)

