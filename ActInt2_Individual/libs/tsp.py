"""
    This code uses a solution to the Travelling salesman problem
    to get the minimum trayectory to visit all nodes in a graph

    Author: Rodrigo Terán Hernández
    Created: 18/11/2023
"""

def print_tsp(tsp_cost, tsp_path):
    """
        This function print the result of the tsp function

        :param tsp_cost: The final cost of the tsp algoritm
        :param tsp_path: The path taken
    """

    print("===== Minimum distance to travel to all cities =====")
    print(f"Distance: {tsp_cost}km")
    print("- Route:")
    for i, route in enumerate(tsp_path):
        if i == len(tsp_path) - 1:
            print(route, end="\n\n")
            continue
        print(route, end=" -> ")

def tsp(matrix, number_of_cities):
    """
        This function has a solution to the Travelling salesman problem
        by using dynamic programming

        Time complexity: O(n^2)
            - n: The number of nodes


        :param matrix: The adjacency matrix
        :param number_of_cities: The number of nodes

        :return: It returns the names of the test inside that directury
    """

    memo = [[None for _ in range(number_of_cities)] for _ in range(1 << number_of_cities)]
    path = [[None for _ in range(number_of_cities)] for _ in range(1 << number_of_cities)]

    def visit(visited, last):
        if memo[visited][last] is not None:
            return memo[visited][last]

        if visited == (1 << number_of_cities) - 1:
            return matrix[last][0] if matrix[last][0] > 0 else float("inf")

        min_cost = float("inf")
        for city in range(number_of_cities):
            if not visited & (1 << city) and matrix[last][city] > 0:
                cost = matrix[last][city] + visit(visited | (1 << city), city)
                if cost < min_cost:
                    min_cost = cost
                    path[visited][last] = city

        memo[visited][last] = min_cost
        return min_cost

    min_cost = visit(1, 0)

    optimal_path = []
    last = 0
    visited = 1
    while True:
        optimal_path.append(chr(last + ord("A")))
        last = path[visited][last]
        if last is None:
            break
        visited |= 1 << last

    optimal_path.append("A")
    print_tsp(min_cost, optimal_path)