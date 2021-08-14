/**
 * @file print-all-valid-n-pair-parentheses.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-08-04
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <string>
using namespace std;
#define MAX_N 100
void backtrack(int pos, int open, int close, int n) {
  static char str[MAX_N];

  if (close == n) {
    cout << str << endl;
    return;
  }

  if (open < n) {
    str[pos]= '(';
    backtrack(pos + 1, open+1 , close, n);
  }

  if (open > close) {
    str[pos]= ')';
    backtrack( pos + 1, open, close + 1, n);
  }
}

void print_all_valid_parenteses(int n) {
  backtrack( 0, 0, 0, n/2);
}
int main(int argc, const char **argv) {
  print_all_valid_parenteses(4);
  return 0;
}