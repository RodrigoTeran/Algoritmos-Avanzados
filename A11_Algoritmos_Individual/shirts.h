/**
 * This class helps to create a production line of shirts.
 * It stores the two production lines efficiency and it has a method to calculate
 * how many days it will take to produce a desired number of shirts.
 *
 * Author: Rodrigo Terán Hernández A01704108
 * Created: 16/08/2023
*/

#ifndef SHIRTS_H
#define SHIRTS_H

#include <iostream>
#include <limits>
#include <tgmath.h>

using namespace std;

class ShirtsProduction {
    private:
        int shirtsPerDayLine1;
        int shirtsPerDayLine2;

    public:
        ShirtsProduction();
        ShirtsProduction(int, int);
        
        void setShirtsProduction1(int);
        void setShirtsProduction2(int);
        
        int daysToProduce(int);
};

ShirtsProduction::ShirtsProduction() {
    shirtsPerDayLine1 = 1;
    shirtsPerDayLine2 = 1;
};
ShirtsProduction::ShirtsProduction(int ShirtsProduction1, int ShirtsProduction2) {
    shirtsPerDayLine1 = ShirtsProduction1;
    shirtsPerDayLine2 = ShirtsProduction2;
};

/**
 * This function sets the number of shirts the line 1 can produce in one day
 * @param shirtsProduction - The number of shirts that this line can produce in one day
*/
void ShirtsProduction::setShirtsProduction1(int shirtsProduction) {
    if (shirtsProduction < 0) {
        return;
    };
    shirtsPerDayLine1 = shirtsProduction;
};

/**
 * This function sets the number of shirts the line 2 can produce in one day
 * @param shirtsProduction - The number of shirts that this line can produce in one day
*/
void ShirtsProduction::setShirtsProduction2(int shirtsProduction) {
    if (shirtsProduction < 0) {
        return;
    };
    shirtsPerDayLine2 = shirtsProduction;
};

/**
 * This function calculates the number of days that two production lines
 * will satisfy the desired number of shirts
 * @param numberShirts - The number of shirts to be produced
 * @returns The number of days that the production will take
*/
int ShirtsProduction::daysToProduce(int numberShirts) {
    if (numberShirts <= 0) {
        return 0;
    };
    int combinedProductionTime = shirtsPerDayLine1 + shirtsPerDayLine2;
    if (combinedProductionTime == 0) {
        // We don't want to divide by zero
        return numeric_limits<int>::max();
    };
    return ceil(1.0 * numberShirts / combinedProductionTime);
};

#endif