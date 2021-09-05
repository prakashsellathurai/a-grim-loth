/**
 * @file knapsack-problem.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 The knapsack problem is as follows: given a set of integers S = {s1,
s2,...,sn}, and a given target number T, find a subset of S that adds up exactly
to T. For example, within S = {1, 2, 5, 9, 10} there is a subset that adds up to
T = 22 but not T = 23.
 * @version 0.1
 * @date 2021-08-30
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
using namespace std;

int isPossible(int S[], int n, int T) {
  bool dp[n + 1][T + 1];

  for (int i = 0; i <= n; i++) {
    dp[i][0] = true;
  }
  for (int i = 0; i <= T; i++) {
    dp[0][i] = false;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = S[i]; j <= T; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j - S[i - 1] > 0) {
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - S[i - 1]];
      }
    }
  }

  return dp[n][T];
}

int main(int argc, const char **argv) {
  int S[] = {1, 2, 5, 9, 10};
  int n = sizeof(S) / sizeof(S[0]);
  int T = 22;

  cout << isPossible(S, n, T) << endl;
  cout << isPossible(S, n, 23);
  return 0;
}