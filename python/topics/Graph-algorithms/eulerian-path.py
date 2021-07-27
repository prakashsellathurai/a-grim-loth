# Python program to check if a given graph is Eulerian or not
# Complexity : O(V+E)

from collections import defaultdict

# This class represents a undirected graph using adjacency list representation


class Graph:
    def __init__(self, vertices):
        self.V = vertices  # No. of vertices
        self.graph = defaultdict(list)  # default dictionary to store graph

    # function to add an edge to graph
    def addEdge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    # A function used by isConnected
    def DFSUtil(self, v, visited):
        # Mark the current node as visited
        visited[v] = True

        # Recur for all the vertices adjacent to this vertex
        for i in self.graph[v]:
            if visited[i] is False:
                self.DFSUtil(i, visited)

    """Method to check if all non-zero degree vertices are
	connected. It mainly does DFS traversal starting from
	node with non-zero degree"""

    def isConnected(self):

        # Mark all the vertices as not visited
        visited = [False] * (self.V)

        # Find a vertex with non-zero degree
        for i in range(self.V):
            if len(self.graph[i]) > 1:
                break

        # If there are no edges in the graph, return true
        if i == self.V - 1:
            return True

        # Start DFS traversal from a vertex with non-zero degree
        self.DFSUtil(i, visited)

        # Check if all non-zero degree vertices are visited
        for i in range(self.V):
            if visited[i] is False and len(self.graph[i]) > 0:
                return False

        return True

    """The function returns one of the following values
	0 --> If grpah is not Eulerian
	1 --> If graph has an Euler path (Semi-Eulerian)
	2 --> If graph has an Euler Circuit (Eulerian) """

    def isEulerian(self):
        # Check if all non-zero degree vertices are connected
        if self.isConnected() is False:
            return 0
        # Count vertices with odd degree
        odd = 0
        for i in range(self.V):
            if len(self.graph[i]) % 2 != 0:
                odd += 1

        """If odd count is 2, then semi-eulerian.
        			If odd count is 0, then eulerian
        			If count is more than 2, then graph is not Eulerian
        			Note that odd count can never be 1 for undirected graph"""
        if odd == 0:
            return 2
        if odd == 2:
            return 1
        if odd > 2:
            return 0

    # Function to run test cases

    def test(self):
        res = self.isEulerian()
        if res == 0:
            print("graph is not Eulerian")
        elif res == 1:
            print("graph has a Euler path")
        else:
            print("graph has a Euler cycle")


# Let us create and test graphs shown in above figures
g1 = Graph(5)
g1.addEdge(1, 0)
g1.addEdge(0, 2)
g1.addEdge(2, 1)
g1.addEdge(0, 3)
g1.addEdge(3, 4)
g1.test()

g2 = Graph(5)
g2.addEdge(1, 0)
g2.addEdge(0, 2)
g2.addEdge(2, 1)
g2.addEdge(0, 3)
g2.addEdge(3, 4)
g2.addEdge(4, 0)
g2.test()

g3 = Graph(5)
g3.addEdge(1, 0)
g3.addEdge(0, 2)
g3.addEdge(2, 1)
g3.addEdge(0, 3)
g3.addEdge(3, 4)
g3.addEdge(1, 3)
g3.test()

# Let us create a graph with 3 vertices
# connected in the form of cycle
g4 = Graph(3)
g4.addEdge(0, 1)
g4.addEdge(1, 2)
g4.addEdge(2, 0)
g4.test()

# Let us create a graph with all veritces
# with zero degree
g5 = Graph(3)
g5.test()
