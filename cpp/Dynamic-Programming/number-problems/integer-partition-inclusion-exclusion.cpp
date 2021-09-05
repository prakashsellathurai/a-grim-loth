/**
 * @file integer-partition-inclusion-exclusion.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 The integer partition takes a set of positive integers S = {s1,...,sn} and
seeks a subset I ⊂ S such that

i∈I
si =
i /∈I
si
Let
i∈S si = M. Give an O(nM) dynamic programming algorithm to solve
the integer partition problem
 * @version 0.1
 * @date 2021-08-30
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
using namespace std;

int main(int argc, const char **argv) {
  int A[] = {1, 1,2};
  int n = sizeof(A) / sizeof(A[0]);
  int M = 0;

  for (int i = 0; i < n; i++) {
    M += A[i];
  }

  int dp[(M / 2) + 1];

  dp[0] = true;

  for (int i = 1; i <= M / 2; i++) {
    dp[i] = false;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = M / 2; j > 0; j--) {
      if (j - A[i - 1] >= 0) {
        dp[j] = dp[j] || dp[j - A[i - 1]];
      }
    }
  }
  cout << dp[M / 2];
  return 0;
}