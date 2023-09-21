/**
 * ...
 *
 * Author: Rodrigo Terán Hernández A01704108
 * Created: 10/09/2023
*/

#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "utils.h"

using namespace std;

void createTable(string* text, int* n) {
    cout << *text << endl << "-----" << endl;
    cout << text->size() << endl << "-----" << endl;

    int lengthOfText =  text->size();
    int remainder = lengthOfText % *n;
    int sizeOfColumn = lengthOfText / *n;

    if (remainder > 0) {
        sizeOfColumn++;
    }

    cout << "lengthOfText: " << lengthOfText << endl;
    cout << "sizeOfColumn: " << sizeOfColumn << endl;
    cout << "remainder: " << remainder << endl;
    cout << "# columns: " << *n << endl;

    vector<vector<string> > columns(*n);
    vector<int> modules(*n, 0);
    vector<string> hexes(*n, "");
    
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
    for (int j = startToAdd; j < startToAdd + amountToAdd; j++) {
        columns.at(j).push_back("[");
    };

    printResult(&columns);
    
    for (int i = 0; i < *n; i++) { // Columns
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

    for (int i = 0; i < *n; i++) {
        modules.at(i) %= 256;
    };

    for (int i = 0; i < *n; i++) {
        cout << modules.at(i) << endl;
    };
    
    cout << endl;

    for (int i = 0; i < *n; i++) {
        ostringstream streamToHex;
        streamToHex << uppercase << hex << modules.at(i);
        string stringifiedHex = streamToHex.str();
        hexes.at(i) = stringifiedHex;
    };

    for (int i = 0; i < *n; i++) {
        cout << hexes.at(i) << endl;
    };
};


#endif
