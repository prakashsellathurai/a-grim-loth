#include <iostream>
#include <vector>
using namespace std;

struct Edge {
  int src, dest, weight;
};
typedef pair<int, int> Pair;

class Graph {
public:
  vector<vector<Pair>> adjList;
  int V;
  Graph(vector<Edge> const &edges, int N) {
    V = N;
    adjList.resize(N);
    for (auto &edge : edges) {
      int src = edge.src;
      int dest = edge.dest;
      int weight = edge.weight;

      adjList[src].push_back(make_pair(dest, weight));
      adjList[dest].push_back(make_pair(src, weight));
    }
  }

  void printGraph() {
    for (int i = 0; i < V; i++) {
      for (Pair v : adjList[i]) {
        cout << "(" << i << ", " << v.first << ", " << v.second << ") ";
      }
      cout << endl;
    }
  }

private:
};

int main(int argc, const char **argv) {

  vector<Edge> edges = {// `(x, y, w)` —> edge from `x` to `y` having weight `w`
                        {0, 1, 6},  {1, 2, 7}, {2, 0, 5}, {2, 1, 4},
                        {3, 2, 10}, {5, 4, 1}, {4, 5, 3}};

  int N = 6;

  Graph graph(edges, N);
  graph.printGraph();
  return 0;
}