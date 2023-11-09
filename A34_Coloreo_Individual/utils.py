"""
    This program solves coloring a graph with
    the least amount of colors available.

    The coloring of each node can't be the same for adjacent nodes.

    Author: Rodrigo Terán Herández
    Date: 08/11/2023
"""

def getGraph():
    try:
        numberOfNodes = int(input())
        matrix = []

        for i in range(numberOfNodes):
            row = input().split(" ")
            rowInts = []

            for n in row:
                rowInts.append(int(n))
            
            matrix.append(rowInts)

        return matrix
            
    except ValueError:
        print("El número de nodos debe de ser un entero")
        return None

    except error:
        print(error)
        return None

def printResult(data):
    try:
        for i in range(len(data)):
            element = data[i]
            print(f"Vértice {i}, color asignado: {element.get('color', '-')}")
        print("")
    except error:
        print(error)