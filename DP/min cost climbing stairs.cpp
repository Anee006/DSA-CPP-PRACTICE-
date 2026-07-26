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

int minCostClimbingStairs(vector<int>& cost) {
}

int main() {
    vector<int> cost = {10, 15, 20};

    cout << minCostClimbingStairs(cost);

    return 0;
}