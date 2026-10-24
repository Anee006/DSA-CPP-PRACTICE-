// LeetCode 863

// Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of 
// all nodes that have a distance k from the target node.

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
// Output: [7,4,1]
// Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

// LOGIC:
// Store each node's parent using DFS.
// Use BFS starting from the target node, exploring left, right, and parent nodes until reached distance k.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
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

unordered_map<Node*, Node*> parent; // stores {node, parent of that node}

// store each node's parent using DFS
void findParent(Node* root, Node* par) {
    if(root == NULL) return;

    parent[root] = par;

    findParent(root->left, root);
    findParent(root->right, root);
}

vector<int> distanceK(Node* root, Node* target, int k) {
    findParent(root, NULL); // parent of root is NULL

    queue<Node*> q;
    unordered_set<Node*> vis; // it prevents from revisiting nodes when moving between parents and children
    vector<int> ans;

    // start BFS from target node (start from target bcoz we want to find all nodes at distance k from it)
    q.push(target);
    vis.insert(target);

    int dis = 0;

    while(!q.empty()) {
        int n = q.size();

        if(dis == k) { // every node remaining in the queue is exactly at distance k from the target
            while (!q.empty()) {
                ans.push_back(q.front()->data);
                q.pop();
            }
            return ans;
        }

        for(int i = 0; i < n; i++) {
            Node* curr = q.front();
            q.pop();

            if(curr->left && !vis.count(curr->left)) {
                q.push(curr->left);
                vis.insert(curr->left);
            }

            if(curr->right && !vis.count(curr->right)) {
                q.push(curr->right);
                vis.insert(curr->right);
            }

            if(parent[curr] && !vis.count(parent[curr])) {
                q.push(parent[curr]);
                vis.insert(parent[curr]);
            }
        }
        dis++;
    }
    return ans;
}

int main() {
    Node* root = new Node(3);
    root->left = new Node(5); // target node
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right = new Node(1);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

    Node* target = root->left; // node 5 is the target node

    vector<int> ans = distanceK(root, target, 2);

    for(int x : ans) cout << x << " ";

    return 0;
}

// TC = O(n)
// SC = O(n)