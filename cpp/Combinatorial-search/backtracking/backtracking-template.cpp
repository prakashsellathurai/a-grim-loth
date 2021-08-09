/**
 * @file backtracking.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief Backtracking constructs a tree of partial solutions,
    where each node represents a partial solution

 * @version 0.1
 * @date 2021-07-27
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
using namespace std;
#define MAXCANDIDATES 100

bool finished = false;

/**
 * @brief Custom Data
 * 
 */
typedef struct Data {
  int value;
  int index;
  Data(int v, int i) : value(v), index(i) {}
} Data;

// is_a_solution
bool is_a_solution(int a[], int k, Data input) {
  return true;
}

// process solution
void process_solution(int a[], int k, Data input) {

}

//construct_candiadtes
void construct_candidates(int a[], int k, Data input, int c[], int n) {

}

//make_move
void make_move(int a[], int k, Data input){

}

void unmake_move(int a[], int k, Data input){

}

/**
 * @brief backtracking function
 * 
 * @param a 
 * @param k 
 * @param input 
 */
void backtrack(int a[], int k, Data input) {
  int c[MAXCANDIDATES]; /*candidate for next position*/
  int nc;               /* next position candidate count */
  int i;                /* counter */

  if (is_a_solution(a, k, input)) {
    finished = true;
    process_solution(a, k, input);
  } else {
    k = k + 1;
    construct_candidates(a, k, input, c, nc);
    for (i = 0; i < nc; i++) {
      a[k] = c[i];
      make_move(a, k, input);
      backtrack(a, k, input);
      unmake_move(a, k, input);
      if (finished) {
        return; /* terminate early */
      }
    }
  }
}

int main(int argc, const char **argv) {
  /*code here*/
  return 0;
}