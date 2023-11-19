"""
    This whole program uses several algorithms to solve the 
    2° Key Problem

    Author: Rodrigo Terán Hernández
    Created: 18/11/2023
"""

from utils.stream import get_data, print_shortest_paths, get_files
from libs.tsp import tsp
from libs.flow import max_flow
from libs.central import Central

def solve_for_route(route):
    try:
        print(f"Input: {route}")

        number_of_cities, adjacency_matrix, capacity_matrix, coordinates, new_point = get_data(route)
        print_shortest_paths(adjacency_matrix, number_of_cities)
        tsp(adjacency_matrix, number_of_cities)
        max_flow(capacity_matrix, number_of_cities)
        central = Central(coordinates, new_point)
        central.compute()

        print("\n\n\n")

    except FileNotFoundError:
        print(f"No se pudo encontrar o abrir el archivo {route}.")

def main():
    routes = get_files("./inputs")

    for route in routes:
        solve_for_route(route)


if __name__ == "__main__":
    main()