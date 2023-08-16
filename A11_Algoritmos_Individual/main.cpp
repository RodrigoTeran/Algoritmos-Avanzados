/**
 * This program has two set of problems.
 * A production line of shirts and a production line of sodas.
 * Each one of these problems have some variables related to the production
 * capacity of their lines and the problem is to find the production time and the max production
 * of sodas respectively.
 *
 * Author: Rodrigo Terán Hernández A01704108
 * Created: 16/08/2023
*/

#include <iostream>
#include "shirts.h"
#include "sodas.h"
#include "utils.h"

using namespace std;

int main() {
    // Shirts production testing
    cout << "Shirts production testing..." << endl;
    ShirtsProduction lines = ShirtsProduction(4, 5);
    assertValue(4, lines.daysToProduce(30));
    assertValue(0, lines.daysToProduce(-5));

    lines.setShirtsProduction1(5);
    assertValue(6, lines.daysToProduce(55));

    lines.setShirtsProduction1(0);
    lines.setShirtsProduction2(10);
    assertValue(10, lines.daysToProduce(100));
    
    // Sodas production testing
    cout << "\nSodas production testing..." << endl;
    SodaProduction container = SodaProduction(1, 2);
    assertValue(8224, container.maxSodasPerFill(600));
    assertValue(4934, container.maxSodasPerFill(1000));

    container.setContainerWidth(0.5);
    assertValue(4838, container.maxSodasPerFill(255));

    container.setContainerWidth(0.75);
    container.setContainerHeight(1);
    assertValue(462, container.maxSodasPerFill(3000));

    return 0;
};