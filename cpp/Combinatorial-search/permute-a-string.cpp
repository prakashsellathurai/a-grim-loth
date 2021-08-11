/**
 * @file permute-a-string.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
    Write a function to find all permutations of the letters in a given string.
 * @version 0.1
 * @date 2021-08-10
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <string>
using namespace std;

bool is_a_solution(int k, int n) { return (k == n); }

// prints the given string
void process_solution(string &s) { cout << s << endl; }
void backtracking(string &s, int n, int k) {
  if (is_a_solution(k, n)) {
    process_solution(s);
    return;
  }
  if (k > n)
    return;

  for (int i = k; i < n; i++) {
    swap(s[i], s[k]);
    backtracking(s, n, k + 1);
    swap(s[i], s[k]);
  }
}
void generate_all_permutations(string &s) {
  int n = s.size();
  backtracking(s, n, 0);
}
int main(int argc, const char **argv) {
  string s = "abc";
  generate_all_permutations(s);

  return 0;
}