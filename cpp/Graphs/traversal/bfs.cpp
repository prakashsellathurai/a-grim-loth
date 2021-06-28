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
  int V;
  Graph(int V, vector<Edge_Node> edges) {
    this->V = V;
    adjList.resize(V);
    for (auto edge : edges) {
      adjList[edge.src].push_back(edge.desc);
    }
  }

  void insert_edge(int x, int y) { adjList[x].push_back(y); }

  void BFS(int source) {
    bool proceesed[V + 1];
    bool discovered[V + 1];
    int parent[V + 1];

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
      std::cout << u << " ";
      proceesed[u] = true;
      for (auto v : adjList[u]) {

        if (!proceesed[v]) {
          // process v
        }
        if (!discovered[v]) {
          q.push(v);
          discovered[v] = true;
          parent[v] = u;
        }
      }
    }

    std::cout << std::endl;
  }
};

int main(int argc, const char **argv) {
  vector<Edge_Node> edges = {{0, 1}, {1, 2}, {2, 3}, {2, 4},
                             {3, 5}, {4, 5}, {5, 4}};
  int V = 6;
  Graph graph = Graph(V, edges);
  graph.BFS(0);
  return 0;
}