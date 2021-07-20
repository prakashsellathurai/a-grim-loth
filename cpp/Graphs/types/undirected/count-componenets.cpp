/* count components using dfs */
#include <cassert>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Graph {
private:
  vector<vector<int>> adj;
  vector<int> visited;
  int count;

public:
  Graph(int V, vector<pair<int, int>> edges) : visited(V, false), count(0) {
    adj.resize(V);
    for (int i = 0; i < edges.size(); i++) {
      adj[edges[i].first].push_back(edges[i].second);
      //   adj[edges[i].second].push_back(edges[i].first);
    }
  }

  int count_componenets() {
    stack<int> dfs;
    vector<int> processed(visited.size(), false);

    int count = 1;
    for (int i = 0; i < visited.size(); i++) {
      if (!visited[i]) {
        dfs.push(i);
        visited[i] = true;

        while (!dfs.empty()) {
          int v = dfs.top();
          dfs.pop();

          for (int j = 0; j < adj[v].size(); j++) {
            if (!visited[adj[v][j]]) {
              dfs.push(adj[v][j]);
              visited[adj[v][j]] = true;
            }
            if (!processed[i]) {
              count++;
              processed[i] = true;
            }
          }
        }
      }
    }
    return count;
  }
};

int main(int argc, const char **argv) {
  vector<pair<int, int>> edges = {
      {0, 1}, {1, 2}, {4, 5}, {5, 6}, {6, 7},
  };
  int V = 7;
  Graph g(V + 1, edges);

  assert(g.count_componenets() == 3);



  return 0;
}