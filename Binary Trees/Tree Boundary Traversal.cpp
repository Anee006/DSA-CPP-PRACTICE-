// geeksforgeeks

// Given a root of a Binary Tree, return its boundary traversal in the following order:
// 1. Left Boundary: Nodes from the root to the leftmost non-leaf node, preferring the left child over the right and excluding leaves.
// 2. Leaf Nodes: All leaf nodes from left to right, covering every leaf in the tree.
// 3. Reverse Right Boundary: Nodes from the root to the rightmost non-leaf node, preferring the right child over the left, excluding leaves, and 
// added in reverse order.
// Note: The root is included once.

// Input: root = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
// Output: [1, 2, 4, 8, 9, 6, 7, 3]

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

vector<int> boundaryTraversal(Node *root) {
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = boundaryTraversal(root);

    for(int x : ans) cout << x << " ";

    return 0;
}