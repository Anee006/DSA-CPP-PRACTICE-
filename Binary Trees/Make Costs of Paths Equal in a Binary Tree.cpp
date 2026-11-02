// LeetCode 2673

// You are given an integer n representing the number of nodes in a perfect binary tree consisting of nodes numbered from 1 to n. 
// The root of the tree is node 1 and each node i in the tree has two children where the left child is the node 2 * i and the right 
// child is 2 * i + 1. Each node in the tree also has a cost represented by a given 0-indexed integer array cost of size n where 
// cost[i] is the cost of node i + 1. You are allowed to increment the cost of any node by 1 any number of times.
// Return the minimum number of increments you need to make the cost of paths from the root to each leaf node equal.

/*
Input: n = 7, cost = [1,5,2,2,3,3,1]
Output: 6

Explanation: We can do the following increments:
- Increase the cost of node 4 one time.
- Increase the cost of node 3 three times.
- Increase the cost of node 7 two times.
The total increments we did is 1 + 3 + 2 = 6.
*/

// STEPS:
// Since the tree is a perfect binary tree, we can use its array representation.
// For a node at index i (0-based):
// Left child = (2 * i + 1) , Right child = (2 * i + 2). We process the nodes from the bottom to the root. (DFS- Bottom up)

// 1. Start from the last non-leaf node (it is at idx n/2 - 1).
// 2. Compare the left and right subtree costs:
// - If both costs are equal, no increments are needed. If they are different, increment the smaller one until both become equal.
// - Add the difference to ans.
// 3. Update the current node. Add the maximum of the left and right costs to the current node's cost.
// This represents the maximum path cost from the current node to any leaf in its subtree.

#include <iostream>
#include <vector>
using namespace std;

int minIncrements(int n, vector<int>& cost) {
    int ans = 0;

    for(int i = n/2 - 1; i >= 0; i--) {
        int left = cost[2 * i + 1];
        int right = cost[2 * i + 2];

        ans += abs(left - right);

        cost[i] += max(left, right);
    }
    return ans;
}

int main() {
    int n = 7;
    vector<int> cost = {1,5,2,2,3,3,1};

    cout << minIncrements(n, cost);

    return 0;
}

// TC: O(n)
// SC: O(1)