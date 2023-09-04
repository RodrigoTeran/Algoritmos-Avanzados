/**
 * This program uses Dynamic Programming and Greeding algorithms
 * to get the minimum amount of coins needed to get the exact change
 * with different coins denominations
 *
 * Author: Rodrigo Terán Hernández A01704108
 * Created: 03/09/2023
*/

#include <iostream>
#include "utils.h"
#include "dynamic.h"
#include "greedy.h"

using namespace std;

int main() {
    int change;
    vector<int> denominations;

    // Get data
    getData(&denominations, &change);
    getChangeDP(&denominations, change);
    cout << endl;
    getChangeGreedy(&denominations, change);
    return 0;
};