import sys

class Graph:
    def __init__(self,N):
        self.N = N
        self.vertices = {}
        self.verticeslist =[0]*N
        self.adjMatrix = [[0]*N for x in range(N)]
        self.level = [0]*N

    def set_vertex(self,vertex,id):
        if 0<=vertex<=self.N:
            self.vertices[id] = vertex
            self.verticeslist[vertex] = id

    def addEdge(self,u,v,capacity):
        self.adjMatrix[u][v] = capacity

    def get_matrix(self):
        return self.adjMatrix

    def display(self):
        mat = self.get_matrix()
        
        print('\n')
        for i,id in zip(range(len(mat)),enumerate(self.vertices)):
            if i == 0:
                print('  ','  '.join([id[1] for id in enumerate(self.vertices)]))
            print(id[1],mat[i])
        print('',end=' ')

    def BFS(self,F,S,T):
        q = []
        q.append(S)

        self.level = [0] * self.N
        self.level[S] = 1
        while q:
            u = q.pop(0)
            for i in range(self.N):
                if (F[u][i] < self.adjMatrix[u][i] and self.level[i] == 0):
                    self.level[i] = self.level[u] + 1
                    q.append(i)
        return self.level[T] > 0
    
    def DFS(self,F,S,cp):
        tmp = cp
        if S == self.N - 1:
            return cp
        for i in range(self.N):
            if self.level[i] == self.level[S] + 1 and F[S][i] < self.adjMatrix[S][i]:
                f = self.DFS(F,i,min(tmp,self.adjMatrix[S][i]-F[S][i]))
                
                F[S][i] += f
                F[i][S] -= f
                tmp -= f
        return cp-tmp

    def maxFlow(self,S,T):
        total = 0
        F = [[0]*self.N] * self.N #flow matrix
        while self.BFS(F,S,T):
            self.pointer = [0]*self.N
            total += self.DFS(F,S,sys.maxsize)
        return total
if __name__ == "__main__":
    N = 4
    E = 2
    graph = Graph(N)
    graph.set_vertex(0,'a')
    graph.set_vertex(1,'b')
    graph.set_vertex(2,'c')
    graph.set_vertex(3,'d')
 
    graph.addEdge(0,1,4)
    graph.addEdge(1,2,3)
    graph.addEdge(0,3,1)
    graph.addEdge(2,3,3)
    # graph.addEdge(3,1,4)
    # graph.addEdge(2,1,4)
    # graph.addEdge(2,0,11)
    # graph.addEdge(3,3,11)
    # graph.addEdge(1,3,11)
    # graph.addEdge(0,2,8)
    # graph.addEdge(3,2,50)
    # graph.addEdge(0,1,8)
    graph.display()
    print(graph.maxFlow(0,3))
