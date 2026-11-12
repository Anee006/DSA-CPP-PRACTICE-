// LeetCode 1028
// Using stack

// We run a preorder depth-first search (DFS) on the root of a binary tree. At each node in this traversal, we output D dashes (where D is the depth 
// of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the 
// root node is 0. If a node has only one child, that child is guaranteed to be the left child.
// Given the output traversal of this traversal, recover the tree and return its root.

// Input: traversal = "1-2--3--4-5--6--7"
// Output: [1,2,5,3,4,6,7]

#include <iostream>
#include <stack>
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

Node* recoverFromPreorder(string traversal) {
}

void preorder(Node* root) {
    if(root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    string traversal = "1-2--3--4-5--6--7";

    Node* root = recoverFromPreorder(traversal);

    preorder(root); // verify the tree created

    return 0;
}

