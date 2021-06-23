#include <iostream>
using namespace std;
int binarySearch(int *arr, int key, int low, int high) {
  int middle;
  if (low > high)
    return -1;
  middle = (low + high) / 2;
  if (arr[middle] == key)
    return key;
  else if (arr[middle] < key) {
    return binarySearch(arr, key, middle + 1, high);
  } else {
    return binarySearch(arr, key, low, middle - 1);
  }
}
int main(int argc, const char **argv) {
  int arr[] = {1,2,3,4,5};
  int n = sizeof(arr) / sizeof(arr[0]);
  std::cout << (binarySearch(arr, 1, 0, n - 1) != -1 ? "Found" : "Not Found")
            << std::endl;
  std::cout << (binarySearch(arr, 100, 0, n - 1) != -1 ? "Found" : "Not Found")
            << std::endl;
  return 0;
}
