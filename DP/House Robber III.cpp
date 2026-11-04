// LeetCode 337

// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root. Besides the root, each house 
// has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically 
// contact the police if two directly-linked houses were broken into on the same night.
// Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

// Input: root = [3,2,3,null,3,null,1]
// Output: 7
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

// LOGIC:
// We cannot rob a node and its direct parent or child on the same night.
// So, for every node there are 2 choices:
// 1. Rob the current house --> can't rob its left or right child
// 2. Do not rob the current house --> can choose to rob or skip its children, whichever gives max money

// For each node maintain 2 values:
// first --> max money when current node is robbed 
// second --> max money when current node is not robbed 

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

pair<int, int> solve(Node* root) {
    if(root == NULL) return {0, 0};

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    // rob current node
    int rob = root->data + left.second + right.second; // can't rob its children (hence used "second" value)

    int notRob = max(left.first, left.second) + max(right.first, right.second); // do not rob current house

    return {rob, notRob};
}

int rob(Node* root) {
    pair<int, int> ans = solve(root);

    return max(ans.first, ans.second);
}

int main() {
    Node* root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(3);
    root->right->right = new Node(1);

    cout << rob(root);

    return 0;
}

// TC: O(n)
// SC: O(h)