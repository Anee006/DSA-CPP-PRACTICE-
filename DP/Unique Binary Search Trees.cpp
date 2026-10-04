// LeetCode 96
// solved using DP

// Given an integer n, return the number of structurally unique BST's which has exactly n nodes of unique values from 1 to n.

// Input: n = 3
// Output: 5

// LOGIC:
// Choose 1 value as the root. Then values smaller than root -> LEFT subtree & values greater than root -> RIGHT subtree.
// No. of possible trees is: (no. of left subtree possibilities) * (no. of right subtree possibilities)

#include <iostream>
using namespace std;

int numTrees(int n) {
}

int main() {
    int n = 3;

    cout << numTrees(n);

    return 0;
}