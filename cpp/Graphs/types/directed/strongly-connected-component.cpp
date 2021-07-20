
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * @brief Directed Graph
 *
 */
class Graph {
public:
  int V;
  vector<bool> discovered;
  vector<int> parent, processed, entry_time, exit_time;
  vector<vector<int>> adjList;

  stack<int> sorted;

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
    std::cout << vertex << " ";
    // std::cout << "Early Vertex Process : " << vertex
    //           << " time : " << entry_time[vertex] << std::endl;
  }

  void process_edge(int u, int v) {
    if (edge_classification(u, v) == "BACK") {
      std::cout << "Warning: directed cycle found, not a DAG\n" << std::endl;
    }
    // std::cout << u << " " << v << " " << edge_classification(u, v) <<
    // std::endl; std::cout << "Process  Edge : " << u << " " << v << std::endl;
  }

  void process_vertex_late(int vertex) {
    sorted.push(vertex);
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
  ~Graph() {
    V = 0;
    parent.clear();
    adjList.clear();
    discovered.clear();
    entry_time.clear();
    exit_time.clear();
    processed.clear();
  }
  Graph transpose() {
    Graph gt(V + 1);
    for (int i = 0; i < V; i++) {

      if (!adjList[i].empty()) {
        for (int x : adjList[i]) {

          gt.addEdge(x, i);
        }
      }
    }
    return gt;
  }
  void strong_components() {
    for (int i = 0; i < V; i++) {
      if (!discovered[i]) {
        DFS(i, 0);
      }
    }
    std::cout << "\nStrongly Connected Components" << std::endl;
    Graph gt = transpose();
    int components_found = 0;

    while (!sorted.empty()) {
      int v = sorted.top();
      sorted.pop();
      if (!gt.discovered[v]) {
        components_found++;
        std::cout << "Component " << components_found << " : ";
        gt.DFS(v, 0);
     std::cout  << std::endl;
      }
    }
    return;
  }
};

int main(int argc, const char **argv) {
  Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
  g.strong_components();
  return 0;
}