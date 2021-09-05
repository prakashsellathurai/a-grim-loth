/**
 * @file is-shuffle-of-two-strings.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
    Suppose you are given three strings of characters: X, Y , and Z, where
    |X| = n, |Y | = m, and |Z| = n + m. Z is said to be a shuffle of X and Y iff
    Z can be formed by interleaving the characters from X and Y in a way that
    maintains the left-to-right ordering of the characters from each string.
    (a) Show that cchocohilaptes is a shuffle of chocolate and chips, but
 chocochilatspe is not.
    (b) Give an efficient dynamic programming algorithm that
 determines whether Z is a shuffle of X and Y . (Hint: the values of the dynamic
 programming matrix you construct should be Boolean, not numeric.)
 * @version 0.1
 * @date 2021-08-26
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
using namespace std;

int isInterleave(string X, string Y, string Z) {
  int n = X.size();
  int m = Y.size();

  bool dp[n + 1][m + 1];


  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
    
     if(i==0 && j==0){
         dp[i][j] = true;
     }else if (i==0) {
         dp[i][j] = dp[i][j-1] && Y[j-1] == Z[i+j-1];
     } else if (j==0) {
         dp[i][j] = dp[i-1][j] && X[i-1] == Z[i+j-1];
     }else {
         dp[i][j] = dp[i][j-1] && Y[j-1] == Z[i+j-1] ||
                    dp[i-1][j] && X[i-1] == Z[i+j-1];
     }
    }
  }

  return dp[n][m];
}

int main(int argc, const char **argv) {
  string X = "chocolate", Y = "chips", Z = "cchocohilaptes",
         Z1 = "chocochilatspe";

  cout << isInterleave(X, Y, Z) << endl;
  cout << isInterleave(X, Y, Z1) << endl;

  return 0;
}