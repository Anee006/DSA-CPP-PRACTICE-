//RECOVER BST (LeetCode 99)

//You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake.
//Recover the tree without changing its structure.

#include <iostream>
#include <vector>
using namespace std;

class Node
{
    public: 
        int data;
        Node* left;
        Node* right;

        Node(int val)
        {
            data = val;
            left = right = NULL;
        }
};

void recoverTree(Node* root)
{

}

int main()
{
    Node* root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(4);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(9);
    
    return 0;
}