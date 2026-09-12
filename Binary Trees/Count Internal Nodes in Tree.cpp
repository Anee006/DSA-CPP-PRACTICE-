// geeksforgeeks

// Given a Binary Tree of size n, your task is to return the count of all the non-leaf nodes of the given binary tree.

// Input: root[] = [1, 2, 3, 4, 5]
// Output: 2
// Explanation: Nodes 1 and 2 are the only non leaf nodes.

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

int countNonLeafNodes(Node* root) {
    if(root == NULL) return 0;

    // a non-leaf node has atleast one child (hence used || operator)
    if(root->left || root->right) {
        return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
    }

    return 0; // if it has no children, it is a leaf node
}
// TC = O(n)
// SC = O(h), where h is the height of the tree

int main() {
    vector<int> pre = {1, 2, 4, -1, -1, 5, -1, -1, -1, 3};

    Node* root = buildBT(pre);

    cout << countNonLeafNodes(root);

    return 0;
}

