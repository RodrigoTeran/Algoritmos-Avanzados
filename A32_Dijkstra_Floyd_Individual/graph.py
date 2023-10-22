"""
    This program uses Dijkstra's and Floyd Algorithms
    to get the minimum distance from all the nodes from a graph
    to all of the ther nodes

    Author: Rodrigo Terán Herández
    Date: 22/10/2023
"""

class Graph():
	def __init__(self, graph):
		self.V = len(graph)
		self.graph = graph

	# This utiliy function print the result from dijsktra
	def printSolution(self, dist):
		for nodeFrom in range(self.V):
			for nodeTo in range(self.V):
				if nodeFrom == nodeTo: continue

				print(f"node {nodeFrom + 1} to node {nodeTo + 1}: {dist[nodeFrom][nodeTo]}")
		print()

	# A utility function to find the vertex with
	# minimum distance value, from the set of vertices
	# not yet included in shortest path tree
	def minDistance(self, dist, sptSet):
		min = 1e7
		
		"""
			Time complexity: O(n)
				- n: The number of nodes
		"""
		for v in range(self.V):
			if dist[v] < min and sptSet[v] == False:
				min = dist[v]
				min_index = v

		return min_index

	# A utility function to get the matrix of distances
	def getEmptyDistances(self):
		dist = []

		for i in range(self.V):
			row = [1e7] * self.V
			row[i] = 0
			dist.append(row)

		return dist

	# A utility function to print the matrix of distances
	@staticmethod
	def preetyPrintMatrix(m):
		for row in m:
			for element in row:
				print(element, end=" ")
			print()
    
	# This function gets all the minimum distances from each node 
	# to all of the other nodes
	#
	# Time complexity: O(n^3)
	#			- n: The number of nodes
	def getDistances(self):
		dist = self.getEmptyDistances()

		"""
			Time complexity: O(n^3)
				- n: The number of nodes
		"""
		for i in range(self.V):
			sptSet = [False] * self.V

			"""
				Time complexity: O(n^2)
					- n: The number of nodes
			"""
			for cout in range(self.V):
				u = self.minDistance(dist[i], sptSet)
				sptSet[u] = True

				"""
					Time complexity: O(n)
						- n: The number of nodes
				"""
				for v in range(self.V):
					isNotSelf = self.graph[u][v] > 0
					isMinDistV = sptSet[v] == False
					isDistGreater = dist[i][v] > dist[i][u] + self.graph[u][v]

					if isNotSelf and isMinDistV and isDistGreater:
						# Update minimum distance
						dist[i][v] = dist[i][u] + self.graph[u][v]

		print("Dijkstra:")
		self.printSolution(dist)

		print("Floyd:")
		Graph.preetyPrintMatrix(dist)