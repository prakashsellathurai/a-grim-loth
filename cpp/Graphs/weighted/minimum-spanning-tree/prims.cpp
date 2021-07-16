/* minimum spanning tree  via prim's algorithm  on weighted graph */
#include <algorithm>
#include <cassert>
#include <iostream>
#include <stdint.h>
#include <vector>

using namespace std;

// MAXINT
#define MAXINT 0x7FFFFFFF
class Edge {

public:
  int from, to, w;
  Edge() {}
  Edge(int from_, int to_, int w_) : from(from_), to(to_), w(w_) {}
};


class Graph {
public:
  int V;
  vector<vector<Edge>> E;
  Graph(int V_) : V(V_), E(V_) {}
  void add_edge(int from, int to, int w) {
    E[from].push_back(Edge(from, to, w));
    E[to].push_back(Edge(to, from, w));
  }
};

/**
 * @brief Prim algorithm for minimum spanning tree
 * 
 * @param G Graph object
 * @param start integer
 * @return int 
 */
int prim(Graph &G, int start) {
  int n = G.V;
  int m = G.E.size();

  vector<bool> intree(n + 1, false);
  vector<int> distance(n + 1, 0), parent(n + 1, -1);
  vector<Edge> p;
  int v, w, dist, weight = 0;

  // init
  for (int i = 0; i < n; i++) {
    intree[i] = false;
    distance[i] = MAXINT;
    parent[i] = -1;
  }

  distance[0] = 0;
  v = start;

  while (!intree[v]) {
    intree[v] = true;
    if (v != start) {
      //   std::cout << "edge : " << parent[v] << " " << v << std::endl;
      weight = weight + dist;
    }

    for (Edge p : G.E[v]) {
      w = p.to;
      if ((distance[w] > p.w) && (!intree[w])) {
        distance[w] = p.w;
        parent[w] = v;
      }
    }

    dist = MAXINT;

    for (int i = 0; i < n; i++) {
      if ((!intree[i]) && (dist > distance[i])) {
        dist = distance[i];
        v = i;
      }
    }
  }

  return weight;
}

// test prim algorithm
int main() {
  Graph G(7);
  G.add_edge(0, 1, 4);
  G.add_edge(0, 2, 3);
  G.add_edge(1, 2, 2);
  G.add_edge(1, 3, 2);
  G.add_edge(1, 4, 4);
  G.add_edge(2, 4, 1);
  G.add_edge(3, 4, 2);
  G.add_edge(3, 5, 2);
  G.add_edge(4, 5, 3);
  G.add_edge(4, 6, 2);
  G.add_edge(5, 6, 4);

  assert(prim(G, 0) == 12);

  Graph G1(3);
  G1.add_edge(0, 1, 2);
  G1.add_edge(1, 2, 2);
  G1.add_edge(2, 0, 2);

  assert(prim(G1, 0) == 4);
  return 0;
}