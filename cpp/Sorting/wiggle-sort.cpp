//  Given an unsorted array {\displaystyle A}{\displaystyle A}, reorder it such
//  that {\displaystyle A[0]<A[1]>A[2]<A[3]....}{\displaystyle
//  A[0]<A[1]>A[2]<A[3]....} For example, one possible answer for input [3, 1,
//  4, 2, 6, 5] is [1, 3, 2, 5, 4, 6]. Can you do it in {\displaystyle
//  O(n)}{\displaystyle O(n)} time using only {\displaystyle O(1)}{\displaystyle
//  O(1)} space?

#include <algorithm>
#include <iostream>
#include <iterator>
#include <type_traits>
#include <vector>

using namespace std;

// A simple function to find median of arr[]. This is called
// only for an array of size 5 in this program.
int findMedian(int arr[], int n) {
  sort(arr, arr + n); // Sort the array
  return arr[n / 2];  // Return middle element
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// It searches for x in arr[l..r], and partitions the array
// around x.
int partition(int arr[], int l, int r, int x) {
  // Search for x in arr[l..r] and move it to end
  int i;
  for (i = l; i < r; i++)
    if (arr[i] == x)
      break;
  swap(&arr[i], &arr[r]);

  // Standard partition algorithm
  i = l;
  for (int j = l; j <= r - 1; j++) {
    if (arr[j] <= x) {
      swap(&arr[i], &arr[j]);
      i++;
    }
  }
  swap(&arr[i], &arr[r]);
  return i;
}
// Returns k'th smallest element in arr[l..r] in worst case
// linear time. ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT
int kthSmallest(int arr[], int l, int r, int k) {
  // If k is smaller than number of elements in array
  if (k > 0 && k <= r - l + 1) {
    int n = r - l + 1; // Number of elements in arr[l..r]

    // Divide arr[] in groups of size 5, calculate median
    // of every group and store it in median[] array.
    int i, median[(n + 4) / 5]; // There will be floor((n+4)/5) groups;
    for (i = 0; i < n / 5; i++)
      median[i] = findMedian(arr + l + i * 5, 5);
    if (i * 5 < n) // For last group with less than 5 elements
    {
      median[i] = findMedian(arr + l + i * 5, n % 5);
      i++;
    }

    // Find median of all medians using recursive call.
    // If median[] has only one element, then no need
    // of recursive call
    int medOfMed =
        (i == 1) ? median[i - 1] : kthSmallest(median, 0, i - 1, i / 2);

    // Partition the array around a random element and
    // get position of pivot element in sorted array
    int pos = partition(arr, l, r, medOfMed);

    // If position is same as k
    if (pos - l == k - 1)
      return arr[pos];
    if (pos - l > k - 1) // If position is more, recur for left
      return kthSmallest(arr, l, pos - 1, k);

    // Else recur for right subarray
    return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
  }

  // If k is more than number of elements in array
  return INT_MAX;
}

int mapindex(int p, int n) { return ((1 + (2 * p)) % (n | 1)); }

int A(int i, int n) { return (2 * i + 1) % (n | 1); }

void wiggleSort(int nums[], int n) {
  int m = (n + 1) >> 1;
  int median = kthSmallest(nums, 0, n - 1, m);

  for (int i = 0, j = 0, k = n - 1; j <= k;) {
    if (nums[A(j, n)] > median) {
      swap(nums[A(i++, n)], nums[A(j++, n)]);
    } else if (nums[A(j, n)] < median) {
      swap(nums[A(j, n)], nums[A(k--, n)]);
    } else {
      j++;
    }
  }
}

void print_vector(int v[], int n) {
  cout << "[";
  for (int i = 0; i < n; i++) {
    cout << v[i] << ", ";
  }
  cout << "]" << endl;
}
int main(int argc, char const *argv[]) {

  int arr[] = {3, 1, 4, 2, 6, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  print_vector(arr, n);
  wiggleSort(arr, n);
  print_vector(arr, n);

  return 0;
}
