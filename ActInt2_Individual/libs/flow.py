"""
    This code uses the Max Flow algorithm to get what is the max amount of flow
    that can go through a graph from a strating node to an end node

    Author: Rodrigo Terán Hernández
    Created: 18/11/2023
"""

from libs.graph import Graph

def max_flow(capacity_matrix, number_of_cities):
    """
        This function computes the max flow a graph can receive
        from a starting node to an ending node

        Time complexity: O(n * m)
            - n: the numbef of connections
            - m: the max flow
        
        :param capacity_matrix: The capacity matrix
        :param number_of_cities: The number of cities
    """

    max_flow = 0

    while True:
        # It creates a graph to do bfs
        graph = Graph(capacity_matrix, number_of_cities)
        path, bottleneck = graph.bfs(0, 1)

        if not path: break

        for i in range(len(path) - 1):
            u, v = path[i], path[i + 1]
            capacity_matrix[u][v] -= bottleneck
            capacity_matrix[v][u] += bottleneck

        max_flow += bottleneck

    print("===== Flow =====")
    print(f"Max flow: {max_flow}", end="\n\n")