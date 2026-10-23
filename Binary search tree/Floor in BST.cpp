// geeksforgeeks

// Given a binary search tree and a number k, find the greatest number in the binary search tree that is less than or equal to k.
// Note: If no such node value exists that is smaller than k, then return -1.

// Input: root = [10, 7, 15, 2, 8, 11, 16],  k  =  14
// Output: 11
// Explanation: The greatest element in the tree which is less than or equal to 14, is 11.

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

int findMaxFork(Node* root, int k) {
    int ans = -1;

    while(root != NULL) {
        if(root->data <= k) {
            ans = root->data;
            root = root->right; // as we need to find the largest no. <= k, go to right subtree of BST
        }

        else root = root->left;
    }

    return ans;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(8);
    root->right = new Node(15);
    root->right->left = new Node(11);
    root->right->right = new Node(16);

    int k = 14;

    cout << findMaxFork(root, k);
    
    return 0;
}

// TC = O(h) , where h = height of tree
// SC = O(1)