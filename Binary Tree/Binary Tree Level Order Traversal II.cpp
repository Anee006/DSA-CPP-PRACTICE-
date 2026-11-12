// LeetCode 107

// Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. 
// (i.e., from left to right, level by level from leaf to root).

// Input: root = [3,9,20,null,null,15,7]
// Output: [[15,7],[9,20],[3]]

// LOGIC:
// Do normal level-order traversal using a queue. Store each level in vector<int> level.
// Store all levels in vector<vector<int>> result.
// Reverse the levels to get leaf -> root order i.e, bottom-up order.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
    vector<vector<int>> result;

    if(root == NULL) return result; // base case

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        vector<int> level; // stores current level

        for(int i = 0; i < size; i++) { // process 1 level
            Node* curr = q.front();
            q.pop();

            level.push_back(curr->data);

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        result.push_back(level);
    }
    reverse(result.begin(), result.end());

    return result;
}
// TC = O(n)
// SC = O(n)

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
