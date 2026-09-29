// LeetCode 1609

// A binary tree is named Even-Odd if it meets the following conditions:
// The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
// For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
// For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
// Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.

/*
Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
Output: true
Explanation: The node values on each level are:
Level 0: [1]
Level 1: [10,4]
Level 2: [3,7,9]
Level 3: [12,8,6,2]
Since levels 0 and 2 are all odd and increasing and levels 1 and 3 are all even and decreasing, the tree is Even-Odd.
*/

#include <iostream>
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

bool isEvenOddTree(Node* root) {
    queue<Node*> q;
    q.push(root);

    int level = 0;

    while(!q.empty()) {
        int n = q.size();
        int prev;

        if(level % 2 == 0) prev = INT_MIN; // for even level, values must increase

        else prev = INT_MAX; // for odd level, values must decrease

        for(int i = 0; i < n; i++) {
            Node* curr = q.front();
            q.pop();

            // even level
            if(level % 2 == 0) {
                if(curr->data % 2 == 0 || curr->data <= prev) return false; // val must be odd and strictly increasing
            }

            // odd level
            else {
                if(curr->data % 2 != 0 || curr->data >= prev) return false; // val must be even and strictly decreasing
            }

            prev = curr->data;

            // add children
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        level++;
    }
    return true;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(10);
    root->left->left = new Node(3);
    root->left->left->left = new Node(12);
    root->left->left->right = new Node(8);
    root->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    root->right->left->left = new Node(6);
    root->right->right->right = new Node(2);

    isEvenOddTree(root) ? cout << "True" : cout << "False";

    return 0;
}