#include <iostream>
#include <vector>
using namespace std;

// fn to solve and return selected items
void knapsack(int n, int W, vector<int>& wt, vector<int>& val) {

    // create DP table:
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if(wt[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], val[i-1] + dp[i-1][w - wt[i-1]]);
            } 
            else {
                dp[i][w] = dp[i-1][w]; // copy the val in the above cell (row)
            }
        }
    }

    cout << "Max value (benefit): " << dp[n][W] << endl;

    // Backtrack to find the selected items --> the "x" vector
    vector<int> x(n, 0); // sol vector
    int i = n, w = W; // start from the last cell in the 2D matrix

    while(i > 0 && w > 0) {
        // if val came from including the item
        if(dp[i][w] != dp[i-1][w]) {
            x[i-1] = 1; // include item
            w = w - wt[i-1]; // reduce capacity
        }
        i--;
    }

    // print the sol vector
    cout << "Selected items (x): ";
    for(int i=0; i<n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

int main() {
    int n = 4; // no. of items
    int W = 8; // max capacity of knapsack

    vector<int> wt = {2, 3, 4, 5};   // weight of each item in the knapsack
    vector<int> val = {1, 2, 5, 6};  // benefit of each item in the knapsack

    knapsack(n, W, wt, val);
    return 0;
}

// TC = O(n * W), SC = O(n * W)