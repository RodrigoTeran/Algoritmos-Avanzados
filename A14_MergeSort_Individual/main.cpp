/**
 * This program uses the merge sort algorithm to
 * sort an array of numbers in descending order
 *
 * Author: Rodrigo Terán Hernández A01704108
 * Created: 27/08/2023
*/

#include <iostream>
#include "utils.h"
#include "merge.h"

using namespace std;

int main() {
    int dataSize;
    vector<double> numbers;

    // Get raw numbers
    fillVectorWithUserData(&dataSize, &numbers);

    // Sort them
    sort(&numbers);

    // Print sorted numbers
    cout << "Sorted:" << endl;
    printVector(&numbers);

    return 0;
};