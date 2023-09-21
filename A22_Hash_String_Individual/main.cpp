/**
 * This program 
 *
 * Author: Rodrigo Terán Hernández A01704108
 * Created: 21/09/2023
*/

#include "utils.h"
#include "hash.h"

using namespace std;

int main() {
    int n;
    string text;

    getData(&text, &n);
    createTable(&text, &n);

    return 0;
}
