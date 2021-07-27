def twoSum(nums, target):

    h = {}
    for i, num in enumerate(nums):
        n = target - num
        if n not in h:
            h[num] = i
        else:
            return [h[n], i]


print(twoSum([3, 2, 4], 6))
