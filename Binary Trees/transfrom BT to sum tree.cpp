// #newnotes

//TRANSFORM BINARY TREE TO SUM TREE

//we want to replace the value of a node by --> value of node + left subtree nodes sum + right subtree nodes sum

//NOTE: we will transform the given BT itself to a sumTree, we won't create a new BT.

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

//to build the BT
static int idx = -1;
Node* buildTree(vector <int>& preorder)
{
    idx++;

    Node* root = new Node(preorder[idx]);

    if(preorder[idx] == -1) return NULL;

    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

//to print the nodes of BT using preorder traversal
void preOrder(Node* root)
{
    if(root == NULL) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

//transforms to sum tree --> transforms the given BT itself to a sumTree
//this fn returns the sum of the entire tree i.e it returns the value of root after adding sum of left subtree and rst to it
int sumTree(Node* root)
{
    if(root == NULL) return 0; //base case

    int leftSum = sumTree(root->left);   //to find sum of left subtree
    int rightSum = sumTree(root->right); //to find sum of right subtree

    root->data += leftSum + rightSum; 

    return root->data;
}

int main()
{
    vector <int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);

    cout << "Before conversion: ";
    preOrder(root); 
    cout << endl;

    sumTree(root); 

    cout << "After conversion: ";
    preOrder(root); 
    cout << endl;

    return 0;
}

//TC = O(n)