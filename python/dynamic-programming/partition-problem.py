# Python3 program to print equal sum
# sets of array.
import numpy as np

# Function to print equal sum
# sets of array.


def printEqualSumSets(arr, n):

    # Finding sum of array elements
    sum_array = sum(arr)

    # Check sum is even or odd. If odd
    # then array cannot be partitioned.
    # Print -1 and return.
    if sum_array & 1:
        print("-1")
        return

    # Divide sum by 2 to find
    # sum of two possible subsets.
    k = sum_array >> 1

    # Boolean DP table to store result
    # of states.
    # dp[i][j] = true if there is a
    # subset of elements in first i elements
    # of array that has sum equal to j.
    dp = np.zeros((n + 1, k + 1))

    # If number of elements are zero, then
    # no sum can be obtained.
    for i in range(1, k + 1):
        dp[0][i] = False

    # Sum 0 can be obtained by not
    # selecting any element.
    for i in range(n + 1):
        dp[i][0] = True

    # Fill the DP table in bottom up manner.
    for i in range(1, n + 1):
        for currSum in range(1, k + 1):

            # Excluding current element.
            dp[i][currSum] = dp[i - 1][currSum]

            # Including current element
            if arr[i - 1] <= currSum:
                dp[i][currSum] = dp[i][currSum] or dp[i - 1][currSum - arr[i - 1]]

    # Required sets set1 and set2.
    set1, set2 = [], []

    # If partition is not possible print
    # -1 and return.
    if not dp[n][k]:
        print("-1")
        return

    # Start from last element in dp table.
    i = n
    currSum = k

    while i > 0 and currSum >= 0:

        # If current element does not
        # contribute to k, then it belongs
        # to set 2.
        if dp[i - 1][currSum]:
            i -= 1
            set2.append(arr[i])

        # If current element contribute
        # to k then it belongs to set 1.
        elif dp[i - 1][currSum - arr[i - 1]]:
            i -= 1
            currSum -= arr[i]
            set1.append(arr[i])

    # Print elements of both the sets.
    print("Set 1 elements:", end=" ")
    for i in range(len(set1)):
        print(set1[i], end=" ")

    print("\nSet 2 elements:", end=" ")
    for i in range(len(set2)):
        print(set2[i], end=" ")


# Driver Code
if __name__ == "__main__":

    arr = [5, 5, 1, 11]
    n = len(arr)
    printEqualSumSets(arr, n)
