// Heapsort is a great sorting algorithm. It is simple to program; indeed, the
// complete implementation has been presented above. It runs in worst-case O(n
// log n) time, which is the best that can be expected from any sorting
// algorithm. It is an inplace sort, meaning it uses no extra memory over the
// array containing the elements to be sorted. Although other algorithms prove
// slightly faster in practice, you won’t go wrong using heapsort for sorting
// data that sits in the computer’s main memory.

#include <time.h>

#include <cmath>
#include <corecrt.h>
#include <cstdlib>
#include <iostream>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
using namespace std;
class MinHeap {
public:
  int n;
  int q[MAXSIZE];

  void make_fast_heap(int *arr, int n) {
    this->n = n;
    *this->q = *new int[n + 1];

    for (int i = 0; i < n; ++i)
      this->q[i + 1] = arr[i];

    for (int i = this->n; i >= 1; i--) {
      bubble_down(i);
    }
  }

  int get_parent(int i) {
    if (i == 1)
      return -1;
    else
      return (int)i / 2;
  }

  int get_young_child(int i) { return (2 * i); }
  void insert(int x) {
    this->n = this->n + 1;
    this->q[this->n] = x;
    bubble_up(this->n);
  }
  void bubble_up(int p) {

    if (get_parent(p) == -1)
      return;
    if (this->q[get_parent(p)] > this->q[p]) {
      swap(this->q[get_parent(p)], this->q[p]);
      bubble_up(get_parent(p));
    }
  }
  void bubble_down(int p) {
    int c;
    int i;
    int min_index;

    c = get_young_child(p);
    min_index = p;

    for (int i = 0; i <= 1; ++i) {
      if (c + i < this->n) {
        if (this->q[min_index] > this->q[c + i])
          min_index = c + i;
      }
    }
    if (min_index != p) {
      swap(this->q[min_index], this->q[p]);
      bubble_down(min_index);
    }
  }
  int extract_min() {
    int min = -1;
    if (this->n <= 0) {
      std::cout << "Warning: Empty Queue" << std::endl;
    } else {
      min = this->q[1];
      this->q[1] = this->q[this->n];
      this->q[this->n] = this->q[this->n - 1];
      bubble_down(1);
    }
    this->n = this->n - 1;
    return min;
  }

  void print() {

    for (unsigned i = 1; i <= this->n; ++i) {
      std::cout << this->q[i] << " ";
    }
    std::cout << std::endl;
  }

protected:
};

void heapSort(int *array, int n) {

  MinHeap pq;

  pq.make_fast_heap(array, n);
  for (int i = 0; i < n; ++i) {
    array[i] = pq.extract_min();
  }
}

int main(int argc, char const *argv[]) {

  int n = 5;
  int array[n];

  srand(time(0));
  for (unsigned i = 0; i < n; ++i) {
    array[i] = rand();
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;

  heapSort(array, n);

  std::cout << "Sorted array" << std::endl;
  for (unsigned i = 0; i < n; ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
