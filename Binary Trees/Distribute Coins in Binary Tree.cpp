// LeetCode 979

// You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins 
// in total throughout the whole tree. In one move, we may choose two adjacent nodes and move one coin from one node to 
// another. A move may be from parent to child, or from child to parent.
// Return the minimum number of moves required to make every node have exactly one coin.

/*
Input: root = [0,3,0]
Output: 3
Explanation: From the left child of the root, we move two coins to the root [taking two moves]. 
Then, we move one coin from the root of the tree to the right child.
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

int distributeCoins(Node* root) {
}

int main() {
    Node* root = new Node(0);
    root->left = new Node(3);
    root->right = new Node(0);

    return 0;
}