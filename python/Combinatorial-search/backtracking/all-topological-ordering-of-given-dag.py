from collections import deque

"""Given a directed acyclic graph (DAG) with n vertices and m edges,
find all possible topological orderings of the vertices.

"""


class Graph:
    def __init__(self, edges, N) -> None:
        self.V = N
        self.adjList = [[] for _ in range(N)]

        self.indegree = [0] * N
        for (src, dest) in edges:
            self.adjList[src].append(dest)
            self.indegree[dest] += 1

    def findAllTopologicalorderings(self, discovered, path):
        for v in range(self.V):
            if self.indegree[v] == 0 and not discovered[v]:
                for u in self.adjList[v]:
                    self.indegree[u] -= 1
                path.append(v)
                discovered[v] = True
                self.findAllTopologicalorderings(discovered, path)
                for u in self.adjList[v]:
                    self.indegree[u] += 1
                path.pop()
                discovered[v] = False
        if len(path) == self.V:
            print(path)

    def printAllTopologicalOrders(self):
        """

        >>> N = 4
        >>> edges = [(0,1),(1,2),(2,3)]
        >>> graph = Graph(edges,N)
        >>> graph.printAllTopologicalOrders()
        [0, 1, 2, 3]
        """
        discovered = [False] * self.V
        path = []
        self.findAllTopologicalorderings(discovered, path)


if __name__ == "__main__":
    import doctest

    doctest.testmod(verbose=True)
