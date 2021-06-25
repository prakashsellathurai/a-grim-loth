
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <random>

using namespace std;

void swap(int *a, int *b) {
  int *temp = a;
  *a = *b;
  *b = *temp;
}
int randomRange(int l, int r) { return l + (std::rand() % (r - l + 1)); }

int partition(int *arr, int l, int r, int k) {
  int i;
  for (i = l; i < r; i++)
    if (arr[i] == k)
      break;
  swap(arr[i], arr[r]);

  i = l;
  for (int j = l; j <= r - 1; j++) {
    if (arr[j] <= k) {
      swap(arr[i], arr[j]);
      i++;
    }
  }
  swap(arr[i], arr[r]);
  return i;
}
int selectMedian(int *arr, int l, int r) {
  int k = (r - l + 1) / 2;
  int p = partition(
      arr, l, r,
      arr[k]); // use median of median for better peroformance in worst case

  if (p - l == k - 1)
    return arr[p];
  else if (p - l > k)
    return selectMedian(arr, l, p - 1);

  return selectMedian(arr, p + 1, r);
}

int main(int argc, char const *argv[]) {
  int arr[] = {12, 3, 5, 17, 4, 19, 26};
  const int n = sizeof(arr) / sizeof(arr[0]);
  array<int, n> arr1;
  std::copy(std::begin(arr), std::end(arr), std::begin(arr1));

  std::cout << selectMedian(arr, 0, n) << std::endl;

  sort(arr1.begin(), arr1.end());
  for (int i = 0; i < n; i++)
  {
      cout << arr1.at(i) << " ";
  }
  cout << endl;
  std::cout << arr1[n/2] << std::endl;
  return 0;
}
