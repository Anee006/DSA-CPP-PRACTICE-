// You’re working on pricing for a ride-sharing app like Uber or Ola Cabs.
// A user is traveling from City A to City D, passing through intermediate stops: A → B → C → D
// At each segment, the app offers multiple ride options (bike, auto, cab), each with different costs.
// Segment Bike Auto Cab
// A → B   50 70 100
// B → C   60 80 120
// C → D   70 90 150

// You cannot choose the same ride type consecutively (e.g., no Bike → Bike).
// Find the "minimum total cost to travel from A to D" following the constraint.

// LOGIC:
// At each segment, you choose: Bike (0), Auto (1), or Cab (2). But, you cannot pick the same option as the previous segment.
// Track minimum cost up to each segment for each ride type.
// Transition by choosing a different ride from the previous one.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Cost matrix: rows = segments, cols = {Bike, Auto, Cab}
    vector<vector<int>> cost = {
        {50, 70, 100},   // A -> B
        {60, 80, 120},   // B -> C
        {70, 90, 150}    // C -> D
    };

    return 0;
}