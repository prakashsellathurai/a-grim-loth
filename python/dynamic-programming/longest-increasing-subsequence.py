# Dynamic programming Python implementation
# of LIS problem

# lis returns length of the longest
# increasing subsequence in arr of size n
def lis_n_squared(arr):
    n = len(arr)

    # Declare the list (array) for LIS and
    # initialize LIS values for all indexes
    lis = [1] * n

    # Compute optimized LIS values in bottom up manner
    for i in range(1, n):
        for j in range(0, i):
            if arr[i] > arr[j] and lis[i] < lis[j] + 1:
                lis[i] = lis[j] + 1

    # Initialize maximum to 0 to get
    # the maximum of all LIS
    maximum = 0

    # Pick maximum of all LIS values
    for i in range(n):
        maximum = max(maximum, lis[i])

    return maximum


# end of lis function

# Driver program to test above function
arr = [10, 22, 9, 33, 21, 50, 41, 60]
print("Length of lis is", lis_n_squared(arr))


# Python program to find
# length of longest
# increasing subsequence
# in O(n Log n) time

# Binary search (note
# boundaries in the caller)
# A[] is ceilIndex
# in the caller
def CeilIndex(A, l, r, key):

    while r - l > 1:

        m = l + (r - l) // 2
        if A[m] >= key:
            r = m
        else:
            l = m
    return r


def LongestIncreasingSubsequenceLength(A, size):

    # Add boundary case,
    # when array size is one

    tailTable = [0 for i in range(size + 1)]
    len = 0  # always points empty slot

    tailTable[0] = A[0]
    len = 1
    for i in range(1, size):

        if A[i] < tailTable[0]:

            # new smallest value
            tailTable[0] = A[i]

        elif A[i] > tailTable[len - 1]:

            # A[i] wants to extend
            # largest subsequence
            tailTable[len] = A[i]
            len += 1

        else:
            # A[i] wants to be current
            # end candidate of an existing
            # subsequence. It will replace
            # ceil value in tailTable
            tailTable[CeilIndex(tailTable, -1, len - 1, A[i])] = A[i]

    return len, pop_zeros(tailTable)


def pop_zeros(items):
    while items[-1] == 0:
        items.pop()
    return items


# Driver program to
# test above function

A = [2, 5, 3, 7, 11, 8, 10, 13, 6]
n = len(A)

print(
    "Length of Longest Increasing Subsequence is ",
    LongestIncreasingSubsequenceLength(A, n),
)

# This code is contributed
# by Anant Agarwal.
