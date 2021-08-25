/**
 * @file minimum-path-sum.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
    Given an s × t grid filled with non-negative numbers, find a path from top
    left to bottom right that minimizes the sum of all numbers along its path.
 You can only move either down or right at any point in time.

    (a) Give a solution based on Dijkstra’s algorithm. What is its time
 complexity as a function of s and t? (b) Give a solution based on dynamic
 programming. What is its time complexity as a function of s and t?
 * @version 0.1
 * @date 2021-08-25
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int math_sum_dijishtra(vector<vector<int>> &grid) {
  int m = grid.size();
  int n = grid[0].size();

  vector<int> paths;
  vector<vector<int>> dist(m, vector<int>(n, 1e5));
  dist[0][0] = grid[0][0];
  priority_queue<vector<int>, vector<vector<int>>> pq;
  pq.push({grid[0][0], 0, 0});
  int dx[] = {0, 1};
  int dy[] = {1, 0};
  while (!pq.empty()) {
    vector<int> v = pq.top();

    pq.pop();
    int distTillNow = v[0];

    int i = v[1];
    int j = v[2];

    for (int k = 0; k < 2; k++) {
      int x = i + dx[k];
      int y = j + dy[k];

      if (x >= 0 && x < m && y >= 0 && y < n &&
          grid[x][y] + distTillNow < dist[x][y]) {
        dist[x][y] = grid[x][y] + distTillNow;
        pq.push({dist[x][y], x, y});
      }
    }
  }

  return dist[m - 1][n - 1];
}

int math_sum_dp(vector<vector<int>> &grid) {
  int n = grid.size();
  int m = grid[0].size();
  int dp[n + 1][m + 1];
  vector<int> paths;
  memset(dp, INT_MAX, sizeof(dp));

  for (int i = 1; i <= n; i++) {
    dp[i][0] = grid[i - 1][0];
  }

  for (int i = 1; i <= m; i++) {
    dp[0][i] = grid[0][i - 1];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {

      dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
    }
  }

  cout << endl;
  return dp[n - 1][m - 1];
}
int main(int argc, const char **argv) {
  vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  cout << math_sum_dijishtra(grid) << endl;
  cout << math_sum_dp(grid) << endl;
  return 0;
}