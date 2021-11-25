import doctest
from typing import List
import heapq

# Time Complexity: O(n+klogn)


class Maxheap:
    def __init__(self, data=None):
        if data is None:
            self.data = None
        else:
            self.data = [-i for i in data]
            heapq.heapify(self.data)

    def top(self):
        return -self.data[0]

    def push(self, item):
        heapq.heappush(self.data, item)

    def pop(self):
        return -heapq.heappop(self.data)

    def replace(self, item):
        return heapq.heapreplace(self.data, -item)


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        """
        >>> Solution().findKthLargest([3,2,1,5,6,4],2)
        5
        >>> Solution().findKthLargest([3,2,3,1,2,4,5,5,6],4)
        4
        """
        if len(nums) < k:
            return -1

        maxheap = Maxheap(nums)

        while k > 1:
            maxheap.pop()
            k = k - 1
        return maxheap.pop()


doctest.testmod(verbose=2)
