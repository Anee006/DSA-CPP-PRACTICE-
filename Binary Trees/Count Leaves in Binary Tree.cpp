// geeksforgeeks

// Given a Binary Tree of size n, You have to count leaves in it. 

// input: {1, 10, 39, 5}
// output: 2
// explanation: 5 and 39 are the two leaf nodes.

// logic:
// leaf is a node whose left and right child both are NULL.

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

// build BT using preorder sequence
Node* buildBT(vector<int>& pre) {
    idx++;

    Node* root = new Node(pre[idx]);

    if(pre[idx] == -1) return NULL;

    root->left = buildBT(pre);
    root->right = buildBT(pre);

    return root;
}

int countLeaves(Node* root) {
    if(root == NULL) return 0;

    if(root->left == NULL && root->right == NULL) return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}
// TC = O(n)
// SC = O(n)

int main() {
    vector<int> pre = {1, 10, 5, -1, -1, -1, 39, -1, -1};

    Node* root = buildBT(pre);

    cout << countLeaves(root);

    return 0;
}
