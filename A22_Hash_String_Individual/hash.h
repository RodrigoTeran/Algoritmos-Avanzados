/**
 * In this file we have the function to create our table step by step
 * so we can output the hexadecial representation of the text that is provided
 * with the table having "n" columns as well.
 *
 * Author: Rodrigo Terán Hernández A01704108
 * Created: 21/09/2023
*/

#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "utils.h"

using namespace std;

/**
 * This function helps us to create the table
 *
 * Time complexity: O(n)
 *  n = length of the text
 * 
 * @param text - The file content
 * @param n - The number of columns we are going to use in our table
*/
void createTable(string* text, int* n) {
    cout << "Texto:" << endl;
    cout << *text << endl << endl << "---------" << endl;

    int lengthOfText =  text->size();
    int remainder = lengthOfText % *n;
    int sizeOfColumn = lengthOfText / *n;

    if (remainder > 0) {
        sizeOfColumn++;
    }

    cout << "lengthOfText: " << lengthOfText << endl;
    cout << "sizeOfColumn: " << sizeOfColumn << endl;
    cout << "# columns: " << *n << endl;
    cout << "---------" << endl;
    
    cout << endl << "Tabla:" << endl;

    vector<vector<string> > columns(*n);
    vector<int> modules(*n, 0);
    vector<string> hexes(*n, "");
    
    // Time complexity: O(n), n = len(text)
    for (int i = 0; i < lengthOfText; i++) {
        if (text->substr(i, 1) == "\n") {
            columns.at(i % *n).push_back("\n");
        } else {
            columns.at(i % *n).push_back(text->substr(i, 1));
        };
    };

    // Add last
    int amountToAdd = *n * sizeOfColumn - lengthOfText;
    int startToAdd = lengthOfText % *n;
    
    // Time complexity: O(n), n = numberOfColumns * (len(text) / numberOfColumns) - len(text)
    for (int j = startToAdd; j < startToAdd + amountToAdd; j++) {
        columns.at(j).push_back("[");
    };

    printResult(&columns);
    
    // Time complexity: O(n), n = numberOfColumns
    for (int i = 0; i < *n; i++) { // Columns
        // Time complexity: O(n), n = len(text) / numberOfColumns
        for (int j = 0; j < columns.at(i).size(); j++) {
            int ascciValueOfChar = 0;
            if (columns.at(i).at(j) == "\n") {
                ascciValueOfChar = 10;
            } else {
                char current = columns.at(i).at(j).at(0);
                ascciValueOfChar = int(current);
            }
            modules.at(i) += ascciValueOfChar;

        };
    };

    // Time complexity: O(n), n = numberOfColumns
    for (int i = 0; i < *n; i++) {
        modules.at(i) %= 256;
    };

    cout << endl << "A[i] % 256:" << endl;

    // Time complexity: O(n), n = numberOfColumns
    for (int i = 0; i < *n; i++) {
        cout << modules.at(i) << " ";
    };
    
    cout << endl;

    // Time complexity: O(n), n = numberOfColumns
    for (int i = 0; i < *n; i++) {
        ostringstream streamToHex;
        streamToHex << uppercase << hex << modules.at(i);
        string stringifiedHex = streamToHex.str();
        hexes.at(i) = stringifiedHex;
    };

    cout << endl;
    cout << "Result" << endl;

    // Time complexity: O(n), n = numberOfColumns
    for (int i = 0; i < *n; i++) {
        cout << hexes.at(i);

        if (i % 4 == 3) {
            cout << "\t";
        }
    };
};


#endif
