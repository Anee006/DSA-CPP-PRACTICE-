// LeetCode 107

// Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. 
// (i.e., from left to right, level by level from leaf to root).

// Input: root = [3,9,20,null,null,15,7]
// Output: [[15,7],[9,20],[3]]

#include <iostream>
#include <vector>
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

static int idx = -1;

Node* buildBT(vector<int>& pre) {
    idx++;

    Node* root = new Node(pre[idx]);

    if(pre[idx] == -1) return NULL;

    root->left = buildBT(pre);
    root->right = buildBT(pre);

    return root;
}

vector<vector<int>> levelOrderBottom(Node* root) {
}

int main() {
    vector<int> pre = {3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};

    Node* root = buildBT(pre);

    vector<vector<int>> ans = levelOrderBottom(root);

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}