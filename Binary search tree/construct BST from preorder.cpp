//CONSTRUCT BST FROM PREORDER TRAVERSAL (LeetCode 1008)

//Given an array of integers preorder, which represents the preorder traversal of a BST, construct the tree and return its root.

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

Node* BSTfromPre(vector<int>& nums)
{

}

int main()
{
    vector<int> nums = {6,3,1,4,8,9};

    return 0;
}

