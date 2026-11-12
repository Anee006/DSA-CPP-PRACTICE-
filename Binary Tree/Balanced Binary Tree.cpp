// LeetCode 110

// Given a binary tree, determine if it is height-balanced.
// A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

// Input: root = [3,9,20,null,null,15,7]
// Output: true

// Logic:
// Calculate height and check whether tree is balanced at the same time.

// Steps:
// For every node:
// Find the height of the left subtree. Find the height of the right subtree.
// If their difference is greater than 1, the tree is not balanced (if, abs(leftHeight - rightHeight) <= 1, the tree is balanced)
// Return the height of the current node.

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

static int idx = -1;

Node* buildBT(vector<int>& pre) {
    idx++;

    Node* root = new Node(pre[idx]);

    if(pre[idx] == -1) return NULL;

    root->left = buildBT(pre);
    root->right = buildBT(pre);

    return root;
}

int checkHeight(Node* root) {
    if(root == NULL) return 0;

    int leftHt = checkHeight(root->left);
    if(leftHt == -1) return -1; // -1 is used to indicate that the tree is unbalanced

    int rightHt = checkHeight(root->right);
    if(rightHt == -1) return -1;

    if(abs(leftHt - rightHt) > 1) return -1;

    return max(leftHt, rightHt) + 1; // returns height of BT
}

bool isBalanced(Node* root) {
    return checkHeight(root) != -1;
}

int main() {
    vector<int> pre = {3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};

    Node* root = buildBT(pre);

    isBalanced(root) ? cout << "True" : cout << "False";

    return 0;
}

// for both checkHeight() and isBalanced():
// TC = O(n)
// SC = O(h) , where h = height of tree