/**
 * @file three-subset-sum.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief subset sum with three number variant
 * @version 0.1
 * @date 2021-08-21
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief checks if the given arr can be split into three subsets of sum k

 Recurrance relation is gove by:
 c[n,wA,wB] = c[n-1,wA-sn,Wb] V c[n-1,wA,Wb-sn]V c[n-1,wA,Wb]
 *
 * @param arr
 * @param n
 * @param k
 * @return int
 */
int is_subset_sum_possible(vector<int> arr, int n, int k) {
  bool dp[n + 1][k + 1][k + 1];

  dp[0][0][0] = true;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= k; j++) {
      dp[0][i][j] = false;
    }
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= k; j++) {
      for (int l = 1; l <= k; l++) {

        if (j < arr[i - 1] || l < arr[j - 1])
          dp[i][j][l] = dp[i - 1][j][l];
        else
          dp[i][j][l] = dp[i - 1][j - arr[i - 1]][l - 1] ||
                        dp[i - 1][j - 1][l - arr[i - 1]] ||
                        dp[i - 1][j - 1][l - 1];
      }
    }
  }
  return dp[n][k][k];
}

int main(int argc, const char **argv) {
  vector<int> arr = {1, 2, 3, 4, 5};
  int k = 5;
  cout << "is_subset_sum_possible : "
       << ((is_subset_sum_possible(arr, arr.size(), k)) ? "yes" : "no") << endl;
  return 0;
}