/**
 * @file kth-permutation-sequence.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */


 #include <iostream>
 #include <vector>
 using namespace std;
 
 void kthPermutationSequence(int n, int k){
     int i;
     vector<int> nums;
     for(i=1; i<=n; i++){
         nums.push_back(i);
     }
     
     vector<int> jc(n+1,1);
     for(i=1; i<=n; i++){
         jc[i] = jc[i-1]*i;
     }
     vector<int> res;
     
     for(i = 0; i < n; ++i) {
         int size = jc[n-i-1];
         int index = k % size == 0 ? k / size - 1 : k / size;;
         res.push_back(nums[index]);
         nums.erase(nums.begin()+index);
         k -= index * size;
     }
     for(i=0; i<n; i++){
         cout << res[i] << " ";
     }
     
    
 }

 int main(int argc, const char** argv) {
     int n = 3;
     int k = 5;
    kthPermutationSequence(n, k);
     return 0;
 }