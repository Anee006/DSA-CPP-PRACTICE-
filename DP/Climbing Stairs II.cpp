// LeetCode 3693

// You are climbing a staircase with n + 1 steps, numbered from 0 to n. You are also given a 1-indexed integer array costs of length n, where costs[i]
// is the cost of step i. From step i, you can jump only to step i + 1, i + 2, or i + 3. The cost of jumping from step i to step j is defined as: 
// costs[j] + (j - i)^2. You start from step 0 with cost = 0. Return the minimum total cost to reach step n.

/*
Input: n = 4, costs = [1,2,3,4]
Output: 13

Explanation:
One optimal path is 0 → 1 → 2 → 4

Jump	Cost Calculation	            Cost
0 → 1	costs[1] + (1 - 0)2 = 1 + 1	    2
1 → 2	costs[2] + (2 - 1)2 = 2 + 1	    3
2 → 4	costs[4] + (4 - 2)2 = 4 + 4	    8

Thus, the minimum total cost is 2 + 3 + 8 = 13
*/

// LOGIC:
// dp[i] = Minimum cost required to reach step i from step 0. dp[0] = 0 --> start at step 0 with zero cost.
// We can reach step i from:
// - Step i-1 (jump of 1)
// - Step i-2 (jump of 2)
// - Step i-3 (jump of 3)
// The cost of a jump from step i-j to step i is: costs[i-1] + j^2

// Thus, dp[i] = min{dp[i-1] + costs[i-1] + 1^2 , dp[i-2] + costs[i-1] + 2^2 , dp[i-3] + costs[i-1] + 3^2}

#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n, vector<int>& costs) {

}

int main() {
    int n = 4;
    vector<int> costs = {1, 2, 3, 4};

    cout << climbStairs(n, costs);

    return 0;
}

// TC: O(3n) = O(n)
// SC: O(n)