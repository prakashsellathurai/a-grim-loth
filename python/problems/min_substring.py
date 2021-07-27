# Python3 program for the above approach

# Function to count minimum removals
# required to make a given string
# concatenation of substring of 0s
# followed by substring of 1s
def minimumDeletions(s):

    # Stores the length of the string
    n = len(s)

    # Precompute the count of 0s
    zeroCount = [0 for i in range(n)]

    # Check for the last character
    zeroCount[n - 1] = 1 if s[n - 1] == "0" else 0

    # Traverse and update zeroCount array
    for i in range(n - 2, -1, -1):

        # If current character is 0,
        zeroCount[i] = zeroCount[i + 1] + \
            1 if (s[i] == "0") else zeroCount[i + 1]

    # Keeps track of deleted 1s
    oneCount = 0

    # Stores the count of removals
    ans = 10 ** 9

    # Traverse the array
    for i in range(n):

        # If current character is 1
        if s[i] == "1":

            # Update ans
            ans = min(ans, oneCount + zeroCount[i])
            oneCount += 1

    # If all 1s are deleted
    ans = min(ans, oneCount)

    # Return the minimum
    # number of deletions
    return zeroCount


# Driver Code
if __name__ == "__main__":
    str = "00101101"
    print(minimumDeletions(str))

    # This code is contributed by mohit kumar 29
