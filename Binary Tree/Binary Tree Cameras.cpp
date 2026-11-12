// LeetCode 968

// You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its 
// parent, itself, and its immediate children. Return the minimum number of cameras needed to monitor all nodes of the tree.

/*
Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree
*/

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

int cameras = 0;

// use postorder traversal (before deciding whether to put camera at the current node, need to know the states of its children)
// States:
// 0 = Node needs a camera
// 1 = Node has a camera
// 2 = Node is covered

int dfs(Node* root) {
    if(root == NULL) return 2; // NULL nodes are considered covered

    int leftChild = dfs(root->left);
    int rightChild = dfs(root->right);

    if(leftChild == 0 || rightChild == 0) { // if any child needs a camera --> put camera at current node
        cameras++;
        return 1;
    }

    if(leftChild == 1 || rightChild == 1) return 2; // if any child has a camera --> current node is covered

    return 0; // both children are covered but current node is not covered
}

int minCameraCover(Node* root) {
    if(dfs(root) == 0) cameras++; // if root itself needs a camera, install one at root

    return cameras;
    
}

int main() {
    Node* root = new Node(0);
    root->left = new Node(0);
    root->left->left = new Node(0);
    root->left->left->left = new Node(0);
    root->left->left->left->right = new Node(0);

    cout << minCameraCover(root);

    return 0;
}

// TC = O(n)
// SC = O(h)