import sys


class Edge:
    def __init__(self, flow, capacity, u, v):
        self.flow = flow
        self.capacity = capacity
        self.u = u
        self.v = v
        super().__init__()


class Vertex:
    def __init__(self, height, excess_flow):
        self.height = height
        self.excess_flow = excess_flow
        super().__init__()


class Graph:
    def __init__(self, V):
        self.V = V
        self.vertices = [Vertex(0, 0) for i in range(V)]
        self.edges = []
        super().__init__()

    def addEdge(self, u, v, capacity):
        self.edges.append(Edge(0, capacity, u, v))

    def preflow(self, s):
        self.vertices[s].height = len(self.vertices)

        for i in range(len(self.edges)):
            if self.edges[i].u == s:
                self.edges[i].flow = self.edges[i].capacity
                self.vertices[self.edges[i].v].excess_flow += self.edges[i].flow
                self.edges.append(
                    Edge(-self.edges[i].flow, 0, self.edges[i].v, s))

    def overflowVertex(self):
        for i in range(len(self.vertices)):
            if self.vertices[i].excess_flow > 0:
                return i
        return -1

    def updateReverseEdgeFlow(self, i, flow):
        u = self.edges[i].v
        v = self.edges[i].u

        for j in range(len(self.edges)):
            if self.edges[j].v == v and self.edges[j].u == u:
                self.edges[j].flow -= flow
                return

        self.edges.append(Edge(0, flow, u, v))

    def push(self, u):
        for i in range(len(self.edges)):
            if self.edges[i].u == u:
                if self.edges[i].flow == self.edges[i].capacity:
                    continue
                if self.vertices[u].height > self.vertices[self.edges[i].v].height:
                    flow = min(
                        self.edges[i].capacity,
                        self.edges[i].flow,
                        self.vertices[u].excess_flow,
                    )
                    self.vertices[u].excess_flow -= flow
                    self.vertices[self.edges[i].v].excess_flow += flow
                    self.edges[i].flow += flow
                    self.updateReverseEdgeFlow(i, flow)
                    return True

        return False

    def relabel(self, u):
        mh = sys.maxsize

        for i in range(len(self.edges)):
            if self.edges[i].u == u:
                if self.edges[i].flow == self.edges[i].capacity:
                    continue
                if self.vertices[self.edges[i].v].height < mh:
                    mh = self.vertices[self.edges[i].v].height
                    self.vertices[u].height = mh + 1

    def getMaxFlow(self, s, t):
        self.preflow(s)
        while self.overflowVertex() != -1:

            u = self.overflowVertex()
            if not self.push(u):
                self.relabel(u)

        return self.vertices[-1].excess_flow


if __name__ == "__main__":
    v = 6
    g = Graph(6)
    g.addEdge(0, 1, 16)
    g.addEdge(0, 2, 13)
    g.addEdge(1, 2, 10)
    g.addEdge(2, 1, 4)

    g.addEdge(1, 3, 12)
    g.addEdge(2, 4, 14)
    g.addEdge(3, 2, 9)
    g.addEdge(3, 5, 20)
    g.addEdge(4, 3, 7)
    g.addEdge(4, 5, 4)

    print(g.getMaxFlow(0, 2))
