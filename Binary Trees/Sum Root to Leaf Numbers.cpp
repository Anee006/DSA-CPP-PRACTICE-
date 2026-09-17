// LeetCode 129
// using dfs

// You are given the root of a binary tree containing digits from 0 to 9 only.
// Each root-to-leaf path in the tree represents a number.
// For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
// Return the total sum of all root-to-leaf numbers.

/*
Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026
*/

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

int solve(Node* root, int num) {
    if(root == NULL) return 0;

    num = num * 10 + root->data; // build the number

    if(root->left == NULL && root->right == NULL) return num; // if it is a leaf node

    // find sum from left & right subtrees
    return solve(root->left, num) + solve(root->right, num);
}

int sumNumbers(Node* root) {
    return solve(root, 0);

}

int main() {
    vector<int> pre = {4, 9, 5, -1, -1, 1, -1, -1, 0, -1, -1};

    Node* root = new Node(4);
    root->left = new Node(9);
    root->left->left = new Node(5);
    root->left->right = new Node(1);
    root->right = new Node(0);

    cout << sumNumbers(root);

    return 0;
}