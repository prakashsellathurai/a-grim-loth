/**
 * @file rod-cutting.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 You are given a rod of length n inches and a table of prices obtainable for
rod-pieces of size n or smaller. Give an efficient algorithm to find the maximum
value obtainable by cutting up the rod and selling the pieces. For example, if
n = 8 and the values of different pieces are:
length 1234 5 6 7 8
price 1 5 8 9 10 17 17 20
then the maximum obtainable value is 22, by cutting into pieces of lengths 2
and 6.
 * @version 0.1
 * @date 2021-08-29
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char **argv) {
  vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};

  int n = prices.size();

  int dp[n + 1];

  for (int i = 0; i <= n; i++) {
    dp[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i] = max(dp[i], prices[j - 1] + dp[i - j]);
    }
  }
  cout << dp[n];

  return 0;
}