from collections import defaultdict
import sys


class Graph:
    def __init__(self, graph):
        super().__init__()
        self.graph = graph
        self.ROW = len(graph)
        self.N = len(graph)

    def BFS(self, s, t, parent):
        visited = [False] * self.ROW

        queue = []
        queue.append(s)
        visited[s] = True

        while queue:
            u = queue.pop(0)
            for ind, val in enumerate(self.graph[u]):
                if visited[ind] == False and val > 0:
                    if ind == t:
                        visited[t] = True
                        return True
                    queue.append(ind)
                    visited[ind] = True
                    parent[ind] = u
        return False

    def FordFulkerson(self, source, sink):
        parent = [-1] * self.ROW
        max_flow = 0
        while not self.BFS(source, sink, parent):
            path_flow = sys.maxsize
            s = sink
            while s != source:
                print(s)
                path_flow = min(path_flow, self.graph[parent[s]][s])
                s = parent[s]
            max_flow += path_flow

            v = sink
            while v != source:
                u = parent[v]
                self.graph[u][v] -= path_flow
                self.graph[v][u] += path_flow
                v = parent[v]

        return max_flow

    def maxflow(self, s, t):
        F = [[0] * self.N] * self.N

        while (path := self.maxflowBFS(F, s, t)) != None:
            flow = min(self.graph[u][v] - F[u][v] for u, v in path)
            for u, v in path:
                F[u][v] += flow
                F[v][u] -= flow
            return sum(F[s][i] for i in range(self.N))

    def maxflowBFS(self, F, s, t):
        queue = [s]
        path = {s: []}

        if s == t:
            return path[s]

        while queue:
            u = queue.pop(0)
            for v in range(self.N):
                if self.graph[u][v] - F[u][v] > 0 and v not in path:
                    path[v] = path[u] + [(u, v)]
                    if v == t:
                        return path[v]
                    queue.append(v)
        return None


if __name__ == "__main__":
    graph = [
        [0, 3, 3, 2, 11, 12],  # s
        [0, 0, 2, 3, 0, 0],  # o
        [0, 0, 0, 0, 2, 0],  # p
        [0, 0, 0, 0, 4, 2],  # q
        [0, 0, 0, 0, 0, 2],  # r
        [0, 0, 0, 0, 0, 3],
    ]  # t

    g = Graph(graph)

    source = 0
    sink = 5

    print("The maximum possible flow is %d " % g.FordFulkerson(source, sink))
    print(g.maxflow(0, 5))
