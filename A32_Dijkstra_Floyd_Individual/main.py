"""
    This program uses Dijkstra's and Floyd Algorithms
    to get the minimum distance from all the nodes from a graph
    to all of the ther nodes

    Author: Rodrigo Terán Herández
    Date: 22/10/2023
"""

from utils import getAdjacencyMatrix
from graph import Graph

def main():
    matrix = getAdjacencyMatrix()
    graph = Graph(matrix)
    graph.getDistances()


if __name__ == "__main__":
    main()
