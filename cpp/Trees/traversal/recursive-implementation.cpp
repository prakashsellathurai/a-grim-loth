
/* pre order recursive travesal in binary tree */
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void PreOrderTraversal(TreeNode *root) {
  if (root == NULL)
    return;
  cout << root->val << " ";
  PreOrderTraversal(root->left);
  PreOrderTraversal(root->right);
}
/*post order traversal in binary tree */
void PostOrderTraversal(TreeNode *root) {
  if (root == NULL)
    return;
  PostOrderTraversal(root->left);
  PostOrderTraversal(root->right);
  cout << root->val << " ";
}
/*in order traversal in binary tree */
void InOrderTraversal(TreeNode *root) {
  if (root == NULL)
    return;
  InOrderTraversal(root->left);
  cout << root->val << " ";
  InOrderTraversal(root->right);
}
/*level order traversal in binary tree */
void LevelOrderTraversal(TreeNode *root) {
  if (root == NULL)
    return;
  queue<TreeNode *> que;
  que.push(root);
  while (!que.empty()) {
    TreeNode *temp = que.front();
    que.pop();
    cout << temp->val << " ";
    if (temp->left != NULL)
      que.push(temp->left);
    if (temp->right != NULL)
      que.push(temp->right);
  }
}

/* print tree in hierachical order */
void printTree(const string &prefix, TreeNode *node, bool isLeft) {
  if (node != nullptr) {
    cout << prefix;

    cout << (isLeft ? "├──" : "└──");

    // print the value of the node
    cout << node->val << endl;

    // enter the next tree level - left and right branchif
    if (node->left != nullptr)
      printTree(prefix + (isLeft ? "│   " : "    "), node->left, true);
    if (node->right != nullptr)
      printTree(prefix + (isLeft ? "│   " : "    "), node->right, false);
  }
}
int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  cout << "pre order traversal of binary tree is ";
  PreOrderTraversal(root);
  cout << "\n";
  cout << "post order traversal of binary tree is ";
  PostOrderTraversal(root);
  cout << "\n";
  cout << "in order traversal of binary tree is ";
  InOrderTraversal(root);
  cout << "\n";

  cout << "tree in hierachical order is \n";
  printTree("", root, false);
  cout << "\n";
  LevelOrderTraversal(root);
  cout << "\n";
  return 0;
}