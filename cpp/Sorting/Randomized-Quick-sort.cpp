#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;
int partition(int arr[], int l, int h) {
  int pivot = arr[l];
  int i = l - 1, j = h + 1;

  while (true) {
    do {
      i++;
    } while (arr[i] < pivot);
    do {
      j--;
    } while (arr[j] > pivot);

    if (i >= j)
      return j;
    swap(arr[i], arr[j]);
  }
}
int Randomizedpartition(int arr[], int l, int h) {
  int firsthigh, p, i;

  srand(time(NULL));
  p = l + rand() % (h - l);
  swap(arr[p], arr[l]);
  return partition(arr, l, h);
}
void RandomizedQuickSort(int arr[], int l, int r) {
  int p;
  if ((r - l) > 0) {
    p = Randomizedpartition(arr, l, r);
    RandomizedQuickSort(arr, l, p);
    RandomizedQuickSort(arr, p + 1, r);

  } else {
    return;
  }
}
void print_arr(int array[], int n) {

  for (int i = 0; i < n; ++i) {
    cout << array[i] << " ";
  }

  std::cout << std::endl;
}
int main(int argc, char const *argv[]) {

  int array[] = {22, 4, 5, 4, 8, 7, 8, 7, 8, 9, 10, 1, 0, 22};
  int n = sizeof(array) / sizeof(array[0]);
  print_arr(array, n);
  RandomizedQuickSort(array, 0, n - 1);
  print_arr(array, n);
}