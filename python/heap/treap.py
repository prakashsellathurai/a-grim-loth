import os
import sys
from random import Random


class _TreapNode:
    """Treap Node"""

    def __init__(self, key, value, heap_id, parent=None, left=None, right=None):
        self.key = key
        self.value = value
        self.heap_id = heap_id
        self.parent = parent
        self.left = left
        self.right = right

    def __repr__(self):
        return str((self.key, self.value, self.heap_id))


class Treap:
    """
    Treap

    Dictionary-like object with sorted keys.

    >>> treap = Treap()
    >>> treap['a'] = 1
    >>> treap['a']
    1
    >>> treap['b'] = 2
    >>> 'b' in treap
    True
    >>> del treap['b']
    >>> 'b' in treap
    False
    """

    def __init__(self, seed=0, max_heap_id=sys.maxsize):
        self.random = Random(seed)
        self.max_heap_id = max_heap_id
        self.root = None

    def __setitem__(self, key, value):
        """Set a key, value pair in the tree."""
        node, parent = self._find_node(key, self.root)
        if node is None:
            heap_id = self.random.randrange(self.max_heap_id)
            node = _TreapNode(key, value, heap_id)
            if parent is None:
                self.root = node
            elif node.key < parent.key:
                parent.left = node
            else:
                parent.right = node
            node.parent = parent
            self._prioritize(node)
        else:
            node.value = value

    @staticmethod
    def _find_node(key, node, parent=None):
        while True:
            if node is None or key == node.key:
                return node, parent
            if key < node.key:
                node, parent = node.left, node
            else:
                node, parent = node.right, node

    def _pivot_up(self, node):
        parent = node.parent
        if parent is None:
            return

        if parent.left == node:
            """
            Given the following binary search tree:
                   5
                  / \
                 3   C
                / \
               A   B
            Imagine we need to pivot 3 and 5 (to maintain the heap
            property). The resulting tree will look like:
                   3
                  / \
                 A   5
                    / \
                   B   C
            """
            node.right, parent.left = parent, node.right
            if parent.left:
                parent.left.parent = parent
        else:
            node.left, parent.right = parent, node.left
            if parent.right:
                parent.right.parent = parent

        grandparent = parent.parent
        node.parent, parent.parent = grandparent, node
        if grandparent:
            if grandparent.left == parent:
                grandparent.left = node
            else:
                grandparent.right = node
        else:
            self.root = node

    def _prioritize(self, node):
        while node.parent and node.parent.heap_id < node.heap_id:
            self._pivot_up(node)

    def __contains__(self, key):
        """Return True iff key is found in tree, else False."""
        node = self._find_node(key, self.root)[0]
        return node is not None

    def __getitem__(self, key):
        """Return the value corresponding to key in the tree."""
        node = self._find_node(key, self.root)[0]
        if node is None:
            raise KeyError(key)
        return node.value

    def __delitem__(self, key):
        """Delete a key, value pair identified by key from the tree."""
        node, parent = self._find_node(key, self.root)

        if node is None:
            raise KeyError(key)
        if parent is None and not (node.left and node.right):
            self.root = node.left or node.right
            if self.root:
                self.root.parent = None
        else:
            while node.left and node.right:
                # Pivot a child node up while the node to be deleted has
                # both left and right children.
                if node.left.heap_id > node.right.heap_id:
                    self._pivot_up(node.left)
                else:
                    self._pivot_up(node.right)

            child = node.left or node.right
            if node.parent.left == node:
                node.parent.left = child
                if child:
                    child.parent = node.parent
            else:
                node.parent.right = child
                if child:
                    child.parent = node.parent

        node.parent = None
        node.left = None
        node.right = None

    def min(self):
        """Return the (key, value) pair with minimum key."""
        if self.root is None:
            return None
        node, parent = self._traverse(self.root, "left")
        return node.key, node.value

    def max(self):
        """Return the (key, value) pair with maximum key."""
        if self.root is None:
            return None
        node, parent = self._traverse(self.root, "right")
        return node.key, node.value

    def clear(self):
        """Clear all the (key, value) pairs from the tree."""
        self.root = None

    @staticmethod
    def _traverse(node, attr, parent=None):
        while getattr(node, attr):
            node, parent = getattr(node, attr), node
        return node, parent

    def check(self):
        """Check treap invariants."""
        nodes = [(self.root, -sys.maxsize, sys.maxsize)]
        while nodes:
            node, min_bound, max_bound = nodes.pop()
            if node:
                if not min_bound < node.key < max_bound:
                    raise AssertionError
                if node.left and node.key <= node.left.key:
                    raise AssertionError
                if node.right and node.key >= node.right.key:
                    raise AssertionError
                if node.parent:
                    parent = node.parent
                    if node.heap_id >= parent.heap_id:
                        raise AssertionError
                    if not (parent.left == node or parent.right == node):
                        raise AssertionError
                nodes.append((node.left, min_bound, node.key))
                nodes.append((node.right, node.key, max_bound))

    def __repr__(self):
        """Return a string representation of treap."""
        lines = []
        nodes = [(self.root, 0)]
        while nodes:
            node, indent = nodes.pop()
            name = str(node) if node else "None"
            lines.append(" " * indent + name)
            if node:
                nodes.append((node.right, indent + 1))
                nodes.append((node.left, indent + 1))
        return os.linesep.join(lines)


if __name__ == "__main__":
    treap = Treap()
    a = [1, 2, 3, 4, 5]

    for i in range(len(a)):
        treap[i] = a[i]

    print(treap)
