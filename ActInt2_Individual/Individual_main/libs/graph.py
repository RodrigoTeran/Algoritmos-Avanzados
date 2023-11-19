"""
    This file has the implementation of a graph and it has useful methods to
    construct paths and to a breath first search traversal

    Author: Rodrigo Terán Hernández
    Created: 18/11/2023
"""

class Graph:
    def __init__(self, matrix, number_of_nodes):
        self.matrix = matrix
        self.n = number_of_nodes

    def reconstruct_path(self, previous_nodes, start, end):
        """
            It constructs the path from prev nodes

            :param previous_nodes: Previous nodes from bfs
            :param start: Starting node
            :param end: Endind node

            :return: The path taken
        """

        path = []
        current_node = end

        while current_node != start:
            path.insert(0, current_node)
            current_node = previous_nodes[current_node]

        path.insert(0, start)
        return path

    def bfs(self, start, end):
        """
            It traverses a graph doing bfs using a queue

            :param start: Starting node
            :param end: Endind node

            :return:
                - The path taken
                - The minimum capacity of the first connection
        """

        path = []
        bottleneck = 0
        visited = [False] * self.n

        queue = [start]
        visited[start] = True

        previous_nodes = [-1] * self.n

        while queue:
            current_node = queue.pop(0)

            for neighbor, capacity in enumerate(self.matrix[current_node]):
                if visited[neighbor] or capacity <= 0: continue

                queue.append(neighbor)
                visited[neighbor] = True
                previous_nodes[neighbor] = current_node

                if neighbor != end: continue

                path = self.reconstruct_path(previous_nodes, start, end)
                bottleneck = min(self.matrix[u][v] for u, v in zip(path, path[1:]))
                return path, bottleneck

        return path, bottleneck