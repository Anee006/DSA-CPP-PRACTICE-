// MAXIMUM DEPTH OF A BINARY TREE (LeetCode 104) 
//(this uses the same logic as that to find the "height of a binary tree").

//Given the root of a binary tree, return its maximum depth.

//A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

#include <iostream>
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

int maxDepth(Node* root)
{
    if(root == NULL) return 0;

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

//TC = O(n) , n is the no. of nodes
//SC = O(n)

int main()
{
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << "Max Depth of Tree is: " << maxDepth(root) << endl; //output is 3

    return 0;
}