"""
    This code has the util to get the data
    from the text files and return it as an array of the files
    data

    Author: Rodrigo Terán Hernández
    Created: 01/10/2023
"""
import os

def get_data(required_path):
    """
        This function gets the data from a path and returns it as an array of
        the files content

        :param required_path: The path to get the data from
        :return: It returns the content from each file as an array
    """
    files_data = []

    for existing_file in os.listdir(required_path):
        files_full_path = os.path.join(required_path, existing_file)
        
        if not os.path.isfile(files_full_path) or not existing_file.endswith(".txt"): return ""

        streamdata = []
        with open (files_full_path, "r") as file: streamdata = [line.strip() for line in file]
        files_data.append("".join(streamdata))
    
    return files_data