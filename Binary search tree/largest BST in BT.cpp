// #newnotes
//LARGEST BST IN BINARY TREE

//(logic is similar to that of validate BST Q)

//given a binary tree, return the size of the largest BST in the BT.

//LOGIC OF BRUTE FORCE APPROACH ( TC: O(n*n) ) -->
//for each node check whether it satisfies BST properties using "validate BST" logic.
//if we find a valid BST we don't need to check further below that node bcoz the BSTs below it will be smaller in size
//and according to the Q we need the "largest" BST.

//LOGIC OF OPTIMISED APPROACH ( TC: O(n) )
//In a BST, left.Max < root->val < right.Min, where left.Max is the max val in lst and righ.tMin is the min val in rst.
//check whether the left and right child of a node are BSTs or not. If both are BSTs, then root node will also be a BST.
//Find the min and max values in the RST and LST.
//Find the size of LST and RST in order to get the size of root.


//NOTE:
//If a node is not a valid BST, it returns (-infinity as min value) and (+infinity as max val) to its upper node.
//if a node is a valid BST, it returns (+infinity as min val) and (-infinity as max val) to its upper node.

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

//each node will have this info with it
class Info
{
    public:
        int min, max, size; //here "size" means the size of the max BST we have found inside the BT

        Info(int min, int max, int size)
        {
            this->min = min;
            this->max = max;
            this->size = size;
        }
};

//returns info of a node
Info helper(Node* root)
{
    if(root == NULL)  //base case --> in case of valid BST (single node is also a valid BST)
    {
        return Info(INT_MAX, INT_MIN, 0); //INT_MAX means (+infinity) and INT_MIN means (-infinity)
    }

    Info left = helper(root->left); //to get info of LST
    Info right = helper(root->right); //to get info of RST

    if(root->data > left.max && root->data < right.min) //is a valid BST
    {
        int currMin = min(root->data, left.min);
        int currMax = max(root->data, right.max);
        int currSize = left.size + right.size + 1;

        return Info(currMin, currMax, currSize);
    }

    return Info(INT_MIN, INT_MAX, max(left.size, right.size)); //in case of invalid BST
}

//to find the largest BST in BT
int largestBSTinBT(Node* root)
{
    Info info = helper(root);

    return info.size; //this is the max BST size
}

int main()
{
    // vector<int> arr = {10,5,1,8,15,7};  --> preorder of BT

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);

    cout << "Size of largest BST in BT = " << largestBSTinBT(root) << endl;

    return 0;
}