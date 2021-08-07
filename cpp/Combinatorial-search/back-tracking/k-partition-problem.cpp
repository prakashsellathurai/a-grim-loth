/**
 * @file k-partition-problem.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
        In the k-partition problem, we need to partition a multiset of positive
 integers into k disjoint subsets that have equal sum. Design and implement an
 algorithm for solving the k-partition problem
 * @version 0.1
 * @date 2021-08-07
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

/*

******************************* Naive method *****************************
*/

// Function to check if all subsets are filled or not
bool checkSum(int sumLeft[], int k) {
  int r = true;
  for (int i = 0; i < k; i++) {
    if (sumLeft[i] != 0) {
      r = false;
      break;
    }
  }

  return r;
}

bool naive_subset_sum(const vector<int> &nums, int n, int sumLeft[], int A[],
                      int k) {
  // return true if a subset is found
  if (checkSum(sumLeft, k)) {
    return true;
  }

  // base case: no items left
  if (n < 0) {
    return false;
  }
  bool result = false;

  // consider current item `S[n]` and explore all possibilities
  // using backtracking
  for (int i = 0; i < k; i++) {
    if (!result && (sumLeft[i] - nums[n] >= 0)) {
      A[n] = i + 1;

      sumLeft[i] = sumLeft[i] - nums[n];

      result = naive_subset_sum(nums, n - 1, sumLeft, A, k);

      sumLeft[i] = sumLeft[i] + nums[n];
    }
  }
  return result;
}

/**
 * @brief 2^n - 1 naive backtracking algorithm
 *
 * @param nums
 * @param n
 * @param k
 */
void k_partition_naive(vector<int> &nums, int n, int k) {
  if (n < k) {
    cout << "K -partition of set is not possible";
    return;
  }
  int sum = accumulate(nums.begin(), nums.end(), 0);
  int A[n], sumLeft[k];

  for (int i = 0; i < k; i++) {
    sumLeft[i] = sum / k;
  }

  bool result = !(sum % k) && naive_subset_sum(nums, n - 1, sumLeft, A, k);

  if (!result) {
    cout << "K -partition of set is not possible";
    return;
  }
  // print all k–partitions
  for (int i = 0; i < k; i++) {
    cout << "Partition " << i << " is ";
    for (int j = 0; j < n; j++) {
      if (A[j] == i + 1) {
        cout << nums[j] << " ";
      }
    }
    cout << endl;
  }
}

/******************************** Bit masking
 * *******************************************************/

/**
 * @brief using bit masking
 *
 * @param nums
 * @param k
 * @return true
 * @return false
 */
bool canPartitionKSubsets(vector<int> &nums, int k) {
  int dp[(1 << 16) + 2];
  int n = nums.size(), sum = 0;
  fill(dp, dp + (1 << 16) + 2, -1);
  dp[0] = 0;
  for (int i = 0; i < n; i++)
    sum += nums[i];
  if (sum % k)
    return false;
  int tar = sum / k;

  for (int mask = 0; mask < (1 << n); mask++) {
    if (dp[mask] == -1)
      continue; // if current state is illegal, simply ignore it
    for (int i = 0; i < n; i++) {
      if (!(mask & (1 << i)) &&
          dp[mask] + nums[i] <= tar) { // if nums[i] is unchosen && choose
                                       // nums[i] would not cross the target
        dp[mask | (1 << i)] = (dp[mask] + nums[i]) % tar;
      }
    }
  }
  return dp[(1 << n) - 1] == 0;
}

/***************************** Bucket methodO(n^k)
 * ******************************/

/*
Put n items into k bucket so each bucket has same total item value.

For each bucket, try all possible content O(k*2^n) -- no good.
For each item, try all possible destined bucket O(n^k) -- doable.
*/  // put #n item of ns into some bucket to meet target
bool put(int n, int target, vector<int> ns, vector<int> bucket

) {
  for (int i = 0; i < bucket.size(); ++i) {
    if (bucket[i] + ns[n] > target)
      continue;         // try next bucket
    bucket[i] += ns[n]; // put it in!
    if (n == ns.size() - 1)
      return true; // all items in bucket, no overflow
    if (put(n + 1, target, ns, bucket))
      return true;        // move on to next item
    else {                // no solution = wrong bucket
      bucket[i] -= ns[n]; // take it out
      if (bucket[i] == 0)
        return false; // no need to try other empty bucket
    }
  }
  return false; // no bucket fits
}

bool CanPartitionKBucket(vector<int> &nums, int k) {
  int target; // of each bucket
  vector<int> ns;
  vector<int> bucket;

  int sum = 0;
  for (int &n : nums)
    sum += n;
  if (sum % k)
    return false; // not divisible
  target = sum / k;
  ns = vector<int>(nums);
  bucket = vector<int>(k, 0);
  // starting with bigger ones makes it faster
  sort(ns.begin(), ns.end());
  reverse(ns.begin(), ns.end());
  return put(0, target, ns, bucket);
}

int main(int argc, const char **argv) {
  vector<int> nums = {7, 3, 5, 12, 2, 1, 5, 3, 8, 4, 6, 4};
  ;
  int n = nums.size();
  int k = 5;

  cout << "Naive method :" << endl;
  k_partition_naive(nums, n, k);

  cout << "\nBit masking method : " << canPartitionKSubsets(nums, k) << endl;

  cout << "\nBucket method : " << CanPartitionKBucket(nums, k) << endl;
  return 0;
}
