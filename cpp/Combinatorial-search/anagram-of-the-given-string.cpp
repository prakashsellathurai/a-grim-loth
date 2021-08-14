/**
* @file anagram-of-the-given-string.cpp
* @author prakash (prakashsellathurai@gmail.com)
* @brief
    An anagram is a rearrangement of the letters in a given string into a
sequence of dictionary words. Propose an algorithm to construct all the anagrams
of a given string.
* @version 0.1
* @date 2021-08-10
*
* @copyright Copyright (c) 2021
*
*/

#include <cassert>
#include <iostream>
#include <string>

using namespace std;

int steps = 0;
void backtracking(string &s, int n, int k) {
  if (k == n) {
    steps++;
    cout << s << endl;
    return;
  }
  if (k > n)
    return;

  for (int i = k; i < n; i++) {
    swap(s[k], s[i]);
    backtracking(s, n, k + 1);
    swap(s[k], s[i]);
  }
}

void generate_anagram(string &s) {
  int n = s.size();
  int k = 0;
  backtracking(s, n, k);
}
int factorial(int n) {
  if (n <= 1)
    return 1;
  return n * factorial(n - 1);
}

int main(int argc, const char **argv) {
  string s = "prakash";
  generate_anagram(s);

  assert(steps == factorial(s.size()));

  return 0;
}