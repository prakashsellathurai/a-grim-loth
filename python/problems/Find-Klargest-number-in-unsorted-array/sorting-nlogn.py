import doctest
from typing import List


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        """
        >>> Solution().findKthLargest([3,2,1,5,6,4],2)
        5
        >>> Solution().findKthLargest([3,2,3,1,2,4,5,5,6],4)
        4
        """
        nums.sort()
        nums = nums[::-1]
        return nums[k - 1]


doctest.testmod(verbose=2)
