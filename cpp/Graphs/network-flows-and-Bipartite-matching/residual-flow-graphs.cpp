/**
 * @file residual-flow-graphs.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-07-21
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <algorithm>
#include <iostream>

#define MAXV 100
using namespace std;
// residual graph edge node
struct edgenode {
  int v;                 /*neighbouring vertex*/
  int capacity;          /*capacity of edge*/
  int flow;              /*flow through edge*/
  int residual;          /* residual capacity of edge */
  struct edgenode *next; /*next edge in list*/
};
int parent[MAXV];
struct flow_graph {};

void add_residual_edges(flow_graph *g) {}
void initialize_search(flow_graph *g) {}
void bfs(flow_graph *g, int source) {}

edgenode *find_edge(flow_graph *g, int parent, int child) {
  return new edgenode;
}
int path_volume(flow_graph *g, int start, int end) {
  edgenode *e; /*edge in question */

  if (parent[end] == -1) {
    return 0;
  }
  e = find_edge(g, parent[end], end);

  if (start == parent[end]) {
    return e->residual;
  } else {
    return (min(path_volume(g, start, parent[end]), e->residual));
  }
}
bool valid_edge(edgenode *e) { return (e->residual > 0); }
void augument_path(flow_graph *g, int start, int end, int volume) {
  edgenode *e;

  if (start == end) {
    return;
  }

  e = find_edge(g, parent[end], end);
  e->flow += volume;
  e->residual -= volume;

  e = find_edge(g, end, parent[end]);
  e->residual += volume;

  augument_path(g, start, parent[end], volume);
}
/**
 * @brief max flow by edmand karp algorithm
 *
 * @param g
 * @param source
 * @param sink
 */
void netflow(flow_graph *g, int source, int sink) {
  int volume; /*weight of the augumenting path */

  add_residual_edges(g);
  bfs(g, source);

  volume = path_volume(g, source, sink);

  while (volume > 0) {
    augument_path(g, source, sink, volume);
    initialize_search(g);
    bfs(g, source);
    volume = path_volume(g, source, sink);
  }
}

int main(int argc, const char **argv) { return 0; }