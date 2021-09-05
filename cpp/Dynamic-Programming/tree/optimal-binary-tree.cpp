/**
 * @file optimal-binary-tree.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief

    Let α and β be constants. Assume that it costs α to go left in a binary
    search tree, and β to go right. Devise an algorithm that builds a tree with
    optimal expected query cost, given keys k1,...,kn and the probabilities that
    each will be searched p1,...,pn.

    Recuurence Relation:

    S(i,j) = min{S(i,r-1)+S(r+1,j)+sum(p-k){i<=k<=j}}
             i<=r<=j
 * @version 0.1
 * @date 2021-09-04
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int> freq, int i, int j) {
  int s = 0;
  for (int k = i; k <= j; k++)
    s += freq[k];
  return s;
}

int optimalSearchTree(vector<int> keys, vector<int> freq, int n, int Alpha,
                      int beta) {

  int cost[n][n];
  int presum[n][n];

  for (int i = 0; i < n; i++)
    cost[i][i] = freq[i];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      presum[i][j] = sum(freq, i, j);
    }
  }

  for (int L = 2; L <= n; L++) {
    for (int i = 0; i <= n - L + 1; i++) {
      int j = i + L - 1;
      cost[i][j] = INT_MAX;

      for (int r = i; r <= j; r++) {
        int c = Alpha * (r > i ? cost[i][r - 1] : 0) +
                beta * (r < j ? cost[r + 1][j] : 0) + 
                 presum[i][r - 1] +
                 presum[r + 1][j] + freq[r];
        if (c < cost[i][j]) {
          cost[i][j] = c;
        }
      }
    }
  }
  return cost[0][n - 1];
}
int main(int argc, const char **argv) {
  vector<int> keys = {10, 12, 20};
  vector<int> freq = {34, 8, 50};
  int Alpha = 2;
  int Beta = 2;
  int n = sizeof(keys) / sizeof(keys[0]);
  cout << "Cost of Optimal BST is "
       << optimalSearchTree(keys, freq, n, Alpha, Beta);
  return 0;
}