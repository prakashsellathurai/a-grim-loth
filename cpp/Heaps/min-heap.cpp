#include <cmath>
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
  MinHeap(int *arr, int n) {
    this->n = 0;
    *this->q = *new int[n+1];
    make_heap(arr, n);
  }

  void make_heap(int *arr, int n) {

    for (unsigned i = 0; i < n; ++i) {
      insert(arr[i]);
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
    if (this->q[get_parent(p)] >= this->q[p]) {
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
      this->q[1] = this->q[this->n ];
      this->q[this->n ] = this->q[this->n -1];
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




int main(int argc, char const *argv[]) {

  int n = 5;
  int array[n];

  for (unsigned i = 0; i < n; ++i) {
    array[i] = rand();
  }

  MinHeap pq(array, n);

  pq.print();
  std::cout << "After Extract min " << pq.extract_min() << std::endl;
  pq.print();
  std::cout << "After Extract min " << pq.extract_min() << std::endl;
  pq.print();



  return 0;
}
