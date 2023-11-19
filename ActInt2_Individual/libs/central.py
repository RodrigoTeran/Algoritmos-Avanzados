"""
    This file has the implementation to get the shortest distance
    from our new central to the current centrals

    Author: Rodrigo Terán Hernández
    Created: 18/11/2023
"""

import math

class Central:
    def __init__(self, coordinates, new_point):
        self.coordinates = coordinates
        self.new_point = new_point

    def compute(self):
        """
            This function computes the closest central and then
            prints the result
        """

        closest_central_index = self.find_closest_central()
        closest_central_coordinates = self.coordinates[closest_central_index]
        distance_to_closest_central = self.calculate_distance(self.new_point, closest_central_coordinates)

        print("===== New central =====")
        print(f"Minimum distance to the nearest center: ({chr(ord('A') + closest_central_index)}): {distance_to_closest_central} km")
        print(f"Coordinates: {closest_central_coordinates}")

    def find_closest_central(self):
        """
            This function gets the closest central

            Time complexity: O(n)
                - n: the number of coordinates

            :return: The closest central's index
        """

        closest_central = None
        min_distance = float('inf')

        for i, central_coordinates in enumerate(self.coordinates):
            distance = self.calculate_distance(central_coordinates, self.new_point)
            if distance < min_distance:
                min_distance = distance
                closest_central = i

        return closest_central

    def calculate_distance(self, point_1, point_2):
        """
            This function uses the distance formula
            to get the distance from two pair of coordinates

            :param point_1: The first pair of coordinates
            :param point_2: The second pair of coordinates

            :return: The distance between the points
        """

        return math.sqrt((point_1[0] - point_2[0]) ** 2 + (point_1[1] - point_2[1]) ** 2)