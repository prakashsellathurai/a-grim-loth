# Python3 Code Addition

# limit for array size
class segment_tree:
    def __init__(self, arr):
        super().__init__()
        self.N = len(arr)

        # Max size of tree
        self.tree = [0] * (2 * self.N)
        self.build(arr)

    # function to build the tree
    def build(self, arr):

        # insert leaf nodes in tree
        for i in range(self.N):
            self.tree[self.N + i] = arr[i]

        # build the tree by calculating parents
        for i in range(self.N - 1, 0, -1):

            self.tree[i] = self.tree[i << 1] + self.tree[i << 1 | 1]

    # function to update a tree node
    def updateTreeNode(self, p, value):

        # set value at position p
        self.tree[p + self.N] = value
        p = p + self.N

        # move upward and update parents
        i = p

        while i > 1:
            self.tree[i >> 1] = self.tree[i] + self.tree[i ^ 1]
            i >>= 1

    # function to get sum on interval [l, r)
    def query(self, l, r):

        res = 0

        # loop to find the sum in the range
        l += self.N
        r += self.N

        while l < r:

            if l & 1:
                res += self.tree[l]
                l += 1

            if r & 1:
                r -= 1
                res += self.tree[r]

            l >>= 1
            r >>= 1

        return res

    def display(self):
        print(self.tree)


# Driver Code
if __name__ == "__main__":

    a = [1, 2, 3, 4, 5]

    ST = segment_tree(a)

    # print the sum in range(1,2) index-based
    print(ST.query(1, 3))
    ST.display()
    # modify element at 2nd index
    ST.updateTreeNode(2, 1)

    # print the sum in range(1,2) index-based
    print(ST.query(1, 3))

    ST.display()
