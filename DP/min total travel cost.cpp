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
#include <algorithm>
using namespace std;

int main() {
    // Cost matrix: rows = segments, cols = {Bike, Auto, Cab}
    vector<vector<int>> cost = {
        {50, 70, 100},   // A -> B
        {60, 80, 120},   // B -> C
        {70, 90, 150}    // C -> D
    };

    int n = cost.size();

    // dp[i][j] --> min cost to reach segment "i" using ride "j"
    vector<vector<int>> dp(n, vector<int>(3,0));

    // initialize the first segment (A → B) so that we have previous results to work with
    for(int j=0; j<3; j++) dp[0][j] = cost[0][j]; // base case

    for(int i=1; i<n; i++) {

        // dp[i][j] = cost[i][j] + min(other two from previous row)  --> so that we don't pick same ride as before

        dp[i][0] = cost[i][0] + min(dp[i-1][1], dp[i-1][2]); // bike
        dp[i][1] = cost[i][1] + min(dp[i-1][0], dp[i-1][2]); // auto
        dp[i][2] = cost[i][2] + min(dp[i-1][0], dp[i-1][1]); // cab
    }

    int ans = min({dp[n-1][0], dp[n-1][1], dp[n-1][2]}); // ans is the min val of last segment

    cout << "Min cost: " << ans;  // ans = 200 (50 + 80 + 70)

    return 0;
}

// TC = O(n x 3) = O(n)