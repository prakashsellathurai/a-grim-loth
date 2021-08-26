/**
 * @file longest-common-substring.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief

 The longest common substring (not subsequence) of two strings X and Y is
the longest string that appears as a run of consecutive letters in both strings.
For example, the longest common substring of photograph and tomography is
ograph.
(a) Let n = |X| and m = |Y |. Give a Θ(nm) dynamic programming algorithm for
longest common substring based on the longest common subsequence/edit distance
algorithm.
 (b) Give a simpler Θ(nm) algorithm that does not rely on dynamic
programming.
 * @version 0.1
 * @date 2021-08-26
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

void LCS(string X, string Y) {
  int n = X.size(), m = Y.size();

  int dp[n + 1][m + 1];
  memset(dp, 0, sizeof(dp));
  int max_;
  int row, col;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {

      if (X[i - 1] == Y[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }

      if (dp[i][j] > max_) {
        max_ = dp[i][j];
        row = i;
        col = j;
      }
    }
  }

  cout << " length : " << max_ << endl;
  vector<char> res(n+1);
  while (dp[row][col] != 0) {
    res.push_back(X[row - 1]);
    row--;
    col--;
  }

  for (auto x : res) {
    cout << x;
  }
}

int main(int argc, const char **argv) {
  string X = "photograph", Y = "tomography";
  LCS(X, Y);
  return 0;
}