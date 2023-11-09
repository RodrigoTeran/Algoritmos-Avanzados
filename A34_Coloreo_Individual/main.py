"""
    This program solves coloring a graph with
    the least amount of colors available.

    The coloring of each node can't be the same for adjacent nodes.

    Author: Rodrigo Terán Herández
    Date: 08/11/2023
"""

from utils import getGraph, printResult
from color import colorGraph

def main():
    try:
        matrix = getGraph()
        if matrix is None: return
        
        data = colorGraph(matrix)
        if data is None: return

        printResult(data)
    except error:
        print(error)

if __name__ == "__main__":
    main()