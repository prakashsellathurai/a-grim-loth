#include <iostream>
#include <vector>
using namespace std;

struct Edge {
  int src, dest;
};

class Graph {
public:
  vector<vector<int>> adjList;
  int nvertices = 0, nedges = 0;
  Graph(vector<Edge> const &edges, int N) {
    nvertices = N;
    adjList.resize(N);

    for (auto &edge : edges) {
      nedges++;
      adjList[edge.src].push_back(edge.dest);
      adjList[edge.dest].push_back(edge.src);
    }
  }
  Graph(Graph &&) = default;
  Graph(const Graph &) = default;
  Graph &operator=(Graph &&) = default;
  Graph &operator=(const Graph &) = default;
  ~Graph() { adjList.resize(0); };
  void insert_edge(int x, int y) {
    nedges++;
    adjList[x].push_back(y);
    adjList[x].push_back(y);
  }
  void printGraph(Graph const &graph, int N) {
    for (int i = 0; i < N; i++) {
      // print the current vertex number
      cout << i << " ——> ";

      // print all neighboring vertices of a vertex `i`
      for (int v : graph.adjList[i]) {
        cout << v << " ";
      }
      cout << endl;
    }
  }

private:
};

int main(int argc, char const *argv[]) {

  vector<Edge> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}};

  // total number of nodes in the graph
  int N = 6;

  // construct graph
  Graph graph(edges, N);
  graph.insert_edge(2, 5);
  // print adjacency list representation of a graph
  graph.printGraph(graph, N);
  return 0;
}
