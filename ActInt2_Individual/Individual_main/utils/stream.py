"""
    This file has the utils to read and print data from specific
    objects and/or files

    Author: Rodrigo Terán Hernández
    Created: 18/11/2023
"""

from libs.dijkstra import dijkstra
import os

def get_files(required_path):
    """
        This function gets the full path of the inputs and returns
        all of the full paths of each test case

        :param required_path: The path to get the data from
        :return: It returns the names of the test inside that directury
    """

    files_names = []

    for existing_file in os.listdir(required_path):
        files_full_path = os.path.join(required_path, existing_file)
        files_names.append(files_full_path)
    
    return files_names

def get_data(file_name):
    """
        This function gets the data from a path and returns the data
        corresponding to the test file

        :param required_path: The path to get the data from
        :return:
            - number_of_nodes: Number of nodes in the graph
            - adjacency_matrix: The graph in form of matrix
            - capacity_matrix: The capacity matrix of flow
            - coordinates: The coordinates of the centrals
            - new_point: The coordinates of the new central
    """

    with open(file_name, "r") as file:
        lines = [line.strip() for line in file.readlines()]

    number_of_nodes = int(lines[0])
    matrix_start, matrix_end = 1, number_of_nodes + 1
    capacity_matrix_start, capacity_matrix_end = matrix_end + 1, matrix_end + 1 + number_of_nodes
    coordinates_start, coordinates_end = capacity_matrix_end + 1, -2

    clean_and_split = lambda l: list(map(int, l.split()))
    clean_coordenates = lambda l: tuple(map(int, l.replace("(", "").replace(")", "").split(",")))

    adjacency_matrix = [clean_and_split(line) for line in lines[matrix_start:matrix_end]]
    capacity_matrix = [clean_and_split(line) for line in lines[capacity_matrix_start:capacity_matrix_end]]
    coordinates = [clean_coordenates(line) for line in lines[coordinates_start:coordinates_end]]
    new_point = clean_coordenates(lines[-1])

    return number_of_nodes, adjacency_matrix, capacity_matrix, coordinates, new_point

def print_shortest_paths(matrix, number_of_cities):
    """
        This function print the best way to connect all of the nodes of a graph from
        a starting node

        Time complexity: O(n^2 * n * log(n))
            - n: the number of cities
        
        :param matrix: The adjacency matrix
        :param number_of_cities: The number of cities
    """

    print("===== Shortest distances between cities =====")

    first_city = "A"
    insertion = lambda f, s: chr(ord(f) + s)

    for start_city in range(number_of_cities):
        for end_city in range(start_city, number_of_cities):
            if start_city == end_city: continue

            # Here we use Dijkstra
            distances, previous_nodes = dijkstra(matrix, number_of_cities, start_city)
            
            # Most optimal paths
            path = []

            current_node = end_city

            while current_node != start_city:
                path.insert(0, insertion(first_city, current_node))
                current_node = previous_nodes[current_node]

            # Here we insert the first city
            path.insert(0, insertion(first_city, start_city))
            path_str = " <-> ".join(path)
            print(f"Between {insertion(first_city, start_city)} and {insertion(first_city, end_city)}")
            print(f"{path_str} ({distances[end_city]} km)", end="\n\n")