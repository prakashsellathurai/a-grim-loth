/**
 * @file constructing-all-paths-in-a-graph.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief Constructing All Paths in a Graph
 * @version 0.1
 * @date 2021-07-28
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
using namespace std;
#define NMAX 1000
int solution_count = 0; // Global variable to store the number of solutions

/**
 * @brief  the edges of the graph
 *
 */
typedef struct edgenode {
  int x, y;
} edgenode;

/**
 * @brief the graph
 *
 */
typedef struct {
  int nvertices;
  int nedges;
  edgenode *edges;
} Graph;

/**
 * @brief paths_data struct to store the data of a path
 *
 */
typedef struct {
  int s;   /* source vertex */
  int t;   /* destination vertex */
  Graph g; /* graph to find paths in */
} path_data;

/**
 * @brief constructs path candidate
 *
 * @param a
 * @param k
 * @param g
 * @param c
 * @param nc
 */
void construct_candidates(int a[], int k, path_data *g, int c[], int *nc) {
  int i;                 /* counters */
  bool in_sol[NMAX + 1]; /* what's already in the solution? */
  edgenode *p;           /* temporary pointer */
  int last;              /* last vertex in the current path */

  /* initialize the solution array */
  for (i = 1; i <= g->g.nvertices; i++) {
    in_sol[i] = false;
  }

  for (i = 0; i < k; i++) {
    in_sol[a[i]] = true;
  }

  if (k == 1) {
    c[0] = g->s;
    *nc = 1;
  } else {
    *nc = 0;
    last = a[k - 1];
    for (p = g->g.edges + (g->g.edges[last].x * g->g.nvertices); p->y != last;
         p++) {
      if (!in_sol[p->y]) {
        c[*nc] = p->y;
        (*nc)++;
      }
    }

    // while (p != NULL) {
    //   if (!in_sol[p->y]) {
    //     c[*nc] = p->y;
    //     (*nc)++;
    //   }
    //   p = p->next;
    // }
  }
}

/**
 * @brief We report a successful path whenever ak = t.
 *
 * @param a
 * @param k
 * @param g
 * @return int
 */
int is_a_solution(int a[], int k, path_data *g) { return (a[k] == g->t); }

/**
 * @brief The sequence of vertices for
each path is stored in the solution vector a, ready to be printed:
 *
 * @param a
 * @param k
 * @param input
 */
void process_solution(int a[], int k, path_data *input) {
  int i;
  solution_count++;
  std::cout << "{ " << std::endl;
  for (i = 1; i <= k; i++) {
    std::cout << a[i] << " ";
  }
  std::cout << "}" << std::endl;
}

/**
 * @brief backtrack function
 *
 * @param a
 * @param k
 * @param input
 */
void backtrack(int a[], int k, path_data *input) {
  int i;
  int c[NMAX];
  int nc;
  if (is_a_solution(a, k, input)) {
    process_solution(a, k, input);
  } else {
    k++;
    construct_candidates(a, k, input, c, &nc);
    for (i = 0; i < nc; i++) {
      a[k] = c[i];
      backtrack(a, k, input);
    }
  }
}

/**
 * @brief main function
 *
 * @param input
 */
void generate_simple_graph_path(path_data *input) {
  int a[NMAX];
  int k = 0;
  backtrack(a, k, input);
}
int main(int argc, const char **argv) {
  path_data input;
  input.s = 1;
  input.t = 4;
  input.g.nvertices = 5;
  input.g.nedges = 5;
  input.g.edges = (edgenode *)malloc(sizeof(edgenode) * (input.g.nvertices *
                                                         input.g.nvertices));
  input.g.edges[0].x = 1;
  input.g.edges[0].y = 2;
  input.g.edges[1].x = 1;
  input.g.edges[1].y = 3;
  input.g.edges[2].x = 1;
  input.g.edges[2].y = 4;
  input.g.edges[3].x = 2;
  input.g.edges[3].y = 3;
  input.g.edges[4].x = 2;
  input.g.edges[4].y = 4;
  input.g.edges[5].x = 3;
  input.g.edges[5].y = 4;

  generate_simple_graph_path(&input);

  return 0;
}