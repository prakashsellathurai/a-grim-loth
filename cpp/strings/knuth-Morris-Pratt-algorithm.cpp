

#include <iostream>
#include <ostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>

void prefix_function(std::string s, std::vector<int> &pi) {
  int m = (int)s.length();

  pi[0] = 0;

  for (int i = 1; i < m; i++) {

    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) {

      j = pi[j - 1];
    }
    if (s[i] == s[j]) {
      j++;
    }

    pi[i] = j;
  }
}
int main(int argc, const char **argv) {
  std::string T = "ABCABCDABABCDABCDABDEABCDABDABCDABD", p = "ABCDABD";

  int n = (int)T.length(), m = (int)p.length();
  std::vector<int> pi(m);
  prefix_function(p, pi);

  for (int l = 0; l < m; l++) {
    std::cout << pi[l] << '\t';
  }
  std::cout << std::endl;
  for (int i = 0; i < m; i++) {
    std::cout << p[i] << '\t';
  }
  std::cout << std::endl;

  int i = 0, j = 0;
  while (i < n) {
    if (p[j] == T[i]) {
      i++;
      j++;
    }
    if (j == m) {
      std::cout << "Found pattern at " << i - j << std::endl;
      j = pi[j - 1];
    } else if (i < n && p[j] != T[i]) {
      if (j != 0) {
        j = pi[j - 1];
      } else {
        i = i + 1;
      }
    }
  }

  return 0;
}