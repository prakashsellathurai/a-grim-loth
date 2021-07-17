/* binary tree traversal iterative implementation */
//
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Tree node in bst
 *
 */
class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  /**
   * @brief maximum depth(height) of the node
   *
   * @return int
   */
  int max_depth() {
    int left_depth = 0, right_depth = 0;
    if (left) {
      left_depth = left->max_depth();
    }
    if (right) {
      right_depth = right->max_depth();
    }
    return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
  }
};

class BinarySearchTree {
public:
  /**
   * @brief root tree node
   *
   */
  TreeNode *root;

  /**
   * @brief Construct a new Binary Search Tree object
   *
   */
  BinarySearchTree() { root = NULL; }

  /**
   * @brief Destroy the Binary Search Tree object
   *
   */
  ~BinarySearchTree() {
    if (root != NULL) {
      root = NULL;
    }
  }

  /**
   * @brief insert a node to the binary tree
   *
   * @param val
   */
  void insert(int val) {
    if (root == NULL) {
      root = new TreeNode(val);
    } else {
      TreeNode *cur = root;
      while (cur != NULL) {
        if (val < cur->val) {
          if (cur->left == NULL) {
            cur->left = new TreeNode(val);
            break;
          } else {
            cur = cur->left;
          }
        } else {
          if (cur->right == NULL) {
            cur->right = new TreeNode(val);
            break;
          } else {
            cur = cur->right;
          }
        }
      }
    }
  }

  /**
   * @brief Inorder traversal iterative implementation
   * @return vector<int>
   */
  vector<int> InOrderTraversal() {
    vector<int> result;
    if (root == NULL)
      return result;
    stack<TreeNode *> s;
    TreeNode *cur = root;
    while (cur != NULL || !s.empty()) {
      if (cur != NULL) {
        s.push(cur);
        cur = cur->left;
      } else {
        cur = s.top();
        s.pop();
        result.push_back(cur->val);
        cur = cur->right;
      }
    }
    return result;
  }

  /**
   * @brief Preorder traversal iterative implementation
   *
   * @param root
   * @return vector<int>
   */
  vector<int> PreorderTraversal() {
    vector<int> result;
    if (root == NULL)
      return result;
    stack<TreeNode *> s;
    TreeNode *cur = root;
    s.push(root);
    while (!s.empty()) {
      cur = s.top();
      s.pop();

      if (cur != NULL) {
        if (cur->right != NULL) {
          s.push(cur->right);
        }
        if (cur->left != NULL) {
          s.push(cur->left);
        }
        result.push_back(cur->val);
      }
    }
    return result;
  }

  /**
   * @brief Postorder traversal iterative implementation
   *
   * @param root
   * @return vector<int>
   */
  vector<int> PostorderTraversal() {
    vector<int> result;
    if (root == NULL)
      return result;
    stack<TreeNode *> s;
    TreeNode *cur = root;
    s.push(root);
    while (!s.empty()) {
      cur = s.top();
      s.pop();

      if (cur != NULL) {

        result.push_back(cur->val);

        if (cur->left != NULL) {
          s.push(cur->left);
        }
        if (cur->right != NULL) {
          s.push(cur->right);
        }
      }
    }
    return result;
  }

  /**
   * @brief prints the traversal of the tree
   *
   * @param vec
   */
  void print_vector(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
      std::cout << vec.at(i) << " ";
    }
    std::cout << std::endl;
  }

  /**
   * @brief prints a binary tree
   *
   * @param prefix
   * @param node
   * @param isLeft
   */
  void printBT(string prefix, const TreeNode *node, bool isLeft) {
    if (node != nullptr) {
      std::cout << (string)(prefix);

      std::cout << (isLeft ? "├──" : "└──");

      // print the value of the node
      std::cout << node->val << std::endl;

      // enter the next tree level - left and right branch
      printBT(prefix + (isLeft ? "│   " : "    "), node->left, true);
      printBT(prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
  }

  /**
   * @brief draw binary tree
   *
   */
  void draw_tree() {
    std::cout << std::endl;
    printBT("", root, false);
  }
};

int main(int argc, const char **argv) {

  BinarySearchTree BStree;
  BStree.insert(5);
  BStree.insert(3);
  BStree.insert(2);
  BStree.insert(4);
  BStree.insert(6);
  BStree.insert(7);
  BStree.insert(8);
  BStree.insert(9);
  BStree.insert(10);
  BStree.insert(11);
  BStree.insert(1);

  std::cout << "Inorder traversal :"
            << "  ";
  vector<int> vec = BStree.InOrderTraversal();
  BStree.print_vector(vec);

  std::cout << "Preorder traversal :"
            << "  ";
  vec = BStree.PreorderTraversal();
  BStree.print_vector(vec);

  std::cout << "Postorder traversal :"
            << "  ";
  vec = BStree.PostorderTraversal();
  BStree.print_vector(vec);


BStree.draw_tree();
  return 0;
}
