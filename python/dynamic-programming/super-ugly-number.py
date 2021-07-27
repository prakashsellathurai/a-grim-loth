# Python3 program for super ugly number

# function will return the nth super ugly number
def ugly(a, size, n):

    # n cannot be negative hence return -1 if n is 0 or -ve
    if n <= 0:
        return -1
    if n == 1:
        return 1

    # Declare a min heap priority queue
    pq = []

    # Push all the array elements to priority queue
    for i in range(size):
        pq.append(a[i])

    # once count = n we return no
    count = 1
    no = 0
    pq = sorted(pq)

    while count < n:
        # sorted(pq)
        # Get the minimum value from priority_queue
        no = pq[0]
        del pq[0]

        # If top of pq is no then don't increment count.
        # This to avoid duplicate counting of same no.
        if no != pq[0]:
            count += 1

            # Push all the multiples of no. to priority_queue
            for i in range(size):
                pq.append(no * a[i])
            # cnt+=1
        pq = sorted(pq)
    # Return nth super ugly number
    return no


# /* Driver program to test above functions */
if __name__ == "__main__":
    a = [2, 3, 5]
    size = len(a)
    print(ugly(a, size, 1000))
