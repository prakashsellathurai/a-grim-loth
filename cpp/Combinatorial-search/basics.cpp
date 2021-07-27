/**
 * @file basics.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
    One million permutations means all arrangements of roughly 10 objects, but
 not more. One million subsets means all combinations of roughly 20 items, but
 not more.
 * @version 0.1
 * @date 2021-07-27
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <assert.h>
#include <cmath>
#include <iostream>

using namespace std;
typedef long long int ll;
#define MAX 100

ll factorial_table[MAX];

ll permutation(ll n) {
  if (n <= 1)
    factorial_table[n] = 1;
  factorial_table[1] = 1;
  for (ll i = 2; i <= n; i++) {
    factorial_table[i] = i * factorial_table[i - 1];
  }

  return factorial_table[n];
}

ll subsets(ll n) { return pow(2, n); }

int main(int argc, const char **argv) {

  assert(permutation(10) >= pow(10,6));
  assert(subsets(20) >= pow(10, 6));
  
  std::cout << "Assertion succeeded" << std::endl;
  return 0;
}