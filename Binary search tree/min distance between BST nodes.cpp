// #newnotes
//MINIMUM DISTANCE BETWEEN BST NODES (LeetCode 783)

//Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

//LOGIC:
//apply inorder traversal to find the min distance. (as inorder gives sorted seq)

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

Node* previous = NULL; //to track the last visited node in inorder sequence

int minDistance(Node* root)
{
    //for inorder --> left, root, right

    if(root == NULL) return INT_MAX; //base case  //returns infinity

    int ans = INT_MAX; //initialised with max value (infinity), as we need to find the min val

    //left 
    if(root->left)
    {
        int leftMin = minDistance(root->left); //returns the min distance in lst
        ans = min(ans, leftMin);
    }

    //root
    if(previous != NULL)
    {
        ans = min(ans, root->data - previous->data);  //(root->data - prev->data) is the current min which is found by subtracting 2 nodes
    }

    previous = root;

    //right
    if(root->right)
    {
        int rightMin = minDistance(root->right);
        ans = min(ans, rightMin);
    }

    return ans;
}
//TC = O(n)

int main()
{
    Node* root = new Node(83);
    root->left = new Node(62);
    root->right = new Node(88);
    root->left->left = new Node(42);
    root->left->right = new Node(82);
    root->left->left->right = new Node(52);

    cout << "Min distance = " << minDistance(root) << endl;

    return 0;
}