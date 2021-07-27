class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key


# A function to do inorder tree traversal
def printInorder(root):
    """
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)

    print("\nInorder traversal of binary tree is")
    printInorder(root)
    print( "Preorder traversal of binary tree is")
    printPreorder(root)
    print("\nPostorder traversal of binary tree is")
    printPostorder(root)

    >>> root = Node(1)
    >>> root.left = Node(2)
    >>> root.right = Node(3)
    >>> root.left.left = Node(4)
    >>> root.left.right = Node(5)
    >>> printInorder(root)
    4 2 5 1 3
    """
    if root:

        # First recur on left child
        printInorder(root.left)

        # then print the data of node
        print(root.val, end=" "),

        # now recur on right child
        printInorder(root.right)


# A function to do preorder tree traversal
def printPreorder(root):
    """
    >>> root = Node(1)
    >>> root.left = Node(2)
    >>> root.right = Node(3)
    >>> root.left.left = Node(4)
    >>> root.left.right = Node(5)
    >>> printPreorder(root)
    1 2 4 5 3

    """
    if root:

        # First print the data of node
        print(root.val, end=" "),

        # Then recur on left child
        printPreorder(root.left)

        # Finally recur on right child
        printPreorder(root.right)


# A function to do postorder tree traversal
def printPostorder(root):
    """
    >>> root = Node(1)
    >>> root.left = Node(2)
    >>> root.right = Node(3)
    >>> root.left.left = Node(4)
    >>> root.left.right = Node(5)
    >>> printPostorder(root)
    4 5 2 3 1

    """
    if root:

        # First recur on left child
        printPostorder(root.left)

        # the recur on right child
        printPostorder(root.right)

        # now print the data of node
        print(root.val, end=" "),


if __name__ == "__main__":

    import doctest

    doctest.testmod()
