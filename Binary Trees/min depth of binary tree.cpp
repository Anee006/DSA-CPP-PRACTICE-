// MINIMUM DEPTH OF A BINARY TREE (LeetCode 111)

//Given a binary tree, find its minimum depth.

//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

//Input: root = [3,9,20,null,null,15,7]
//Output: 2 
//Explanation: shortest path is of 3 and 9 edge. So min depth = 2

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

int minDepth(Node* root)
{
    if(root == NULL) return 0;

    // If the left child is missing, continue searching down the right side.
    if(root->left == NULL)
    {
        return 1 + minDepth(root->right);
    }

    // If the right child is missing, continue searching down the left side.
    if(root->right == NULL)
    {
        return 1 + minDepth(root->left);
    }

    // If both children exist, we take the shorter path.
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main()
{
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << "Min depth of binary tree = " << minDepth(root) << endl;

    return 0;
}