// C++ program to print DFS traversal from
// a given vertex in a given graph
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph {
public:
  int V;
  vector<bool> discovered;
  vector<int> parent, processed, entry_time, exit_time;
  vector<vector<int>> adjList;

  Graph(int v) {
    V = v;
    parent.resize(V + 1);
    adjList.resize(V);
    discovered.resize(V);
    entry_time.resize(V);
    exit_time.resize(V);
    processed.resize(V);
  }

  // function to add an edge to graph
  void addEdge(int v, int w) {
    adjList[v].push_back(w); // Add w to v’s list.
  }

  // DFS traversal of the vertices
  // reachable from v
  void DFS(int u, int time) {
    // Mark the current node as discovered and
    // print it
    discovered[u] = true;
    // cout << v << " ";
    time += 1;
    entry_time[u] = time;

    process_vertex_early(u);
    // Recur for all the vertices adjacent
    // to this vertex

    for (auto v : adjList[u]) {
      parent[v] = u;
      if (!discovered[v]) {
        processed[v] = v;
        process_edge(u, v);
        DFS(v, time);
      } else if (!processed[v]) {
        process_edge(u, v);
      }
    }

    time += 1;
    exit_time[u] = time;
    process_vertex_late(u);
    processed[u] = true;
  }

  void process_vertex_early(int vertex) {
    // std::cout << "Early Vertex Process : " << vertex
    //           << " time : " << entry_time[vertex] << std::endl;
  }

  void process_edge(int u, int v) {
    std::cout << u << " " << v << " " << edge_classification(u, v) << std::endl;
    // std::cout << "Process  Edge : " << u << " " << v << std::endl;
  }

  void process_vertex_late(int vertex) {
    // std::cout << "late Vertex Process : " << vertex
    //           << " time : " << exit_time[vertex] << std::endl;
  }
  string edge_classification(int x, int y) {
    if (parent[y] == x)
      return ("TREE");
    else if (discovered[y] && !processed[y])
      return ("BACK");
    else if (processed[y] && (entry_time[y] > entry_time[x]))
      return ("FORWARD");
    else if (processed[y] && (entry_time[y] < entry_time[x]))
      return ("CROSS");
    else
      cout << "Warning: unclassified edge (%d,%d)\n" << x << y;
    return " ";
  }
};

int main() {

  Graph g(6);

  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 4);
  g.addEdge(3, 5);
  g.addEdge(2, 3);

  g.DFS(0, 0);

  return 0;
}
