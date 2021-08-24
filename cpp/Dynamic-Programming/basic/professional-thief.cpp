/**
 * @file professional-thief.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
    Imagine you are a professional thief who plans to rob houses along a street
    of n homes. You know the loot at house i is worth mi, for 1 ≤ i ≤ n, but you
    cannot rob neighboring houses because their connected security systems will
    automatically contact the police if two adjacent houses are broken into.
 Give an efficient algorithm to determine the maximum amount of money you can
 steal without alerting the police.
 * @version 0.1
 * @date 2021-08-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int count_max_amount(vector<int> &m) {
  int n = m.size();

  if (n < 1) {
    return -1;
  }

  if (n == 1) {
    return m[0];
  }

  int dp[n + 1];
  dp[0] = 0;
  dp[1] = m[0];

  for (int i = 2; i <= n; i++) {
    dp[i] = max(dp[i - 2] + m[i-1], dp[i - 1]);
  }

  return dp[n];
}


int count_max_amount_optimized(vector<int> &m) {
  int n = m.size();

  if (n < 1) {
    return 0;
  }

  if (n == 1) {
    return m[0];
  }

  int curr,prev,prev2;
  prev2 = 0;
  prev = m[0];

  for (int i = 2; i <= n; i++) {
    curr = max(prev2 + m[i-1], prev);
    prev2 = prev;
    prev = curr;
  }

  return curr;
}
int main(int argc, const char **argv) {
  vector<int> m = {1, 2, 3, 1};
  cout << count_max_amount(m) << endl;
  cout << count_max_amount_optimized(m);
  return 0;
}