#include <iostream>
#include <memory>
using namespace std;



void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  std::cout << std::endl;
}



void Three_way_partition(int a[], int n) {
  int start = 0, walker = 0, end = n - 1, mid = a[n / 2];
  mid = 1;// since median of 0,1,2 is 1
  while (walker <= end) {
    if (a[walker] < mid) // i.e. *red* should come before *white*
    // if(a[walker] == 0)
    {
      swap(a[start], a[walker]);
      start++;
      walker++;
    } 
    else if (a[walker] > mid) // i.e. *blue* should come after *white*
    // else if (a[walker] == 2)
    {
      swap(a[walker], a[end]);
      end--;
    } else
      walker++; // already in middle position
  }
}

int main() {
  int arr[] = {2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,0,1};
  int n = sizeof(arr) / sizeof(arr[0]);

  Three_way_partition(arr, n);

  printArray(arr, n);

  return 0;
}