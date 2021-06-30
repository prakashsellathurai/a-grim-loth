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
  bool isCycledetceted = false;

  Graph(int V, vector<Edge_Node> edges) {
    this->V = V;
    parent.resize(V + 1);
    adjList.resize(V);
    discovered.resize(V);
    entry_time.resize(V);
    exit_time.resize(V);
    processed.resize(V);

    fill(discovered.begin(), discovered.end(), false);
    std::fill(std::begin(parent), std::end(parent), -1);
    for (auto edge : edges) {
      adjList[edge.src].push_back(edge.desc);
       adjList[edge.desc].push_back(edge.src);
    }
  }

  void insert_edge(int x, int y) { adjList[x].push_back(y); }

  void DFS(int u, int time) {

    if (isfinished)

      return;

    discovered[u] = true;
    time += 1;
    entry_time[u] = time;

    process_vertex_early(u);

    for (auto v : adjList[u]) {
      if (discovered[v] == false) {
        parent[v] = u;
        process_edge(u, v);
        if (isfinished)
          return;
        DFS(v, time);
      } else if (processed[v] == false) {
        process_edge(u, v);
      }
    }

    time += 1;
    process_vertex_late(u);
    processed[u] = true;
  }
  /*
  run it only after bfs so that parent get filled
  */
  void find_paths(int u, int v) {
    // std::cout << "Path from " << u << " to " << v << " : " << std::endl;
    find_pathUtil(u, v);
  }
  void find_pathUtil(int u, int v) {
    if (u == v || v == -1) {
      std::cout << u << std::endl;
    } else {
      find_pathUtil(u, parent[v]);
      std::cout << v << std::endl;
    }
  }
  void process_vertex_early(int vertex) {
    // std::cout << "Early Vertex Process : " << vertex
    //           << " time : " << entry_time[vertex] << std::endl;
  }

  void process_edge(int u, int v) {
    if ((discovered[v]) && (parent[u] != v)) {
      std::cout << "Cycle detected" << std::endl;
      find_paths(v, u);
      std::cout << std::endl;
      isCycledetceted = true;
      isfinished = true;
    }
    // std::cout << "Process  Edge : " << u << " " << v << std::endl;
  }

  void process_vertex_late(int vertex) {
    // std::cout << "late Vertex Process : " << vertex
    //           << " time : " << exit_time[vertex] << std::endl;
  }

  void printGraph() {
    for (int i = 0; i < V; i++) {
      // print the current vertex number
      cout << i << " ——> ";

      // print all neighboring vertices of a vertex `i`
      for (int v : adjList[i]) {
        cout << v << " ";
      }
      cout << endl;
    }
  }
};

int main(int argc, const char **argv) {
  vector<Edge_Node> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}};
  int V = 6;
  Graph graph = Graph(V, edges);
  graph.DFS(0, 0);
  graph.printGraph();
  std::cout << "is cycle dtected " << (graph.isCycledetceted ? "yes" : "no")
            << std::endl << std::endl << std::endl << std::endl << std::endl;

  vector<Edge_Node> edges1 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5},{5, 0}};
  int V1 = 6;
  Graph graph1 = Graph(V1, edges1);
  graph1.DFS(0, 0);
  graph1.printGraph();
    std::cout << "is cycle dtected " << (graph1.isCycledetceted ? "yes" : "no")
            << std::endl;
  return 0;
}