#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int findSquareRoot(int n, int l, int h) {
  int m = (h + l) / 2;
  int mSquared = m * m;
  if (l > h)
    return -1;

  if (mSquared == n) {
    return m;
  }
  if (mSquared <= n) {
    return findSquareRoot(n, m, h);
  } else {
    return findSquareRoot(n, l, m);
  }
}
int main(int argc, char const *argv[]) {
  int n = pow(10, 2);
  std::cout << findSquareRoot(n, 1, n) << std::endl;
  return 0;
}
