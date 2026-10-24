// geeksforgeeks

// Given a binary tree with nodes where all elements are unique, implement a function that deletes a node with a specified value (key) from the tree. 
// When a node is deleted, the tree should shrink from the bottom, meaning the deleted node is replaced by the bottom-most, right-most node in the tree. 
// After deletion, the binary tree will be printed using in-order traversal.

// Input: root[] = [10, 20, 30], key = 10
// Output: [20, 30]
// Explanation: The node with the key 10 (the root) is to be deleted. The bottom-most, right-most node (30) replaces node 10.
// The inorder traversal of the modified tree is [20, 30].

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

Node* deleteNode(Node* root, int key) {
}

void inorder(Node* root) {
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    
    int key = 10;

    root = deleteNode(root, key);

    inorder(root); // inorder of modified tree 

    return 0;
}