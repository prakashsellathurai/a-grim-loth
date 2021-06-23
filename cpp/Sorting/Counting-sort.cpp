// Counting sort is a stable sorting technique,
//     which is used to sort objects according the keys that are small
//         numbers.It counts the number of keys whose key values are
//             same.This sorting technique is efficient when difference between
//                 different keys are not so big,
//     otherwise it can increase the space complexity.
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int getMax(int* arr, int n) {
  int max_ = arr[1];
  for (int i = 2; i <= n; i++) {
    if (arr[i] > max_) {
      max_ = arr[i];
    }
  }
  return max_;
}
void CountingSort(int* arr, int n) {
  int max_ele = getMax(arr, n);

  int count[max_ele + 1];
  int output[n + 1];

  for (int i = 0; i <= max_ele; i++) {
    count[i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    count[arr[i]]++;
  }

  for (int i = 1; i <= max_ele; i++) {
    count[i] += count[i - 1];
  }

  for (int i = n ; i >= 1; i--) {
    output[count[arr[i]]] = arr[i];
    count[arr[i]]--;
  }
  for (int i = 1; i <= n; i++) {
    arr[i] = output[i];
  }
}
void PrintArray(int* arr, int n) {
  cout << "Sorted array is \n";
  for (int i = 1; i <= n; i++)
    cout << arr[i] << " ";
  std::cout << std::endl;
}
int main(int argc, const char **argv) {
  int arr[] = {0, 10, 12, 4, 8, 4, 6, 7, 8, 9, 0, 1, 15};
  int n = sizeof(arr)/sizeof(arr[0])-1;
  CountingSort(arr, n);
  PrintArray(arr, n);
  return 0;
}
