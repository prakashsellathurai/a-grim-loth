/**
 * @file construct-distinct-BST-1-to-n.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-08-03
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <vector>
using namespace std;

typedef struct Node {
  int data;
  Node *left;
  Node *right;
} Node;

struct Node *newNode(int data) {
  Node *node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void preorder(Node *root) {
  if (root == NULL) {
    return;
  }
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

vector<Node *> constructTrees(int start, int end) {
  vector<Node *> result;
  if (start > end) {
    result.push_back(NULL);
    return result;
  }

  for (int i = start; i <= end; i++) {
    vector<Node *> left = constructTrees(start, i - 1);
    vector<Node *> right = constructTrees(i + 1, end);
    for (int j = 0; j < left.size(); j++) {
      for (int k = 0; k < right.size(); k++) {
        Node *root = newNode(i);
        root->left = left[j];
        root->right = right[k];
        result.push_back(root);
      }
    }
  }
  return result;
}

void construct_distinct_BST(int n) {

  vector<Node *> resullts = constructTrees(1, n);

  for (int i = 0; i < resullts.size(); i++) {
    cout << "BST " << i << ": ";
    preorder(resullts[i]);
    cout << endl;
  }
}
int main(int argc, const char **argv) {
  construct_distinct_BST(3);
  return 0;
}