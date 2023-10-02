"""
    This code has the implementation of the
    longest common substring algorithm.

    Author: Rodrigo Terán Hernández
    Created: 01/10/2023
"""

def get_longest_common_substring(first_text, second_text):
    """
        This function gets the longest common substring from two
        strings

        Time complexity:
            O(m * n)
                m = First text length
                n = Second text length

        :param first_text: The first text to be searching the substring
        :param second_text: The second text to be searching the substring
        :return: It returns the longest substring
    """
    coincidences = [[0 for col in range(len(first_text))] for row in range(len(second_text))]
    tup = [-1, -1]
    
    for row in range(len(second_text)):
        for col in range(len(first_text)):
            if first_text[col] == second_text[row]:
                if row > 0 and col > 0:
                    coincidences[row][col] = 1 + coincidences[row - 1][col - 1]

                else:
                    coincidences[row][col] = 1
                
                if coincidences[row][col] > tup[1]:
                    tup[0] = col
                    tup[1] = coincidences[row][col]
            
            else:
                coincidences[row][col] = 0
    
    return first_text[tup[0] - tup[1] + 1 : tup[0] + 1]