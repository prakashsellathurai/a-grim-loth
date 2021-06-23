/**

 algorithm has two parts:

Figure out how many bits are necessary to store the largest array index.
Incrementally construct the index of the target value in the array by
determining whether each bit in the index should be set to 1 or 0.

Approach:

Store number of bits to represent the largest array index in variable lg.
Use lg to start off the search in a for loop.
If the element is found return pos.
Otherwise, incrementally construct an index to reach the target value in the for
loop. If element found return pos otherwise -1.
 */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int metaBinarySearch(int *Arr, int n, int key) {
  int largestArrayIndex = log2(n - 1) + 1;
  int pos = 0;

  for (int i = largestArrayIndex; i >= 0; i--) {
    if (Arr[pos] == key)
      return pos;
    int new_pos = pos | (1 << i);
    if ((new_pos < n) && (Arr[new_pos] <= key)) {
      pos = new_pos;
    }
  }

  return ((Arr[pos] == key) ? pos : -1);
}

int main(int argc, const char **argv) {
  int Arr[] = {-3, -1, -10, 10, 145, 500, 14542};
  int n = sizeof(Arr) / sizeof(Arr[0]);
  std::cout << metaBinarySearch(Arr, n, 145) << std::endl;
  return 0;
}
