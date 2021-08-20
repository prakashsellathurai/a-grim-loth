#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
#define MAXSIZE 20
bool dp[MAXSIZE][MAXSIZE];
int parent[MAXSIZE][MAXSIZE];

void report_subset(int n, int k) {
  if (k == 0) {
    return;
  }
  if (parent[n][k] == -1) {
    report_subset(n - 1, k);
  } else {

    report_subset(n - 1, parent[n][k]);
    cout << k - parent[n][k] << " ";
  }
}
int subset_sum(int arr[], int n, int k) {

  dp[0][0] = true;
  parent[0][0] = -1;

  for (int i = 1; i <= k; i++) {
    dp[0][i] = false;
    parent[0][i] = -1;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) { // j is the number of elements in the subset
      dp[i][j] = dp[i - 1][j];
      parent[i][j] = -1;

      if ((j >= arr[i - 1]) && (dp[i - 1][j - arr[i - 1]] == true)) {
        dp[i][j] = true;
        parent[i][j] = j - arr[i - 1];
      }
    }
  }
  cout << "is subset sum possible " << (dp[n][k] ? "yes" : "no") << endl;
  if (dp[n][k]) {
    cout << "The subset is : ";
    report_subset(n, k);
  }
  return dp[n][k];
}

int main(int argc, char const *argv[]) {
  int arr[] = {1, 2, 4, 8};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 11;
  subset_sum(arr, n, k);
  return 0;
}
