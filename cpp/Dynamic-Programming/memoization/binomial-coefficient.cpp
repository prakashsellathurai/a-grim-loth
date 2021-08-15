/**
 * @file binomial-coefficient.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-08-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;

int binomial_coefficient_dp(int n, int k) {
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

  // base case
  // when k=0 dp[i][0] = 1

  for (int i = 0; i <= n; i++) {
    dp[i][0] = 1;
  }
  // when k==n dp[i][k] = 1
  for (int i = 0; i <= n; i++) {
    dp[i][i] = 1;
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
    }
  }

  return dp[n][k];
}

int fact(int num) {
  int dp[num + 1];
  dp[0] = 1;

  for (int i = 1; i <= num; i++) {
    dp[i] = dp[i - 1] * i;
  }
  return dp[num];
}

int binomial_coefficient_fact(int n, int k) {
  return (fact(n) / (fact(k) * fact(n - k)));
}

int main(int argc, const char **argv) {

  assert(binomial_coefficient_dp(5, 3) == 10);
  assert(binomial_coefficient_dp(5, 3) == binomial_coefficient_fact(5, 3));

  return 0;
}