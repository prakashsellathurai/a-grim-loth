
#include <iostream>

using namespace std;
void merge(int arr[], int l, int m, int r) {
  int nl = m - l + 1;
  int nr = r - m;
  int lh[nl], rh[nr];

  for (int i = 0; i < nl; ++i) {
    lh[i] = arr[l + i];
  }

  for (int i = 0; i < nr; ++i) {
    rh[i] = arr[m + i + 1];
  }

  int i = 0, j = 0, k = l;
  while (i < nl && j < nr) {
    if (lh[i] <= rh[j]) {
      arr[k] = lh[i];
      i++;
    } else {
      arr[k] = rh[j];
      j++;
    }
    k++;
  }

  while (i < nl) {
    arr[k] = lh[i];
    i++;
    k++;
  }
  while (j < nr) {
    arr[k] = rh[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l >= r) {
    return;
  } else {
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
  }
}
void print_arr(int array[], int n) {

  for (int i = 0; i < n; ++i) {
    cout << array[i] << " ";
  }

  std::cout << std::endl;
}

int main(int argc, char const *argv[]) {

  int array[] = {22, 4, 5, 4, 8, 7, 8, 7, 8, 9, 10, 1, 0};
  int n = sizeof(array) / sizeof(array[0]);
  print_arr(array, n);
  mergeSort(array, 0, n - 1);
  print_arr(array, n);
  return 0;
}
