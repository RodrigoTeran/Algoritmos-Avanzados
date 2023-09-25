/**
 * This program asks for a string and retrieves the suffix array
 * ordered alphabetically.
 *
 * Author: Rodrigo Terán Hernández A01704108
 * Created: 24/09/2023
*/

#include <iostream>
#include "utils.h"
#include "suffix.h"
using namespace std;

int main() {
	string textToCompute;
	cin >> textToCompute;
    vector<int> suffixArray(textToCompute.size());
    buildSuffixArray(textToCompute, &suffixArray);
	printResult(&suffixArray, textToCompute);
	return 0;
}
