/**
* @file print-all-subset-of-given-string.cpp
* @author prakash (prakashsellathurai@gmail.com)
* @brief 
* @version 0.1
* @date 2021-08-10
* 
* @copyright Copyright (c) 2021
* 
*/

#include <iostream>
using namespace std;


void backtracking(string &str,int n,int k,string &candidate,bool choosen[]){
    if(k==n){
        cout<< "{ ";
        for(int i = 0; i < n; ++i) {
            if(choosen[i]){
                cout << candidate[i];
            }
        }
        cout<< " } ";
        cout << endl;
        
        return;
    }
    if(k>n) return;
    
    int nc = 2;
    bool c[nc];
    c[0] = true;
    c[1] = false;

    for(int i = 0; i < nc; i++) {
        candidate[k] = str[k];
        choosen[k] = c[i];
        backtracking(str,n,k+1,candidate,choosen);
    }
    
}

void print_all_subset_of_given_string(string str){
    int n = str.size();
    string candidate = new char[n];
    bool choosen[n] = {false};
    backtracking(str,n,0,candidate,choosen);
}

int main(int argc, const char** argv) {
    string S= "abc";
    print_all_subset_of_given_string(S);
    return 0;
}