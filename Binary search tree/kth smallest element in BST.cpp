// LeetCode 230
// (similar to kth largest Q)

// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

// Input: root = [5,3,6,2,4,null,null,1], k = 3
// Output: 3

// LOGIC:
// Use inorder traversal to find kth smallest element.
// left --> root --> right => gives nodes in ascending order (we get 1st smallest, 2nd smallest... kth smallest)

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

int count = 0, ans = -1; // ans = -1 indicates haven't found the ans yet

void inorder(Node* root, int k) {
    if(root == NULL) return;

    inorder(root->left, k);

    count++; // visit current node

    if(count == k) {
        ans = root->data;
        return;
    }

    inorder(root->right, k);
}

int kthSmallest(Node* root, int k) {
    inorder(root, k);

    return ans;
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);

    int k = 3;
    cout << kthSmallest(root, k) << endl;

    return 0;
}

// TC = O(n)
// SC = O(h)