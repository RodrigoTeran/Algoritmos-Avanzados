"""
    This code uses Dijkstra's algorithm to get the minimun distances
    to get to each node from a starting node

    Author: Rodrigo Terán Hernández
    Created: 18/11/2023
"""

import heapq

def dijkstra(matrix, n, start):
    """
        This function uses dijkstra's algorithm to traverse all the graph
        in search of the shortest distance from a starting node
        to all of the nodes

        Time complexity: O(n * log n)
            - n: the number of nodes

        :param matrix: The adjacency graph
        :param n: The number of nodes
        :param start: Starting node

        :return:
            - The distances to all of the nodes
            - The paths taken
    """

    distances = [float("inf")] * n
    distances[start] = 0

    visited = [False] * n

    previous_nodes = [-1] * n

    priority_queue = [(0, start)]

    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)

        visited[current_node] = True

        for neighbor, weight in enumerate(matrix[current_node]):
            if not visited[neighbor] and weight > 0:
                distance = current_distance + weight
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    previous_nodes[neighbor] = current_node
                    heapq.heappush(priority_queue, (distance, neighbor))

    return distances, previous_nodes