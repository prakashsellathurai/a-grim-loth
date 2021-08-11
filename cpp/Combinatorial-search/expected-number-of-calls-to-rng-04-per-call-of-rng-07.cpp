/**
* @file expected-number-of-calls-to-rng-04-per-call-of-rng-07.cpp
* @author prakash (prakashsellathurai@gmail.com)
* @brief
    Use a random number generator (rng04) that generates numbers from {0, 1, 2,
    3, 4} with equal probability to write a random number generator that
    generates numbers from 0 to 7 (rng07) with equal probability. What is the
    expected number of calls to rng04 per call of rng07
* @version 0.1
* @date 2021-08-11
*
* @copyright Copyright (c) 2021
*
*/

#include <iostream>
#include <map>
#include <random>
using namespace std;

int rng04() {
  int min = 0;
  int max = 3;
  return min + (rand() * (int)(max - min) / RAND_MAX);
}

// return 0 1 2 3
int rng03() {
  while (true) {
    int i = rng04();
    if (i < 4) {
      return i;
    }
  }
}
// return 0 1 
int rng01() {
  while (true) {
    int i = rng04();
    if (i < 4) {
      return i%2;
    }
  }
}

// generate uniform numbers in 0 1 2 3 4 5 6 7
int rng07() {
  int i = rng03();
  int j = rng01();
  return i * 2 + j;
}
int main(int argc, const char **argv) {
  map<int, int> count_map;
  for (int i = 0; i < 100; i++) {
    int rng_result = rng07();
    count_map[rng_result]++;
  }
  for (auto it : count_map) {
    cout << it.first << " " << it.second << endl;
  }

  return 0;
}