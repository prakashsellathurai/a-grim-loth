#include <iostream>
#include <algorithm>
using namespace std;
/**
 * @brief O(n) kadane algorithm for largest subarray sum
 * 
 * @param arr 
 * @param n 
 */
void kadane_algorithm(int arr[], int n) {
  int current_sum = 0, best_sum = 0, current_start = 0, current_end = 0,
      best_start = 0, best_end = 0;
  for (int i = 0; i < n; i++) {
    current_end = i;
    if (current_sum <= 0) {
      current_start = current_end;
      current_sum = arr[i];
    } else {
      current_sum += arr[i];
    }
    if (current_sum > best_sum) {
      best_sum = current_sum;
      best_start = current_start;
      best_end = current_end;
    }
  }
  std::cout << best_start << " " << best_end << " " << best_sum << std::endl;
}

int main(int argc, const char **argv) {
  int arr[] = {-1, -5, 2, 4, 1, 4, -4};
  int n = sizeof(arr) / sizeof(arr[0]);
  kadane_algorithm(arr, n);
  return 0;
}