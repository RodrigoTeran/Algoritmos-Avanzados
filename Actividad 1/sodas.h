/**
 * This class helps to create a production line of sodas
 * It stores the measurements of the container that fills the sodas.
 * It has a method to calculate what is the maximum number of sodas
 * the container can fill at the same time.
 *
 * Author: Rodrigo Terán Hernández A01704108
 * Created: 16/08/2023
*/

#ifndef SODAS_H
#define SODAS_H

#include <iostream>
#include <cmath>
#include <tgmath.h>

using namespace std;

class SodaProduction {
    private:
        float containerWidthMeters;
        float containerHeightMeters;

        float getContainerMililiters();

    public:
        SodaProduction();
        SodaProduction(float, float);
        
        void setContainerWidth(float);
        void setContainerHeight(float);
        
        int maxSodasPerFill(float);
};

SodaProduction::SodaProduction() {
    containerWidthMeters = 1;
    containerHeightMeters = 1;
};
SodaProduction::SodaProduction(float width, float height) {
    containerWidthMeters = width;
    containerHeightMeters = height;
};

/**
 * This function sets the width of the container in meters
 * @param width - The width of the container in meters
*/
void SodaProduction::setContainerWidth(float width) {
    if (width <= 0) {
        return;
    };
    containerWidthMeters = width;
};

/**
 * This function sets the height of the container in meters
 * @param height - The height of the container in meters
*/
void SodaProduction::setContainerHeight(float height) {
    if (height <= 0) {
        return;
    };
    containerHeightMeters = height;
};

/**
 * This function calculates the container's capacity in mililiters
 * @returns The number of mililiters the container has
*/
float SodaProduction::getContainerMililiters() {
    float radiusContainer = containerWidthMeters / 2;
    float volumeMetersCube = pow(M_PI * radiusContainer, 2) * containerHeightMeters;
    return volumeMetersCube * 1000000;
};

/**
 * This function calculates the maximum number of sodas the container can fill
 * at the same time
 * @param sodaMililiters - The number of mililiters a single soda has
 * @returns The maximum number of sodas the container can fill at the same time
*/
int SodaProduction::maxSodasPerFill(float sodaMililiters) {
    if (sodaMililiters <= 0) {
        // We don't want to divide by zero
        return 0;
    };
    float containerMililiters = getContainerMililiters();
    return floor(containerMililiters / sodaMililiters);

};

#endif