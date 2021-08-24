/**
 * @file substring-search.cpp
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

#define MAX_SIZE 100
#define MATCH 0
#define INSERT 1
#define DELETE 2

typedef struct {
  int cost;
  int parent;
} cell;

int substring_matching(string T, string P) {
  int n = T.length();
  int m = P.length();

  int i, j, k;
  cell dp[n + 1][m + 1];
  int opt[3];
    int lowest_cost;
  // row init
  for (i = 0; i <= n; i++) {
    dp[i][0].cost = 0;
    dp[i][0].parent = -1;
  }
  // column init
  for (j = 0; j <= m; j++) {
   dp[0][j].cost = 0;
    dp[0][j].parent = -1;
  }
  // fill dp
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      opt[MATCH] = dp[i - 1][j - 1].cost + (T[i - 1] == P[j - 1] ? 0 : 1);
      opt[INSERT] = dp[i][j-1].cost + 1;
      opt[DELETE] = dp[i-1][j ].cost + 1;
 

      dp[i][j].cost = opt[MATCH];
      dp[i][j].parent = MATCH;

      for(k=INSERT;k<=DELETE;k++){
          if(opt[k]<dp[i][j].cost){
              dp[i][j].cost = opt[k];
              dp[i][j].parent = k;
          }
      }
   
    }
  }

  // goal cell
  i = T.length() ;
  j = 0;
  for (k = 1; k <= P.length(); k++) {
    if (dp[i][k].cost < dp[i][j].cost) {
      j = k;
    }
  }


  
  return dp[i][j].cost;
}

int main(int argc, const char **argv) {
  string T = "text";
  string P = "ext";

 cout<< substring_matching(T,P)<<endl;
 
  return 0;
}