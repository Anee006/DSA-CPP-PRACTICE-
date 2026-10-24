// LeetCode 863

// Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of 
// all nodes that have a distance k from the target node.

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
// Output: [7,4,1]
// Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

// LOGIC:
// Store each node's parent using DFS.
// Use BFS starting from the target node, exploring left, right, and parent nodes until reached distance k.

#include <iostream>
#include <vector>
#include <unordered_map>
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

vector<int> distanceK(Node* root, Node* target, int k) {
}

int main() {
    Node* root = new Node(3);
    root->left = new Node(5);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right = new Node(1);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

    return 0;
}