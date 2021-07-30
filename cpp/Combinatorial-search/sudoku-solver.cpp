/**
 * @file sudoku-solver.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief solve sudoku via backtracking & search pruning
 * @version 0.1
 * @date 2021-07-30
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
using namespace std;

#define DIMENSION 9                 /* 9*9 board */
#define NCELLS DIMENSION *DIMENSION /* 81 cells in 9-by-9-board */
#define MAXCANDIDATES DIMENSION     /* max digit choices per cell */

// Board type
class SudokuBoard {
private:
  int grid[DIMENSION][DIMENSION]; /* board contents */
  int freecount;                  /* open square count */
  bool finished = false;
  bool isPresentInCol(int col,
                      int num) { // check whether num is present in col or not
    for (int row = 0; row < DIMENSION; row++)
      if (grid[row][col] == num)
        return true;
    return false;
  }
  bool isPresentInRow(int row,
                      int num) { // check whether num is present in row or not
    for (int col = 0; col < DIMENSION; col++)
      if (grid[row][col] == num)
        return true;
    return false;
  }
  bool isPresentInBox(int boxStartRow, int boxStartCol, int num) {
    // check whether num is present in 3x3 box or not
    for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
        if (grid[row + boxStartRow][col + boxStartCol] == num)
          return true;
    return false;
  }
  bool isValidPlace(int row, int col, int num) {
    // when item not found in col, row and current 3x3 box
    return !isPresentInRow(row, num) && !isPresentInCol(col, num) &&
           !isPresentInBox(row - row % 3, col - col % 3, num);
  }

  bool
  findEmptyPlace(int &row,
                 int &col) { // get empty location and update row and column
    for (row = 0; row < DIMENSION; row++)
      for (col = 0; col < DIMENSION; col++)
        if (grid[row][col] == 0) // marked with 0 is empty
          return true;
    return false;
  }

  void print_board() {

    for (int row = 0; row < DIMENSION; row++) {
      for (int col = 0; col < DIMENSION; col++) {
        if (col == 3 || col == 6)
          std::cout << " | ";
        std::cout << grid[row][col] << " ";
      }
      if (row == 2 || row == 5) {
        std::cout << endl;
        for (int i = 0; i < DIMENSION; i++)
          std::cout << "---";
      }
      std::cout << endl;
    }
    std::cout << std::endl;
  }

  void make_move(int row, int col, int num) { grid[row][col] = num; }
  void unmake_move(int row, int col) { grid[row][col] = 0; }
  bool is_a_solution(int &row, int &col) {
    return !this->findEmptyPlace(row, col);
  }

  void process_solution() {
    finished = true;
    std::cout << "process solution" << std::endl;
  }

  /**
   * @brief back track to find solution
   *
   * @param a
   * @param k
   * @param board
   */
  bool backtrack() {
    int row, col;
    if (is_a_solution(row, col)) {
      process_solution();
      return true;
    } else {
      for (int num = 1; num <= DIMENSION; num++) {

        if (isValidPlace(row, col, num)) {
          steps++;
          make_move(row, col, num);
          if (backtrack() == true)
            return true;
          unmake_move(row, col);
          
        }
        if (finished)
            break;
        
      }
      
    }
    return false;
  }

public:
  int steps = 0; /* number of steps taken */
  SudokuBoard(int sample[DIMENSION][DIMENSION]) {
    int i, j;
    for (i = 0; i < DIMENSION; i++) {
      for (j = 0; j < DIMENSION; j++) {
        grid[i][j] = sample[i][j];
      }
    }
  }
  void solve() {
    if (backtrack() == true) {
      print_board();
    } else {
      std::cout << "No solution exists" << std::endl;
    }
  }
};

int main(int argc, const char **argv) {

  int grid_data[DIMENSION][DIMENSION] = 
  
  {
      {3, 0, 6, 5, 0, 8, 4, 0, 0}, {5, 2, 0, 0, 0, 0, 0, 0, 0},
      {0, 8, 7, 0, 0, 0, 0, 3, 1}, {0, 0, 3, 0, 1, 0, 0, 8, 0},
      {9, 0, 0, 8, 6, 3, 0, 0, 5}, {0, 5, 0, 0, 9, 0, 6, 0, 0},
      {1, 3, 0, 0, 0, 0, 2, 5, 0}, {0, 0, 0, 0, 0, 0, 0, 7, 4},
      {0, 0, 5, 2, 0, 6, 3, 0, 0}

  };

  SudokuBoard board(grid_data);
  board.solve();
  std::cout << "\n Steps : " << board.steps << std::endl;
  return 0;
}