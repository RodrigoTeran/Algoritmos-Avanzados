"""
    This program uses Dynamic programming to solve
    the Knapsack problem

    Author: Rodrigo Terán Herández
    Date: 29/10/2023
"""

from utils import getWeightsAndProfitsData, printMatrix
from knapsack import knapsack

def main():
    try:
        data = getWeightsAndProfitsData()
        if data is None: return

        matrix = [[-1 for i in range(data.get("W", 0) + 1)] for j in range(data.get("N", 0) + 1)] 

        maxProfit = knapsack(
            matrix,
            data.get("weights", []),
            data.get("profits", []),
            data.get("W", 0),
            data.get("N", 0)
        )
        print(maxProfit)

        printMatrix(matrix)
    except error:
        print(error)

if __name__ == "__main__":
    main()