/**
 * @file
 * combinations-every-element-appears-twice-distance-appearances-equal-value.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-08-03
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
using namespace std;

void print_combination(int arr[], int size, int k) {
  int i;
  for (i = 0; i < 2 * size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
void backtrack(int arr[], int k, int n) {

  if (k > n) {
    print_combination(arr, n, k);
    return;
  }

  for (int i = 0; i < 2 * n; i++) {
    if (arr[i] == -1 && i + k + 1 < 2 * n && arr[i + k + 1] == -1) {
      arr[i] = k;
      arr[i + k + 1] = k;
      backtrack(arr, k + 1, n);
      arr[i] = -1;
      arr[i + k + 1] = -1;
    }
  }
}
void generate_combination(int n) {
  int arr[2 * n];

  for (int i = 0; i < 2 * n; ++i) {
    arr[i] = -1;
  }

  backtrack(arr, 1, n);
}

int main(int argc, const char **argv) {
  generate_combination(3);
  return 0;
}