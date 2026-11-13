// LeetCode 1530

// You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the 
// length of the shortest path between them is less than or equal to distance. Return the number of good leaf node pairs in the tree.

// Input: root = [1,2,3,4,5,6,7], distance = 3
// Output: 2
// Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. 

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

int countPairs(Node* root, int distance) {
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int distance = 3;

    cout << countPairs(root, distance);

    return 0;
}