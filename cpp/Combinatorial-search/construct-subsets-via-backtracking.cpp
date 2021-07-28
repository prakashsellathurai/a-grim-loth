/**
 * @file construct-subsets-via-backtracking.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-07-28
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <cmath>
#include <iostream>

using namespace std;
#define MAXCANDIDATES 1000
bool finished = false;
/**
 * @brief is a solution for subset
 *
 * @param a
 * @param k
 * @param n
 * @return int
 */
int is_a_solution(int a[], int k, int n) { return (k == n); }

/**
 * @brief construct subset candidates
 *
 * @param a
 * @param k
 * @param n
 * @param c
 * @param nc
 */
void construct_candidates(int a[], int k, int n, int c[], int *nc) {
  c[0] = true;
  c[1] = false;
  *nc = 2;
}

void process_solution(int a[], int k, int input) {
  int i;
  std::cout << "{ ";
  for (i = 1; i <= k; i++) {
    if (a[i]) {
      std::cout << i << " ";
    }
  }
  std::cout << "}" << std::endl;
}

/**
 * @brief back track routine for subsets
 *
 * @param a
 * @param k
 * @param n
 */
void back_track(int a[], int k, int n) {
  int c[MAXCANDIDATES];
  int nc;
  int i;

  if (is_a_solution(a, k, n)) {
    // finished = true;
    process_solution(a, k, n);
  } else {
    k = k + 1;
    construct_candidates(a, k, n, c, &nc);

    for (i = 0; i < nc; i++) {
      a[k] = c[i];
      back_track(a, k, n);
      if (finished)
        return;
    }
  }
}

/**
 * @brief  instantiate the call to backtrack with the right arguments
 *
 * @param n
 */
void generate_subsets(int n) {
  int a[MAXCANDIDATES];
  back_track(a, 0, n);
}
int main(int argc, const char **argv) {
  generate_subsets(3);
  return 0;
}