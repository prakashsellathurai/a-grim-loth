// C++ program to print DFS traversal from
// a given vertex in a given graph
#include <iostream>
#include <list>
#include <map>
#include <stack>
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

  void addEdge(char v, char w) {
    adjList[(int)(v - 'a')].push_back((int)(w - 'a')); // Add w to v’s list.
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
  void printStack(stack<int> S) {
    while (S.empty() == false) {
      cout << char(S.top() + 'a') << " ";
      S.pop();
    }
  }
  void top_sort() {
    for (int i = 0; i < V; i++) {
      if (!discovered[i]) {
        DFS(i, 0);
      }
    }
    printStack(sorted);
  }
};

int main() {

  Graph g(10);

  g.addEdge('a', 'b');
  g.addEdge('a', 'd');

  g.addEdge('b', 'c');
  g.addEdge('b', 'd');
  g.addEdge('b', 'e');

  g.addEdge('d', 'e');
  g.addEdge('d', 'g');

  g.addEdge('c', 'f');

  g.addEdge('e', 'g');
  g.addEdge('e', 'f');

  g.addEdge('g', 'f');
  g.addEdge('g', 'i');

  g.addEdge('i', 'j');

  g.addEdge('h', 'g');
  g.addEdge('h', 'j');
  g.addEdge('h', 'f');
  g.top_sort();

  return 0;
}
