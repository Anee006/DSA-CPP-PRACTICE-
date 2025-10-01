//CONSTRUCT BST FROM PREORDER TRAVERSAL (LeetCode 1008)

//Given an array of integers preorder, which represents the preorder traversal of a BST, construct the tree and return its root.

//LOGIC:
//the val at 0th idx in the preorder arary, will be the root of the BST.

//BRUTE FORCE APPROACH: insert arr elements into the BST one by one, following the BST properties.
//TC = O(n*n), as first we need to traverse each element and then find its correct position to insert in the BST.

//OPTIMISED APPROACH: 
//values in lst: min value can be -infinity but max value should be < root. 
//so to build each subtree we will pass its upper bound i.e, the max value.
//we will build the root first, then left then the right subtree.
//to build the rst, the upper bound will be same as was that of the parent.

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

//helper
Node* buildBST(vector<int>& preorder, int& i, int upperBound) //used &i here bcoz we want to the same i value to get updated each time
{
    if(i >= preorder.size() || preorder[i] > upperBound) return NULL; //base case
    //i >= preorder.size() is when we have build the entire bst
    //preorder[i] > upperBound is when upperbound conditon becomes invalid

    Node* root = new Node(preorder[i]); // building the root  
    //can also write it as:  Node* root = new Node(preorder[i ++]) and remove the i++ from below

    i++;

    //build lst
    root->left = buildBST(preorder, i, root->data); //root->data is the upper bound here

    //build rst
    root->right = buildBST(preorder, i, upperBound); // upperbound for rst is the same as that of its parent node

    return root;
}
//TC = O(n)  --> as we traverse the preorder array once to build the bst

Node* BSTfromPre(vector<int>& preorder)
{
    int i=0;
    return buildBST(preorder, i, INT_MAX); //upper bound = INT_MAX
}

void inorder(Node* root)
{
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

}
int main()
{
    vector<int> preorder = {6,3,1,4,8,9};

    Node* root = BSTfromPre(preorder);

    cout << "Root of BST = " << root->data << endl;
    cout << "Inorder of BST = ";
    inorder(root);

    return 0;
}

