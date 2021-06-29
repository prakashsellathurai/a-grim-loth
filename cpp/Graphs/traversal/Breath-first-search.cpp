// BFS(G,s)
// for each vertex u ∈ V [G] − {s} do
// state[u] = “undiscovered”
// p[u] = nil, i.e. no parent is in the BFS tree
// state[s] = “discovered”
// p[s] = nil
// Q = {s}
// while Q = ∅ do
// u = dequeue[Q]
// process vertex u as desired
// for each v ∈ Adj[u] do
// process edge (u,v) as desired
// if state[v] = “undiscovered” then
// state[v] = “discovered”
// p[v] = u
// enqueue[Q,v]
// state[u] = “processed”

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
  Graph(int V, vector<Edge_Node> edges) {
    this->V = V;
    parent.resize(V + 1);
    adjList.resize(V);
    for (auto edge : edges) {
      adjList[edge.src].push_back(edge.desc);
    }
  }

  void insert_edge(int x, int y) { adjList[x].push_back(y); }

  void BFS(int source) {
    bool proceesed[V + 1];
    bool discovered[V + 1];

    for (int i = 0; i < V; i++) {
      proceesed[i] = discovered[i] = false;
      parent[i] = -1;
    }
    /*BFS starts here*/
    queue<int> q; /* queue of vertices to visit */
    int u;        /*Current vertex */
    int v;        /*successor vertex*/
    Edge_Node *p; /* temporary pointer */

    q.push(source);
    discovered[source] = true;

    while (!q.empty()) {
      u = q.front();
      q.pop();
      process_vertex_early(u);
      proceesed[u] = true;
      for (auto v : adjList[u]) {

        if (!proceesed[v]) {
          // process v
          process_edge(u, v);
        }
        if (!discovered[v]) {
          q.push(v);
          discovered[v] = true;
          parent[v] = u;
        }
      }
      process_vertex_late(u);
    }

    std::cout << std::endl;
  }

  /*
  run it only after bfs so that parent get filled
  */
  void find_paths(int u, int v) {
    std::cout << "Path from " << u << " to " << v << " : " << std::endl;
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
    std::cout << "Early Vertex Process : " << vertex << std::endl;
  }

  void process_edge(int u, int v) {
    nedges++;
    std::cout << "Process  Edge : " << u << " " << v << std::endl;
  }

  void process_vertex_late(int vertex) {
    // std::cout << "late Vertex Process : "<<  vertex << std::endl;
  }
};

int main(int argc, const char **argv) {
  vector<Edge_Node> edges = {{0, 1}, {1, 2}, {2, 3}, {2, 4},
                             {3, 5}, {4, 5}, {5, 4}};
  int V = 6;
  Graph graph = Graph(V, edges);
  graph.BFS(0);
  graph.find_paths(0, 4);
  graph.find_paths(5, 1);
  return 0;
}