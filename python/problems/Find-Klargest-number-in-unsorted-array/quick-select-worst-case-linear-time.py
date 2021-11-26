import doctest
from typing import List

# Time Complexity: O(n)


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        """
        >>> Solution().findKthLargest([3,2,1,5,6,4],2)
        5
        >>> Solution().findKthLargest([3,2,3,1,2,4,5,5,6],4)
        4
        """

        def swap(nums, i, j):
            nums[i], nums[j] = nums[j], nums[i]

        def median(nums, i, l):
            tmp = nums[i: i + l]
            return sorted(tmp)[len(tmp) // 2]

        def pivot(nums, i, j, e):
            # print "pivot for nums",nums,"i",i,"j",j,"e",e
            idx = -1
            for idx in range(i, j + 1):
                if nums[idx] == e:
                    break
            swap(nums, idx, j)
            # print "nums after pivot at last",nums
            for l in range(i, j):
                if nums[l] <= nums[j]:
                    swap(nums, i, l)
                    i += 1
            swap(nums, i, j)
            # print "final pivoted nums",nums
            return i

        def modifiedQuickSelect(nums, i, j, k):
            n = j - i + 1
            # print "n",n
            if k > 0 and k <= n:
                med = []
                l = 0
                while l < n // 5:
                    # print "med for",nums[i+l*5:i+l*5+5]
                    med.append(median(nums, i + l * 5, 5))
                    # print "is",med[-1]
                    l += 1
                if l * 5 < n:
                    # print "med for",nums[i+l*5:i+l*5+n%5]
                    med.append(median(nums, i + l * 5, n % 5))
                    # print "is",med[-1]
                    l += 1
                # print "final med",med
                medOfMed = None
                if l == 1:
                    medOfMed = med[-1]
                else:
                    medOfMed = modifiedQuickSelect(med, 0, l - 1, l // 2)
                # print "medOfMed",medOfMed
                pvt = pivot(nums, i, j, medOfMed)
                # print "pvt",pvt
                if pvt - i == k - 1:
                    return nums[pvt]
                elif pvt - i > k - 1:
                    return modifiedQuickSelect(nums, i, pvt - 1, k)
                return modifiedQuickSelect(nums, pvt + 1, j, k - pvt + i - 1)
            else:
                return sys.maxint

        return modifiedQuickSelect(nums, 0, len(nums) - 1, len(nums) - k + 1)


doctest.testmod(verbose=2)
