// LeetCode 653
// Using Two-Pointer approach

// Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that 
// their sum is equal to k, or false otherwise.

// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true

// LOGIC:
// perform inorder traveral on BST to get a sorted array. Use 2 pointers to find a pair whose sum == k.

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

// store BST elements in a sorted order
void inorder(Node* root, vector<int>& arr) {
    if(root == NULL) return;

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

bool findTarget(Node* root, int k) {
    vector<int> arr;

    inorder(root, arr); // convert BST into a sorted array

    // Use Two-Pointer approach
    int left = 0, right = arr.size()-1;

    while(left < right) {
        int sum = arr[left] + arr[right];

        if(sum == k) return true;

        else if (sum < k) left++;

        else right--;
    }
    return false;
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right = new Node(6);
    root->right->right = new Node(7);

    int k = 9;

    findTarget(root, k) ? cout << "True" : cout << "False";

    return 0;
}

// TC = O(n)
// SC = O(n)