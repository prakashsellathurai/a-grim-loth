/**
 * @file approximate-string-matching.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-08-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <ostream>
#define underline "\033[4m"
namespace Color {
enum Code {
  FG_RED = 31,
  FG_GREEN = 32,
  FG_BLUE = 34,
  FG_DEFAULT = 39,
  BG_RED = 41,
  BG_GREEN = 42,
  BG_BLUE = 44,
  BG_DEFAULT = 49
};
std::ostream &operator<<(std::ostream &os, Code code) {
  return os << "\033[" << static_cast<int>(code) << "m";
}
} // namespace Color

#include <iostream>
#include <string>
using namespace std;

#define MATCH 0
#define INSERT 1
#define SWAPS 2
#define DELETE 3
typedef struct cell {
  int cost;
  int parent;
} cell;

/*costt of insertionor deletion */
int indelCost(char a) { return 1; }
/*cost of match or mismatch */
int matchCost(char &a, char &b) {
  if (a == b) {
    return 0;
  }
  return 1;
}

int swapCost(string &a, string &b, int i, int j) {
  if (a[i] == b[j - 1] && a[i - 1] == b[j])
    return 1;
  return 10;
}

void match_out(string &a, string &b, int i, int j) {
  if (a[i] == b[j])
    cout << 'M';
  else {
    cout << 'S';
  }
}
void insert_out(string &a, string &b, int i, int j) { cout << 'I'; }
void delete_out(string &a, string &b, int i, int j) { cout << 'D'; }

void reconstruct_path(string &s, string &t, int i, int j, cell *dp[]) {
  if (dp[i][j].parent == -1) {
    return;
  }

  if (dp[i][j].parent == MATCH) {
    reconstruct_path(s, t, i - 1, j - 1, dp);
    match_out(s, t, i, j);
    return;
  }
  if (dp[i][j].parent == INSERT) {
    reconstruct_path(s, t, i, j - 1, dp);
    insert_out(s, t, i, j);
    return;
  }

  if (dp[i][j].parent == DELETE) {
    reconstruct_path(s, t, i - 1, j, dp);
    delete_out(s, t, i, j);
    return;
  }
}

/**
 * @brief recursive string compare algorithm with Time complexity O(3^n)
 *
 * @param S
 * @param T
 * @param i
 * @param j
 * @return int
 */
int string_compare_recursive(string S, string T, int i, int j) {
  int k;      /*counter*/
  int opt[4]; /* cost of three options*/
  int lowest_cost;

  // base case
  if (i == 0) {
    return j * indelCost(' ');
  }
  if (j == 0) {
    return i * indelCost(' ');
  }

  // recursive case
  opt[MATCH] =
      string_compare_recursive(S, T, i - 1, j - 1) + matchCost(S[i], S[j]);
  opt[INSERT] = string_compare_recursive(S, T, i, j - 1) + indelCost(T[j]);
  opt[DELETE] = string_compare_recursive(S, T, i - 1, j) + indelCost(S[i]);

  lowest_cost = opt[MATCH];
  for (k = MATCH; k <= DELETE; k++) {
    if (opt[k] < lowest_cost) {
      lowest_cost = opt[k];
    }
  }
  return lowest_cost;
}

int string_compare_dp(string s, string T) {
  cell dp[s.length() + 1][T.length() + 1];

  int i, j, k;
  int opt[4];

  // init row
  for (i = 0; i <= s.length(); i++) {
    dp[i][0].cost = i;
    if (i > 0) {
      dp[i][0].parent = INSERT;
    } else {
      dp[i][0].parent = -1;
    }
  }

  for (i = 0; i <= T.length(); i++) {
    dp[0][i].cost = i;
    if (i > 0) {
      dp[0][i].parent = DELETE;
    } else {
      dp[0][i].parent = -1;
    }
  }
  // fill dp
  for (i = 1; i <= s.length(); i++) {
    for (j = 1; j <= T.length(); j++) {
      opt[MATCH] = (dp[i - 1][j - 1]).cost + matchCost(s[i - 1], T[j - 1]);
      opt[INSERT] = (dp[i][j - 1]).cost + indelCost(T[j - 1]);
      if (i > 1 && j > 1) {
        opt[SWAPS] = (dp[i - 2][j - 2]).cost + swapCost(s, T, i - 1, j - 1);
      } else {
        opt[SWAPS] = INT_MAX;
      }

      opt[DELETE] = (dp[i - 1][j]).cost + indelCost(s[i - 1]);

      (dp[i][j]).cost = opt[MATCH];
      (dp[i][j]).parent = MATCH;

      for (k = INSERT; k <= DELETE; k++) {
        if (opt[k] < (dp[i][j]).cost) {
          (dp[i][j]).cost = opt[k];
          (dp[i][j]).parent = k;
        }
      }
    }
  }
  return dp[s.length()][T.length()].cost;
}

/*visulaize dp*/
void visulaize_dp_and_recosntruct_path(string S, string T) {
  int n = S.length(), m = T.length();
  cell dp[n + 1][m + 1];
  int i, j, k;
  int opts[4];
  int lowest_cost;

  for (i = 0; i <= n; i++) {
    dp[i][0].cost = i;
    if (i > 0) {
      dp[i][0].parent = INSERT;
    } else {
      dp[i][0].parent = -1;
    }
  }

  for (i = 0; i <= m; i++) {
    dp[0][i].cost = i;
    if (i > 0) {
      dp[0][i].parent = DELETE;
    } else {
      dp[0][i].parent = -1;
    }
  }

  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      opts[MATCH] = dp[i - 1][j - 1].cost + matchCost(S[i - 1], T[j - 1]);
      opts[INSERT] = dp[i][j - 1].cost + indelCost(T[j - 1]);
      opts[DELETE] = dp[i - 1][j].cost + indelCost(S[i - 1]);

      dp[i][j].cost = opts[MATCH];
      dp[i][j].parent = MATCH;
      for (k = INSERT; k <= DELETE; k++) {
        if (opts[k] < dp[i][j].cost) {
          dp[i][j].cost = opts[k];
          dp[i][j].parent = k;
        }
      }
    }
  }

  lowest_cost = dp[n][m].cost;
  cout << Color::FG_DEFAULT << "lowest cost is " << lowest_cost << endl;
}
int main(int argc, const char **argv) {

  cout << string_compare_dp("thou shalt", "you should") << endl;
  cout << string_compare_dp("steve", "setve") << endl;

  return 0;
}