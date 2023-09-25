/**
 * This program has important functions that help us for our program
 *
 * Author: Rodrigo Terán Hernández A01704108
 * Created: 24/09/2023
*/

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>

using namespace std;

/**
 * This function helps us print the vector containing the suffix array
 * 
 * @param arr - The table to print
*/
void printResult(vector<int> *vector, string txt) {
	for (int i = 0; i < vector->size(); i++) {
		cout << vector->at(i) << " ";
	}
}

#endif