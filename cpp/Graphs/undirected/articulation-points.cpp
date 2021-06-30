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
#include <string>
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
  vector<int> reachable_ancestor;
  vector<int> tree_out_degree;

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
    reachable_ancestor.resize(V + 1);
    tree_out_degree.resize(V + 1);

    fill(discovered.begin(), discovered.end(), false);
    std::fill(std::begin(parent), std::end(parent), -1);
    for (auto edge : edges) {
      insert_edge(edge.src, edge.desc);
    }
  }

  void insert_edge(int x, int y) {
    adjList[x].push_back(y);
    adjList[y].push_back(x);
  }

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
    reachable_ancestor[vertex] = vertex;

    // std::cout << "Early Vertex Process : " << vertex
    //           << " time : " << entry_time[vertex] << std::endl;
  }
  std::string edge_classification(int u, int v) {
    if (parent[u] != v) {
      return "BACK";
    } else {
      return "TREE";
    }
  }
  void process_edge(int u, int v) {
    std::string edge_class = edge_classification(u, v);
    if (edge_class == "TREE")
      tree_out_degree[u] = tree_out_degree[u] + 1;

      

    if (edge_class == "BACK" && (parent[u] != v))
      if (entry_time[v] < entry_time[reachable_ancestor[u]])
        reachable_ancestor[u] = v;
    // std::cout << "Process  Edge : " << u << " " << v << std::endl;
  }

  void process_vertex_late(int v) {
    bool root;       /* is the vertex the root of the DFS tree? */
    int time_v;      /* earliest reachable time for v */
    int time_parent; /* earliest reachable time for parent[v] */

    if (parent[v] < 1) { /* test if v is the root */
      if (tree_out_degree[v] > 1) {
        std::cout << "root articulation vertex " << v << " " << std::endl;
      }
      return;
    }

    root = (parent[parent[v]] < 1); /* is parent[v] the root? */

    if (reachable_ancestor[v] == parent[v] && (!root)) {
      std::cout << "parent articulation vertex " << parent[v] << " "
                << std::endl;
    }

    if (reachable_ancestor[v] == v) {
      std::cout << "bridge articulation vertex " << parent[v] << " "
                << std::endl;

      if (tree_out_degree[v] > 0) { /* test if v is not a leaf */
        std::cout << "bridge articulation vertex " << v << std::endl;
      }
    }

    time_v = entry_time[reachable_ancestor[v]];
    time_parent = entry_time[reachable_ancestor[parent[v]]];

    if (time_v < time_parent) {
      reachable_ancestor[parent[v]] = reachable_ancestor[v];
    }

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
  vector<Edge_Node> edges = {{0, 1}, {1, 4}, {1, 2}, {2, 3},
                             {3, 4}, {4, 5}, {5, 3}};
  int V = 6;
  Graph graph = Graph(V, edges);
  graph.DFS(0, 0);

  return 0;
}