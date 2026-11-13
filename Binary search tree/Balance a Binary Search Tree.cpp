// LeetCode 1382

// Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return 
// any of them. A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

// Input: root = [1,null,2,null,3,null,4,null,null]
// Output: [2,1,3,null,null,null,4]
// Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.

// LOGIC:
// To convert the given BST into a balanced BST, use:
// 1. Inorder Traversal: Traverse the BST and store all node values in a sorted array. 
// 2. Build Balanced BST: Choose the middle element as the root and recursively construct the left and right subtrees.
// This ensures that the heights of the left and right subtrees remain as balanced as possible.

#include <iostream>
#include <vector>
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

Node* balanceBST(Node* root) {
}

void levelOrder(Node* root) {
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}

int main() {
    Node* root = new Node(1);
    root->right = new Node(2);
    root->right->right = new Node(3);
    root->right->right->right = new Node(4);

    cout << "Original Tree Level Order Traversal:\n";
    levelOrder(root);
    
    Node* newRoot = balanceBST(root);

    cout << "\nBalanced Tree Level Order Traversal:\n";
    levelOrder(newRoot);

    return 0;
}