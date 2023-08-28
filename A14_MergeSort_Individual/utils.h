/**
 * This file has useful functions that
 * help to use our datastructures
 *
 * Author: Rodrigo Terán Hernández A01704108
 * Created: 27/08/2023
*/

#ifndef UTILS_H
#define UTILS_H

#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * This function helps us to fill with data a vector with a string
 * containing comma-separated integers
 *
 * The time complexity is O(n), been "n" the size of the data
 * 
 * @param dataSize - the size of the data
 * @param vectorToBeFilled - a vector to be filled with the data
*/
template <class T>
void fillVectorWithUserData(int *dataSize, vector<T> *vectorToBeFilled) {
    cin >> *dataSize;
    cin.ignore();

    // Time complexity - O(n), been "n" the dataSize
    for (int i = 0; i < *dataSize; i++) {
        double currentNumber;
        cin >> currentNumber;
        cin.ignore();
        vectorToBeFilled->push_back(currentNumber);
    };
};


/**
 * This function helps us to print the data from the vector line by line
 *
 * The time complexity is O(n), been "n" the size of the vector
 * 
 * @param vectorToBePrinted - The vector to be printed
*/
template <class T>
void printVector(vector<T> *vectorToBePrinted) {
    // Time complexity - O(n), been "n" the size of the vector
    for (int i = 0; i < vectorToBePrinted->size(); i++) {
        cout << vectorToBePrinted->at(i) << endl;
    };
};

#endif