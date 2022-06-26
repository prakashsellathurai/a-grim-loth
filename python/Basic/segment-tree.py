
class SegmentTree:
    def __init__(self, arr):
        self.n = len(arr)
        self.tree = [0]*(4*self.n)
        self.build(arr,1,0,self.n-1)

    def build(self, arr, vertex, ltree, rtree):
        if ltree == rtree:
            self.tree[vertex] = arr[ltree]
        else:
            mtree = (ltree+rtree) >> 1
            self.build(arr, vertex*2, ltree, mtree)
            self.build(arr, vertex*2+1, mtree+1, rtree)
            self.tree[vertex] = self.tree[vertex*2] + self.tree[vertex*2+1] 

    def sum(self,v, tl, tr, l, r):
        if l > r:
            return 0
        if l == tl and r == tr:
            return self.tree[v]
        tm = (tl+tr) >> 1
        return self.sum(v*2, tl, tm, l, min(r,tm))+self.sum(v*2 + 1, tm+1,tr,max(l,tm+1),r)
    
    def update(self, v, tl,tr, pos, new_val):
        if tl == tr:
            self.tree[v] = new_val
        else:
            tm = (tl+tr) >> 1
            if pos <= tm:
                self.update(v*2,  tl, tm, pos, new_val)
            else:
                self.update(v*2+1 ,tm+1,tr, pos, new_val)
            self.tree[v] = self.tree[v*2]+self.tree[v*2+1]
    
    def print(self):
        print(self.tree)


        
class maxSegmentTree(SegmentTree):
    def __init__(self,*args,**kwargs):
        super().__init__(*args,**kwargs)

    def build(self, arr, v, lt, rt):
        if lt == rt:
            self.tree[v] = arr[lt]
        else:
            mt = (lt + rt) >> 1
            self.build(arr, 2*v, lt, mt)
            self.build(arr, 2*v+1, mt+1, rt)
            self.tree[v] = max(self.tree[2*v] , self.tree[2*v+1])
    
    def update(self, v, lt, rt, pos, new_val):
        
        if lt == rt:
            self.tree[v] = new_val
        else:
            mt = (lt + rt) >> 1

            if pos <= mt:
                self.update(2*v, lt, mt, pos, new_val)
            else:
                self.update(2*v+1, 1+mt, rt, pos, new_val)
            self.tree[v] = max(self.tree[2*v],self.tree[2*v+1])

    def max(self, l ,r):
        return self.findmax(1, 0, self.n-1, l, r)

    def findmax(self, v, lt, rt, l, r):
        if l > r:
            return 0

        if lt == l and rt == r:
            return self.tree[v]
        
        tm = (lt + rt) >> 1

        return max(self.findmax(2*v, lt , tm, l, min(tm, r)),self.findmax(2*v + 1, tm+1, rt, max(l,tm+1), r))

class MinSegmentTree(SegmentTree):
    def __init__(self, *args,**kwargs):
        super().__init__(*args,**kwargs)
    
    def build(self, arr, v, lt, rt):
        if lt == rt:
            self.tree[v] = arr[lt]
        else:
            mt = (lt + rt) >> 1
            self.build(arr, 2*v, lt, mt)
            self.build(arr, 2*v+1, mt+1 ,rt)
            self.tree[v] = min(self.tree[2*v],self.tree[2*v+1])
    
    def update(self, v, lt, rt, pos, new_val):
        if lt == rt:
            self.tree[v] = new_val
        else:
            mt = (lt + rt) >> 1
            if pos <= mt:
                self.update(2*v , lt, mt, pos, new_val)
            else:
                self.update(2*v+1 , mt+1, rt, pos, new_val)
            self.tree[v] = min(self.tree[2*v],self.tree[2*v+1])

    def min(self, l, r):
        return self.min_utils(1, 0, self.n-1, l, r)

    def min_utils(self, v, lt, rt, l, r):
        if l > r :
            return float('inf')
        if l == lt and rt == r:
            return self.tree[v]
        mt = (lt+rt) >> 1
        return min(self.min_utils(2*v, lt, mt, l, min(r, mt)), self.min_utils(2*v+1, mt+1, rt, max(l,mt+1), r))

class MaxAndOccurenceSegmentTree:
    def __init__(self, arr):
        self.n = len(arr)
        self.tree = [(0,0)]*(4*self.n)
        self.build(arr, 1, 0, len(arr)-1)
    
    def build(self, arr, v, lt, rt):
        if lt == rt:
            self.tree[v] = (arr[lt], 1)
        else:
            mt = (lt + rt) >> 1
            self.build(arr, 2*v, lt, mt)
            self.build(arr, 2*v+1, mt+1, rt)
            self.tree[v] = self.combine(self.tree[2*v], self.tree[2*v+1])

    def combine(self, a, b):
        if a[0] > b[0]:
            return a
        if b[0] > a[0]:
            return b
        return (a[0], a[1]+b[1])

    def max(self, l=None, r=None):
        if l is None and r is None:
            l = 0
            r = self.n-1
        return self.findmax( 1, 0, self.n-1, l, r)

    def findmax(self, v, lt, rt, l, r):
        if l > r:
            return (float('-inf'), 0)

        if l < 0 or r > self.n:
            raise ValueError(f"The values of `l` and `r` must be between [0,{self.n-1}]")
    
        if lt == l and rt == r:
            return self.tree[v]
        
        tm = (lt + rt) >> 1

        return self.combine(
                    self.findmax(2*v, lt, tm, l, min(tm, r)),
                    self.findmax(2*v + 1, tm+1, rt, max(l,tm+1), r)
                )
    
    def print(self):
        print(self.tree)

import unittest

class TestsegmentTrees(unittest.TestCase):
    def setUp(self):
        self.arr = [1,2,3,4,5,6,7]
        self.n = len(self.arr)

    def test_segmenttree(self):
        st = SegmentTree(self.arr)
        assert st.sum(1,0,self.n-1,0,self.n-1)==(self.n*(self.n+1)//2)
        assert st.sum(1,0,self.n-1,2,5) ==  18
        st.update(1, 0, st.n, 6, 0)
        assert st.sum(1,0,self.n-1,0,self.n-1)== 21 

    def test_maxsegmenttree(self):
        maxst = maxSegmentTree(self.arr)
        assert maxst.max(2,5) == 6
        assert maxst.max(0,0) == 1
        assert maxst.max(0,-1) == 0

        maxst.update(1, 0, maxst.n, 6, 0)
        assert maxst.max(0, 6)== 6 

    def test_minsegmenttree(self):
        maxst = MinSegmentTree(self.arr)
        assert maxst.min(0,2) == 1
        assert maxst.min(2,4) == 3 
    
    def test_MaxAndOccurenceSegmentTree(self):
        arr = [1,1,2,2]
        t = MaxAndOccurenceSegmentTree(arr)
        assert t.max(0,1) == (1,2)
        with self.assertRaisesRegex(ValueError,"The values of `l` and `r`"):
            t.max(0,10)

        
if __name__ == "__main__":
    unittest.main()

