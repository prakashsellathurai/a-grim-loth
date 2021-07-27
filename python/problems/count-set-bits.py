# Python3 program to Count set
# bits in an integer

# Function to get no of set bits in binary
# representation of positive integer n */
def countSetBits(n):

    count = 0
    while n:
        n &= n - 1
        count += 1

    return count


# Program to test function countSetBits */
i = 10000
print(countSetBits(i))
