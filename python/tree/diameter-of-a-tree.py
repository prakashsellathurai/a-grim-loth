class Node:
    def __init__(self, value, children):
        self.value = value
        self.children = children

    @classmethod
    def preorder(cls, lists):
        return cls(lists[0], [cls.preorder(l) for l in lists[1:]])


def dd(root):
    """
    returns depth, diameter for tree with given root node

    >>> dd(Node.preorder([0, [1], [2]]))
    (1, 2)
    >>> dd(Node.preorder([1, [2, [3]], [4, [5]]]))
    (2, 4)
    >>> dd(Node.preorder([1, [2, [3, [4]], [5, [6, [7], [8]]]], [9]]))
    (4, 5)
    """
    d1 = d2 = -1
    md = 0
    for child in root.children:
        depth, diameter = dd(child)
        if diameter > md:
            md = diameter
        if depth >= d1:
            d2 = d1
            d1 = depth
        elif depth > d2:
            d2 = depth
    return d1 + 1, max(md, d1 + d2 + 2)


if __name__ == "__main__":
    import doctest

    doctest.testmod()
