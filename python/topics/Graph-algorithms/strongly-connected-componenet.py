# Python program to check if a given directed graph is strongly
# connected or not

from collections import defaultdict

#This class represents a directed graph using adjacency list representation
class Graph:

	def __init__(self,vertices):
		self.V= vertices #No. of vertices
		self.graph = defaultdict(list) # default dictionary to store graph

	# function to add an edge to graph
	def addEdge(self,u,v):
		self.graph[u].append(v)
	

	#A function used by isSC() to perform DFS
	def DFSUtil(self,v,visited):

		# Mark the current node as visited
		visited[v]= True

		#Recur for all the vertices adjacent to this vertex
		for i in self.graph[v]:
			if visited[i] is False:
				self.DFSUtil(i,visited)


	# Function that returns reverse (or transpose) of this graph
	def getTranspose(self):

		g = Graph(self.V)

		# Recur for all the vertices adjacent to this vertex
		for i in self.graph:
			for j in self.graph[i]:
				g.addEdge(j,i)
		
		return g

		
	# The main function that returns true if graph is strongly connected
	def isSC(self):

		# Step 1: Mark all the vertices as not visited (For first DFS)
		visited =[False]*(self.V)
		
		# Step 2: Do DFS traversal starting from first vertex.
		self.DFSUtil(0,visited)

		# If DFS traversal doesnt visit all vertices, then return false
		if any(i is False for i in visited):
			return False

		# Step 3: Create a reversed graph
		gr = self.getTranspose()
		
		# Step 4: Mark all the vertices as not visited (For second DFS)
		visited =[False]*(self.V)

		# Step 5: Do DFS for reversed graph starting from first vertex.
		# Staring Vertex must be same starting point of first DFS
		gr.DFSUtil(0,visited)

		# If all vertices are not visited in second DFS, then
		# return false
		if any(i is False for i in visited):
			return False

		return True

# Create a graph given in the above diagram
g1 = Graph(5)
g1.addEdge(0, 1)
g1.addEdge(1, 2)
g1.addEdge(2, 3)
g1.addEdge(3, 0)
g1.addEdge(2, 4)
g1.addEdge(4, 2)
print ("Yes" if g1.isSC() else "No")

g2 = Graph(4)
g2.addEdge(0, 1)
g2.addEdge(1, 2)
g2.addEdge(2, 3)
print ("Yes" if g2.isSC() else "No")

#This code is contributed by Neelam Yadav
