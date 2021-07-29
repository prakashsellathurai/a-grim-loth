/**
 * @file constructing-all-paths-in-a-graph.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief program to construct all path from s to t in graph
 * @version 0.1
 * @date 2021-07-28
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
using namespace std;

// define a graph
struct Graph {
    int V;  // No. of vertices
    int *adj;  // Pointer to an array that stores adjacency list
    Graph(int V);  // Constructor
    void addEdge(int v, int w);  // function to add an edge to graph
};

// Graph constructor
Graph::Graph(int V){
    this->V = V;
    adj = new int[V];
    for (int i = 0; i < V; i++) {
        adj[i] = -1;
    }
}

// function to add an edge in a graph
void Graph::addEdge(int v, int w){
    adj[v] = w;
}

// print all paths from s to t in a graph
void printAllPathsUtil(int v, int path[], int pathLen, int s, int t, Graph g){
    // base case: if s and t are same
    if (v == t && pathLen != 0) {
        cout << "path { ";
        for (int i = 0; i < pathLen; i++) {
            cout << path[i] << " ";
        }
        cout << "}"<< endl;
        return;
    }
    // if s is not reachable from t
    if (g.adj[v] == -1) {
        return;
    }
    // if s is not reachable from t
    if (g.adj[v] == s) {
        path[pathLen] = v;
        pathLen++;
        printAllPathsUtil(v + 1, path, pathLen, s, t, g);
        pathLen--;
    }
    else {
        path[pathLen] = v;
        pathLen++;
        printAllPathsUtil(g.adj[v], path, pathLen, s, t, g);
        pathLen--;
        printAllPathsUtil(v + 1, path, pathLen, s, t, g);
        pathLen--;
    }
}


int main(int argc, const char** argv) {
    // create a graph
    Graph g(5);
    // add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    // print all paths from s to t
    int path[10];
    int pathLen = 0;
    printAllPathsUtil(0, path, pathLen, 0, 4, g);
  return 0;
}