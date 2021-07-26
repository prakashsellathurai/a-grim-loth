/**
 * @file maximum-matching.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief Maximum matching of a tree in linear time
 * @version 0.1
 * @date 2021-07-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <algorithm>
#include <iostream>
using namespace std;

//Tree node
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// maximum matching Bottom-up DFS approach
int max_matching_bottom_up(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int matching = 0;
    int max_matching = 0;
    int left_matching = 0;
    int right_matching = 0;
    max_matching = max(max_matching, left_matching);
    max_matching = max(max_matching, right_matching);
    if (root->left != NULL) {
        left_matching = max_matching_bottom_up(root->left);
    }
    if (root->right != NULL) {
        right_matching = max_matching_bottom_up(root->right);
    }
    matching = max(left_matching, right_matching) + 1;
    max_matching = max(matching, max_matching);
    return max_matching;
}

         

int main(int argc, const char** argv) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);

    cout << "Maximum matching of the tree is " << max_matching_bottom_up(root) << endl;
    return 0;
}