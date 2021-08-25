/**
 * @file coin-change-variant-basket-balls.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
    Basketball games are a sequence of 2-point shots, 3-point shots, and 1-
point free throws. Give an algorithm that computes how many possible mixes
(1s,2s,3s) of scoring add up to a given n. For n = 5 there are four possible
solutions: (5, 0, 0), (2, 0, 1), (1, 2, 0), and (0, 1, 1).
 * @version 0.1
 * @date 2021-08-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <cstring>
#include <iostream>
using namespace std;

/**
 * @brief Recuurence  R[i] = R[i-1]+R[i-2]+R[i-3]
 *
 * @param scores
 * @param n
 * @param size
 * @return int
 */
int count_all_possible_mixes(int scores[], int n, int size) {
  int dp[n + 1];
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;

  for (int i = 0; i < size; i++) {
    for (int j = scores[i]; j <= n; j++) {
      dp[j] += dp[j - scores[i]];
    }
  }
  return dp[n];
}

int main(int argc, const char **argv) {
  int n = 5;
  int scores[] = {1, 2, 3};
  int size = 3;
  cout << count_all_possible_mixes(scores, n, size) << endl;

  return 0;
}