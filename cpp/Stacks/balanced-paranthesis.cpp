// A common problem for compilers and text editors is determining whether the
// parentheses in a string are balanced and properly nested. For example, the
// string
// ((())())() contains properly nested pairs of parentheses, which the strings
// )()( and
// ()) do not. Give an algorithm that returns true if a string contains properly
// nested and balanced parentheses, and false if otherwise. For full credit,
// identify the position of the first offending parenthesis if the string is not
// properly nested and balanced.

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(std::string S) {
  std::stack<char> brackets;
  char x;
  for (int i = 0; i < S.length(); ++i) {
    if (S[i] == '(') {
      brackets.push(S[i]);
      continue;
    }

    if (brackets.empty())
      return false;
    else if (S[i] == ')') {
      if (brackets.top() == '(') {
        brackets.pop();
        continue;
      } else
        break;
    }
  }
  return (bool)brackets.empty();
}

int main(int argc, char const *argv[]) {
  string S;
  S = "((())())()";

  std::cout << S << " is " << (isBalanced(S) ? "Balanced" : "Not Balanced")
            << std::endl;
  S = "()";
  std::cout << S << " is " << (isBalanced(S) ? "Balanced" : "Not Balanced")
            << std::endl;
  S = "(";
  std::cout << S << " is " << (isBalanced(S) ? "Balanced" : "Not Balanced")
            << std::endl;
  S = ")()(";
  std::cout << S << " is " << (isBalanced(S) ? "Balanced" : "Not Balanced")
            << std::endl;
  S = "((()))";
  std::cout << S << " is " << (isBalanced(S) ? "Balanced" : "Not Balanced")
            << std::endl;
  S = "((())))";
  std::cout << S << " is " << (isBalanced(S) ? "Balanced" : "Not Balanced")
            << std::endl;

  return 0;
}
