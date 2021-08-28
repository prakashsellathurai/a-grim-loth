/**
* @file scs.cpp
* @author prakash (prakashsellathurai@gmail.com)
* @brief
    The longest common subsequence (LCS) of two sequences T and P is the
    longest sequence L such that L is a subsequence of both T and P. The
shortest common supersequence (SCS) of T and P is the smallest sequence L such
that both T and P are a subsequence of L.

    (a) Give efficient algorithms to find the LCS and SCS of two given
sequences. (b) Let d(T,P) be the minimum edit distance between T and P when no
    substitutions are allowed (i.e., the only changes are character insertion
    and deletion). Prove that d(T,P) = |SCS(T,P)|−|LCS(T,P)| where
    |SCS(T,P)| (|LCS(T,P)|) is the size of the shortest SCS (longest LCS)
    of T and P
* @version 0.1
* @date 2021-08-27
*
* @copyright Copyright (c) 2021
*
*/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string scs(string X, string Y) {
  int m = X.length();
  int n = Y.length();

  int dp[m + 1][n + 1];
  // Fill table in bottom up manner
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {

      if (i == 0) {
        dp[i][j] = j;
      } else if (j == 0) {
        dp[i][j] = i;
      } else if (X[i - 1] == Y[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  string str;

  int i = m, j = n;

  while (i > 0 && j > 0) {
    if (X[i - 1] == Y[j - 1]) {
      str.push_back(X[i - 1]);
      i--;j--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      str.push_back(Y[j - 1]);
      j--;
    } else {
      str.push_back(X[i - 1]);
      i--;
    }
  }

  while (i > 0) {
    str.push_back(X[i - 1]);
    i--;
  }

  while (j > 0) {
    str.push_back(Y[j - 1]);
    j--;
  }
  reverse(str.begin(),str.end());

  return str;
}

int main(int argc, const char **argv) {
  string X = "abac";
  string Y = "cab";
  cout << scs(X, Y) << endl;
  return 0;
}