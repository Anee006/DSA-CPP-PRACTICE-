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

// find leaf nodes using dfs
void findLeaves(Node* root, vector<Node*>& leaves) {
    if(root == NULL) return;

    // check if current node is a leaf node
    if(root->left == NULL && root->right == NULL) leaves.push_back(root);

    findLeaves(root->left, leaves);
    findLeaves(root->right, leaves);
}

void pairwiseSwap(Node *root) {
    if(root == NULL) return;

    vector<Node*> leaves;

    findLeaves(root, leaves);

    for(int i = 0; i + 1 < leaves.size(); i += 2) {
        swap(leaves[i]->data , leaves[i+1]->data); // swap pairwise
    }
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

    cout << "\nAfter swapping:\n";
    levelOrder(root);

    return 0;
}

// TC: O(n) , where n = no. of nodes
// SC: O(L + h) , where L = no. of leaf nodes , h = tree height