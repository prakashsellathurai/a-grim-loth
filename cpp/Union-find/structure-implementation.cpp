/**
 * @file implementation.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-07-19
 *
 * @copyright Copyright (c) 2021
 * For Kruskal’s algorithm to run efficiently, we need a data structure that
efficiently supports the following operations:
• Same component(v1, v2) – Do vertices v1 and v2 occur in the same connected
component of the current graph? • Merge components(C1, C2) – Merge the given
pair of connected components into one component in response to the insertion of
an edge between them.
 */

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

// structure for union find
typedef struct {
  vector<int> parent; // parent[i] = parent of i
  vector<int> size;   // size[i] = size of the component containing i
  int n;              // number of elements in set
} UnionFind;

/**
 * @brief intializex the union find algorithm
 *
 * @param s
 * @param n
 */
void union_find_init(UnionFind *s, int n) {
  int i;
  s->parent.resize(n + 1);
  s->size.resize(n + 1);
  for (int i = 0; i < n; i++) {
    s->parent[i] = i;
    s->size[i] = 1;
  }
  s->n = n;
}

int find(UnionFind *s, int x) {
  if (s->parent[x] == x) {
    return x;
  }
  return (find(s, s->parent[x]));
}

void union_sets(UnionFind *s, int s1, int s2) {
  int r1, r2;
  r1 = find(s, s1);
  r2 = find(s, s2);

  if (r1 == r2) {
    return;
  }

  if (s->size[r1] >= s->size[r2]) {
    s->size[r1] = s->size[r1] + s->size[r2];
    s->parent[r2] = r1;
  } else {
    s->size[r2] = s->size[r1] + s->size[r2];
    s->parent[r1] = r2;
  }
}

bool same_component(UnionFind *s, int s1, int s2) {
  return (find(s, s1) == find(s, s2));
}

class UnionFindDataStructure {
public:
  int n;
  UnionFind uf;
  UnionFindDataStructure(int n_) : n(n_) { union_find_init(&uf, n); }
  void merge(int s1, int s2) { union_sets(&uf, s1, s2); }
  bool connected(int s1, int s2) { return same_component(&uf, s1, s2); }
};

int main(int argc, const char **argv) {
  UnionFindDataStructure uf(10);

  uf.merge(1, 2);
  uf.merge(3, 4);
  uf.merge(5, 6);
  uf.merge(7, 8);
  uf.merge(9, 10);
  uf.merge(1, 3);
  uf.merge(1, 5);
  uf.merge(1, 7);
  uf.merge(1, 9);
  uf.merge(2, 4);
  uf.merge(2, 6);

  assert(uf.connected(1, 2));
  assert(uf.connected(1, 3));
  assert(uf.connected(1, 5));
  assert(uf.connected(1, 7));
  assert(uf.connected(1, 9));
  assert(uf.connected(2, 4));
  assert(uf.connected(2, 6));
  assert(uf.connected(3, 4));

  return 0;
}