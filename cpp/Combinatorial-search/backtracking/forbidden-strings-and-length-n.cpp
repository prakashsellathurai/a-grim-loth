/**
 * @file forbidden-strings-and-length-n.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
          Given an alphabet Σ, a set of forbidden strings S, and a target length n,
          give an algorithm to construct a string of length n on Σ without any element
          of S as a substring. For Σ = {0, 1}, S = {01, 10}, and n = 4, the two possible
          solutions are 0000 and 1111. For S = {0, 11} and n = 4, no such string exists
 * @version 0.1
 * @date 2021-08-06
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int steps = 0;
bool is_a_solution(string &candidate, int k, int n, vector<string> S) {

  if (k == n) {
    return true;
  } else {

    return false;
  }
}

void backtrack(string &candidate, int k, int n, vector<string> alphabet,
               vector<string> S, bool withprune) {
  steps += 1;
  if (is_a_solution(candidate, k, n, S)) {
    cout << (string)candidate << endl;
    return;
  }
  if (k >= n) {
    return;
  }

  for (auto str : alphabet) {
    for (auto chr : str) {
      candidate.push_back(chr);
      bool is_a_go = true;
      if (withprune) {
        for (auto forbidden : S) {
          if ((candidate.find(forbidden) != string::npos)) {
            is_a_go = false;
            break;
          }
        }
      }

      if (is_a_go) {
        backtrack(candidate, k + 1, n, alphabet, S, withprune);
      }

      candidate.pop_back();
    }
  }
}

int main(int argc, const char **argv) {
  vector<string> alphabet = {"0", "1"};
  vector<string> S = {"01", "10"};
  int n = 4;
  string candidate = "";
  backtrack(candidate, 0, n, alphabet, S, false);
  cout << "naive backtrack steps taken " << steps << endl;

  steps = 0;
  alphabet = {"0", "1"};
  S = {"01", "10"};
  n = 4;
  candidate = "";
  backtrack(candidate, 0, n, alphabet, S, true);
  cout << "(with pruning) steps taken " << steps << endl;

  return 0;
}