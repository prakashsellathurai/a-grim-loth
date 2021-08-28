/**
 * @file Lcs-basic.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-08-28
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string s1 = "Hellollworld", s2 = "Hello";
  int M = s1.length();
  int N = s2.length();
  int m[M + 1][N + 1];

  for (int i = 0; i <= M; i++) {
    for (int j = 0; j <= N; j++) {
      if (i == 0 || j == 0) {
        m[i][j] = 0;
        continue;
      }
      if (s1[i] == s2[j])
        m[i][j] = 1 + m[i - 1][j - 1];
      else
        m[i][j] = max(m[i][j - 1], m[i - 1][j]);
    }
  }

  string str;

  int i = M, j = N;

  while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) {
      str.push_back(s1[i - 1]);
      i--;
      j--;
    } 
    else if (m[i][j - 1] < m[i - 1][j]) {
      str.push_back(s2[j - 1]);
      j--;
    } else {
      
      i--;
    }
  }
  reverse(str.begin(), str.end());
  std::cout << "Longest common subsequence : " << str << " " << m[M][N]
            << std::endl;
}