/**
 * This program creates a suffix array from a given string
 *
 * Author: Rodrigo Terán Hernández A01704108
 * Created: 24/09/2023
*/

#ifndef SUFFIX_H
#define SUFFIX_H

#include <string>
#include <map>
#include <vector>

using namespace std;

/**
 * This function helps us to create the suffix array using an
 * ordered map
 *
 * Time complexity: O(n^2 + nlogn)
 * Spce complexity: O(n)
 * 
 * @param txt - The text to create the suffix array
 * @param suffixArr - The vector to store the suffix array
*/
void buildSuffixArray(string txt, vector<int> *suffixArr) {
    map<string, int> Map;
    int n = txt.size();

    // Creating a map containing the suffixes and its indexes
    string sub = "";
    for (int i = n - 1; i >= 0; i--) {
        sub = txt[i] + sub;
        Map[sub] = i;
    }
 
    int j = 0;
    for(map<string, int>::iterator it = Map.begin(); it != Map.end(); it++) {
        suffixArr->at(j) = it->second;
        j++;
    };
}

#endif