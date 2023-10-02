"""
    This code has the implementation of KMP
    (KNUTH MORRIS PRATT), it gets the coincidence between a text and a pattern.

    Author: Rodrigo Terán Hernández
    Created: 01/10/2023
"""
def longest_preffix_suffix(pattern):
    """
        This function gets the longest prexif suffix

        Time complexity:
            O(n)
                n = Pattern's to search length

        :param pattern: The pattern to be searched on the text
        :return: It returns an array of the preffixes
    """
    pi = [0] * len(pattern)
    for i in range(1, len(pi)):
        if pattern[pi[i - 1]] == pattern[i]:
            pi[i] = pi[i - 1] + 1
        else:
            pi[i] = 0
    return pi


def search_coincidences(text, pattern):
    """
        This function searches for a pattern match on a text.

        Time complexity:
            O(m + n)
                m = Text's to search length
                n = Pattern's to search length

        :param text: The text to search the pattern
        :param pattern: The pattern to be searched on the text
        :return: It returns all the coincidences
    """
    pi = longest_preffix_suffix(pattern)
    i = 0
    j = 0

    coincidences = []

    while i < len(text):
        if j < len(pattern) and text[i] == pattern[j]:   
            j += 1 
        
            if j == len(pattern):
                coincidences.append(i - j + 1)
        
        elif j > 0:
            j = pi[j - 1]
            i -= 1

        i += 1

    return coincidences