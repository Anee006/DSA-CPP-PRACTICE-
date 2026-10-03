// geeksforgeeks

// Given the root of a Binary Search Tree and an integer k, find the k-th largest element in the BST without modifying its structure.

// Input: root = [4, 2, 9], k = 2
// Output: 4
// Explanation: The second largest element is 4.

// LOGIC:
// Use reverse inorder
// Inorder: Left -> Root -> Right => gives elements in ascending order.
// Reverse inorder: Right -> Root -> Left => gives elements in descending order.
// (the nodes are visited as: 1st largest, 2nd largest... k-th largest)

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

int count = 0, ans = 0;

void reverseInorder(Node* root, int k) {
    if(root == NULL) return;

    reverseInorder(root->right, k);

    count++; // visit current node

    if(count == k) { // found req kth largest element
        ans = root->data;
        return;
    }

    reverseInorder(root->left, k);
}

int kthLargest(Node *root, int k) {
    reverseInorder(root, k);

    return ans;
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(9);

    int k = 2;
    cout << kthLargest(root, k);

    return 0;
}

// TC = O(H + k) , where H = height of tree
// SC= O(H)