/**
 * @file list-k-element-subsets-of-n-items.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief Implement an efficient algorithm for listing all k-element subsets of n items.
 * @version 0.1
 * @date 2021-08-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */


 #include <iostream>
 using namespace std;
 
 void backtracking(
     string &s,
     int n,
     int k,
     int index,
     string &candidate,
     int i){
    
     if(index == k){
         for(int j = 0; j < k; j++){
             cout << candidate[j] << " ";
         }
         cout << endl;
         return;
     }

     if(index > k) return;
     
     for(int j = i; j < n; j++){
         candidate[index] = s[j];
         backtracking(s, n, k, index+1, candidate, j+1);
     }

  
 }

void generateKsubsets(string &s,int n,int k){
    string candidate = new char[k];
    backtracking(s,n,k,0,candidate,0);
}
 int main(int argc, const char** argv) {
     string S = "abc";
     int k = 2;
     int n = S.size();
     generateKsubsets(S,n,k);
     return 0;
 }