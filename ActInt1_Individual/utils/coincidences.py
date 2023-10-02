"""
    This code has the implementation to search
    for the malicious code in the transmissions.

    Author: Rodrigo Terán Hernández
    Created: 01/10/2023
"""
from libs.kmp import search_coincidences
from libs.manacher import search_longest_palindrome
from libs.lcs import get_longest_common_substring

def write_matches(coincidences, file, matched, prefix=None):
    """
        This function writes the positions in which a match was performed

        :param coincidences: The coincidences
        :param file: The file object to write on
        :param matched: The string that was matched
        :param prefix: The optional prefix to write before the positions
    """
    for coincidence in coincidences:
        if prefix is not None:
            file.write(prefix)
        file.write(f"Posición inicial: {coincidence} ")
        file.write(f"Posición final: {coincidence + len(matched) - 1}\n")

def match_substr(matches, transmission, file):
    """
        This function searches and writes all the matches found on a transmission

        :param matches: The matches
        :param transmission: The transmissions content
        :param file: The file object to write on
    """
    for i, v in enumerate(matches):
        file.write(f"mcode {i + 1}\n")
        coincidences = search_coincidences(text=transmission, pattern=v)

        if len(coincidences) == 0:
            file.write("(false) Cadena no encontrada en la transmisión\n\n")
            continue

        write_matches(coincidences=coincidences, file=file, matched=v, prefix="(true) ")
        
        file.write("\n")

def get_coincidences(files_transmission, files_mcode, file):
    """
        This function searches, writes and gets the mirrored code for all the transmissions.
        It also gets the longest substring between the two transmissions.

        :param files_transmission: The transmissions content as an array
        :param files_mcode: The mcodes content as an array
        :param file: The file object to write on
    """
    for i, t in enumerate(files_transmission):
        file.write(f"T R A N S M I S S I O N {i + 1}\n\n")
        
        match_substr(matches=files_mcode, transmission=t, file=file)

        palindrome, index = search_longest_palindrome(t)

        if len(palindrome) > 1:
            write_matches(coincidences=[index], file=file, matched=palindrome, prefix=f"Código espejeado {palindrome}\n")
            file.write("\n")
        else:
            out.write("No se encontró código espejeado en el archivo de transmisión\n\n")
    
    if len(files_transmission) != 2: return
    longest_substring = get_longest_common_substring(first_text=files_transmission[0], second_text=files_transmission[1])
    file.write(f"Sub-String más largo: {longest_substring}\n\n")

    for i, t in enumerate(files_transmission):
        file.write(f"Posiciones en la Transmisión {i + 1}\n")
        coincidences = search_coincidences(text=t, pattern=longest_substring)
        write_matches(coincidences=coincidences, file=file, matched=longest_substring)
        file.write("\n")