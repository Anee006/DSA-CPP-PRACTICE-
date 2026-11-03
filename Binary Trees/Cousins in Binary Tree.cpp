// LeetCode 993

// Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the 
// nodes corresponding to the values x and y in the tree are cousins, or false otherwise.
// Two nodes of a binary tree are cousins if they have the same depth with different parents.

// Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
// Output: true

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

bool isCousins(Node* root, int x, int y) {
    if(root == NULL) return false;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int n = q.size();
        bool foundX = false, foundY = false;

        for(int i = 0; i < n; i++) {
            Node* curr = q.front();
            q.pop();

            if(curr->left != NULL && curr->right != NULL) { // check if x and y are siblings
                // if have same parents --> can't be cousins
                if ((curr->left->data == x && curr->right->data == y) || (curr->left->data == y && curr->right->data == x)) return false;
            }

            // check x
            if(curr->left != NULL) {
                if(curr->left->data == x) foundX = true;

                q.push(curr->left);
            }

            if(curr->right != NULL) {
                if(curr->right->data == x) foundX = true;

                q.push(curr->right);
            }

            // check y
            if(curr->left != NULL) {
                if(curr->left->data == y) foundY = true;
            }

            if(curr->right != NULL) {
                if(curr->right->data == y) foundY = true;
            }
        }
        if(foundX && foundY) return true; // both found at same level --> are cousins

        if(foundX || foundY) return false; // if only found one at this level --> not cousins
    }
    return false;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);

    int x = 5, y = 4;

    isCousins(root, x, y) ? cout << "True" : cout << "False";

    return 0;
}

// TC: O(n)
// SC: O(n)