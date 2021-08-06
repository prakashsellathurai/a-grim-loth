/**
 * @file partition-2k-elements-into-two-kgroups.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-08-05
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

void print_result(vector<char> &set1) {

  for (int i = 0; i < set1.size() / 2; i++) {
    cout << " " << set1.at(i);
  }

  cout << " | ";

  for (int i = (set1.size() / 2); i < set1.size(); i++) {
    cout << " " << set1.at(i);
  }
  cout << endl;
}
// partition 2^k elements into two groups
void backtracing(vector<char> &arr, int k, int n, int depth) {

  if (depth == 0) {
    print_result(arr);
  }

  if (depth == 1) {
    print_result(arr);
    return;
  }

  for (int i = 0; i <= k - 1; i++) {
    for (int j = n - 1; j > k; j--) {
      swap(arr[i], arr[j]);
      backtracing(arr, k, n, depth + 1);
      swap(arr[i], arr[j]);
    }
  }
}
int main(int argc, const char **argv) {
  vector<char> v = {'A', 'B', 'C', 'D'};
  int n = v.size();
  int k = n / 2;
  backtracing(v, k, n, 0);

  cout << endl;

  v = {'A', 'B', 'C', 'D','E','F'};
  n = v.size();
  k = n / 2;
  backtracing(v, k, n, 0);
  return 0;
}