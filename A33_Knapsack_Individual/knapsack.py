"""
    This program uses Dynamic programming to solve
    the Knapsack problem

    Author: Rodrigo Terán Herández
    Date: 29/10/2023
"""

"""
    Time complexity: O(N * W)
    - N: Length of values
    - W: Max weight of sack

"""
def knapsack(matrix, weights, profits, W, N):
    try:
        # base conditions 
        if N == 0 or W == 0: 
            return 0

        if matrix[N][W] != -1: 
            return matrix[N][W]
    
        # choice diagram code
        if weights[N - 1] <= W: 
            prevProfit = profits[N - 1]
            prevKRow = knapsack(matrix, weights, profits, W - weights[N - 1], N - 1)

            matrix[N][W] = max(
                prevProfit + prevKRow,
                knapsack(matrix, weights, profits, W, N - 1)
            )

            return matrix[N][W]
        
        matrix[N][W] = knapsack(matrix, weights, profits, W, N - 1)
        
        return matrix[N][W]
    except error:
        print(error)
        return 0