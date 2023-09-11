/**
 * This program uses Backtracking to solve a labyrinth
 *
 * Author: Rodrigo Terán Hernández A01704108
 * Created: 10/09/2023
*/

#include <vector>
#include "utils.h"
#include "backtracking.h"

using namespace std;

int main() {
    vector<vector<double> > matrix;
    if (!getData(&matrix)) return 0;    
    backtrackingLabyrinth<double>(&matrix);

    return 0;
}
