from collections import defaultdict,deque
class Graph:
    def __init__(self):
        self.graph = defaultdict(list)
    def add_edge(self,u,v):
        self.graph[u].append(v)
        self.graph[v].append(u)
    def bfs(self,s,x):
        visited = [False] * (max(self.graph)+1)
        level = [0] * (max(self.graph)+1)
        queue = deque()

        for i in range((max(self.graph)+1)):
            visited[i] = False
            level[i] = 0

        visited[s] = True
        queue.append(s)
        level[s] = 0

        while (len(queue) > 0):
            s = queue.popleft()
            for i in self.graph[s]:
                if (not visited[i]):
                    level[i] = level[s] + 1
                    visited[i] = True
                    queue.append(i)
        count = 0
        for i in range((max(self.graph)+1)):
            if (level[i] == x - 1):
                count += 1
             
        return count
N = int(input())

G = Graph()

for i in range(N-1):
    a,b = list(map(int,input().split()))
    G.add_edge(a,b)
x = int(input())
print(G.bfs(1,x))
