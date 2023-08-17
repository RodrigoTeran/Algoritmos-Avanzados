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
#include <limits>
#include "shirts.h"
#include "sodas.h"
#include "utils.h"

using namespace std;

int main() {
    // Shirts production testing
    cout << "##### Shirts production testing #####" << endl;
    ShirtsProduction lines = ShirtsProduction();
    lines.daysToProduce(300);

    // Not possible, so it takes no time
    assertValue(0, lines.daysToProduce(-5));

    // It takes no time to produce zero
    assertValue(0, lines.daysToProduce(0));

    lines.daysToProduce(400);
    
    // Sodas production testing
    cout << "\n##### Sodas production testing #####" << endl;
    SodaProduction container = SodaProduction(1, 2);
    assertValue(2617, container.maxSodasPerFill(600));

    // Not possible, so it fills zero
    assertValue(0, container.maxSodasPerFill(-1000));

    // It takes no time to fill zero
    container.setContainerWidth(0.5);
    assertValue(0, container.maxSodasPerFill(0));

    container.setContainerWidth(0.75);
    container.setContainerHeight(1);
    assertValue(147, container.maxSodasPerFill(3000));

    return 0;
};