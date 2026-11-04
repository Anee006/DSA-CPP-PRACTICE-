// LeetCode 337

// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root. Besides the root, each house 
// has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically 
// contact the police if two directly-linked houses were broken into on the same night.
// Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

// Input: root = [3,2,3,null,3,null,1]
// Output: 7
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

#include <iostream>
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

int rob(Node* root) {
    
}

int main() {
    Node* root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(3);
    root->right->right = new Node(1);

    return 0;
}

