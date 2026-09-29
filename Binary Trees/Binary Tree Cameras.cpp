// LeetCode 968

// You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its 
// parent, itself, and its immediate children. Return the minimum number of cameras needed to monitor all nodes of the tree.

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

int minCameraCover(Node* root) {
    
}

int main() {
    Node* root = new Node(0);
    root->left = new Node(0);
    root->left->left = new Node(0);
    root->left->left->left = new Node(0);
    root->left->left->left->right = new Node(0);

    return 0;
}