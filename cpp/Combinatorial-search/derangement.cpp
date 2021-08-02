/**
 * @file derangement.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-08-02
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
using namespace std;
bool finished = false;
#define NMAX 10000

void construct_candidates(int a[], int k, int n, int c[], int *nc) {
  int i;              /* counter */
  bool in_perm[NMAX]; /* what is now in perm*/

  for (i = 1; i < NMAX; i++) {
    in_perm[i] = false;
  }

  for (i = 1; i < k; i++) {
    in_perm[a[i]] = true;
  }

  *nc = 0;

  for (i = 1; i <= n; i++) {
    if (!in_perm[i] && i != k) {
      c[*nc] = i;
      *nc = *nc + 1;
    }
  }
}

bool is_a_solution(int a[], int k, int n) { return (k == n); }

void process_solution(int a[], int k, int n) {
  int i;
  std::cout << "{ ";
  for (i = 1; i <= k; i++) {
    std::cout << a[i] << " ";
  }
  std::cout << "}" << std::endl;
}

void backtrack(int a[], int k, int n) {
  int i;
  int c[NMAX];
  int nc;
  if (is_a_solution(a, k, n)) {
    process_solution(a, k, n);
  } else {
    k = k + 1;
    construct_candidates(a, k, n, c, &nc);

    for (i = 0; i < nc; i++) {
      a[k] = c[i];
      backtrack(a, k, n);
    }
  }
}

void print_derangement(int n) {
  int a[NMAX];
  backtrack(a, 0, n);
}

// Function to generate derangement
int main(int argc, const char **argv) {
  print_derangement(3);
  return 0;
}