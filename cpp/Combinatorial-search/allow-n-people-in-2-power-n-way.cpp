/**
* @file allow-n-people-in-2-power-n-way.cpp
* @author prakash (prakashsellathurai@gmail.com)
* @brief
    You start with an empty room and a group of n people waiting outside. At
    each step, you may either admit one person into the room, or let one out.
Can you arrange a sequence of 2n steps, so that every possible combination of
people is achieved exactly once?

    generate gray code of size n
* @version 0.1
* @date 2021-08-11
*
* @copyright Copyright (c) 2021
*
*/

#include <bitset>
#include <iostream>
#include <limits>
using namespace std;

// print all  gray code
void generate_each_gray_code(int n) {
  int len = 1 << n;
  // for 2^n gray codes
  for (int i = 0; i < len; i++) {
    // convert binary to gray code
    int gray_code = (i ^ i >> 1);
    // print gray code
    for (int j = 0; j < n; j++) {
      if (gray_code & (1 << j)) {
        cout << "1";
      } else {
        cout << "0";
      }
    }
    cout << endl;
  }
}
void recursive_generate_gray_code(int size,int n, int num) {
  if (n == 0) {
    // print gray code
    for (int j = 0; j < size; j++) {
      if (num & (1 << j)) {
        cout << "1";
      } else {
        cout << "0";
      }
    }
    cout << endl;
    return;
  }

  if (n < 0)
    return;

  recursive_generate_gray_code(size,n - 1, num);
  num = num ^ (1 << (n - 1));
  recursive_generate_gray_code(size,n - 1, num);
  
}

int main(int argc, const char **argv) {
  int n = 3;
  generate_each_gray_code(n);
//   recursive_generate_gray_code(n,n, 0);
  return 0;
}