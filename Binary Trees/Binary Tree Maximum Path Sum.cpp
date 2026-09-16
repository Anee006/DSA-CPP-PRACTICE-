// #newnotes
// LeetCode 124

// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. 
// A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
// The path sum of a path is the sum of the node's values in the path.
// Given the root of a binary tree, return the maximum path sum of any non-empty path.

/*
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
*/
 

// LOGIC:
// For every node calculate:
// 1. Max gain from this node going upwards. 
//   - can choose a node and 1 of its subtree. Can't take both left and right, bcoz path wouldn't continue through parent.
// 2. Max path passing through this node --> leftGain + node value + rightGain
//  - forms a complete path fron left subtree --> node --> right subtree

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;

Node* buildBT(vector<int>& pre) {
    idx++;

    Node* root = new Node(pre[idx]);

    if(pre[idx] == -1) return NULL;

    root->left = buildBT(pre);
    root->right = buildBT(pre);

    return root;
}

int maxSum = 0; // global max

int maxGain(Node* root) {
    if(root == NULL) return 0; // base case

    int leftGain = max(0, maxGain(root->left)); // max gain from left subtree
    // using 0 here bcoz, use the left subtree only if it contributes something positive

    int rightGain = max(0, maxGain(root->right)); // max gain from right subtree

    int currSum = root->data + leftGain + rightGain; // max path passing through current node

    maxSum = max(maxSum, currSum);

    return root->data + max(leftGain, rightGain); // gain returned to parent
}

int maxPathSum(Node* root) {
    maxSum = INT_MIN; // path must be non-empty (INT_MIN handles trees containing -ve values)

    maxGain(root);
    
    return maxSum;
}

int main() {
    vector<int> pre = {-10, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};

    Node* root = buildBT(pre);

    cout << maxPathSum(root);

    return 0;
}

// TC = O(n) , where n = no. of nodes
// SC = O(h) , where h = height of tree