class Tree:
    def __init__(self, cargo, left=None, right=None):
        self.cargo = cargo
        self.left  = left
        self.right = right

    def __str__(self):
        return str(self.cargo)


def total(tree):
    if tree is None: return 0
    return total(tree.left) + total(tree.right) + tree.cargo

def print_tree(tree):
    if tree is None: return
    print(tree.cargo)
    print_tree(tree.left)
    print_tree(tree.right)
    
if __name__ == "__main__":
    left = Tree(2)
    right = Tree(3)
    tree = Tree(1, left, right)
    print(total(tree))
    print(print_tree(tree))
