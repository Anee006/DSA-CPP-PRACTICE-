// #newnotes
// LeetCode 746

// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
// You can either start from the step with index 0, or the step with index 1. Return the minimum cost to reach the top of the floor.

/*
Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
Pay 15 and climb two steps to reach the top. The total cost is 15.
*/

#include <iostream>
#include <vector>
using namespace std;

// Using tabulation + space optimization
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();

    int prev1 = 0; // acts as dp[0] -> dp[n-2]
    int prev2 = 0; // acts as dp[1] -> dp[n-1]
    int result = prev2;

    for(int i = 2; i <= n; i++) {
        result = min(prev2 + cost[i-1] , prev1 + cost[i-2]);
    }
    return result;
}

int main() {
    vector<int> cost = {10, 15, 20};

    cout << minCostClimbingStairs(cost);

    return 0;
}

// TC = O(n)
// SC = O(1)