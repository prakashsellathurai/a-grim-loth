/**
 * @file 8-queens-puzzle.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-08-01
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <vector>

using namespace std;
class EightQueensPuzzle {
public:
  int n;
  std::vector<vector<int>> board;
  vector<vector<int>> slashDiagnol, backSlashDiagnol;
  vector<bool> rowLookup, slashDiagnolLook, backslashDiagnolLook;

  EightQueensPuzzle(int n_) : n(n_) {
    board.resize(n);
    for (int i = 0; i < n; i++) {
      board[i].resize(n);
      for (int j = 0; j < n; j++) {
        board[i][j] = 0;
      }
    }

    slashDiagnol.resize(n);
    backSlashDiagnol.resize(n);
    for (int i = 0; i < n; i++) {
      slashDiagnol[i].resize(n);
      backSlashDiagnol[i].resize(n);
      for (int j = 0; j < n; j++) {
        slashDiagnol[i][j] = 0;
        backSlashDiagnol[i][j] = 0;
      }
    }
    rowLookup.resize(n, false);
    slashDiagnolLook.resize(2 * n - 1, false);
    backslashDiagnolLook.resize(2 * n - 1, false);

    // initialize helper matrices
    for (int r = 0; r < n; r++)
      for (int c = 0; c < n; c++) {
        slashDiagnol[r][c] = r + c, backSlashDiagnol[r][c] = r - c + 7;
      }
  }

  bool isSafe(int row, int col) {
    int i, j;
    /* check row */
    for (i = 0; i < n; i++) {
      if (board[row][i] == 1) {
        return false;
      }
    }
    /* check column */
    for (i = 0; i < n; i++) {
      if (board[i][col] == 1) {
        return false;
      }
    }
    /* check upper diagonal */
    for (i = row, j = col; i < n && j < n; i++, j++) {
      if (board[i][j] == 1) {
        return false;
      }
    }
    /* check lower diagonal */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
      if (board[i][j] == 1) {
        return false;
      }
    }
    return true;
  }
  bool backtrackNqueens(int col) {

    if (col >= n) {
      return true;
    }
    for (int i = 0; i < n; i++) {
      if (isSafe(i, col)) {
        board[i][col] = 1;
        if (backtrackNqueens(col + 1)) {
          return true;
        }
        board[i][col] = 0;
      }
    }
    return false;
  }
  void solve_with_backtrack() {
    if (!backtrackNqueens(0)) {
      std::cout << "No solution" << std::endl;
    } else {
      printSolution();
    }
  }

  void solve_with_branch_and_bound() {
    if (!recursion_with_branch_and_bound(0)) {
      std::cout << "No solution" << std::endl;
    } else {
      printSolution();
    }
  }

  bool isBranchandBoundPossible(int row, int col) {
    if (slashDiagnolLook[slashDiagnol[row][col]] ||
        backslashDiagnolLook[backSlashDiagnol[row][col]] || rowLookup[row])
      return false;
    else

      return true;
  }

  bool recursion_with_branch_and_bound(int col) {
    if (col >= n) {
      return true;
    }
    for (int i = 0; i < n; i++) {
      if (isBranchandBoundPossible(i, col)) {
        slashDiagnolLook[slashDiagnol[i][col]] = true;
        backslashDiagnolLook[backSlashDiagnol[i][col]] = true;
        rowLookup[i] = true;
        board[i][col] = 1;
        if (recursion_with_branch_and_bound(col + 1)) {
          return true;
        }
        slashDiagnolLook[slashDiagnol[i][col]] = false;
        backslashDiagnolLook[backSlashDiagnol[i][col]] = false;
        rowLookup[i] = false;
        board[i][col] = 0;
      }
    }
    return false;
  }

  void reset() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        board[i][j] = 0;
      }
    }
  }

  void printSolution() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << board[i][j] << " ";
      }
      cout << endl;
    }
  }
};

int main(int argc, const char **argv) {
  EightQueensPuzzle p(8);
  std::cout << "Backtracking" << std::endl;
  p.solve_with_backtrack();

  p.reset();
  std::cout << "Branch and Bound" << std::endl;
  p.solve_with_branch_and_bound();

  return 0;
}