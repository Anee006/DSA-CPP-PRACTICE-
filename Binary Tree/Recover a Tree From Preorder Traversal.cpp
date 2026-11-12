// LeetCode 1028
// Using stack

// We run a preorder depth-first search (DFS) on the root of a binary tree. At each node in this traversal, we output D dashes (where D is the depth 
// of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the 
// root node is 0. If a node has only one child, that child is guaranteed to be the left child.
// Given the output traversal of this traversal, recover the tree and return its root.

// Input: traversal = "1-2--3--4-5--6--7"
// Output: [1,2,5,3,4,6,7]

#include <iostream>
#include <stack>
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

Node* recoverFromPreorder(string traversal) {
    stack<Node*> s; // to keep track of the current path from root to current node
    int i = 0;
    int n = traversal.length();

    while(i < n) {
        // count no. of dashes (depth)
        int depth = 0;

        while(i < n && traversal[i] == '-') {
            depth++;
            i++;
        }

        // extract node value
        int val = 0;

        // read all consecutive digits to get the complete node value (also handles multi-digit values)
        while(i < n && isdigit(traversal[i])) {
            val = val * 10 + (traversal[i] - '0');
            i++;
        }

        Node* node = new Node(val); // create a new node

        // before inserting a node at depth D, pop nodes from the stack while its size is greater than D
        while(s.size() > depth) s.pop(); // remove nodes until stack size matches depth

        // attach node to its parent (top element represents the parent of the new node)
        if(!s.empty()) {
            if(s.top()->left == NULL) s.top()->left = node; // if parent's left child is empty, attach the new node as its left child

            else s.top()->right = node;
        }
        s.push(node); // push current node in stack
    }

    while(s.size() > 1) s.pop(); // root node is at bottom, so pop all nodes except root 

    return s.top();
}

void preorder(Node* root) {
    if(root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    string traversal = "1-2--3--4-5--6--7";

    Node* root = recoverFromPreorder(traversal);

    preorder(root); // verify the tree created (should print the same preorder as given)

    return 0;
}

// TC: O(n)
// SC: O(n)

