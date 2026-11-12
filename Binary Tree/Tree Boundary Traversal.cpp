// geeksforgeeks

// Given a root of a Binary Tree, return its boundary traversal in the following order:
// 1. Left Boundary: Nodes from the root to the leftmost non-leaf node, preferring the left child over the right and excluding leaves.
// 2. Leaf Nodes: All leaf nodes from left to right, covering every leaf in the tree.
// 3. Reverse Right Boundary: Nodes from the root to the rightmost non-leaf node, preferring the right child over the left, excluding leaves, and 
// added in reverse order.
// Note: The root is included once.

// Input: root = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
// Output: [1, 2, 4, 8, 9, 6, 7, 3]

// LOGIC: use DFS

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

// check whether a node is a leaf node
bool isLeaf(Node* root) {
    return (root->left == NULL && root->right == NULL);
}

// add leaf nodes from left to right
void addLeaves(Node* root, vector<int>& ans) {
    if (root == NULL) return;
    
    if(isLeaf(root)) ans.push_back(root->data);
    
    addLeaves(root->left, ans);
    addLeaves(root->right, ans);
}

// add left boundary (excluding leaf nodes)
void addLeft(Node* root, vector<int>& ans) {
    Node* curr = root->left;
    
    while(curr != NULL) {
        if(!isLeaf(curr)) ans.push_back(curr->data);
        
        if(curr->left != NULL) curr = curr->left;
        else curr = curr->right;
    }
}

// add right boundary (excluding leaf nodes)
void addRight(Node* root, vector<int>& ans) {
    Node* curr = root->right;
    vector<int> temp; // store the traversal from top to bottom
    
    while(curr != NULL) {
        if(!isLeaf(curr)) temp.push_back(curr->data);
        
        if(curr->right != NULL) curr = curr->right;
        else curr = curr->left;
    }
    
    // add right boundary in reverse (from bottom to top)
    for(int i = temp.size()-1; i >= 0; i--) {
        ans.push_back(temp[i]);
    }
}

vector<int> boundaryTraversal(Node* root) {
    vector<int> ans;
		
    if(root == NULL) return ans;
    
    if(!isLeaf(root)) ans.push_back(root->data); // add root (only once)
    
    else {
        ans.push_back(root->data);
        return ans;
    }
    
    addLeft(root, ans); // 1. Left boundary
    
    addLeaves(root, ans); // 2. Leaf nodes
    
    addRight(root, ans); // 3. Reverse right boundary
    
    return ans;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = boundaryTraversal(root);

    for(int x : ans) cout << x << " ";

    return 0;
}

// TC: O(n)
// SC : O(n)