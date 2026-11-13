// LeetCode 1530

// You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the 
// length of the shortest path between them is less than or equal to distance. Return the number of good leaf node pairs in the tree.

// Input: root = [1,2,3,4,5,6,7], distance = 3
// Output: 2
// Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. 

// LOGIC:
// If the current node is a leaf node, return a vector containing distance 1.
// Recursively find the distances of leaf nodes in the left and right subtrees.
// Compare every distance from the left subtree with every distance from the right subtree.
// If the sum of the two distances is less than or equal to distance, increment the count.
// Return the updated distances to the parent node.

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

int ans = 0;

vector<int> dfs(Node* root, int distance) {
    if(root == NULL) return {};

    // if leaf node --> return distance 1
    if(root->left == NULL && root->right == NULL) return {1};

    vector<int> left = dfs(root->left, distance);
    vector<int> right = dfs(root->right, distance);

    // check all leaf pairs
    for(int l : left) {
        for(int r : right) {
            if(l + r <= distance) ans++;
        }
    }

    // return distances to parent
    vector<int> res;

    for(int i : left) {
        if(i + 1 < distance) res.push_back(i + 1);
    }

    for(int i : right) {
        if(i + 1 < distance) res.push_back(i + 1);
    }

    return res;
}

int countPairs(Node* root, int distance) {
    dfs(root, distance);

    return ans;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int distance = 3;

    cout << countPairs(root, distance);

    return 0;
}

// TC: O(n * d^d)
// SC: O(n * d)