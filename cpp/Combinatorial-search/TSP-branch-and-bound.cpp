/**
 * @file travelling-salesman-problem.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief travelling-salesman-problem using branch and bound
 * @version 0.1
 * @date 2021-08-01
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>


using namespace std;

class TSP {

public:
  int n;
  int final_res = INT_MAX;
  vector<int> final_path;
  vector<bool> visited;
  vector<vector<int>> graph;

  TSP(vector<vector<int>> input_, int n_) {
    graph = input_;
    n = n_;
    visited.resize(n, false);
    final_path.resize(n + 1, 0);
  }

  // implement travelling salesman problem
  void solve(int p) {
    int curr_path[n + 1];

    // Calculate initial lower bound for the root node
    // using the formula 1/2 * (sum of first min +
    // second min) for all edges.
    // Also initialize the curr_path and visited array
    int curr_bound = 0;
    memset(curr_path, -1, sizeof(curr_path));
    visited.resize(sizeof(curr_path), false);

    // Compute initial bound
    for (int i = 0; i < n; i++)
      curr_bound += (firstMin(graph, i) + secondMin(graph, i));
    // Rounding off the lower bound to an integer
    curr_bound = (curr_bound & 1) ? curr_bound / 2 + 1 : curr_bound / 2;

    // We start at vertex 1 so the first vertex
    // in curr_path[] is 0
    visited[0] = true;
    curr_path[0] = 0;
    TSP_Recursive(graph, curr_bound, 0, 1, curr_path);
  }
  // function that takes as arguments:
  // curr_bound -> lower bound of the root node
  // curr_weight-> stores the weight of the path so far
  // level-> current level while moving in the search
  //         space tree
  // curr_path[] -> where the solution is being stored which
  //                would later be copied to final_path[]
  void TSP_Recursive(vector<vector<int>> adj, int curr_bound, int curr_weight,
              int level, int curr_path[]) {
    // base case is when we have reached level N which
    // means we have covered all the nodes once
    if (level == n) {

      // check if there is an edge from last vertex in
      // path back to the first vertex
      if (adj[curr_path[level - 1]][curr_path[0]] != 0) {
        // curr_res has the total weight of the
        // solution we got
        int curr_res = curr_weight + adj[curr_path[level - 1]][curr_path[0]];

        // Update final result and final path if
        // current result is better.
        if (curr_res < final_res) {
          copyToFinal(curr_path);
          final_res = curr_res;
        }
      }
      return;
    }

    // for any other level iterate for all vertices to
    // build the search space tree recursively
    for (int i = 0; i < n; i++) {
      // Consider next vertex if it is not same (diagonal
      // entry in adjacency matrix and not visited
      // already)
      if (adj[curr_path[level - 1]][i] != 0 && visited[i] == false) {
        int temp = curr_bound;
        curr_weight += adj[curr_path[level - 1]][i];

        // different computation of curr_bound for
        // level 2 from the other levels
        if (level == 1)
          curr_bound -=
              ((firstMin(adj, curr_path[level - 1]) + firstMin(adj, i)) / 2);
        else
          curr_bound -=
              ((secondMin(adj, curr_path[level - 1]) + firstMin(adj, i)) / 2);

        // curr_bound + curr_weight is the actual lower bound
        // for the node that we have arrived on
        // If current lower bound < final_res, we need to explore
        // the node further
        if (curr_bound + curr_weight < final_res) {
          curr_path[level] = i;
          visited[i] = true;

          // call TSP_Recursive for the next level
          TSP_Recursive(adj, curr_bound, curr_weight, level + 1, curr_path);
        }

        // Else we have to prune the node by resetting
        // all changes to curr_weight and curr_bound
        curr_weight -= adj[curr_path[level - 1]][i];
        curr_bound = temp;

        // Also reset the visited array
        visited.resize(visited.size(), false);
        for (int j = 0; j <= level - 1; j++)
          visited[curr_path[j]] = true;
      }
    }
  }

  // Function to copy temporary solution to
  // the final solution
  void copyToFinal(int curr_path[]) {
    for (int i = 0; i < n; i++)
      final_path[i] = curr_path[i];
    final_path[n] = curr_path[0];
  }

  // print result
  void print_result() {
    cout << "Minimum Cost : " << final_res << endl;
    std::cout << "Path taken :" << std::endl;
    for (int i = 0; i < n; i++) {
      std::cout << final_path[i] << " ";
    }
    std::cout << std::endl;
  }

  // Function to find the minimum edge cost
  // having an end at the vertex i
  int firstMin(vector<vector<int>> graph, int i) {
    int min = INT_MAX;
    for (int k = 0; k < n; k++)
      if (graph[i][k] < min && i != k)
        min = graph[i][k];
    return min;
  }

  // function to find the second minimum edge cost
  // having an end at the vertex i
  int secondMin(vector<vector<int>> graph, int i) {
    int first = INT_MAX, second = INT_MAX;
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;

      if (graph[i][j] <= first) {
        second = first;
        first = graph[i][j];
      } else if (graph[i][j] <= second && graph[i][j] != first)
        second = graph[i][j];
    }
    return second;
  }
};
int main(int argc, const char **argv) {
  vector<vector<int>> graph = {
      {0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
  int n = graph.size();
  int s = 0; /* source vertex*/
  TSP tsp(graph, n);
  tsp.solve(s);
  tsp.print_result();
  return 0;
}