// LeetCode 96
// solved using DP

// Given an integer n, return the number of structurally unique BST's which has exactly n nodes of unique values from 1 to n.

// Input: n = 3
// Output: 5

// LOGIC:
// Choose 1 value as the root. Then values smaller than root -> LEFT subtree & values greater than root -> RIGHT subtree.
// No. of possible trees is: (no. of left subtree possibilities) * (no. of right subtree possibilities)

#include <iostream>
#include <vector>
using namespace std;

int numTrees(int n) {
    vector<int> dp(n + 1, 0); // dp[i] = no. of unique BSTs that can be created using i nodes

    // base case
    dp[0] = 1; // dp[0] means have 0 nodes --> 1 possible empty subtree (when we choose a root, one side might have 0 nodes)
    dp[1] = 1; // with 1 node there is only 1 possible BST

    // for dp[2]: There are two choices for the root

    // calc no. of unique BSTs for 2 to n nodes
    for(int nodes = 2; nodes <= n; nodes++) {

        // try every val as the root
        for(int root = 1; root <= nodes; root++) {
            int left = root - 1; // left subtree size (root is not included in left subtree)
            int right = nodes - root; // right subtree size

            dp[nodes] += dp[left] * dp[right];
        }
    }
    return dp[n];
}

int main() {
    int n = 3;

    cout << numTrees(n);

    return 0;
}

// TC = O(n*n)
// SC = O(n)