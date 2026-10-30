// geeksforgeeks

// Given the root of a binary tree, swap the values of leaf nodes pairwise in left-to-right order and return the modified tree. If there is an odd 
// number of leaf nodes, leave the last leaf unchanged. The driver code will print the modified tree in level order. For a node at index i:
// Its left child is placed at index 2 * i + 1.
// Its right child is placed at index 2 * i + 2.
// If a child does not exist, 'N' is printed at that position.

// Input: [1, 2, 3, N, 5, 6, 7]
// Output: [1, 2, 3, N, 6, 5, 7]  

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

void levelOrder(Node* root) {
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data;

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}

void pairwiseSwap(Node *root) {
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Before swapping:\n";
    levelOrder(root);

    pairwiseSwap(root);

    cout << "After swapping:\n";
    levelOrder(root);

    return 0;
}