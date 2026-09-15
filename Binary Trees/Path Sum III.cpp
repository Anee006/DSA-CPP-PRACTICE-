// LeetCode 437

// Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along 
// the path equals targetSum. The path does not need to start or end at the root or a leaf, but it must go downwards.

/*
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are: [5 -> 3] , [5 -> 2 -> 1], [-3 -> 11]
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

static int idx = -1;

Node* buildBT(vector<int>& pre) {
    idx++;

    Node* root = new Node(pre[idx]);

    if(pre[idx] == -1) return NULL;

    root->left = buildBT(pre);
    root->right = buildBT(pre);

    return root;
}

int countPaths(Node* root, int targetSum) {
    if(root == NULL) return 0;

    int count = 0;

    if(root->data == targetSum) count++; // if current path equals target

    // continue the path downwards
    count += countPaths(root->left, targetSum - root->data);
    count += countPaths(root->right, targetSum - root->data);

    return count;
}

int pathSum(Node* root, int targetSum) {
    if(root == NULL) return 0;

    int count = countPaths(root, targetSum); // count paths starting from current root

    count += pathSum(root->left, targetSum); // paths starting somewhere in the left subtree
    count += pathSum(root->right, targetSum); // paths starting somewhere in the right subtree

    return count;

}

int main() {
    vector<int> pre = {10, 5, 3, 3, -1, -1, -2, -1, -1, 2, -1, 1, -1, -1, -3, -1, 11, -1, -1};
    int targetSum = 8;

    Node* root = buildBT(pre);

    cout << pathSum(root, targetSum);

    return 0;
}

// TC = O(n*n)
// SC = O(H), where H = tree height