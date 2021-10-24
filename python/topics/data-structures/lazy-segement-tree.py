class LPSTree:
    """
    LPSTree(n[, value=None[, reducef=None[, modulo=None]]]) -> new LPSTree
    Build a new LPSTree with n elements.
    If value is provided, all elements are set to value, otherwise 0.
    Default reduce function is sum. Can alse be set to max or min.
    If modulo is provide, modulo operation will be donw automatically.
    """

    def __init__(self, n, value=None, reducef=None, modulo=None):
        if n <= 0:
            raise ValueError("n most be greater than 0")
        self.n = n
        size = 1
        while size < n:
            size *= 2
        size *= 2
        self.size = size
        self.tree = [None] * size
        self.boolset = [False] * size
        self.booladd = [False] * size
        self.lazyset = [None] * size
        self.lazyadd = [None] * size
        self.modulo = modulo
        if not reducef:
            reducef = sum
        if reducef == sum:
            self.nodef = lambda val, n: val * n
        elif reducef in (max, min):
            self.nodef = lambda val, n: val
        else:
            raise ValueError("reducef can only be sum, max or min")
        if self.modulo:
            self.reducef = lambda x: reducef(x) % self.modulo
        else:
            self.reducef = reducef

        if value is not None:
            array = [value] * n
        else:
            array = [0] * n

        def construct(tree, array, sleft, sright, v):
            if sleft + 1 == sright:
                tree[v] = array[sleft]
                return tree[v]
            smid = (sleft + sright) // 2
            tree[v] = self.reducef(
                (
                    construct(tree, array, sleft, smid, 2 * v + 1),
                    construct(tree, array, smid, sright, 2 * v + 2),
                )
            )
            # if self.modulo:
            # 	tree[v] %= self.modulo
            # print tree
            return tree[v]

        construct(self.tree, array, 0, n, 0)

    def __len__(self):
        return self.n

    def _lazypropagate(self, v, vleft, vright):
        tree = self.tree
        boolset = self.boolset
        booladd = self.booladd
        lazyset = self.lazyset
        lazyadd = self.lazyadd
        vmid = (vleft + vright) // 2
        # print tree, v, tree[2*v+1], boolset[v], booladd[v]
        if boolset[v]:
            tree[2 * v + 1] = self.nodef(lazyset[v], vmid - vleft)
            tree[2 * v + 2] = self.nodef(lazyset[v], vright - vmid)
            if self.modulo:
                tree[2 * v + 1] %= self.modulo
                tree[2 * v + 2] %= self.modulo
            boolset[2 * v + 1] = boolset[2 * v + 2] = True
            booladd[2 * v + 1] = booladd[2 * v + 2] = False
            lazyset[2 * v + 1] = lazyset[2 * v + 2] = lazyset[v]
            boolset[v] = False
        if booladd[v]:
            tree[2 * v + 1] += self.nodef(lazyadd[v], vmid - vleft)
            tree[2 * v + 2] += self.nodef(lazyadd[v], vright - vmid)
            if self.modulo:
                tree[2 * v + 1] %= self.modulo
                tree[2 * v + 2] %= self.modulo
            if booladd[2 * v + 1]:
                lazyadd[2 * v + 1] += lazyadd[v]
            else:
                booladd[2 * v + 1] = True
                lazyadd[2 * v + 1] = lazyadd[v]
            if booladd[2 * v + 2]:
                lazyadd[2 * v + 2] += lazyadd[v]
            else:
                booladd[2 * v + 2] = True
                lazyadd[2 * v + 2] = lazyadd[v]
            booladd[v] = False
        # print tree, v, tree[2*v+1]

    def get(self, start, stop):
        """
        LPSTree.get(start, stop) -> value
        You can assume it same as reduce(reducef, tree[start:stop]).
        """
        n = self.n
        if not (start < stop and start >= 0 and stop <= n):
            raise IndexError(start, stop)
        tree = self.tree
        boolset = self.boolset
        booladd = self.booladd
        lazyset = self.lazyset
        lazyadd = self.lazyadd

        def _get(sleft, sright, v, vleft, vright):
            # print v, start, stop, vleft, vright, tree
            if sleft >= vright or sright <= vleft:
                return
            if sleft <= vleft and sright >= vright:
                # if self.modulo:
                # 	tree[v] %= self.modulo
                return tree[v]
            vmid = (vleft + vright) // 2
            self._lazypropagate(v, vleft, vright)
            # print v, start, stop, vleft, vright, tree
            return self.reducef(
                [
                    x
                    for x in (
                        _get(sleft, sright, 2 * v + 1, vleft, vmid),
                        _get(sleft, sright, 2 * v + 2, vmid, vright),
                    )
                    if x is not None
                ]
            )

        return _get(start, stop, 0, 0, n)

    def set(self, start, stop, value):
        """
        LPSTRee.set(start, stop, value)
        Set all elements in [start, stop) to value.
        """
        n = self.n
        if not (start < stop and start >= 0 and stop <= n):
            raise IndexError(start, stop)
        tree = self.tree
        boolset = self.boolset
        booladd = self.booladd
        lazyset = self.lazyset
        lazyadd = self.lazyadd

        def _set(sleft, sright, v, vleft, vright, value):
            # print v, start, stop, vleft, vright, value, tree
            if sleft >= vright or sright <= vleft:
                return
            if sleft <= vleft and sright >= vright:
                tree[v] = self.nodef(value, vright - vleft)
                if self.modulo:
                    tree[v] %= self.modulo
                boolset[v] = True
                booladd[v] = False
                lazyset[v] = value
                # print v, tree, tree[v], tree[v] % self.modulo
                return
            vmid = (vleft + vright) // 2
            self._lazypropagate(v, vleft, vright)
            _set(sleft, sright, 2 * v + 1, vleft, vmid, value)
            _set(sleft, sright, 2 * v + 2, vmid, vright, value)
            tree[v] = self.reducef((tree[2 * v + 1], tree[2 * v + 2]))
            # if self.modulo:
            # 	tree[v] %= self.modulo
            # print v, start, stop, vleft, vright, value, tree

        _set(start, stop, 0, 0, n, value)

    def add(self, start, stop, diff):
        """
        LPSTRee.add(start, stop, diff)
        Add diff to all elements in [start, stop).
        """
        n = self.n
        if not (start < stop and start >= 0 and stop <= n):
            raise IndexError(start, stop)
        tree = self.tree
        boolset = self.boolset
        booladd = self.booladd
        lazyset = self.lazyset
        lazyadd = self.lazyadd

        def _add(sleft, sright, v, vleft, vright, diff):
            if sleft >= vright or sright <= vleft:
                return
            if sleft <= vleft and sright >= vright:
                tree[v] += self.nodef(diff, vright - vleft)
                if self.modulo:
                    tree[v] %= self.modulo
                if booladd[v]:
                    lazyadd[v] += diff
                else:
                    booladd[v] = True
                    lazyadd[v] = diff
                return
            vmid = (vleft + vright) // 2
            self._lazypropagate(v, vleft, vright)
            _add(sleft, sright, 2 * v + 1, vleft, vmid, diff)
            _add(sleft, sright, 2 * v + 2, vmid, vright, diff)
            tree[v] = self.reducef((tree[2 * v + 1], tree[2 * v + 2]))
            # if self.modulo:
            # 	tree[v] %= self.modulo

        _add(start, stop, 0, 0, n, diff)

    def __getitem__(self, index):
        return self.get(index, index + 1)

    def __setitem__(self, index, value):
        self.set(index, index + 1, value)

    def __repr__(self):
        return repr([self[x] for x in range(self.n)])

    def tolist(self):
        """
        LPSTree.tolist() -> a list object
        Return a list containing all the elements in LPSTree.
        """
        return [self[x] for x in range(self.n)]


if __name__ == "__main__":
    tree = LPSTree(10, reducef=max)
    # tree = LPSTree(10, modulo=2)
    # tree = LPSTree(10)
    print(tree.n, tree.size)
    print(tree.get(0, 10))
    print(tree[0], tree[1])
    tree[9] = 20
    print(tree)
    print(tree.get(0, 10))
    tree.set(1, 5, 5)
    print(tree)
    tree.add(1, 10, 12)
    print(tree)
    tree.set(0, 3, 5)
    tree.add(0, 4, 2)
    print(tree)
    tree.set(0, 10, 0)
    print(tree)
    tree.add(1, 9, -10)
    print(tree)
    print(tree.get(8, 9))
    tree.set(0, 3, 9)
    print(tree)

    tree = LPSTree(10, reducef=max)
    print(tree)
    # tree.set(0, 10, 0)
    # help(tree.set)
    tree.set(1, 9, -10)
    print(tree)
