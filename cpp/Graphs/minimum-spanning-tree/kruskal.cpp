/**
 * @file kruskal.cpp
 * @author prakash sellathurai
 * @brief minimum spanning tree using Kruskal algorithm
 * @version 0.1
 * @date 2021-07-16
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <algorithm>
#include <boost/pending/disjoint_sets.hpp>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Edge pairs are stored in a vector
 *
 */
class EdgePair {
public:
  int x, y, weight;
  EdgePair() {}
  EdgePair(int x, int y, int weight) : x(x), y(y), weight(weight) {}
};

/**
 * @brief Weighted Graph
 * 
 */
class Graph {
private:
  int V;                                // No. of vertices
  int E;                                // No. of edges
  vector<vector<pair<int, int>>> edges; // Graph represented as adjacency list

public:
  Graph(int V) : V(V+1), E(0) { edges.resize(V+1); }
  void addEdge(int v, int w, int weight) {
    edges[v].push_back(make_pair(w, weight));
    edges[w].push_back(make_pair(v, weight));
    E++;
  }

  static bool sortbysec(const EdgePair &e1, const EdgePair &e2) {
    return e1.weight < e2.weight;
  }
  vector<EdgePair> to_edgearray() {
    vector<EdgePair> res;
    for (int i = 0; i < V; i++) {
      for (auto edge : edges[i]) {
        res.push_back(EdgePair(i, edge.first, edge.second));
      }
    }
    return res;
  }

  /**
   * @brief kruskal  algorithm, for finding minimum spanning tree weight
   *
   * @return int
   */
  int kruskal() {
    int weight = 0; /*cost of minimum spanning tree*/
    vector<EdgePair> e = to_edgearray();
    sort(e.begin(), e.end(), sortbysec);
    int vectorlist[V + 1];
    int parentlist[V + 1];
    boost::disjoint_sets<int *, int *> ds(vectorlist, parentlist);
    for (int i = 0; i < V; i++) {
      ds.make_set(i);
    }

    std::cout << std::endl;
    for (auto edge:e) {
      auto u = ds.find_set(edge.x);
      auto v = ds.find_set(edge.y);
      if (u != v) {
        std::cout << "Edge : " << edge.x << " " << edge.y << std::endl;
        weight += edge.weight;
        ds.link(edge.x, edge.y);
      }
    }
    return weight;
  }
};

int main(int argc, const char **argv) {
  Graph g(5);
  g.addEdge(0, 1, 1);
  g.addEdge(1, 2, 2);
  g.addEdge(2, 3, 3);
  std::cout << "Minimum spanning tree weight is : " << g.kruskal() << std::endl;
  return 0;
}