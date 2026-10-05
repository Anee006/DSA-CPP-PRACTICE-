// LeetCode 653
// Using Two-Pointer approach

// Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that 
// their sum is equal to k, or false otherwise.

// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true

// LOGIC:
// perform inorder traveral on BST to get a sorted array. Use 2 pointers to find a pair whose sum == k.

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

bool findTarget(Node* root, int k) {
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right = new Node(6);
    root->right->right = new Node(7);

    int k = 9;

    findTarget(root, k) ? cout << "True" : cout << "False";

    return 0;
}