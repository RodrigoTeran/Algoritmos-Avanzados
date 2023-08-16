/**
 * This file helps to assert tests and log the result.
 *
 * Author: Rodrigo Terán Hernández A01704108
 * Created: 16/08/2023
*/

#ifndef UTILS_H
#define UTILS_H

#include <iostream>

using namespace std;

/**
 * This function logs if a value is equal or not to a desired one
 * @param desiredValue - The expected value
 * @param computedValue - The value that was computed an wanted to compare
*/
void assertValue(int desiredValue, int computedValue) {
    if (desiredValue == computedValue) {
        cout << "✓ Test passed: " << computedValue <<  " equals " << desiredValue << endl;
        return;
    };

    cout << "𐄂 Test not passed: " << computedValue <<  " not equals " << desiredValue << endl;
};

#endif