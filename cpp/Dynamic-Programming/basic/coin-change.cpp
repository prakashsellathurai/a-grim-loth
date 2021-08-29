/**
 * @file coin-change.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-08-29
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <algorithm>
#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

int naive(vector<int> denom, int n, int m) {
  if (n == 0) {
    return 1;
  }

  if (n < 0) {
    return 0;
  }

  if (m <= 0 && n >= 1) {
    return 0;
  }

  return naive(denom, m - 1, n) + naive(denom, m, n - denom[m - 1]);
}

int number_of_ways(vector<int> denom, int k) {
  int n = denom.size();
  int dp[k + 1];
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;

  for (int j = 0; j < n; j++) {
    for (int i = denom[j]; i <= k; i++) {
      dp[i] += dp[i - denom[j]];
    }
  }


  return dp[k];
}

int main(int argc, const char **argv) {
  vector<int> denominations = {1, 6, 10};
  int k = 20;

  cout << number_of_ways(denominations, k);
  return 0;
}