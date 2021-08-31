/**
 * @file max-circular-subarray-sum.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief

    Assume that there are n numbers (some possibly negative) on a circle, and
    we wish to find the maximum contiguous sum along an arc of the circle. Give
    an efficient algorithm for solving this problem.
 * @version 0.1
 * @date 2021-08-31
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char **argv) {
  vector<int> nums = {1, -2, 3, -4, 5};

  int MaxSum = nums[0], 
      CurSum = 0, 
      MinSum = nums[0], 
      CurMinSum = 0, 
      total = 0;

  for (int num : nums) {
      CurSum = max(CurSum+num,num);
      MaxSum = max(CurSum,MaxSum);

      CurMinSum = min(CurMinSum+num,num);
      MinSum = min(CurMinSum,MinSum);

      total+=num;
  }
  cout << (MaxSum > 0 ? max(MaxSum, total - MinSum) : MaxSum);
  return 0;
}