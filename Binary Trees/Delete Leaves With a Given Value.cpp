// LeetCode 1325

// Given a binary tree root and an integer target, delete all the leaf nodes with value target.
// Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, 
// it should also be deleted (you need to continue doing that until you cannot).

// Input: root = [1,2,3,2,null,2,4], target = 2
// Output: [1,null,3,null,4]

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

void levelOrder(Node* root) {
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if(curr == NULL) {
            if(!q.empty()) {
                cout << endl;
                q.push(NULL);
                continue;
            }

            else break;
        }

        cout << curr->data << " ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}

Node* removeLeafNodes(Node* root, int target) {
    if(root == NULL) return NULL;

    // delete target leaves from left and right subtrees
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);

    // check if current node became NULL
    if(root->left == NULL && root->right == NULL && root->data == target) {
        return NULL; // delete target node
    }

    return root;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(2);
    root->right->right = new Node(4);

    cout << "Original Tree Level Order Traversal:\n";
    levelOrder(root);

    int target = 2;

    Node* newRoot = removeLeafNodes(root, target);

    cout << "\nModified Tree Level Order Traversal:\n";
    levelOrder(newRoot);
    return 0;
}

// TC = O(n)
// SC = O(h)