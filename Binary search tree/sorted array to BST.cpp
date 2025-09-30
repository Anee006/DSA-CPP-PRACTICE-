//CONVERT SORTED ARRAY TO BST (LeetCode 108)

//Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

//Input: nums = [-10,-3,0,5,9]
//Output: [0,-3,9,-10,null,5]

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

//helper fn 
Node* helper(vector<int>& nums, int st, int end)
{
    if(st > end) return NULL; //base case 

    int mid = st + (end-st)/2;
    Node* root = new Node(nums[mid]); //root node is the mid el of the array

    root->left = helper(nums, st, mid-1); //to build the LST
    root->right = helper(nums, mid+1, end); //to build the RST

    return root;
}
//TC = O(n)

Node* sortedArrToBST(vector<int>& nums)
{
    return helper(nums, 0, nums.size() -1); //st = 0 and end = n-1 
}

void inorder(Node* root) //the inorder of the balance BST should be same as the given array, to indicate that the created BST is correct
{
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    vector<int> nums = {-10,-3,0,5,9};

    Node* root = sortedArrToBST(nums);
    cout << "Root = " << root->data << endl << endl;
    cout << "Inorder traversal: ";
    inorder(root);

    return 0;
}