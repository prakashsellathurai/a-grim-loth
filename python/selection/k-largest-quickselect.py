
def partition(arr, lo, hi):
    pivot = arr[(lo+hi)//2]
    arr[hi],arr[pivot]=arr[pivot],arr[hi]
    i = lo
    for j in range(lo,hi):
        if arr[i] < pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i+=1
    arr[i+1],arr[hi]=arr[hi],arr[i+1]
    return i+1
    
def quickselect(arr, lo, hi, k):
    while lo <= hi:
        p = partition(arr, lo, hi)
        if k == p:
            return arr[p]

        if  k > p:
            lo = p+1
        else:
            hi = p - 1
    return -1

def klargest(arr, k):
    n = len(arr) - 1
    k = n-k
    return quickselect(arr,0,n,k)

import unittest
import random 
class TestClass(unittest.TestCase):

    def test_basic_select(self):
        maxlen = 10*3
        arr = [random.randrange(maxlen)]*maxlen
        k = random.randrange(maxlen)
        actual = klargest(arr, k)
        expected = sorted(arr)[-k]
        self.assertEqual(actual, expected)



if __name__ == '__main__':
    unittest.main()
