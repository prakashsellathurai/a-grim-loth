##!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Articulation points  in a graph

DFS(G,u)
    state[u] = “discovered”
    process vertex u if desired
    entry[u] = time
    time = time + 1
    for each v ∈ Adj[u] do
        process edge (u,v) if desired
        if state[v] = “undiscovered” then
            p[v] = u
            DFS(G,v)
    state[u] = “processed”
    exit[u] = time
    time = time + 1

"""
__author__ = "prakashsellathurai"
__copyright__ = "Copyright 2021"
__version__ = "1.0.1"
__email__ = "prakashsellathurai@gmail.com"

# Articulation points
# 1). root with two childs
# 2) vertex with tree edge
from collections import defaultdict

class Graph:
  def __init__(self,V):
    self.V = V
    self.graph = defaultdict(list)
    self.time = 0


  def addEdge(self,u,v):
    self.graph[u].append(u)
    self.graph[v].append(u)
  
  def dfs(self,u,visited,ap,parent,low,disc):
    children= 0
    visited[u] = True

    disc[u] = self.time
    low[u] = self.time
    self.time+=1

    for v in self.graph[u]:
      if not visited[v]:
        parent[v] = u
        children+=1
        self.dfs(v,visited,ap,parent,low,disc)
        low[u] = min(low[u],low[v])

        if parent[u] == -1 and children >1:
          ap[u] = True

        if parent[u] != -1 and low[v] >= disc[u]:
          ap[u] = True
      elif v != parent[u]:
        low[u] = min(low[u],disc[v])
  def Articulation_points(self):
    visited = [False] * (self.V)
    disc = [float("Inf")] * (self.V)
    low = [float("Inf")] * (self.V)
    parent = [-1] * (self.V)
    ap = [False] * (self.V) 
  
    for i in range(self.V):
      if not visited[i]:
        self.dfs(i, visited, ap, parent, low, disc)

    for i,v in enumerate(ap):
        if  v:
          print(i,end=" ")


g1 = Graph(5)
g1.addEdge(1, 0)
g1.addEdge(0, 2)
g1.addEdge(2, 1)
g1.addEdge(0, 3)
g1.addEdge(3, 4)

g1.Articulation_points()



  