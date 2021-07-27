import math
from collections import deque


def computehash(s):
    hash_value = 0
    p = 51
    m = math.e ** 9 + 9
    p_pow = 1

    for c in s:
        hash_value = (hash_value + ((ord(c) - ord("a") + 1) * p_pow)) % m
        p_pow = (p_pow * p) % m
    return int(hash_value)


def merge(arr, start, mid, end, key="hash"):
    start2 = mid + 1
    # If the direct merge is already sorted
    if arr[mid][key] <= arr[start2][key]:
        return

    while start <= mid and start2 <= end:
        # If element 1 is in right place
        if arr[start][key] <= arr[start2][key]:
            start += 1
        else:
            value = arr[start2][key]
            index = start2

            # Shift all the elements between element 1
            # element 2, right by 1.
            while index != start:
                arr[index] = arr[index - 1]
                index -= 1

            arr[start][key] = value

            # Update all the pointers
            start += 1
            mid += 1
            start2 += 1


def mergeSort(arr, l, r, key="hash"):
    if l < r:
        m = l + (r - l) // 2
        mergeSort(arr, l, m)
        mergeSort(arr, m + 1, r)
        merge(arr, l, m, r, key=key)


def groupidenticalStrings(s):
    n = len(s)
    hashes = [{}] * n
    for i in range(n):
        hashes[i] = {"hash": computehash(s[i]), "index": i}
    mergeSort(hashes, 0, n - 1, key="hash")

    groups = []
    count = -1
    for i in range(n):
        if i == 0 or hashes[i]["hash"] != hashes[i - 1]["hash"]:
            count += 1
            groups.append([])

        try:
            groups[count].append(hashes[i]["index"])
        except:
            groups.append([hashes[i]["index"]])

    return groups


def main():
    list_of_strings = ["hello"] * 2 + ["hi"] * 2 + ["fizz"] * 5 + ["hello"] * 2
    print(groupidenticalStrings(list_of_strings))


if __name__ == "__main__":
    main()
else:
    print("None")
