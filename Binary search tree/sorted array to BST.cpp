//CONVERT SORTED ARRAY TO BST (LeetCode 108)

//Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

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

Node* sortedArrToBST(vector<int>& nums)
{
    
}

int main()
{
    return 0;
}