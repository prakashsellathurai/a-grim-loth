/**
 * @file bellman-ford.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief Bellman-Ford shortest path algorithm in O(V^2) time.
 * @version 0.1
 * @date 2021-07-26
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Vertex structure
 *
 */
struct Vertex {
  int id;
  int distance;
  int previous;
};

/**
 * @brief Graph structure
 *
 */
struct Graph {
  int V;
  vector<Vertex> graph;
};

/**
 * @brief Bellman-Ford shortest path algorithm in O(V^2) time.
 *
 * @param graph - Graph object.
 * @param source - Source vertex.
 * @return - True if the algorithm is successful, false otherwise.
 */
bool bellman_ford(Graph graph, Vertex source) {
  int V = graph.V;
  int i, j;
  bool flag = true;
  Vertex temp;
  for (i = 0; i < V; i++) {
    for (j = 0; j < V; j++) {
      if (graph.graph[j].distance >
          graph.graph[j].distance + graph.graph[j].previous) {
        flag = false;
        break;
      }
    }
    if (flag == false) {
      break;
    }
  }
  if (flag == true) {
    return true;
  } else {
    return false;
  }
}

int main(int argc, const char **argv) {
  Graph graph;
  Vertex source;
  int V, i;
  V = 5;
  graph.V = V;
  graph.graph.resize(V);
  graph.graph[0].id = 0;
  graph.graph[0].distance = 0;
  graph.graph[0].previous = -1;
  graph.graph[1].id = 1;
  graph.graph[1].distance = 6;
  graph.graph[1].previous = 0;
  graph.graph[2].id = 2;
  graph.graph[2].distance = 5;
  graph.graph[2].previous = 1;
  graph.graph[3].id = 3;
  graph.graph[3].distance = 3;
  graph.graph[3].previous = 2;
  graph.graph[4].id = 4;
  graph.graph[4].distance = 2;
  graph.graph[4].previous = 3;
  source.id = 0;
  source.distance = 0;
  source.previous = -1;
  if (bellman_ford(graph, source)) {
    cout << "Graph is an acyclic graph." << endl;
  } else {
    cout << "Graph is not an acyclic graph." << endl;
  }

  return 0;
}