/**
 * @file construct-permutation-via-backtracking.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-07-28
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
using namespace std;
#define NMAX 10000

/**
 * @brief construct candidates
 *
 * @param a
 * @param k
 * @param n
 * @param c
 * @param nc
 */
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
    if (!in_perm[i]) {      // if not in perm
      c[*nc] = i;
      *nc = *nc + 1;
    }
  }
}

/**
 * @brief process solution
 *
 * @param a
 * @param k
 * @param input
 */
void process_solution(int a[], int k, int input) {
  int i;
  std::cout << "{ ";
  for (i = 1; i <= k; i++) {
    std::cout << a[i] << " ";
  }
  std::cout << "}" << std::endl;
}

/**
 * @brief is_a_solution
 *
 * @param a
 * @param k
 * @param n
 * @return is
 */

int is_a_solution(int a[], int k, int n) { return (k == n); }

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

/**
 * @brief generate_permutations
 *
 * @param n
 */
void generate_permutations(int n) {
  int a[NMAX]; /* solution vector */
  backtrack(a, 0, n);
}
int main(int argc, const char **argv) {
  generate_permutations(3);
  return 0;
}