//VALIDATE BST (LeetCode 98)

/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:
- The left subtree of a node contains only nodes with keys strictly less than the node's key.
- The right subtree of a node contains only nodes with keys strictly greater than the node's key.
- Both the left and right subtrees must also be binary search trees.
*/

#include <iostream>
#include <vector>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;

        Node( int val)
        {
            data = val;
            left = right = NULL;
        }
};

bool isValidBST(Node* root)
{
    
}

int main()
{
    return 0;
}