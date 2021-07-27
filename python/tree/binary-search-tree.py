 
class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key
 
# A utility function to insert 
# a new node with the given key
 
 
def insert(root, key):
    if root is None:
        return Node(key)
    if root.val == key:
        return root
    if root.val < key:
        root.right = insert(root.right, key)
    else:
        root.left = insert(root.left, key)
    return root
 
# A utility function to do inorder tree traversal
 
def search(root,key):
    
    # Base Cases: root is null or key is present at root
    if root is None or root.val == key:
        return root

    # Key is greater than root's key
    if root.val < key:
        return search(root.right,key)

    # Key is smaller than root's key
    return search(root.left,key)
 
def is_in_tree(root,key):
    return search(root,key) is not None
    
 
def inorder(root):
    if root:
        inorder(root.left)
        print(root.val)
        inorder(root.right)
 

def deleteNode(root, key):
 
    # Base Case
    if root is None:
        return root
 
    # Recursive calls for ancestors of
    # node to be deleted
    if key < root.key:
        root.left = deleteNode(root.left, key)
        return root
 
    if(key > root.key):
        root.right = deleteNode(root.right, key)
        return root
 
    # We reach here when root is the node
    # to be deleted.
 
    # If one of the children is empty
 
    if root.left is None:
        temp = root.right
        root = None
        return temp
 
    if root.right is None:
        temp = root.left
        root = None
        return temp
 
    # If both children exist
 
    succParent = root
 
    # Find Successor
 
    succ = root.right
 
    while succ.left is not None:
        succParent = succ
        succ = succ.left
 
    # Delete successor.Since successor
    # is always left child of its parent
    # we can safely make successor's right
    # right child as left of its parent.
    # If there is no succ, then assign
    # succ->right to succParent->right
    if succParent != root:
        succParent.left = succ.right
    else:
        succParent.right = succ.right
 
    # Copy Successor Data to root
 
    root.key = succ.key
 
    return root
 
def minValue(node): 
    current = node 
  
    # loop down to find the lefmost leaf 
    while(current.left is not None): 
        current = current.left 
  
    return current.val 
def maxValue(node): 
    current = node 
  
    # loop down to find the lefmost leaf 
    while(current.right is not None): 
        current = current.right 
  
    return current.val 

def get_height(node):
    if node is None:
        return -1 ; 
 
    # Compute the depth of each subtree
    lDepth = get_height(node.left)
    rDepth = get_height(node.right)
 
    # Use the larger one
    if (lDepth > rDepth):
        return lDepth+1
    return rDepth+1
 
INT_MAX = 4294967296
INT_MIN = -4294967296
# Returns true if the given tree is a binary search tree
# (efficient version)
def isBST(node):
    return (isBSTUtil(node, INT_MIN, INT_MAX))
 
# Retusn true if the given tree is a BST and its values
# >= min and <= max
def isBSTUtil(node, mini, maxi):
     
    # An empty tree is BST
    if node is None:
        return True
 
    # False if this node violates min/max constraint
    if node.val < mini or node.val > maxi:
        return False
 
    # Otherwise check the subtrees recursively
    # tightening the min or max constraint
    return (isBSTUtil(node.left, mini, node.val -1) and
          isBSTUtil(node.right, node.val+1, maxi))
# Driver rogram to test the above functions
# Let us create the following BST
#    50
#  /     \
# 30     70
#  / \ / \
# 20 40 60 80
 
r = Node(50)
r = insert(r, 30)
r = insert(r, 20)

r = insert(r, 40)
r = insert(r, 70)
r = insert(r, 60)
r = insert(r, 80)
 
# Print inoder traversal of the BST
inorder(r)
print(is_in_tree(r,30))
print(is_in_tree(r,100))
print(get_height(r))
print(minValue(r))
print(maxValue(r))
print(isBST(r))