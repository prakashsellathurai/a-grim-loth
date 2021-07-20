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
  vector<bool> processed, discovered;

  Graph(int V, vector<Edge_Node> edges) {
    this->V = V;
    parent.resize(V + 1);
    adjList.resize(V);
    processed.resize(V + 1);
    discovered.resize(V + 1);

    for (int i = 0; i < V; i++) {
      processed[i] = discovered[i] = false;
      parent[i] = -1;
    }
    for (auto edge : edges) {
      insert_edge(edge.src, edge.desc);
    }
  }

  void insert_edge(int x, int y) {
    adjList[x].push_back(y);
    adjList[y].push_back(x);
  }

  void BFS(int source) {

    /*BFS starts here*/
    queue<int> q; /* queue of vertices to visit */
    int u;        /*Current vertex */
    int v;        /*successor vertex*/

    q.push(source);
    discovered[source] = true;

    while (!q.empty()) {
      u = q.front();
      q.pop();
      process_vertex_early(u);
      processed[u] = true;
      for (auto v : adjList[u]) {

        if (!processed[v]) {

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
  void process_vertex_early(int vertex) { std::cout << vertex << " "; }

  void process_edge(int u, int v) {
    // std::cout << "Process  Edge : " << u << " " << v << std::endl;
  }

  void process_vertex_late(int vertex) {
    // std::cout << "late Vertex Process : "<<  vertex << std::endl;
  }

  void connected_components() {
    int c;
    c = 0;
    for (int i = 1; i < V; i++) {
      if (discovered[i] == false) {
        c = c + 1;
        std::cout << "componenet " << c << " : ";
        BFS(i);
        std::cout << std::endl;
      }
    }
  }

  void printGraph() {
    cout << endl;
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
  vector<Edge_Node> edges = {{0, 1}, {2, 3}, {2, 4}, {3, 5}, {4, 5}, {5, 4}};
  int V = 6;
  Graph graph = Graph(V, edges);
  graph.connected_components();
  graph.printGraph();

  return 0;
}