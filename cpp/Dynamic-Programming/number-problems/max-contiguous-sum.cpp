/**
 * @file max-contiguous-sum.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 Given an array A of n integers, find an efficient algorithm to compute the
largest sum of a continuous run. For A = [−3, 2, 7, −3, 4, −2, 0, 1], the
largest such sum is 10, from the second through fifth positions
 * @version 0.1
 * @date 2021-08-30
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, const char **argv) {
  signed int A[] = {-3, 2, 7, -3, 4, -2, 0, 1};
  int n = sizeof(A) / sizeof(A[0]);

  int maxsoFar = INT_MIN;
  int curr_max = 0;

  int start = 0,end=n-1;

  for(int i=0;i<n;i++){
     curr_max += A[i];

     if(curr_max > maxsoFar){
         maxsoFar = curr_max;
         end = i;
     }
     if(curr_max<0){
         curr_max =0;
         start = i+1;
     }
  }
  cout << maxsoFar << " from : "<<start <<", to : "<<end;

  return 0;
}