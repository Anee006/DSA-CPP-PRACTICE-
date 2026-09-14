// LeetCode 113
// Using dfs + backtracking

// Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node 
// values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

/*
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
*/

// LOGIC:
// Add current node's val to the path. Subtract node->val from targetSum.
// If node is a leaf and remaining targetSum = 0, found a valid path --> add it to result vector.
// Otherwise, explore left and right subtrees.
// Remove current node from the path before returning --> backtrack

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
Node* buildBT(vector<int> pre) {
    idx++;

    Node* root = new Node(pre[idx]);

    if(pre[idx] == -1) return NULL;

    root->left = buildBT(pre);
    root->right = buildBT(pre);

    return root;
}

// helper fn
void dfs(Node* root, int targetSum, vector<int>& path, vector<vector<int>>& result) {
    if(root == NULL) return;

    path.push_back(root->data); // add current node to path

    // check if current node is a leaf node
    if(root->left == NULL && root->right == NULL) {
        // check if path sum equals the targetSum
        if(root->data == targetSum) result.push_back(path);
    }

    else {
        dfs(root->left, targetSum - root->data, path, result); // explore left subtree
        dfs(root->right, targetSum - root->data , path, result); // explore right subtree
    }

    path.pop_back(); // backtracking
}

vector<vector<int>> pathSum(Node* root, int targetSum) {
    vector<vector<int>> result;
    vector<int> path;

    dfs(root, targetSum, path, result);

    return result;
}

int main() {
    vector<int> pre = {5, 4, 11, 7, -1, -1, 2, -1, -1, -1, 8, 13, -1, -1, 4, 5, -1, -1, 1, -1, -1};
    int targetSum = 22;

    Node* root = buildBT(pre);
    vector<vector<int>> result = pathSum(root, targetSum);

    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// TC = O(N × H) , where N = no. of nodes in the tree, H is the tree height
// SC = O(H)