// LeetCode 1373

// Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

// Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
// Output: 20
// Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.

// LOGIC:
// Use postorder dfs bcoz, to determine whether the current subtree is a valid BST, we first need info about its left and right subtrees.
// For every node, maintain 4 pieces of information: (return these values as a vector)
// Index  Meaning
// 0      Whether the subtree is a valid BST (1 = Yes, 0 = No)
// 1      Sum of all nodes in the subtree
// 2      Minimum value in the subtree
// 3      Maximum value in the subtree

// A subtree is a valid BST if:
// 1. Its left subtree is a valid BST --> left[0]
// 2. Its right subtree is a valid BST --> right[0]
// 3. The current root value is greater than the maximum value in the left subtree  --> root->data > left[3]
// 4. The current root value is smaller than the minimum value in the right subtree root->data < right[2]

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

// The fn returns {is_bst, sum, min, max}
vector<int> solve(Node* root, int& ans) {
    if(root == NULL) return {1, 0, INT_MAX, INT_MIN}; // empty subtree is a valid bst

    vector<int> left = solve(root->left, ans); // stores info about left subtree
    vector<int> right = solve(root->right, ans); // stores info about right subtree

    // check whether current subtree is a valid bst
    if(left[0] && right[0] && root->data > left[3] && root->data < right[2]) {
        int sum = root->data + left[1] + right[1]; // sum of all nodes in current subtree

        ans = max(ans, sum); 

        int minimum = min(root->data, left[2]); // minimum value in the current subtree
        int maximum = max(root->data, right[3]); // maximum value in the current subtree

        return {1, sum, minimum, maximum}; // return info to parent
    }
    return {0, 0, 0, 0}; // current subtree is not a bst
}

int maxSumBST(Node* root) {
    int ans = 0; // stores max sum of a valid bst found so far

    solve(root, ans);
    return ans; 
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(4);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right = new Node(3);
    root->right->left = new Node(2);
    root->right->right = new Node(5);
    root->right->right->left = new Node(4);
    root->right->right->right = new Node(6);

    cout << maxSumBST(root);

    return 0;
}

// TC: O(n)
// SC: O(h)