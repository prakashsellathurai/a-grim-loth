import queue
from collections import defaultdict, Counter


def findLongestConseqSubseq(nums, n):

    q = queue.Queue()
    q.put(nums[0])
    for i in range(1, n):
        if nums[i - 1] != nums[i]:
            q.put(nums[i])

    return q.qsize()


def findLongestConseqSubseqs(nums, n):

    q = []
    q.append(nums[0])
    for i in range(1, n):
        if nums[i - 1] != nums[i]:
            q.append(nums[i])

    return q.__len__()


N = int(5)
arr = list(map(int, "2 2 1 3 1".split()))
print(findLongestConseqSubseq(arr, N))
print(findLongestConseqSubseqs(arr, N))
