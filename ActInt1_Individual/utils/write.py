"""
    This code has the util to write the header for
    the transmissions and mcodes data content

    Author: Rodrigo Terán Hernández
    Created: 01/10/2023
"""
def write_files(files_data, title, file):
    """
        This function writes the files content

        :param files_data: The files content
        :param title: The title to display before the content
        :param file: The file object to write on
    """
    for i, v in enumerate(files_data):
        file.write(f"{title} {i + 1}\n")
        file.write(f"{v}\n\n")