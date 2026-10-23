// LeetCode 938

// Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a
// value in the inclusive range [low, high].

// Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
// Output: 32
// Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

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

int rangeSumBST(Node* root, int low, int high) {
    if(root == NULL) return 0;

    // if curr val is smaller than low, search in right subtree
    if(root->data < low) return rangeSumBST(root->right, low, high);

    // if curr val is greater than high, search in left subtree
    if(root->data > high) return rangeSumBST(root->left, low, high);

    // if curr val lies in [low, high]
    return root->data + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right = new Node(15);
    root->right->right = new Node(18);

    int low = 7, high = 15;

    cout << rangeSumBST(root, low, high);
    
    return 0;
}

// TC = O(n)
// SC = O(n)