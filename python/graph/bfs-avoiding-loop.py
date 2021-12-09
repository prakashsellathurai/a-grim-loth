# Time Complexity: O(n)
# Space Complexity: O(n)
from collections import deque
from typing import List

def canReach( arr: List[int], start: int) -> bool:
    n = len(arr)
    
    q = deque()
    q.append(start)
    visited = {}
    
    while len(q) > 0:
        index = q.popleft()
        
        if arr[index] == 0:
            return True
        
        for candidate in [index-arr[index],index+arr[index]]:
            if 0<= candidate <= n-1 and candidate not in visited:
                q.append(candidate)
        visited[index] = True
    
    
    return False


import unittest

class basetest(unittest.TestCase):
  def testcases1(self):
    self.assertTrue(canReach([4,2,3,0,3,1,2],5))
  def testcases2(self):
    self.assertTrue(canReach([4,2,3,0,3,1,2],0))
  def testcases3(self):
    self.assertFalse(canReach([3,0,2,1,2],2))

if __name__ == "__main__":
  unittest.main()