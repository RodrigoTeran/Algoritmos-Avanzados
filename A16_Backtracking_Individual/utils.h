/**
 * This program has important functions that help us for our program
 *
 * Author: Rodrigo Terán Hernández A01704108
 * Created: 10/09/2023
*/

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>

using namespace std;

/**
 * This function helps us to know the rows and cols of the labyrinth
 * and to fill our matrix with the provided data
 * 
 * @param matrix - The matrix we want to fill with the data
*/
template <class T>
bool getData(vector<vector<T> > *matrix) {
    int rows, cols;

    cin >> rows;
    cin.ignore();

    cin >> cols;
    cin.ignore();

    if (rows <= 0 || cols <= 0) {
        cout << "The size of the labyrinth needs to ve valid" << endl;
        return false;
    }

    for (int i = 0; i < rows; i++) {
        vector<double> newRow(cols);
        int cellValue;
        for (int j = 0; j < cols; j++) {
            cin >> cellValue;
            // If the cell is neither 1 nor 0
            if (cellValue != 1 && cellValue != 0) {
                cout << "The labyrinth can only have 1's or 0's as cell's values" << endl;
                return false;
            }
            newRow[j] = cellValue;
        }
        matrix->push_back(newRow);
    }

    return true;
};

/**
 * This function helps us to print a matrix
 *
 * The time complexity is O(n^2), been "n" the size of the matrix
 * 
 * @param matrix - The matrix we want to print
*/
template <class T>
void printResult(vector<vector<T> > *matrix) {
    for (int i = 0; i < matrix->size(); i++) {
        for (int j = 0; j < matrix->at(i).size(); j++) {
            cout << matrix->at(i).at(j) << " ";
        }
        cout << endl;
    }
}

#endif