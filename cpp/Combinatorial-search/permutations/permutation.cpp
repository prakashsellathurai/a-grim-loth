/**
 * @file permutation.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-08-03
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <algorithm>
#include <iostream>

using namespace std;

/**
 * @brief prints the permutation of the given array
 *
 * @param arr
 * @param n
 */
void print_permutation(int *arr, int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
/**
 * @brief backtrack function to print permutation
 *
 * @param arr
 * @param n
 * @param k
 */
void backtrack(int *arr, int n, int k) {
  if (k == n) {
    print_permutation(arr, k);
  }
  if (k > n) {
    return;
  }
  for (int i = k; i < n; i++) {
    swap(arr[k], arr[i]);
    backtrack(arr, n, k + 1);
    swap(arr[k], arr[i]);
  }
}

// generate permutations of a n
// n is the number of elements in the array
// the array is in the form of an array of integers
void generatePermutations(int arr[], int n) { backtrack(arr, n, 0); }

int main(int argc, const char **argv) {
  int a[] = {1, 2, 3};
  int n = sizeof(a) / sizeof(a[0]);
  generatePermutations(a, n);
  return 0;
}