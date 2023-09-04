/**
 * This program uses dynamic program to get the minimum amount of coins
 * to retrieve when we have different coin denominations and change
 *
 * Author: Rodrigo Terán Hernández A01704108
 * Created: 03/09/2023
*/

#ifndef DYNAMIC_H
#define DYNAMIC_H

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <bits/stdc++.h>
#include "utils.h"

using namespace std;

/**
 * This function helps us to get the coordenate in which the result of the
 * coins used is
 *
 *  The time complexity is O(1)
 * 
 * @param i - The coordenate of the final result combining all of the denominations
 * @param j - The coordenates of the final result meaning the actual total change
*/
string coordenateToString(int i, int j) {
    stringstream coordenates;
    string coordenateToString;

    coordenates << i << "-" << j;
    coordenates >> coordenateToString;

    return coordenateToString;
}

/**
 * This function helps us to modify the map depending on our choice made of the table
 *
 * The time complexity is O(1)
 * 
 * @param results - The map containing all the result of the min amount of coins
 * @param denominationToIncrease - The denomination that we can possibly increase if it was used or not
 * @param mapToUpdate - The map that we got to reference the result
 * @param coordenateToAdd - The coordenate that we are going to add to the map
 * @param addOne - If we are going to add one or not to the denomination
*/
void addResult(
    unordered_map<string, unordered_map<int, int > > *results,
    int denominationToIncrease,
    unordered_map<int, int> mapToUpdate,
    string coordenateToAdd,
    bool addOne
) {
    if (addOne) {
        mapToUpdate.at(denominationToIncrease)++;
    }

    results->insert(make_pair(coordenateToAdd, mapToUpdate));
}

/**
 * This function creates a table of results and on each iteration it checks using dynamic
 * programming what coin denomination to use to add up the result
 *
 * The time complexity is O(n * change), been "n" the size of the denominations
 * The space complexity is O(n * change), been "n" the size of the denominations
 * 
 * @param denominations - The vector containing the denominations to use
 * @param change - The amount of change we need to retrieve
*/
template <class T>
void getChangeDP(vector<T> *denominations, int change) {
    vector<vector<int> > solutions;
    unordered_map<string, unordered_map<int, int > > results;

    sort(denominations->begin(), denominations->end());

    for (int i = 0; i < denominations->size(); i++) {
        vector<int> row;
        for (int j = 0; j <= change; j++) {
            if (i == 0) {
                // Zero quantity in every denomination
                unordered_map<int, int> basicMap;
                for (int denominationI = 0; denominationI < denominations->size(); denominationI++) {
                    int value = 0;

                    if (denominations->at(denominationI) == denominations->at(i)) {
                        value = j / denominations->at(i);
                    }

                    basicMap.insert(make_pair(denominations->at(denominationI), value));
                }
                row.push_back(j / denominations->at(i));
                addResult(&results, denominations->at(i), basicMap, coordenateToString(i, j), false);
            } else if (j - denominations->at(i) >= 0) {
                int withPrevDenominations = solutions.at(i - 1).at(j);
                int addCurrentSmart = row.at(j - denominations->at(i)) +  1;

                if (withPrevDenominations <= addCurrentSmart) {
                    row.push_back(withPrevDenominations);
                    addResult(&results, denominations->at(i - 1), results.at(coordenateToString(i - 1, j)), coordenateToString(i, j), false);
                } else {
                    row.push_back(addCurrentSmart);
                    addResult(&results, denominations->at(i), results.at(coordenateToString(i, j - denominations->at(i))), coordenateToString(i, j), true);
                }
            } else {
                row.push_back(solutions.at(i - 1).at(j));
                addResult(&results, denominations->at(i - 1), results.at(coordenateToString(i - 1, j)), coordenateToString(i, j), false);
            }
        }
        solutions.push_back(row);
    }

    printResult(&results, denominations->size() - 1, change);
}

#endif
