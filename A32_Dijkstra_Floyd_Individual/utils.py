"""
    This program uses Dijkstra's and Floyd Algorithms
    to get the minimum distance from all the nodes from a graph
    to all of the ther nodes

    Author: Rodrigo Terán Herández
    Date: 22/10/2023
"""

def getAdjacencyMatrix():
    try:
        numberOfNodes = int(input())
        matrix = []

        for _ in range(numberOfNodes):
            weights = input()
            matrix.append([*[int(weight) for weight in weights.split(" ")]])

        return matrix

    except ValueError:
        print("The number of nodes should be an integer")