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
  void convert_to_linkedlist();
  int getHeight();
  void destroy_tree();
  void printTree();

private:
  void destroy_tree(node *leaf);
  int maxDepth(node *leaf);

  node *insert(int key, node *leaf);
  void Inorder_traversal(node *root);
  void Preorder_traversal(node *root);
  void Postorder_traversal(node *root);
  void printBT(const string &prefix, node *node, bool isLeft);

  node *minValueNode(node *node);
  node *search(int key, node *leaf);
  node *delete_(int key, node *leaf);
  node *root;
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

node *BinarySearchTree::insert(int key, node *leaf) {

  if (leaf == NULL) {
    node *head = new node;
    head->key_value = key;
    head->left = NULL;
    head->right = NULL;
    return head;
  } else {

    if (key > leaf->key_value) {
      leaf->right = insert(key, leaf->right);
    } else {
      leaf->left = insert(key, leaf->left);
    }
    return leaf;
  }
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
void flatten(node *root) {
  // base condition- return if root is NULL
  // or if it is a leaf node
  if (root == NULL || root->left == NULL && root->right == NULL) {
    return;
  }

  // if root->left exists then we have
  // to make it root->right
  if (root->left != NULL) {

    // move left recursively
    flatten(root->left);

    // store the node root->right
    node *tmpRight = root->right;
    root->right = root->left;
    root->left = NULL;

    // find the position to insert
    // the stored value
    node *t = root->right;
    while (t->right != NULL) {
      t = t->right;
    }

    // insert the stored value
    t->right = tmpRight;
  }
  flatten(root->right);
}
void BinarySearchTree::convert_to_linkedlist() { flatten(root); }
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

int main(int argc, char const *argv[]) {
  BinarySearchTree bst;
  bst.insert(10);
  bst.insert(7);
  bst.insert(8);
  bst.insert(1);
  bst.insert(9);
  bst.insert(2);
  bst.insert(12);
  bst.insert(5);
  bst.printTree();

  bst.Inorder_traversal();
  bst.convert_to_linkedlist();
  bst.printTree();
  return 0;
}
