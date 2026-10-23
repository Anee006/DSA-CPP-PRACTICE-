// geeksforgeeks

// Given the root of a Binary Search Tree (BST) and two integers low and high, return all node values that lie in the inclusive range 
// [low, high] in ascending order.

// Input: root = [17, 4, 18, 2, 9, N, N], l = 4, h = 17
// Output: [4, 9, 17]
// Explanation: The BST nodes whose values lie in the range [4, 17] are 4, 9, and 17. Hence the result is returned as [4, 9, 17].

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

vector<int> nodesInRange(Node *root, int low, int high) {
}

int main() {
    Node* root = new Node(17);
    root->right = new Node(18);
    root->left = new Node(4);
    root->left->left = new Node(2);
    root->left->right = new Node(9);

    int low = 4, high = 17;

    vector<int> ans = nodesInRange(root, low, high);

    for(int x : ans) cout << x << " ";

    return 0;
}