/**
 * @file floyd-all-pair-shortest-path.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-07-21
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
using namespace std;

/**
 * @brief Graph class
 *
 */
class Graph {
public:
  int V;               // No. of vertices
  int **weight;        // weight of the edge
  int **shortest_path; // shortest path matrix
  Graph(int **weight) {
    this->V = (int)(sizeof(weight) / sizeof(weight[0]));
    this->weight = weight;
    this->shortest_path = weight;
  }

  // floyd algo
  int **floyd() {

    int i, j, k;
    int through_k;

    for (k = 0; k < this->V; k++) {
      for (i = 0; i < this->V; i++) {
        for (j = 0; j < this->V; j++) {
          through_k = this->shortest_path[i][k] + this->shortest_path[k][j];
          if (through_k < this->shortest_path[i][j]) {
            this->shortest_path[i][j] = through_k;
          }
        }
      }
    }
    return shortest_path;
  }
  ~Graph() {
    delete[] weight;
    this->V = 0;
  }
};

int main(int argc, const char **argv) {
  int **weight = new int *[5];
  for (int i = 0; i < 5; i++) {
    weight[i] = new int[5];
  }
  weight[1][2] = 5;
  weight[1][3] = 8;
  weight[1][4] = -4;
  weight[2][3] = 7;
  weight[2][4] = -2;
  weight[3][4] = 3;
  Graph g(weight);
  int **shortest_path = g.floyd();
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      cout << "Shortest path between " << i << " and " << j << " is "
           << shortest_path[i][j] << endl;
    }
  }
  return 0;
}