"""
    This program uses Dynamic programming to solve
    the Knapsack problem

    Author: Rodrigo Terán Herández
    Date: 29/10/2023
"""

def getWeightsAndProfitsData():
    try:
        numberValues = int(input())
        profits = []
        weights = []

        for _ in range(numberValues):
            profits.append(int(input()))
        for _ in range(numberValues):
            weights.append(int(input()))

        sackWeight = int(input())

        return {
            "N": numberValues ,
            "profits": profits,
            "weights": weights,
            "W": sackWeight
        }

    except ValueError:
        print("The values most be integers")
        return None

    except error:
        print(error)
        return None

def printMatrix(matrix):
    try:
        for row in matrix:
            print(row)
    except error:
        print(error)