"""
    This program aims to get detect malicious code
    between text transmisions

    Author: Rodrigo Terán Hernández
    Created: 01/10/2023
"""
from utils.read import get_data
from utils.write import write_files
from utils.coincidences import get_coincidences
from config.rules import MCODE_DIRECTORY_PATH, TRANSMISSION_DIRECTORY_PATH, OUTPUT_PATH

malicious = get_data(MCODE_DIRECTORY_PATH)
transmission = get_data(TRANSMISSION_DIRECTORY_PATH)

def main():
    with open(OUTPUT_PATH, "w") as out:
        write_files(files_data=transmission, title="Archivo de transmisión", file=out)
        write_files(files_data=malicious, title="Archivo mcode", file=out)
        get_coincidences(files_transmission=transmission, files_mcode=malicious, file=out)

if __name__ == "__main__":
    main()