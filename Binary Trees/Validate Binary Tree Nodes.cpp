// LeetCode 1361

// You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all 
// the given nodes form exactly one valid binary tree. If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

// Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
// Output: true

// LOGIC:
// For a binary tree to be valid, check these 3 conditions:
// 1. A valid binary tree must have exactly one node with indegree 0 (i.e, it should have no parent).
// 2. Every other node has exactly one parent. No node can have more than one parent.
// 3. All nodes are connected: Starting from the root, we must be able to visit all n nodes.

// STEPS:
// First, calculate the indegree (number of incoming edges) of every node.
// Find the node whose indegree is 0. If there are multiple roots or no root, return false.
// Use BFS (Breadth-First Search) starting from the root. If a node is visited more than once, return false.
// Finally, check whether the number of visited nodes equals n.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
}

int main() {
    int n = 4;
    vector<int> leftChild = {1,-1,3,-1};
    vector<int> rightChild = {2,-1,-1,-1};

    validateBinaryTreeNodes(n, leftChild, rightChild) ? cout << "True" : cout << "False";

    return 0;
}