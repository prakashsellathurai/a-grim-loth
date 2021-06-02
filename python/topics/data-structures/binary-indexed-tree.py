# Python implementation of Binary Indexed Tree

# Returns sum of arr[0..index]. This function assumes
# that the array is preprocessed and partial sums of
# array elements are stored in BITree[].
def getsum(BITTree,i):
	s = 0 #initialize result

	# index in BITree[] is 1 more than the index in arr[]
	i = i+1

	# Traverse ancestors of BITree[index]
	while i > 0:

		# Add current element of BITree to sum
		s += BITTree[i]

		# Move index to parent node in getSum View
		i -= i & (-i)
	return s
# Returns count of inversions of size three
def getInvCount(arr, n):
 
    invcount = 0 # Initialize result
 
    # Find maximum element in arrays
    maxElement = max(arr)
 
    # Create a BIT with size equal to
    # maxElement+1 (Extra one is used
    # so that elements can be directly
    # be used as index)
    BIT = [0] * (maxElement + 1)
    for i in range(1, maxElement + 1):
        BIT[i] = 0
    for i in range(n - 1, -1, -1):
        invcount += getsum(BIT, arr[i] - 1)
        updatebit(BIT, maxElement, arr[i], 1)
    return invcount
# Updates a node in Binary Index Tree (BITree) at given index
# in BITree. The given value 'val' is added to BITree[i] and
# all of its ancestors in tree.
def updatebit(BITTree , n , i ,v):

	# index in BITree[] is 1 more than the index in arr[]
	i += 1

	# Traverse all ancestors and add 'val'
	while i <= n:

		# Add 'val' to current node of BI Tree
		BITTree[i] += v

		# Update index to that of parent in update View
		i += i & (-i)


# Constructs and returns a Binary Indexed Tree for given
# array of size n.
def construct(arr, n):

    # Create and initialize BITree[] as 0
    BITTree = [0]*(n+1)

    # Store the actual values in BITree[] using update()
    for i in range(n):
        updatebit(BITTree, n, i, arr[i])

    # Uncomment below lines to see contents of BITree[]
    #for i in range(1,n+1):
    #	 print BITTree[i],
    return BITTree


# Driver code to test above methods
freq = [2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9]
BITTree = construct(freq,len(freq))
print("Sum of elements in arr[0..5] is " + str(getsum(BITTree,5)))
freq[3] += 6
updatebit(BITTree, len(freq), 3, 6)
print("Sum of elements in arr[0..5]"+
					" after update is " + str(getsum(BITTree,5)))
print(getInvCount([8, 4, 2, 1], len([8, 4, 2, 1])))