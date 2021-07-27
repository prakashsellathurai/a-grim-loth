import sys


class Graph():

    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)]
                    for row in range(vertices)]

    def printSolution(self, dist):
        print("Vertex tDistance from Source")
        for node in range(self.V):
            print(node, "t", dist[node])

    # A utility function to find the vertex with
    # minimum distance value, from the set of vertices
    # not yet included in shortest path tree
    def minDistance(self, dist, sptSet):

        # Initilaize minimum distance for next node
        min = sys.maxsize

        # Search not nearest vertex not in the
        # shortest path tree
        for v in range(self.V):
            if dist[v] < min and sptSet[v] is False:
                min = dist[v]
                min_index = v

        return min_index

    def FloydWarshall(self):
        dist = list(map(lambda i: list(map(lambda j: j, i)), self.graph))
        V = len(self.graph)
        for k in range(V):
            # pick all vertices as source one by one
            for i in range(V):
                # Pick all vertices as destination for the
                # above picked source
                for j in range(V):
 
                    # If vertex k is on the shortest path from
                    # i to j, then update the value of dist[i][j]
                    dist[i][j] = min(dist[i][j],
                                    dist[i][k] + dist[k][j]
                                    )
        self.printSolution(dist)
        
INF = sys.maxsize
# Driver program
g = Graph(4)
g.graph = [[0, 5, INF, 10],
         [INF, 0, 3, INF],
         [INF, INF, 0,   1],
         [INF, INF, INF, 0]
         ]
g.FloydWarshall()