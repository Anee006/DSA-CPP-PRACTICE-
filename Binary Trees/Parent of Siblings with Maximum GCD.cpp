// geeksforgeeks

// Given a binary tree, find the value of the node whose two immediate children have the maximum GCD. If multiple nodes have the same 
// maximum GCD, return the maximum value among those nodes.
// A node is considered only if it has both a left and a right child. Return 0 if no such node exists.


// Input: root[] = [1, 3, 5, 6, 9, 4, 8]
// Output: 5
// Explanation: 
// Node 3 has children 6 and 9, whose GCD is 3, while node 5 has children 4 and 8, whose GCD is 4. Since 4 is the max GCD, the ans is 5.

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

int maxGCD(Node* root) {
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(5);
    root->left->left = new Node(6);
    root->left->right = new Node(9);
    root->right->left = new Node(4);
    root->right->right = new Node(8);

    cout << maxGCD(root);
    
    return 0;
}