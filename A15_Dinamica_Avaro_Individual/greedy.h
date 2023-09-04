/**
 * This program uses a greedy approach to get the minimum amount of coins
 * to retrieve when we have different coin denominations and change
 *
 * Author: Rodrigo Terán Hernández A01704108
 * Created: 03/09/2023
*/

#ifndef GREEDY_H
#define GREEDY_H

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "utils.h"

using namespace std;

/**
 * This function sorts from higher to lower the coin's denominations so it always uses the
 * max coin denomination. This is a greedy approach to get the minimun
 * amount of coins to use
 *
 * The time complexity is O(n), been "n" the size of the denominations
 * The space complexity is O(n), been "n" the size of the denominations
 * 
 * @param denominations - The vector containing the denominations to use
 * @param change - The amount of change we need to retrieve
*/
void getChangeGreedy(vector<int> *denominations, int change) {
    sort(denominations->begin(), denominations->end(), greater<int>());

    vector<int> results(denominations->size(), 0);

    for (int i = 0; i < denominations->size(); i++) {
        results.at(i) = change / denominations->at(i);
        change -= results.at(i) * denominations->at(i);
    };
    
    printVector(&results);
}

#endif