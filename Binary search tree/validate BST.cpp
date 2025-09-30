// #newnotes
//VALIDATE BST (LeetCode 98)

/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:
- The left subtree of a node contains only nodes with keys strictly less than the node's key.
- The right subtree of a node contains only nodes with keys strictly greater than the node's key.
- Both the left and right subtrees must also be binary search trees.
*/

//LOGIC:
//check that for a node its left subtree contains val only < node->val and its right subtree contains val only > node->val.
//i.e, leftMax < node->val < rightMax, where leftMax is the max val in the LST and rightMax is the max val in the RST.

//for a node check if it lies within the (min,max) range for that node. If it does, then it's a valid node and can check for lst & rst.
//else it is an invalid node hence BST is invalid, return false.

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

//helper fn
bool helper(Node* root, Node* min , Node* max) //here, min and max will be based on the nodes of the bst
{
    if(root == NULL) return true; //a null node is a valid BST

    // we'd assumed the min and max value to be +infinity and -infinity. Here we consider (min,max) as NULL

    if(min != NULL && root->data <= min->data)  //compare root with the min allowed val
    {
        return false; //if root->data becomes greater than the min value, invalid bst
    }

    if(max != NULL && root->data >= max->data) //compare root with the max allowed val
    {
        return false;
    }

    return helper(root->left, min, root) &&   //for LST, min val remains same but max val becomes equal to the parent
            helper(root->right, root, max);   //for RST, max val remains same but min val becomes equal to the parent

    //Note: both in the above return statement should return true for it to be a valid BST
}
//TC = O(n)

bool isValidBST(Node* root)
{
    return helper(root, NULL, NULL); //min = NULL and max = NULL
}

int main()
{
    //valid BST example
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);

    bool res_1 = isValidBST(root1);
    if(res_1) cout << "BST_1 is a valid BST" << endl;
    else cout << "BST_1 is not a valid BST" << endl;

    cout << endl;

    //invalid BST example
    Node* root2 = new Node(5);
    root2->left = new Node(1);
    root2->right = new Node(4);
    root2->right->left = new Node(3);
    root2->right->right = new Node(6);

    bool res_2 = isValidBST(root2);
    if(res_2) cout << "BST_2 is a valid BST" << endl;
    else cout << "BST_2 is not a valid BST" << endl;

    return 0;
}