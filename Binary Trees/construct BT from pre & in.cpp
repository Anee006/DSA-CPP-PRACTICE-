//Construct Binary Tree from Preorder and Inorder Traversal (LeetCode 105)

//Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the 
//same tree, construct and return the binary tree.

//Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//Output: [3,9,20,null,null,15,7]

//LOGIC:
//preorder sequence gives us the root of the tree. For the given eg, root of tree will be 3 as it is the 1st node in the preorder.
//the problem with preorder is that we don't know which nodes will be in the left subtree and which nodes will be in the right subtree of the root.

//in inorder, the root comes in the middle, so after we have found our root in the inorder, then the nodes on the left of the root in the inorder
//will be in its left subtree and the rest will be in its rigth subtree.

//for the given inorder since root = 3, so 9 will be in its left subtree and 15,20,7 will be in its right subtree.
//so now build the left and right subtrees based on the preorder.

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

//to search for the root inside inorder
int search(vector<int>& inorder, int left, int right, int val) //val is the value we need to search 
{
    for(int i=left; i<=right; i++)
    {
        if(inorder[i] == val) 
        {
            return i; //returns the idx at which root is found inside the inorder
        }
    }

    return -1; //will never be executed as it is given in the Q that inorder and preorder are valid
}

//helper fn

Node* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left, int right) 
//preIdx is used to iterate on elements inside preorder one by one and left & right are the boundaries of the inorder
{
    //base case
    if(left > right) return NULL;  //means we gone out of the boundary of the inorder

    Node* root = new Node(preorder[preIdx]); //to construct the root of the tree //the 1st node of preorder is the root

    //to search for the root inside the inorder:
    int inIdx = search(inorder, left, right, preorder[preIdx]); //preorder[preIdx] is the value we need to search inside the inorder
    preIdx++; //to move to the next value inside preorder

    //to build the left and right subtree
    root->left = helper(preorder, inorder, preIdx, left, inIdx-1);
    root->right = helper(preorder, inorder, preIdx, inIdx+1, right);

    return root;
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    int preIdx = 0; 

    return helper(preorder, inorder, preIdx, 0, inorder.size()-1); //left = 0 and right = n-1 for the inorder
}

int main()
{
    vector<int> preorder = {3,9,20,15,7};
    vector <int> inorder = {9,3,15,20,7};

    Node* root = buildTree(preorder, inorder);

    cout << "Root = " << root->data << endl;
    cout << "Root->left = " << root->left->data << endl;
    cout << "Root->right = " << root->right->data << endl;
    cout << "Root->right->left = " << root->right->left->data << endl;
    cout << "Root->right->right = " << root->right->right->data << endl;
    


    return 0;
}

//TC = O(n*n)
//SC = O(n)