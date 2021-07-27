# A node structure
class Node:

    # A utility function to create a new node
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None


# height of a binary tree
def printLevelOrder(root):
    """
    prints the level order traversal of a tree

    >>> root = Node(1)
    >>> root.left = Node(2)
    >>> root.right = Node(3)
    >>> root.left.left = Node(4)
    >>> root.left.right = Node(5)
    >>> root.right.left = Node(6)
    >>> root.right.right = Node(7)
    >>> printLevelOrder(root)
    [1, 2, 3, 4, 5, 6, 7]
    """

    # Base Case
    if root is None:
        return

    # Create an empty queue
    # for level order traversal
    queue = []

    # Enqueue Root and initialize height
    queue.append(root)
    res = []
    while len(queue) > 0:

        # Print front of queue and
        # remove it from queue
        res.append(queue[0].data)
        node = queue.pop(0)

        # Enqueue left child
        if node.left is not None:
            queue.append(node.left)

        # Enqueue right child
        if node.right is not None:
            queue.append(node.right)
    print(res)


if __name__ == "__main__":
    import doctest

    doctest.testmod()
