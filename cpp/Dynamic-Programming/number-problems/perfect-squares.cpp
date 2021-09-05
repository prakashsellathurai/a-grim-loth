/**
 * @file perfect-squares.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief

 Given a positive integer n, find an efficient algorithm to compute the smallest
number of perfect squares (e.g. 1, 4, 9, 16,...) that sum to n. What is the
running time of your algorithm?
 * @version 0.1
 * @date 2021-08-30
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, const char **argv) {
  int n = 100;

  int dp[n + 1];

  dp[0] = 0;


  for (int i = 0; i <= n; i++) {
    dp[i] = i;
    for (int j = 1; j <= ceil(sqrt(i)); j++) {
      if (j * j > i) {
        break;
      } else {
        dp[i] = min(dp[i], 1 + dp[i - (j * j)]);
      }
    }
  }
  cout << dp[n];

  return 0;
}