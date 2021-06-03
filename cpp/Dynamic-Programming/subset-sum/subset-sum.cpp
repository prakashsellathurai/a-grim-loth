#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int A[] = {1, 2, 3, 4};
  int n = sizeof(A) / sizeof(A[0]);
  int M = 6;

  // Solution
  int m[M + 10];
  for (int i = 0; i < M+ 10; i++)
    m[i] = 0;
  m[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = M; j >= A[i]; j--) {
      m[j] |= m[j - A[i]];
    }
  }
  for (int i = 0; i < M+ 10; i++) {
    std::cout << m[i] << '\t';
  }
  std::cout  << std::endl;
 
    for (int i = 0; i < M+ 10; i++) {
    std::cout << i << '\t';
  }
   std::cout  << std::endl;
   std::cout << "is subset froms the sum of "<< M <<"? "<< (m[M] ? " True":" False") << std::endl;
  return 0;
}
