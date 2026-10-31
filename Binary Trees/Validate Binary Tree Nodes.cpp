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
    vector<int> indegree(n, 0); // stores indegree of each node

    // calc indegree of each node
    for(int i = 0; i < n; i++) {
        if(leftChild[i] != -1) indegree[leftChild[i]]++;
        if(rightChild[i] != -1) indegree[rightChild[i]]++;
    }

    // find root node (has indegree = 0)
    int root = -1;

    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            if(root != -1) return false; // can't have more than 1 root in a valid binary tree

            root = i; // else, current node is the root node
        }
    }

    if(root == -1) return false; // no root found, hence invalid binary tree

    // perform BFS traversal starting from root
    queue<int> q;
    vector<bool> vis(n, false); // visited vector

    q.push(root);
    vis[root] = true;

    int count = 0; // tracks how many nodes are visited in the BFS traversal of the tree

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        count++;

        if(leftChild[curr] != -1) { // visit left child
            int child = leftChild[curr];

            if(vis[child]) return false;

            vis[child] = true;
            q.push(child);
        }

        if(rightChild[curr] != -1) { // visit right child
            int child = rightChild[curr];

            if(vis[child]) return false;

            vis[child] = true;
            q.push(child);
        }
    }
    return count == n; // if it is a valid binary tree, all nodes must be visited by now
} 

int main() {
    int n = 4;
    vector<int> leftChild = {1,-1,3,-1};
    vector<int> rightChild = {2,-1,-1,-1};

    validateBinaryTreeNodes(n, leftChild, rightChild) ? cout << "True" : cout << "False";

    return 0;
}

// TC: O(n)
// SC: O(n)