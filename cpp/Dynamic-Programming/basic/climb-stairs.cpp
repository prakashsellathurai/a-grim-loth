/**
 * @file climb-stairs.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 Up to k steps in a single bound! A child is running up a staircase with n
steps and can hop between 1 and k steps at a time. Design an algorithm to
count how many possible ways the child can run up the stairs, as a function of
n and k. What is the running time of your algorithm?
 * @version 0.1
 * @date 2021-08-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
using namespace std;

int climb_stairs_with_n_space(int n) {
  int dp[n + 1];
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n];
}

int climb_stairs_with_1_space(int n){
    int curr,prev,prev2;
    prev = 1;
    prev2 = 1;

    if(n<=1){
        return prev;
    }
    for(int i=2;i<n+1;i++){
        curr = prev+prev2;
        prev2 = prev;
        prev = curr;
    }
    return curr;
}

int main(int argc, const char **argv) {
  int n = 5;
  cout << climb_stairs_with_n_space(n) << endl;
  cout << climb_stairs_with_1_space(n);
  return 0;
}