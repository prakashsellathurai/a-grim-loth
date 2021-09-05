/**
 * @file poker-chips.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief


 Suppose you are given n poker chips stacked in two stacks, where the edges
of all chips can be seen. Each chip is one of three colors. A turn consists of
choosing a color and removing all chips of that color from the tops of the
stacks. The goal is to minimize the number of turns until the chips are gone.
For example, consider the stacks (RRGG, GBBB). Playing red, green, and
then blue suffices to clear the stacks in three moves. Give an O(n2) dynamic
programming algorithm to find the best strategy for a given pair of chip piles.
 * @version 0.1
 * @date 2021-08-28
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <string>

#define MAXLEN 101 /* longest possible string */

/* [[[ editdistance_mid_cut */
#define MATCH 0  /* enumerated type symbol for match */
#define INSERT 1 /* enumerated type symbol for insert */
#define DELETE 2 /* enumerated type symbol for delete */

/* [[[ editdistance_cell_struct_cut */
typedef struct {
  int cost;   /* cost of reaching this cell */
  int parent; /* parent cell */
} cell;
/* ]]] */

/*    For normal edit distance computation  */

cell m[MAXLEN + 1][MAXLEN + 1];

void goal_cell(std::string s, std::string t, int *i, int *j) {
  *i = s.length() - 1;
  *j = t.length() - 1;
}

int match(char c, char d) {
  if (c == d) {
    return (0);
  }
  return (1);
}
int indel(char c) { return (1); }
void row_init(int i, cell m[MAXLEN + 1][MAXLEN + 1]) {
  m[0][i].cost = i;
  if (i > 0) {
    m[0][i].parent = INSERT;
  } else {
    m[0][i].parent = -1;
  }
}

void column_init(int i, cell m[MAXLEN + 1][MAXLEN + 1]) {
  m[i][0].cost = i;
  if (i > 0) {
    m[i][0].parent = DELETE;
  } else {
    m[0][i].parent = -1;
  }
}

void match_out(std::string s, std::string t, int i, int j) {
  if (s[i] == t[j]) {
    printf("M");
  } else {
    printf("S ");
    std::cout<< s[i] << " " ;
  }
}

void insert_out(std::string t, int j) { printf("I"); }

void delete_out(std::string s, int i) { printf("D"); }

/* [[[ reconstruct_path_ed_cut */
void reconstruct_path(std::string s, std::string t, int i, int j,
                      cell m[MAXLEN + 1][MAXLEN + 1]) {
  if (m[i][j].parent == -1) {
    return;
  }

  if (m[i][j].parent == MATCH) {
    reconstruct_path(s, t, i - 1, j - 1, m);
    match_out(s, t, i, j);
    return;
  }

  if (m[i][j].parent == INSERT) {
    reconstruct_path(s, t, i, j - 1, m);
    insert_out(t, j);
    return;
  }

  if (m[i][j].parent == DELETE) {
    reconstruct_path(s, t, i - 1, j, m);
    delete_out(s, i);
    return;
  }
}
using namespace std;

void bestStrategy(string S1, string S2) {

  int i, j, k;
  int opt[3];

  for (i = 0; i <= MAXLEN; i++) {
    row_init(i, m);
    column_init(i, m);
  }

  for (i = 1; i < S1.length(); i++) {
    for (j = 1; j < S1.length(); j++) {
      opt[MATCH] = m[i - 1][j - 1].cost + match(S1[i], S2[j]);
      opt[INSERT] = m[i][j - 1].cost + indel(S2[j]);
      opt[DELETE] = m[i - 1][j].cost + indel(S1[i]);

      m[i][j].cost = opt[MATCH];
      m[i][j].parent = MATCH;
      for (k = INSERT; k <= DELETE; k++) {
        if (opt[k] < m[i][j].cost) {
          m[i][j].cost = opt[k];
          m[i][j].parent = k;
        }
      }
    }
  }
  goal_cell(S1, S2, &i, &j);

  cout << (m[i][j].cost) << endl;
  reconstruct_path(S1, S2, i, j, m);
}

int main(int argc, const char **argv) {
  string S1 = "RRGG", S2 = "GBBB";
  bestStrategy(S1, S2);
  return 0;
}