import doctest
from typing import List
import heapq


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        """
        >>> Solution().findKthLargest([3,2,1,5,6,4],2)
        5
        >>> Solution().findKthLargest([3,2,3,1,2,4,5,5,6],4)
        4
        """
        minheap = nums[:k]
        heapq.heapify(minheap)
        for num in nums[k:]:
            if num > minheap[0]:
                heapq.heapreplace(minheap, num)
        return minheap[0]


doctest.testmod(verbose=2)
