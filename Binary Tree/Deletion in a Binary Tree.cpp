// geeksforgeeks

// Given a binary tree with nodes where all elements are unique, implement a function that deletes a node with a specified value (key) from the tree. 
// When a node is deleted, the tree should shrink from the bottom, meaning the deleted node is replaced by the bottom-most, right-most node in the tree. 
// After deletion, the binary tree will be printed using in-order traversal.

// Input: root[] = [10, 20, 30], key = 10
// Output: [20, 30]
// Explanation: The node with the key 10 (the root) is to be deleted. The bottom-most, right-most node (30) replaces node 10.
// The inorder traversal of the modified tree is [20, 30].

// LOGIC:
// 1. Use level-order traversal (BFS) to find:
// - The node containing key.
// - The bottom-most, right-most node.
// - The parent of that bottom-most node.
// 2. Copy the bottom-most, right-most node's value into the node containing key.
// 3. Delete the bottom-most, right-most node from its parent.

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

Node* deleteNode(Node* root, int key) {
    if(root == NULL) return NULL;

    if(root->left == NULL && root->right == NULL) { // if tree contains only 1 node
        if(root->data == key) return NULL; // delete root node

        return root;
    }

    queue<Node*> q;
    q.push(root);

    Node* target = NULL; // stores the node to delete
    Node* last = NULL;  // stores the bottom-right most node 
    Node* parent = NULL; // stores the parent of the bottom-right most node 

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if(curr->data == key) target = curr;

        if(curr->left) {
            parent = curr;
            last = curr->left;
            q.push(curr->left);
        }

        if(curr->right) {
            parent = curr;
            last = curr->right;
            q.push(curr->right);
        }
    }

    if(target == NULL) return root; // key does not exist in the tree

    target->data = last->data; // replace target's value with the bottom-right node's value

    // remove bottom-right node
    if(parent->right == last) parent->right = NULL;
    else parent->left = NULL;

    delete last;

    return root;
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

// TC: O(n)
// SC: O(n)