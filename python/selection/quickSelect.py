import random
import unittest
from typing import List


def partition(arr, low, high):
    i = low - 1  # index of smaller element
    pivot = arr[high]  # pivot

    for j in range(low, high):

        # If current element is smaller than or
        # equal to pivot
        if arr[j] <= pivot:

            # increment index of smaller element
            i = i + 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1


# The main function that implements QuickSort
# arr[] --> Array to be sorted,
# low --> Starting index,
# high --> Ending index

# Function to do Quick sort


def quickSort(arr, low, high):
    if len(arr) == 1:
        return arr
    if low < high:

        # pi is partitioning index, arr[p] is now
        # at right place
        pi = partition(arr, low, high)

        # Separately sort elements before
        # partition and after partition
        quickSort(arr, low, pi - 1)
        quickSort(arr, pi + 1, high)


def QuickSelect(arr: List[int], k: int) -> List[int]:
    quickSort(arr, 0, len(arr) - 1)
    return arr[:k]


class TestCases(unittest.TestCase):
    def testcase1(self):
        k = random.randint(3, 9)
        arr = [random.randrange(1, 50, 1) for i in range(9)]
        self.assertEqual(QuickSelect(arr, k), sorted(arr)[:k])

    def testcase2(self):
        max_num = 100
        k = random.randint(0, max_num)
        arr = [random.randrange(1, max_num, 1) for i in range(max_num)]
        self.assertEqual(QuickSelect(arr, k), sorted(arr)[:k])

    def testcase3(self):
        max_num = 10 ** 5
        k = random.randint(0, max_num)
        arr = [random.randrange(1, max_num, 1) for i in range(max_num)]
        self.assertEqual(QuickSelect(arr, k), sorted(arr)[:k])


if __name__ == "__main__":
    unittest.main(verbosity=2)
