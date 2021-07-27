/*Program to construct binary tree from given inorder and preorder traversal.*/
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *splitTree(vector<int> &P, unordered_map<int, int> &M, int pix,int ileft, int iright) {
    
  int rval = P[pix], imid = M[rval];
  TreeNode *root = new TreeNode(rval);
  if (imid > ileft)
    root->left = splitTree(P, M, pix + 1, ileft, imid - 1);
  if (imid < iright)
    root->right = splitTree(P, M, pix + imid - ileft + 1, imid + 1, iright);
  return root;
}

TreeNode *buildTree(vector<int> &P, vector<int> &I) {
  unordered_map<int, int> M;
  for (int i = 0; i < I.size(); i++)
    M[I[i]] = i;
  return splitTree(P, M, 0, 0, I.size() - 1);
}

// A function to print Inorder traversal of
// a given binary tree
void Print(TreeNode *root) {
  if (root == NULL)
    return;

  Print(root->left);
  cout << root->val << " ";
  Print(root->right);
}

int main() {
  vector<int> inorder = {2, 1, 3};
  vector<int> preorder = {2, 1, 3};
  TreeNode *root = buildTree(preorder, inorder);

  Print(root);
  cout << endl;
  return 0;
}