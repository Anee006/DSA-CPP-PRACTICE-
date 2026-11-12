// Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees 
// is maximized. Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

// Input: root = [1,2,3,4,5,6]
// Output: 110
// Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)

// LOGIC: Use two DFS traversals- one for the total tree sum and another for subtree sums

#include <iostream>
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

long long totalSum = 0;
long long bestProduct = 0;

// find sum of all nodes in a tree using DFS
long long findSum(Node* root){
    if(root == NULL) return 0;
    
    return root->data + findSum(root->left) + findSum(root->right);
}

long long findMaxProduct(Node* root) {
    if(root == NULL) return 0;

    // calc every subtree sum using postorder traversal
    long long leftSum = findMaxProduct(root->left);
    long long rightSum = findMaxProduct(root->right);

    long long subtreeSum = root->data + leftSum + rightSum;

    // cutting the edge above this subtree gives: subtreeSum & (totalSum - subtreeSum)

    long long product = subtreeSum * (totalSum - subtreeSum);

    bestProduct = max(bestProduct, product);

    return subtreeSum;
}

int maxProduct(Node* root) {
    totalSum = findSum(root);

    findMaxProduct(root);

    return bestProduct % 1000000007; // apply modulo
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    cout << maxProduct(root);

    return 0;
}

// TC: O(n)
// SC: O(h)