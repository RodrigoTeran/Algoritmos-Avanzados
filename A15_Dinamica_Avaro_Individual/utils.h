/**
 * This program has important functions that help us for our program
 *
 * Author: Rodrigo Terán Hernández A01704108
 * Created: 03/09/2023
*/

#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;

/**
 * This function helps us to fill the denominations in the input and the change
 *
 * The time complexity is O(n), been "n" the size of the denominations
 * 
 * @param denominations - The vector to be filled with the data
 * @param change - The integer that references to the change needed
*/
template <class T>
void getData(vector<T> *denominations, int *change) {
    int denominationsSize;
    cin >> denominationsSize;
    cin.ignore();

    for (int i = 0; i < denominationsSize; i++) {
        int denomination;
        cin >> denomination;
        cin.ignore();
        denominations->push_back(denomination);
    };

    int price, bill;
    cin >> price;
    cin.ignore();

    cin >> bill;
    cin.ignore();

    *change = bill - price;
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

/**
 * This function helps us to print the data from the unordered_map
 * that contains what were the coins that we used on our DP
 * algorithm
 *
 * The time complexity is O(n log n), been "n" the size of the denominations
 *
 * @param results - The vector to be printed
 * @param i - The coordenate of the final result combining all of the denominations
 * @param j - The coordenates of the final result meaning the actual total change
*/
void printResult(unordered_map<string, unordered_map<int, int > > *results, int i, int j) {
    stringstream coordenates;
    string coordenateToPrint;

    coordenates << i << "-" << j;
    coordenates >> coordenateToPrint;

    unordered_map<int, int > denominations = results->at(coordenateToPrint);
    unordered_map<int, int>::iterator itr;
    
    vector<int> keys;

    for (itr = denominations.begin(); itr != denominations.end(); itr++) {
        keys.push_back(itr->first);
    }

    sort(keys.begin(), keys.end());

    for (int i = keys.size() - 1; i >= 0; i--) {
        cout << denominations.at(keys.at(i)) << endl;
    }
};

#endif
