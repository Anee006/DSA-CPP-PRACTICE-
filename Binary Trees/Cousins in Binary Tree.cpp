// LeetCode 993

// Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the 
// nodes corresponding to the values x and y in the tree are cousins, or false otherwise.
// Two nodes of a binary tree are cousins if they have the same depth with different parents.

// Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
// Output: true

#include <iostream>
#include <queue>
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

bool isCousins(Node* root, int x, int y) {
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);

    int x = 5, y = 4;

    isCousins(root, x, y) ? cout << "True" : cout << "False";

    return 0;
}