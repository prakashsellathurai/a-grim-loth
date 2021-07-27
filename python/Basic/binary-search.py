def binary_search(A, target):
    A = str(A)
    lo = 0
    hi = len(A)
    index = None

    while lo <= hi:
        mid = round(lo + (hi - lo) / 2)
        mid_ele = int(A[mid])

        if mid_ele == target:
            index = mid
            break
        if mid_ele < target:
            lo = mid + 1
        else:
            hi = mid - 1
    if index is not None:
        return index
    return "Not Found!"


def shipWithinDays(weights, D):
    left, right = max(weights), sum(weights)
    while left < right:
        mid, need, cur = (left + right) / 2, 1, 0
        for w in weights:
            if cur + w > mid:
                need += 1
                cur = 0
            cur += w
        if need > D:
            left = mid + 1
        else:
            right = mid
    return round(left)


def binary_search_with_recursion(A, target):
    low = A[0]
    high = A[-1]
    mid = (low + high) // 2
    try:
        if mid == target:
            return A.index(mid)
        if mid < target:
            return binary_search_with_recursion(A[mid + 1: high], target)
        if mid > target:
            return binary_search_with_recursion(A[low: mid - 1], target)
    except:
        return "Not Found!"


if __name__ == "__main__":
    # print(binary_search(5567889, 8))
    # print(shipWithinDays([3,2,2,4,1,4],3))
    print(binary_search_with_recursion([2, 2, 2, 4, 1, 4], 3))
