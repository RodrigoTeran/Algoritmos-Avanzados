/**
 * This program has important functions that help us for our program
 *
 * Author: Rodrigo Terán Hernández A01704108
 * Created: 21/09/2023
*/

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/**
 * This function helps us to get the file content and now what is going
 * to be our n
 * 
 * @param text - The file content
 * @param n - The number of columns we are going to use in our table
*/
void getData(string* text, int* n) {
    fstream newFile;
    stringstream streamText;

    string fileName;

    cin >> fileName;

    // open a file to perform read operation using file object.
    newFile.open("./tests/files/" + fileName, ios::in); 
    
    // Checking whether the file is open.
    if (newFile.is_open()) { 
        string sa;
        // Read data from the file object and put it into a string.
        while (getline(newFile, sa)) { 
            // Print the data of the string.
            streamText << sa << "\n";
        }
        
        // Close the file object.
        newFile.close(); 
    };

    cin >> *n;

    *text = streamText.str();
    text->pop_back();
};

/**
 * This function helps us print the table on console
 * 
 * @param matrix - The table to print
*/
void printResult(vector<vector<string> > *matrix) {
    for (int i = 0; i < matrix->size(); i++) {
        for (int j = 0; j < matrix->at(i).size(); j++) {
            if (matrix->at(i).at(j) == "\n") {
                cout << "-" << " ";
            } else {
                cout << matrix->at(i).at(j) << " ";
            }
        }
        cout << endl;
    }
}

#endif