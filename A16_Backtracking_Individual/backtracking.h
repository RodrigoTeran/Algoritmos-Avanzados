/**
 * We use here backtracking to solve what's the best solution
 * to solve a labyrinth
 *
 * Author: Rodrigo Terán Hernández A01704108
 * Created: 10/09/2023
*/

#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

/**
 * With this function we check if it's possible
 * to move to this specific position
 *
 * @param labyrinth - The matrix we are goint to check
 * @param x - The x coordenate
 * @param y - The y coordenate
 **/
bool isPossibleToMove(vector<vector<double> > *labyrinth, int x, int y) {
    return (
        // is in boundary
        x >= 0 &&
        y >= 0 &&
        x < labyrinth->size() &&
        y < labyrinth->at(0).size() &&

        // is possible to travel to this position
        labyrinth->at(x).at(y) == 1
    );
}

/**
 * We use this util to backtrack
 *
 * The complexity is O(n^2), being "n" the size of the matrix
 *
 * @param labyrinth - Our matrix that has the labyrinth data
 * @param x - Where we start solving the maze as the cols coordenate
 * @param y - Where we start solving the maze as the rows coordenate
 * @param solution - Our matrix representing our solution
**/
template <class T>
bool backtrackingLabyrinthUtil(vector<vector<T> > *labyrinth, int x, int y, vector<vector<T> > *solution) {
    if (
        // If we are on the edge
        x == labyrinth->size() - 1 &&
        y == labyrinth->at(0).size() - 1 &&
        labyrinth->at(x).at(y) == 1
    ) {
        solution->at(x).at(y) = 1;
        return true;
    }

    if (isPossibleToMove(labyrinth, x, y)) {
        if (solution->at(x).at(y) == 1) {
            return false;
        }

        // We assume is a solution
        solution->at(x).at(y) = 1;

        if (backtrackingLabyrinthUtil(labyrinth, x + 1, y, solution) || // Moving down
            backtrackingLabyrinthUtil(labyrinth, x, y + 1, solution) || // Moving right
            backtrackingLabyrinthUtil(labyrinth, x - 1, y, solution) || // Moving up
            backtrackingLabyrinthUtil(labyrinth, x, y - 1, solution)) // Moving left
            return true;

        // If we didnt get to the edge then we backtrack
        solution->at(x).at(y) = 0;
        return false;
    }

    return false;
}

/**
 * We use this function to solve the labyrinth using backtracking
 * Here we create another matrix to use it as our solution maxtrix
 * and call our util function to solve recursively
 *
 * The complexity is O(n^2), being "n" the size of the matrix
 *
 * @param matrix - Our matrix with the labyrinth data
**/
template <class T>
void backtrackingLabyrinth(vector<vector<T> > *matrix) {
    // Create empty matrix
    vector<vector<T> > solution(matrix->size(), vector<double>(matrix->at(0).size(), 0));

    if (!backtrackingLabyrinthUtil(matrix, 0, 0, &solution)) {
        cout << "Solution doesn't exist" << endl;
        return;
    }
    
    printResult<double>(&solution);
}

#endif
