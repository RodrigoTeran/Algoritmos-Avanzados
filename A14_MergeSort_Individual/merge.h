/**
 * This file has the implementation of mergeSort
 * sorting in descending order
 *
 * Author: Rodrigo Terán Hernández A01704108
 * Created: 27/08/2023
*/

#ifndef MERGE_H
#define MERGE_H

#include "utils.h"
#include <string>
#include <vector>

using namespace std;

/**
 * This function helps us to merge two sections from a vector
 * separated from "left", "mid", and "right"
 * this two sections should be already sorted.
 *
 * The time complexity is O(n), been "n" the size of the vector we need to merge
 * In this case it can be a small part, but still we only care about the "n".
 * 
 * @param vectorToBeSorted - the vector that has all the data and its going to be sorted
 * @param left - from where we need to merge
 * @param midPoint - the midpoint that separate the two sorted sections of the vector
 * @param right - the last inclusive index value that we need to considerate to merge
*/
template <class T>
void merge(vector<T> *vectorToBeSorted, int left, int midPoint, int right) {
    vector<T> subArrayLeft;
    vector<T> subArrayRight;

    // Time complexity - O(n), been "n" = "right" - "left", beacuse "i" will iterate from "left" to "right"
    for (int i = left; i <= right; i++) {
        if (i <= midPoint) {
            subArrayLeft.push_back(vectorToBeSorted->at(i));
        } else {
            subArrayRight.push_back(vectorToBeSorted->at(i));
        }
    };

    int index = left;
    int indexLeft = 0;
    int indexRight = 0;

    // Time complexity - O(n), been "n" at the most the sum of the sizes of the two sub arrays
    while (
        indexLeft < subArrayLeft.size() &&
        indexRight < subArrayRight.size()
    ) {
        double compareLeft = subArrayLeft.at(indexLeft);
        double compareRight = subArrayRight.at(indexRight);

        if (compareLeft >= compareRight) {
            vectorToBeSorted->at(index) = compareLeft;
            indexLeft++;
        } else {
            vectorToBeSorted->at(index) = compareRight;
            indexRight++;
        };

        index++;
    };

    // Time complexity - O(n), been "n" the size of the left subarray
    while (indexLeft < subArrayLeft.size()) {
        double leftValue = subArrayLeft.at(indexLeft);
        vectorToBeSorted->at(index) = leftValue;
        indexLeft++;
        index++;
    };

    // Time complexity - O(n), been "n" the size of the right subarray
    while (indexRight < subArrayRight.size()) {
        double rightValue = subArrayRight.at(indexRight);
        vectorToBeSorted->at(index) = rightValue;
        indexRight++;
        index++;
    };
};

/**
 * This function helps us to sort the vector from a starting
 * index to and end
 *
 * The time complexity is O(n log(n)), been "n" the size of the vector we need to sort
 * 
 * @param vectorToBeSorted - the vector that has all the data and its going to be sorted
 * @param left - from where we need to sort
 * @param right - the last inclusive index value that we need to considerate to sort
*/
template <class T>
void mergeSort(vector<T> *vectorToBeSorted, int left, int right) {
    if (left >= right) {
        return;
    }
    
    int midPoint = left + (right - left) / 2;

    // Here we split the job by two every time, so the time complexity is the height of the binary tree
    // we create, that heigh is log(n)
    mergeSort(vectorToBeSorted, left, midPoint);
    mergeSort(vectorToBeSorted, midPoint + 1, right);

    // And on each step it takes O(n) to merge
    // So the overall time complexity is O(n log(n))
    merge(vectorToBeSorted, left, midPoint, right);
};

/**
 * This function helps us to call the mergeSort function so the user
 * doesn´t need to call it with its corresponding starting indexes
 *
 * The time complexity is O(n log(n)), been "n" the size of the vector we need to sort
 * 
 * @param vectorToBeSorted - the vector that has all the data and its going to be sorted
*/
template <class T>
void sort(vector<T> *vectorToBeSorted) {
    mergeSort(vectorToBeSorted, 0, vectorToBeSorted->size() - 1);
};

#endif