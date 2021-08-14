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

int fibonacci_recursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

 int fibonacci_memoized(int n) {
     if (n == 0) {
         return 0;
     }
     if (n == 1) {
         return 1;
     }
     if (fib[n] != 0) {
         return fib[n];
     }
     fib[n] = fibonacci_memoized(n-1) + fibonacci_memoized(n-2);
     return fib[n];
 }
 int main(int argc, const char** argv) {
     int n;
     n = 30;
     
    using milli = std::chrono::milliseconds;
    auto start = std::chrono::high_resolution_clock::now();
    fibonacci_recursive(n);
    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << "recursion took "
              << std::chrono::duration_cast<milli>(finish - start).count()
              << " milliseconds\n";


    using milli = std::chrono::milliseconds;
    start = std::chrono::high_resolution_clock::now();
    fibonacci_memoized(n);
    finish = std::chrono::high_resolution_clock::now();
    std::cout << "dp took "
              << std::chrono::duration_cast<milli>(finish - start).count()
              << " milliseconds\n";


     return 0;
 }