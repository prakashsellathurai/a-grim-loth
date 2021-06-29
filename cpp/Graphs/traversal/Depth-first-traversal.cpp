/*
DFS(G,u)
    state[u] = “discovered”
    process vertex u if desired
    entry[u] = time
    time = time + 1
    for each v ∈ Adj[u] do
        process edge (u,v) if desired
        if state[v] = “undiscovered” then
            p[v] = u
            DFS(G,v)
    state[u] = “processed”
    exit[u] = time
    time = time + 1
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct Edge_Node {
  int src, desc;
};

class Graph {
public:
  vector<vector<int>> adjList;
  int V, nedges;
  vector<int> parent;
  vector<bool> discovered;
  vector<bool> processed;
  vector<int> entry_time, exit_time;
  bool isfinished = false;

  Graph(int V, vector<Edge_Node> edges) {
    this->V = V;
    parent.resize(V + 1);
    adjList.resize(V);
    discovered.resize(V);
    entry_time.resize(V);
    exit_time.resize(V);
    processed.resize(V);

    fill(discovered.begin(), discovered.end(), false);

    for (auto edge : edges) {
      adjList[edge.src].push_back(edge.desc);
    }
  }

  void insert_edge(int x, int y) { adjList[x].push_back(y); }

  void DFS(int u, int time) {


    if(isfinished == true) return;

    discovered[u] = true;
    time += 1;
    entry_time[u] = time;

    process_vertex_early(u);

    for (auto v : adjList[u]) {
      if (discovered[v] == false) {
        parent[v] = u;
        process_edge(u, v);
        DFS(v, time);
      } else if (processed[v] == false) {
        process_edge(u, v);
      }
    }

    time += 1;
    process_vertex_late(u);
    processed[u] = true;
  }

  void process_vertex_early(int vertex) {
    std::cout << "Early Vertex Process : " << vertex
              << " time : " << entry_time[vertex] << std::endl;
  }

  void process_edge(int u, int v) {
    std::cout << "Process  Edge : " << u << " " << v << std::endl;
  }

  void process_vertex_late(int vertex) {
    std::cout << "late Vertex Process : " << vertex
              << " time : " << exit_time[vertex] << std::endl;
  }
};

int main(int argc, const char **argv) {
  vector<Edge_Node> edges = {{0, 1}, {1, 2}, {2, 3}, {2, 4},
                             {3, 5}, {4, 5}, {5, 4}};
  int V = 6;
  Graph graph = Graph(V, edges);
  graph.DFS(0, 0);

  return 0;
}