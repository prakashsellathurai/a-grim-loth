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
#include <vector>
using namespace std;

/**
 * @brief Graph class
 *
 */
class Graph {
public:
  int V;                             // No. of vertices
  vector<vector<int>> weight;        // weight of the edge
  vector<vector<int>> shortest_path; // shortest path matrix
  vector<vector<int>> parent;        // parent matrix

  Graph(vector<vector<int>> weight) {
    this->V = weight.size();
    this->weight = weight;
    this->shortest_path = weight;
    this->parent = weight;
    for (int i = 0; i < this->V; i++) {
      for (int j = 0; j < this->V; j++) {
        if (this->weight[i][j]) {
          this->parent[i][j] = j;
        } else {
          this->parent[i][j] = -1;
        }
      }
    }
  }

  // floyd algo
  vector<vector<int>> floyd() {

    int i, j, k;
    int through_k;

    for (k = 0; k < this->V; k++) {
      for (i = 0; i < this->V; i++) {
        for (j = 0; j < this->V; j++) {
          through_k = this->shortest_path[i][k] + this->shortest_path[k][j];
          if (through_k < this->shortest_path[i][j]) {
            this->shortest_path[i][j] = through_k;
            this->parent[i][j] = this->parent[i][k];
          }
        }
      }
    }
    return shortest_path;
  }
  void print_parent() {
    std::cout << "    ";
    for (int i = 0; i < this->V; i++) {
      std::cout << i << " ";
    }
    cout << endl;
    std::cout << "    ";
    for (int i = 0; i < this->V; i++) {
      std::cout << "- ";
    }
    cout << endl;
    for (int i = 0; i < this->V; i++) {
      std::cout << i << " | ";
      for (int j = 0; j < this->V; j++) {
        cout << this->parent[i][j] << " ";
      }
      cout << endl;
    }
  }
  // print path from a source to a destination
  void print_path(int source, int destination) {
      vector<int> path = {source};
      while (source != destination) {
          source= this->parent[source][destination];
          path.push_back(source);
      }
      for (int i = 0; i < path.size(); i++) {
          std::cout << path[i] << " ";
      }
      std::cout << endl;
  }
  // print the shortest path matrix
  void print_shortest_path() {
    std::cout << "    ";
    for (int i = 0; i < this->V; i++) {
      std::cout << i << " ";
    }
    cout << endl;
    std::cout << "    ";
    for (int i = 0; i < this->V; i++) {
      std::cout << "- ";
    }
    cout << endl;
    for (int i = 0; i < this->V; i++) {
      std::cout << i << " | ";
      for (int j = 0; j < this->V; j++) {
        cout << this->shortest_path[i][j] << " ";
      }
      cout << endl;
    }
  }

  ~Graph() {
    weight.clear();
    this->V = 0;
  }
};

int main(int argc, const char **argv) {
  vector<vector<int>> weight = {{5, 8, 2, 5, 50},
                                {8, 1, 2, 3, 7},
                                {2, 1, 3, 4, 5},
                                {5, 3, 4, 1, 2},
                                {50, 7, 5, 2, 1}};

  Graph g(weight);
  g.floyd();
  g.print_shortest_path();
 g.print_path(0, 4);
 
  return 0;
}