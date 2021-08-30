/**
 * @file divide-luggage.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 Two drivers have to divide up m suitcases between them, where the weight
of the ith suitcase is wi. Give an efficient algorithm to divide up the loads so
the two drivers carry equal weight, if possible
 * @version 0.1
 * @date 2021-08-30
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
using namespace std;

int main(int argc, const char **argv) {
  int w[] = {2, 4, 6,4,4};
  int k = 2;
  int n = 5;

  int sum = 0, parent[n + 1];

  for (int i = 0; i < n; i++) {
    sum += w[i];
    parent[i] = 0;
  }
  int dp[n + 1][(sum / 2) + 1];

  for (int i = 0; i <= n; i++) {
    dp[i][0] = true;
  }

  for (int i = 0; i <= (sum / 2); i++) {
    dp[0][i] = false;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= (sum / 2); j++) {
      dp[i][j] = dp[i - 1][j];
      if (j - w[i - 1] >= 0) {
        dp[i][j] = dp[i-1][j] || dp[i - 1][j - w[i - 1]];
        parent[j-1] = j-w[i-1];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << parent[i] << " ";
  }

  cout << "is possible: " << ((dp[n][sum / 2]) ? "yes" : "no");

  return 0;
}