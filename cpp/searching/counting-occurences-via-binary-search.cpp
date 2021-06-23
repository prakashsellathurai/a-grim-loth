#include <iostream>
using namespace std;
int modifiedbinarySearch(int *arr, int key, int low, int high, bool isleft) {
  int middle;
  if (low >= high)
    return low;
  middle = (low + high) / 2;
  if (isleft) {
    if (arr[middle] < key) {
      return modifiedbinarySearch(arr, key, middle + 1, high, isleft);
    } else {
      return modifiedbinarySearch(arr, key, low, middle - 1, isleft);
    }
  } else {
    if (arr[middle] > key) {
      return modifiedbinarySearch(arr, key, low, middle - 1, isleft);

    } else {
      return modifiedbinarySearch(arr, key, middle + 1, high, isleft);
    }
  }
}
int count_occurences(int *arr, int n, int key) {
  int upper_bound = modifiedbinarySearch(arr, key, 0, n - 1, false);
  int lower_bound = modifiedbinarySearch(arr, key, 0, n - 1, true);
  int res = upper_bound - lower_bound;
  if (res == 0 && arr[lower_bound ] != key)
    return 0;
  else if (res == 0)
    return res + 1;
  else
    return res;
}

# include <bits/stdc++.h>
int improved_count(int arr[], int x, int n)
{   
  /* get the index of first occurrence of x */
  int *low = lower_bound(arr, arr+n, x);
 
  // If element is not present, return 0
  if (low == (arr + n) || *low != x)
     return 0;
    
  /* Else get the index of last occurrence of x.
     Note that we  are only looking in the
     subarray after first occurrence */  
  int *high = upper_bound(low, arr+n, x);    
    
  /* return count */
  return high - low;
}

int main(int argc, const char **argv) {
  int arr[] = {1, 2, 3, 4, 4, 4, 4, 4, 4, 5, 7, 8, 9, 19};
  int n = sizeof(arr) / sizeof(arr[0]);
  std::cout << "count of 4 in sorted list " << count_occurences(arr, n, 4)
            << std::endl;
  std::cout << "count of 5 in sorted list " << improved_count(arr, 5,n)
            << std::endl;

  return 0;
}
