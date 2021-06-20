//] Write a function to compare whether two binary trees are identical.
//Identical
// trees have the same key value at each position and the same structure.

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>

using namespace std;
struct node {
  int key_value;
  node *left;
  node *right;
};

class BinarySearchTree {
public:
  BinarySearchTree();
  ~BinarySearchTree();

  void insert(int key);
  node *search(int key);
  void *delete_(int key);
  void Inorder_traversal();
  void Preorder_traversal();
  void Postorder_traversal();
  int getHeight();
  void destroy_tree();
  void printTree();
  node *root;

private:
  void destroy_tree(node *leaf);
  int maxDepth(node *leaf);

  void insert(int key, node *leaf);
  void Inorder_traversal(node *root);
  void Preorder_traversal(node *root);
  void Postorder_traversal(node *root);
  void printBT(const string &prefix, node *node, bool isLeft);

  node *minValueNode(node *node);
  node *search(int key, node *leaf);
  node *delete_(int key, node *leaf);
};

//-------------------------- IMplemenetataion======================

BinarySearchTree::BinarySearchTree() { root = NULL; }

BinarySearchTree::~BinarySearchTree() { destroy_tree(); }

void BinarySearchTree::destroy_tree(node *leaf) {
  if (leaf != NULL) {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}
void BinarySearchTree::insert(int key, node *leaf) {
  if (key < leaf->key_value) {
    if (leaf->left != NULL)
      insert(key, leaf->left);
    else {
      leaf->left = new node;
      leaf->left->key_value = key;
      leaf->left->left = NULL;  // Sets the left child of the child node to null
      leaf->left->right = NULL; // Sets the right child of the child node to
                                // null
    }
  } else if (key >= leaf->key_value) {
    if (leaf->right != NULL)
      insert(key, leaf->right);
    else {
      leaf->right = new node;
      leaf->right->key_value = key;
      leaf->right->left = NULL; // Sets the left child of the child node to null
      leaf->right->right =
          NULL; // Sets the right child of the child node to null
    }
  }
}

node *BinarySearchTree::search(int key, node *leaf) {
  if (leaf != NULL) {
    if (key == leaf->key_value)
      return leaf;
    if (key < leaf->key_value)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  } else
    return NULL;
}

void BinarySearchTree::insert(int key) {
  if (root != NULL)
    insert(key, root);
  else {
    root = new node;
    root->key_value = key;
    root->left = NULL;
    root->right = NULL;
  }
}
void BinarySearchTree::Inorder_traversal() {
  std::cout << "Inorder Traversal" << std::endl;
  Inorder_traversal(root);
  std::cout << std::endl;
}
void BinarySearchTree::Inorder_traversal(node *root) {
  if (root != NULL) {
    Inorder_traversal(root->left);
    cout << " " << root->key_value;
    Inorder_traversal(root->right);
  }
}
void BinarySearchTree::Preorder_traversal() {
  std::cout << "Preorder traversal" << std::endl;
  Preorder_traversal(root);
  std::cout << std::endl;
}
void BinarySearchTree::Preorder_traversal(node *root) {
  if (root != NULL) {
    cout << " " << root->key_value;
    Preorder_traversal(root->left);
    Preorder_traversal(root->right);
  }
}

void BinarySearchTree::Postorder_traversal() {
  std::cout << "PostOrder Traversal" << std::endl;
  Postorder_traversal(root);
  std::cout << std::endl;
}
void BinarySearchTree::Postorder_traversal(node *root) {

  if (root != NULL) {

    Postorder_traversal(root->left);
    Postorder_traversal(root->right);
    cout << " " << root->key_value;
  }
}

int BinarySearchTree::maxDepth(node *root) {
  if (root == NULL)
    return 0;
  else {
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    if (leftDepth > rightDepth) {
      return rightDepth + 1;
    } else {
      return leftDepth + 1;
    }
  }
}
int BinarySearchTree::getHeight() { return maxDepth(root); }
node *BinarySearchTree::minValueNode(struct node *node) {
  struct node *current = node;

  /* loop down to find the leftmost leaf */
  while (current && current->left != NULL)
    current = current->left;

  return current;
}
node *BinarySearchTree::delete_(int key, node *root) {
  if (root == NULL)
    return root;

  if (key < root->key_value)
    root->left = delete_(key, root->left);
  else if (key > root->key_value)
    root->right = delete_(key, root->right);
  else {
    if (root->left == NULL && root->right == NULL)
      return NULL;
    else if (root->left == NULL) {
      node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      node *temp = root->left;
      free(root);
      return temp;
    }
    node *temp = minValueNode(root->right);
    root->key_value = temp->key_value;
    root->right = delete_(temp->key_value, root->right);
  }
  return root;
}

void *BinarySearchTree::delete_(int key) {
  if (root != NULL) {
    delete_(key, root);
  }
  return nullptr;
}

void BinarySearchTree::printBT(const string &prefix, node *node, bool isLeft) {
  if (node != nullptr) {
    std::cout << prefix;

    std::cout << (isLeft ? "├──" : "└──");

    // print the value of the node
    std::cout << node->key_value << std::endl;

    // enter the next tree level - left and right branch
    printBT(prefix + (isLeft ? "│   " : "    "), node->left, true);
    printBT(prefix + (isLeft ? "│   " : "    "), node->right, false);
  }
}

void BinarySearchTree::printTree() { printBT("", root, false); }
node *BinarySearchTree::search(int key) { return search(key, root); }

void BinarySearchTree::destroy_tree() { destroy_tree(root); }

bool compareTrees(node *t1, node *t2) {

 if(t1&&t2){
     return t1->key_value==t2->key_value && compareTrees(t1->left, t2->left)&&  compareTrees(t1->right, t2->right);
 }
 return t1 == t2;
}

int main(int argc, char const *argv[]) {
  BinarySearchTree bst1;
  bst1.insert(10);
  bst1.insert(7);
  bst1.insert(8);
  bst1.insert(1);
  bst1.insert(9);
  bst1.insert(2);
  bst1.insert(12);
  bst1.insert(5);

  BinarySearchTree bst2;
  bst2.insert(10);
  bst2.insert(7);
  bst2.insert(8);
  bst2.insert(1);
  bst2.insert(9);
  bst2.insert(2);
  bst2.insert(12);
  bst2.insert(5);
  std::cout << "Tree Equality : "
            << (compareTrees(bst1.root, bst2.root) ? "Yes" : "No") << std::endl;

  BinarySearchTree bst3;
  bst3.insert(10);
  bst3.insert(7);
  bst3.insert(8);
  bst3.insert(1);
  bst3.insert(9);
  bst3.insert(2);
  bst3.insert(12);
  bst3.insert(5);

  BinarySearchTree bst4;
  bst4.insert(10);
  bst4.insert(7);
  bst4.insert(8);
  bst4.insert(1);
  bst4.insert(0);
  bst4.insert(2);
  bst4.insert(12);
  bst4.insert(5);
  std::cout << "Tree Equality : "
            << (compareTrees(bst3.root, bst4.root) ? "Yes" : "No") << std::endl;

  return 0;
}
