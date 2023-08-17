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
#include <sstream>
#include <random>
#include <limits>
#include <tgmath.h>

using namespace std;

class ShirtsProduction {
    private:
        int shirtsPerDayLine1;
        int shirtsPerDayLine2;

        void setProductionLines();
        void logShirtsResult(int, int, string, string);

    public:
        ShirtsProduction();
        int daysToProduce(int);
};

ShirtsProduction::ShirtsProduction() {
    setProductionLines();
};

/**
 * This function sets the production lines at a random value
 * from 0 to 100 shirts per day
*/
void ShirtsProduction::setProductionLines() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, 100);

    shirtsPerDayLine1 = distr(gen);
    shirtsPerDayLine2 = distr(gen);
};

/**
 * This function calculates the number of days that two production lines
 * will satisfy the desired number of shirts
 * @param numberShirts - The number of shirts to be produced
 * @returns The number of days that the production will take
*/
int ShirtsProduction::daysToProduce(int numberShirts) {
    if (numberShirts <= 0) {
        logShirtsResult(0, numberShirts, "Line 1: []", "Line 2: []");
        return 0;
    };

    stringstream historyLine1;
    stringstream historyLine2;

    int daysToProduce = 0;
    int missingShirts = numberShirts;

    historyLine1 << "Line 1: [";
    historyLine2 << "Line 2: [";
    while (missingShirts > 0) {
        missingShirts -= (shirtsPerDayLine1 + shirtsPerDayLine2);
        if (daysToProduce != 0) {
            historyLine1 << ", ";
            historyLine2 << ", ";
        };
        historyLine1 << shirtsPerDayLine1;
        historyLine2 << shirtsPerDayLine2;
        daysToProduce += 1;

        // Next day
        setProductionLines();
    };

    historyLine1 << "]";
    historyLine2 << "]";

    logShirtsResult(daysToProduce, numberShirts, historyLine1.str(), historyLine2.str());
    return daysToProduce;
};

/**
 * This function logs the result for the shirt function
 * @param daysToProduce - The number of days it took to produce those shirts
 * @param shirts - The number of shirts produced
 * @param historyLine1 - String containing all the production of line 1 at different days
 * @param historyLine2 - String containing all the production of line 2 at different days
*/
void ShirtsProduction::logShirtsResult(int daysToProduce, int shirts, string historyLine1, string historyLine2) {
    cout << endl << "- It took " << daysToProduce << " day";
    if (daysToProduce != 1) {
        cout << "s";
    };
    cout << " to produce " << shirts << " shirts." << endl;
    cout << "Lines of production: " << endl;
    cout << historyLine1 << endl;
    cout << historyLine2 << endl;
};

#endif