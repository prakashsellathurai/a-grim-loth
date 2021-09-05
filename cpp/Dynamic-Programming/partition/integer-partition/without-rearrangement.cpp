/**
* @file without-rearrangement.cpp
* @author prakash (prakashsellathurai@gmail.com)
* @brief
    Problem: Integer Partition without Rearrangement
    Input: An arrangement S of non-negative numbers s1,...,sn and an integer k.
    Output: Partition S into k or fewer ranges, to minimize the maximum sum over
    all the ranges, without reordering any of the numbers.
* @version 0.1
* @date 2021-08-21
*
* @copyright Copyright (c) 2021
*
*/

#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <vector>

using namespace std;

void print_partition(vector<int> arr, int start, int end) {
  cout << " { ";
  for (int i = start; i <= end; i++) {
    cout << i << " : " << arr[i - 1] << " ";
  }
  cout << "} " << endl;
}
void recosntruct_part(vector<int> arr, vector<vector<int>> divider, int n,
                      int k) {
  if (k == 1) {
    print_partition(arr, 1, n + 1);
  } else {
    recosntruct_part(arr, divider, divider[n][k], k - 1);
    print_partition(arr, divider[n][k] + 1, n);
  }
}

/**
 * @brief Time complexity - O(nk^2)
             n               n
 M[n,k] = min  [max(M[n,k-1],Es_i)]
            i=1              j+1

 *
 * @param arr
 * @param k
 */
void min_sum_over_k_ranges(vector<int> &arr, int k) {
  int n = arr.size();
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, false));
  vector<vector<int>> divider(n + 1, vector<int>(k + 1, -1));
  ;
  vector<int> presum(n + 1, -1);

  presum[0] = 0;
  for (int i = 1; i <= n; i++) {
    presum[i] = presum[i - 1] + arr[i];
  }

  // base case
  for (int i = 1; i <= n; i++) {
    dp[i][1] = presum[i];
  }

  for (int j = 1; j <= k; j++) {
    dp[1][j] = arr[0];
  }

  // recursive case
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= k; j++) {
      dp[i][j] = INT_MAX;

      for (int x = 1; x <= i - 1; x++) {
        int cost = max(dp[x][j - 1], presum[i] - presum[x]);
        if (cost < dp[i][j]) {
          dp[i][j] = cost;
          divider[i][j] = x;
        }
      }
    }
  }

  cout << " MAx Sum : " << dp[n][k] << endl;

  cout << "parts:" << endl;
  recosntruct_part(arr, divider, n - 1, k);
}

int main(int argc, const char **argv) {
  vector<int> arr = {1, 1, 1, 1, 1, 1, 1, 1, 1};
  int k = 3;
  min_sum_over_k_ranges(arr, k);
  arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  k = 3;
  min_sum_over_k_ranges(arr, k);

  return 0;
}