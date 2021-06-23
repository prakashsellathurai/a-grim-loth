// If input in uniformly dustributred
// like sorting a  float numbers  in """linear time"""
//          don't use:
//              1. comparision sort (mergesort,heapsort,Quick sort)
//                  - they can peroform better than O(nlogn)
//              2. counting sort
//                  - because it uses keys as index (float numbers cannot be
//                  used)
//            use:
//                 Bucker Sort
//                      bucketSort(arr[], n)
//                            1) Create n empty buckets (Or lists).
//                            2) Do following for every array element arr[i].
//                            .......a) Insert arr[i] into bucket[n*array[i]]
//                            3) Sort individual buckets using insertion sort.
//                            4) Concatenate all sorted buckets.
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void bucketSort(float *arr, int n) {
  vector<float> b[n];

  for (int i = 0; i < n; ++i) {
    int index = n * arr[i];
    b[index].push_back(arr[i]);
  }
  for (int i = 0; i < n; ++i) {
    sort(b[i].begin(), b[i].end());
  }
  int index = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < b[i].size(); ++j) {
      arr[index++] = b[i][j];
    }
  }
}

void PrintArray(float *arr, int n) {
  cout << "Sorted array is \n";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  std::cout << std::endl;
}
int main(int argc, char const *argv[]) {
  float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
  int n = sizeof(arr) / sizeof(arr[0]);
  bucketSort(arr, n);
  PrintArray(arr, n);
  return 0;
}
