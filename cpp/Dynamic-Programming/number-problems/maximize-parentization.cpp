/**
 * @file maximize-parentization.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 Your boss has written an arithmetic expression of n terms to compute your
annual bonus, but permits you to parenthesize it however you wish. Give an
efficient algorithm to design the parenthesization to maximize the value. For
the expression:
6+2 × 0 − 4
there exist parenthesizations with values ranging from −32 to 2.
 * @version 0.1
 * @date 2021-08-29
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <algorithm>
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <cmath>
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
    return 0;
  }
}

long long get_maximum_value(const string &exp) {
  int length = exp.size();
  int numOfnum = (length + 1) / 2;
  long long minArray[numOfnum][numOfnum];
  long long maxArray[numOfnum][numOfnum];
  memset(minArray,0,sizeof(minArray)); // initialize to 0
  memset(maxArray,0,sizeof(maxArray));
  for (int i = 0; i < numOfnum; i++)
  {
	  //The values on the main diagonal is just the number themselves
	  minArray[i][i] = std::stoll(exp.substr(2*i,1));
	  maxArray[i][i] = std::stoll(exp.substr(2*i,1));
  }

  for (int s = 0; s < numOfnum - 1; s++)
  {
	  for (int i = 0; i < numOfnum - s - 1; i++)
	  {
		  int j = i + s + 1;
		  long long minVal = LLONG_MAX;
	      long long maxVal = LLONG_MIN;
	      // find the minimum and maximum values for the expression
	      // between the ith number and jth number
		  for (int k = i; k < j; k++ )
	      {
			  long long a = eval(minArray[i][k],minArray[k + 1][j],exp[2 * k + 1]);
			  long long b = eval(minArray[i][k],maxArray[k + 1][j],exp[2 * k + 1]);
			  long long c = eval(maxArray[i][k],minArray[k + 1][j],exp[2 * k + 1]);
			  long long d = eval(maxArray[i][k],maxArray[k + 1][j],exp[2 * k + 1]);
			  minVal = min(minVal,min(a,min(b,min(c,d))));
			  maxVal = max(maxVal,max(a,max(b,max(c,d))));
	      }
		  minArray[i][j] = minVal;
		  maxArray[i][j] = maxVal;
	  }
  }

  return maxArray[0][numOfnum - 1];
}

int main() {
  string s="6+2*0-4";
  std::cout << get_maximum_value(s) << '\n';
}