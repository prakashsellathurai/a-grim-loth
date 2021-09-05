/**
 * @file data-compression.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
        Consider the following data compression technique. We have a table of m
        text strings, each at most k in length. We want to encode a data string D of
        length n using as few text strings as possible. For example, if our table
        contains (a,ba,abab,b) and the data string is bababbaababa, the best way to
        encode it is (b,abab,ba,abab,a)—a total of five code words. Give an O(nmk)
        algorithm to find the length of the best encoding. You may assume that every
        string has at least one encoding in terms of the table.
 * @version 0.1
 * @date 2021-09-01
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printTable(char **table, int k) {
  printf("Table: {%s", table[0]);
  for (int i = 1; i < k; i++) {
    printf(", %s", table[i]);
  }
  printf("}\n");
}


void printSolution(char *string, int *branchLengths, int n) {
  if (!n) {
    return;
  }
  printSolution(string, branchLengths, branchLengths[n]);
  printf("%.*s ", n - branchLengths[n], string + branchLengths[n]);
}

int *solve(char *string, char **table, int n, int m, int k, int *comparisons) {
  int *currentBranchEnds =
      (int *)calloc(sizeof(int), n); // keeps track of all of the current ends
  int currentBranchCount =
      1; // keeps track of how many active branch ends there are

  int *newBranchEnds = (int *)calloc(
      sizeof(int), n); // keeps track of the new branches on each iteration
  int newBranchCount = 0;

  int *branchLengths = (int *)calloc(
      sizeof(int), (n + 1)); // used to reconstruct the solution in the end

  // used for O(1) length lookups
  int *tableStringLengths = (int *)malloc(sizeof(int) * k);
  for (int i = 0; i < k; i++) {
    tableStringLengths[i] = strlen(table[i]);
  }

  *comparisons = 0;

  // continue searching while the entire string hasn't been encoded
  while (!branchLengths[n]) {

    // for every active branch
    for (int i = 0; i < currentBranchCount; i++) {

      // try all table strings
      for (int j = 0; j < k; j++) {
        int newBranchEnd = currentBranchEnds[i] + tableStringLengths[j];

        // if the new length (branch end) already exists OR
        // if the new branch would be too long for the string, discard the
        // branch
        *comparisons += 1;
        if (newBranchEnd > n || branchLengths[newBranchEnd]) {
          continue;
        }

        // check to see if the table string matches the target string at this
        // position could be done with strcmp, but is done in a loop here to be
        // explicit about complexity
        char match = 1;
        for (int l = 0; table[j][l]; l++) {
          *comparisons += 1;
          if (string[currentBranchEnds[i] + l] != table[j][l]) {
            match = 0;
            break;
          }
        }

        // if it matches, we can create a new branch at this position
        *comparisons += 1;
        if (match) {
          branchLengths[newBranchEnd] = currentBranchEnds[i];
          newBranchEnds[newBranchCount] = newBranchEnd;
          newBranchCount += 1;
        }
      }
    }

    // swap the branch ends arrays to save copying
    int *tmp = currentBranchEnds;
    currentBranchEnds = newBranchEnds;
    newBranchEnds = tmp;

    currentBranchCount = newBranchCount;
    newBranchCount = 0;
  }

  free(currentBranchEnds);
  free(newBranchEnds);
  free(tableStringLengths);

  return branchLengths;
}

int main() {
  int k = 4;
  int m = 4;

  char **table = (char **)malloc(sizeof(char *) * k);
  table[0] = (char *)"a";
  table[1] = (char *)"ba";
  table[2] = (char *)"abab";
  table[3] = (char *)"b";

  printTable(table, k);

  char *string = (char *)"bababbaababa";
  int n = strlen(string);
  printf("String: %s\n", string);

  int comparisons;
  int *solution = solve(string, table, n, m, k, &comparisons);
  printf("Solution: ");
  printSolution(string, solution, n);
  printf("\n");
  printf("Comparisons: %d\n", comparisons);
  


  free(table);
  free(solution);

}
