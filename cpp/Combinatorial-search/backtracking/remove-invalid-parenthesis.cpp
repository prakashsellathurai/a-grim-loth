/**
* @file remove-invalid-parenthesis.cpp
* @author prakash (prakashsellathurai@gmail.com)
* @brief
    Given a string s that contains parentheses and letters, remove the minimum
    number of invalid parentheses to make the input string valid.
    (https://leetcode.com/problems/remove-invalid-parentheses/)
* @version 0.1
* @date 2021-08-13
*
* @copyright Copyright (c) 2021
*
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
  vector<string> ans;
  vector<int> delLeft;

  void getAns(string &s, string cur, int pos, int cntl, int cntr, int cnt) {
    if(cntr == 0 && cntl == 0)
      ans.push_back(cur + s.substr(pos));
    else {
      for (int tail = s.length() - cntl - cntr; pos <= tail; ++pos) {
        if (s[pos] == ')') {
          if (cntr && (cur.empty() || cur.back() != ')'))
            getAns(s, cur, pos + 1, cntl, cntr - 1, cnt);
          if (cnt == 0)
            return;
          --cnt;
          cur += ')';
        } else if (s[pos] == '(') {
          if (cntr == 0 && cntl > delLeft[pos] &&
              (cur.empty() || cur.back() != '('))
            getAns(s, cur, pos + 1, cntl - 1, cntr, cnt);
          ++cnt;
          cur += '(';
        } else
          cur += s[pos];
      }
    }
  }

public:
  vector<string> removeInvalidParentheses(string s) {
      // edge case
    if (s == "")
      return vector<string>(1, "");

    // finding the number of opening brackets to be deleted with presum technique
    int cntr = 0;
    delLeft.resize(s.length());
    delLeft[s.length() - 1] = 0;
    for (int i = s.length() - 1; i > 0; --i) {
      if (s[i] == ')')
        ++cntr, delLeft[i - 1] = delLeft[i];
      else if (s[i] == '(') {
        if (cntr)
          --cntr, delLeft[i - 1] = delLeft[i];
        else
          delLeft[i - 1] = delLeft[i] + 1;
      } else
        delLeft[i - 1] = delLeft[i];
    }
    ans.resize(0);
   

    // cntr hold how many extra closing brackets are there

    if (s[0] == '(' && cntr == 0)
      getAns(s, "", 0, delLeft[0] + 1, cntr, 0);
    else if (s[0] == '(')
      getAns(s, "", 0, delLeft[0], cntr - 1, 0);
    else if (s[0] == ')')
      getAns(s, "", 0, delLeft[0], cntr + 1, 0);
    else
      getAns(s, "", 0, delLeft[0], cntr, 0);
    return ans;
  }
};
int main(int argc, const char **argv) {
  vector<string> results = Solution().removeInvalidParentheses("()())()");
  for (auto result : results) {
    cout << result << endl;
  }
  return 0;
}