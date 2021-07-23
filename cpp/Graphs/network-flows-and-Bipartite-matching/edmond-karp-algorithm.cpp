/**
 * @file edmond-karp-algorithm.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief edmond-karp algorithm implementation
 * @version 0.1
 * @date 2021-07-23
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define INF 100000
using namespace std;

class Graph {
public:
  int V;            // No. of vertices
  int E;            // No. of edges
  vector<vector<int>> adj; // Adjacency Lists
  int *dist;        // Distance from source
  int *parent;      // parent of i
  int source;       // source vertex
  int sink;         // sink vertex
  int max_flow;     // max flow
  int *flow;        // flow values
  int *pred;        // predecessor
  int *q;           // queue
  bool *visited;    // visited vertices

  Graph(int V) { this->V = V; }
  Graph(int V, int E, vector<vector<int>> adj) {
    this->V = V;
    this->E = E;
    this->adj = adj;
    this->dist = new int[V];
    this->parent = new int[V];
    this->flow = new int[V];
    this->pred = new int[V];
    this->q = new int[V];
    this->visited = new bool[V];
    for (int i = 0; i < V; i++) {
      dist[i] = INF;
      parent[i] = -1;
      flow[i] = 0;
      pred[i] = -1;
      visited[i] = false;
    }
  }

  ~Graph() {
    delete[] dist;
    delete[] parent;
    delete[] flow;
    delete[] pred;
    delete[] q;
    delete[] visited;
  }
  int EdmondKarp(int source, int sink) {
    max_flow = 0;
    while (BFS(source, sink)) {
      int path_flow = INF;
      for (int u = sink; u != source; u = parent[u]) {
        path_flow = min(path_flow, adj[u][parent[u]]);
      }
      for (int u = sink; u != source; u = parent[u]) {
        adj[u][parent[u]] -= path_flow;
        adj[parent[u]][u] += path_flow;
      }
      max_flow += path_flow;
    }
    return max_flow;
  }

private:
  bool BFS(int source, int sink) {
    for (int i = 0; i < V; i++) {
      dist[i] = INF;
      parent[i] = -1;
      q[i] = 0;
      visited[i] = false;
    }
    dist[source] = 0;
    q[source] = 1;
    int front = 0;
    int rear = 1;
    while (front <= rear) {
      int u = q[front++];
      visited[u] = true;
      for (int v = 0; v < V; v++) {
        if (visited[v] == false && adj[u][v] > 0 && dist[u] != INF &&
            dist[u] + adj[u][v] < dist[v]) {
          dist[v] = dist[u] + adj[u][v];
          parent[v] = u;
          q[rear++] = v;
        }
      }
    }
    return dist[sink] != INF;
  }
};

int main(int argc, const char **argv) {
  int V = 5;
  int E = 8;
  vector<vector<int>> adj = {
      {0, 2, 0, 0, 0},
      {2, 10, 4, 0, 0},
      {0, 4, 0, 6, 0},
      {0, 0, 6, 0, 8},
      {0, 0, 0, 8, 0},
  };
      
  Graph g(V, E, adj);
  int sink = 4;
  int source = 0;
  int max_flow = g.EdmondKarp(source, sink);
  std::cout << max_flow << std::endl;
  return 0;
}