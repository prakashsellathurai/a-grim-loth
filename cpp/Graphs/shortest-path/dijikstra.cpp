/**
 * @file dijikstra.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-07-20
 *
 * @copyright Copyright (c) 2021
 *

 ShortestPath-Dijkstra(G, s, t)
    known = {s}
    for each vertex v in G, dist[v] = ∞
        dist[s]=0
    for each edge (s, v), dist[v] = w(s, v)
        last = s
        while (last = t)
            select vnext, the unknown vertex minimizing dist[v]
            for each edge (vnext, x), dist[x] = min[dist[x], dist[vnext] +
 w(vnext, x)] last = vnext known = known ∪ {vnext}
 */

#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <vector>
using namespace std;

class EdgeNode {
public:
  int x, y, w;
  EdgeNode() {}
  EdgeNode(int x, int y, int w) : x(x), y(y), w(w) {}
};
class Graph {

private:
  vector<bool> intree;
  vector<int> distance, parent;

public:
  int V, E;
  vector<vector<EdgeNode>> adjList;
  // constructor
  Graph(int V) : V(V), E(0) {

    adjList.resize(V + 1);
    intree.resize(V + 1);
    distance.resize(V + 1);
    parent.resize(V + 1);

    fill(intree.begin(), intree.end(), false);
    fill(distance.begin(), distance.end(), INT_MAX);
    fill(parent.begin(), parent.end(), -1);
  }

  // function to add an edge to graph
  void addEdge(int x, int y, int w) {
    E++;
    adjList[x].push_back(EdgeNode(x, y, w));
  }

  /**
   * @brief dijikstra algorithm for weight of shortest path from source
   *
   * @param s source vertex
   * @return int
   */
  int dijikstra(int s) {
    int n = V;
    int m = adjList.size();

    vector<EdgeNode> p;
    int v, w, dist, weight = 0;

    // init
    for (int i = 0; i < n; i++) {
      intree[i] = false;
      distance[i] = INT_MAX;
      parent[i] = -1;
    }

    distance[0] = 0;
    v = s;

    while (!intree[v]) {
      intree[v] = true;
      if (v != s) {
        // std::cout << "edge : " << parent[v] << " " << v << " " << dist
        //           << std::endl;
        weight = weight + dist;
      }

      for (EdgeNode p : adjList[v]) {
        w = p.y;
        if ((distance[w] > distance[v] + p.w) && (!intree[w])) {
          distance[w] = distance[v] + p.w;
          parent[w] = v;
        }
      }

      dist = INT_MAX;

      for (int i = 0; i < n; i++) {
        if ((!intree[i]) && (dist > distance[i])) {
          dist = distance[i];
          v = i;
        }
      }
    }

    return weight;
  }

  int distance_from_s_to_t(int s, int t) {
    dijikstra(s);
    return distance[t];
  }
  void path_from_s_to_t(int s, int t) {
    int u;
    std::cout << "Path from " << s << " to " << t << std::endl;
    u = t;
    while (u != s) {
      std::cout << " " << u;
      u = parent[u];
    }
    std::cout << " " << s << std::endl;
  }
  // destructor
  ~Graph() { adjList.clear(); }
};
int main(int argc, const char **argv) {
  // create graph
  Graph g(6);
  g.addEdge(0, 1, 4);
  g.addEdge(1, 2, 3);
  g.addEdge(2, 4, 3);
  g.addEdge(4, 3, 3);
  g.addEdge(3, 2, 5);
  g.addEdge(3, 5, 5);

  // print shortest path
  int w = g.dijikstra(0);

  std::cout << "Shortest Path" << std::endl;
  cout << w << endl;
  std::cout << "Shortest parh from 0 to 5 " << g.distance_from_s_to_t(0, 4)
            << std::endl;
  g.path_from_s_to_t(0, 5);

  g.path_from_s_to_t(2, 3);
  return 0;
}
