// SUM OF LEFT LEAVES (LeetCode 404)

//Given the root of a binary tree, return the sum of all left leaves.

//A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

//Input: root = [3,9,20,null,null,15,7]
//Output: 24
//Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

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

int sumOfLeftLeaves(Node* root)
{
    if(root == NULL) return 0;

    int sum = 0;

    //check if the left child exists and is a LEAF node
    if(root->left != NULL && root->left->left == NULL && root->left->right == NULL)
    {
        sum += root->left->data;
    }

    return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}

//TC = O(n)
//SC = O(n)

int main()
{
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << "Sum of left leaves: " << sumOfLeftLeaves(root) << endl;

    return 0;
}