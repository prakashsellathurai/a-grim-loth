#include <algorithm>
#include <iostream>
using namespace std;

bool isValid(int arr[], int n, int len, int k) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    count += arr[i] / len;
  }
  return count >= k;
}

/**
 * @brief Find the maximum possible length O(n*log(Max))
 *
 * @param arr
 * @param n
 * @param k
 * @return int
 */
int max_possible_length(int arr[], int n, int k) {
  int l = 1;
  int r = *max_element(arr, arr + n);
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (isValid(arr, n, m, k)) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return r;
}

int main(int argc, char const *argv[]) {
  int wooden_sticks[] = {10, 6, 5, 3};
  int K = 4;
  int n = sizeof(wooden_sticks) / sizeof(wooden_sticks[0]);
  std::cout << "Maximum length possible "
            << max_possible_length(wooden_sticks, n, K) << std::endl;
  return 0;
}
