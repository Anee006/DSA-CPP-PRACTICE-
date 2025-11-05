// PATH SUM (LeetCode 112)

//Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up 
//all the values along the path equals targetSum.

//Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
//Output: true (5 + 4 + 11 + 2 = 22)

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

bool hasPathSum(Node* root, int targetSum)
{
    if(root == NULL) return false; //if tree is empty no path exists

    //check if it's a leaf node
    if(root->left == NULL && root->right == NULL)
    {
        return root->data == targetSum; //returns true if path exists else returns false
    }

    //check left and right subtrees with remaining sum

    int remainingSum = targetSum - root->data;

    return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
}
//TC = O(n)

int main()
{
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(11);
    root->right->left = new Node(13);
    root->right->right = new Node(4);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(2);
    root->right->right->right = new Node(1);

    if(hasPathSum(root, 22)) cout << "Path exists\n";
    else cout << "No path exists\n";

    return 0;
}