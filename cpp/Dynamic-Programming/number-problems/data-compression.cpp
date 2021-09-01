/**
 * @file data-compression.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
    Consider the following data compression technique. We have a table of m
    text strings, each at most k in length. We want to encode a data string D of
    length n using as few text strings as possible. For example, if our table
 contains (a,ba,abab,b) and the data string is bababbaababa, the best way to
 encode it is (b,abab,ba,abab,a)—a total of five code words. Give an O(nmk)
 algorithm to find the length of the best encoding. You may assume that every
 string has at least one encoding in terms of the table.
 * @version 0.1
 * @date 2021-09-01
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char **argv) {
  string D = "bababbaababa";
  int n = D.length();

  vector<string> m = {"a", "ba", "abab", "b"};

  vector<int> L(n + 1, 0);
  vector<string> ES(n + 1);
  for (int i = 0; i <= n; i++) {
    L[i] = INT_MAX;
    ES[i] = "";
  }
  L[n] = 0;

  for (int i = n; i >= 0; i--) {
    int min_ = L[i];
    for (string str : m) {
      if (D.substr(i, i + str.length() - 1) == str) {
        if (i + str.length() <= n ) {
          min_ = 1 + L[i + str.length()];
          ES[i] = str;
        }
      }
    }

    L[i] = min(L[i], min_);
    if (L[i] == INT_MAX) {
      L[i] = L[i + 1];
    }
  }
  for (int i = 1; i <= n; i++)
    cout << L[i] << " ";

  cout << endl;
  for (int i = 1; i <= n; i++)
    if (ES[i] != "")
      cout << ES[i] << " ";
  return 0;
}