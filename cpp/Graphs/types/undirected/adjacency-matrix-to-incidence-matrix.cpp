#include <cassert>
#include <iostream>
#include <vector>


typedef std::vector<bool> matrix_row;
typedef std::vector<matrix_row> matrix; // Saves some typing

matrix adjacency_to_incidence(const matrix &adj) {
  int cols = adj.size();
  assert(cols > 0);

  int rows = adj[0].size();
  assert(rows > 0);

  assert(rows == cols);

  int edge = 0;
  matrix incidence;

  for (int col = 0; col < cols; ++col) {
    // We only look at half the adjacency matrix, so that we only add each
    // edge to the incidence matrix once.
    for (int row = 0; row <= col; ++row) {
      if (adj[col][row]) {
        incidence.push_back(matrix_row(cols, 0));
        incidence[edge][row] = incidence[edge][col] = 1;
        ++edge;
      }
    }
  }

  return incidence;
}

matrix incidence_to_adjacency(const matrix &inc) {
  int edges = inc.size();
  assert(edges > 0);

  int vertices = inc[0].size();
  assert(vertices > 0);

  matrix adjacency(vertices, matrix_row(vertices, 0));

  for (int edge = 0; edge < edges; ++edge) {
    int a = -1, b = -1, vertex = 0;
    for (; vertex < vertices && a == -1; ++vertex) {
      if (inc[edge][vertex])
        a = vertex;
    }
    for (; vertex < vertices && b == -1; ++vertex) {
      if (inc[edge][vertex])
        b = vertex;
    }
    if (b == -1)
      b = a;
    adjacency[a][b] = adjacency[b][a] = 1;
  }

  return adjacency;
}

void print_matrix(const matrix &m) {
  int cols = m.size();
  if (cols == 0)
    return;
  int rows = m[0].size();
  if (rows == 0)
    return;

  for (int c = 0; c < cols; ++c) {
    for (int r = 0; r < rows; ++r) {
      std::cout << m[c][r] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

int main() {

  // The initially given matrix. Uses C++11 initializer list.
  matrix adj = {{1, 1, 1, 0}, {1, 0, 0, 1}, {1, 0, 0, 1}, {0, 1, 1, 0}};

  matrix incidence = adjacency_to_incidence(adj);
  print_matrix(incidence);

  matrix adjacency = incidence_to_adjacency(incidence);
  print_matrix(adjacency);

  return 0;
}