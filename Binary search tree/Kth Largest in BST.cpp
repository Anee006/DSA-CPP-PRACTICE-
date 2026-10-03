// geeksforgeeks

// Given the root of a Binary Search Tree and an integer k, find the k-th largest element in the BST without modifying its structure.

// Input: root = [4, 2, 9], k = 2
// Output: 4
// Explanation: The second largest element is 4.

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

int kthLargest(Node *root, int k) {

}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(9);

    int k = 2;
    cout << kthLargest(root, k);

    return 0;
}