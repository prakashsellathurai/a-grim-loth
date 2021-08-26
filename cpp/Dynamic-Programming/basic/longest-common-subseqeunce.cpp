/**
 * @file longest-common-subseqeunce.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-08-17
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

#define MAXLEN 100
#define MATCH 0
#define INSERT 1
#define DELETE 2
typedef struct cell {
  int cost;
  int parent;
} cell;

/*costt of insertionor deletion */
int indelCost(char a) { return 1; }
/*cost of match or mismatch */
int matchCost(char &a, char &b) {
  if (a == b) {
    return 0;
  }
  return MAXLEN;
}

int LCS(string s, string T) {
  cell dp[s.length() + 1][T.length() + 1];

  int i, j, k;
  int opt[3];

  // init row
  for (i = 0; i <= s.length(); i++) {
    dp[i][0].cost = i;
    if (i > 0) {
      dp[i][0].parent = INSERT;
    } else {
      dp[i][0].parent = -1;
    }
  }

  for (i = 0; i <= T.length(); i++) {
    dp[0][i].cost = i;
    if (i > 0) {
      dp[0][i].parent = DELETE;
    } else {
      dp[0][i].parent = -1;
    }
  }
  // fill dp
  for (i = 1; i < s.length(); i++) {
    for (j = 1; j < T.length(); j++) {
      opt[MATCH] = (dp[i - 1][j - 1]).cost + matchCost(s[i - 1], T[j - 1]);
      opt[INSERT] = (dp[i][j - 1]).cost + indelCost(T[j - 1]);
      opt[DELETE] = (dp[i - 1][j]).cost + indelCost(s[i - 1]);

      (dp[i][j]).cost = opt[MATCH];
      (dp[i][j]).parent = MATCH;

      for (k = INSERT; k <= DELETE; k++) {
        if (opt[k] < (dp[i][j]).cost) {
          (dp[i][j]).cost = opt[k];
          (dp[i][j]).parent = k;
        }
      }
    }
  }
  int complen =  dp[s.length()-1][T.length()-1].cost;

  return (s.length() + T.length()  - complen) / 2;
}
int main(int argc, const char **argv) {
  cout << "Longest common subsequence : " << LCS("quickbrownfox", "fox")
       << endl
       << LCS("democrats","republicans");
      

  return 0;
}