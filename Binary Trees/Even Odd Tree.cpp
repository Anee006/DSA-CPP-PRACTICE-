// LeetCode 1609

// A binary tree is named Even-Odd if it meets the following conditions:
// The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
// For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
// For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
// Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.

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

bool isEvenOddTree(Node* root) {

}

int main() {
    Node* root = new Node(1);
    root->left = new Node(10);
    root->left->left = new Node(3);
    root->left->left->left = new Node(12);
    root->left->left->right = new Node(8);
    root->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    root->right->left->left = new Node(6);
    root->right->right->right = new Node(2);

    return 0;
}