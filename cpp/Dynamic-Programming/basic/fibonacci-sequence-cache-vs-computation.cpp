/**
 * @file fibonacci-sequence.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */


 #include <iostream>
 #include <chrono>
 using namespace std;
 int fib[500];

int fib_recursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fib_recursive(n-1) + fib_recursive(n-2);
}

 int fib_dp(int n) {
     if (n == 0) {
         return 0;
     }
     if (n == 1) {
         return 1;
     }
     if (fib[n] != 0) {
         return fib[n];
     }
     fib[n] = fib_dp(n-1) + fib_dp(n-2);
     return fib[n];
 }



 int fib_ultimate(int n) {
     int i;
     int back2 = 0,back1 = 1;
     int next;

     if(n==0) return 0;

     for(i=2;i<n;i++) {
         next = back2 + back1;
         back2 = back1;
         back1 = next;
     }
     return next;
 }


 int main(int argc, const char** argv) {
     int n;
     n = 30;
     
    using milli = std::chrono::milliseconds;
    auto start = std::chrono::high_resolution_clock::now();
    fib_recursive(n);
    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << "recursion took "
              << std::chrono::duration_cast<milli>(finish - start).count()
              << " milliseconds\n";


    using milli = std::chrono::milliseconds;
    start = std::chrono::high_resolution_clock::now();
    fib_dp(n);
    finish = std::chrono::high_resolution_clock::now();
    std::cout << "dp took "
              << std::chrono::duration_cast<milli>(finish - start).count()
              << " milliseconds\n";


       using milli = std::chrono::milliseconds;
    start = std::chrono::high_resolution_clock::now();
    fib_ultimate(n);
    finish = std::chrono::high_resolution_clock::now();
    std::cout << "dp with lessa space took "
              << std::chrono::duration_cast<milli>(finish - start).count()
              << " milliseconds\n";
    
     return 0;
 }