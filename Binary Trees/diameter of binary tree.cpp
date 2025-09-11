// #newnotes

//DIAMETER OF BINARY TREE (LeetCode 543)
//using optimised approach with O(n) TC.

//Given the root of a binary tree, return the length of the diameter of the tree.

//The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
//The length of a path between two nodes is represented by the number of edges between them.

//Input: root = [1,2,3,4,5]
//Output: 3
//Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

//LOGIC:
/* 
traverse each node of the BT. calculate ONLY the current diameter for each node, no need to calculate leftDia and rightDia.
(current diameter is the diameter for the case when path passes through root node)
( current dia = height(left subtree) + height(right subtree) )
*/

//STEPS:
//1. create a global variable, ans = 0.
//2. calculate the current diameter inside the "height" fn itself.
//3. compare this current diameter with "ans" each time. The max of these two will be the diameter for the BT.

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

int ans = 0; //global variable used to find the diameter of BT

int height(Node* root)
{
    if(root == NULL) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    //to find the curr diameter
    ans = max(ans, leftHeight + rightHeight); // (leftHeight + rightHeight) is the current diameter for a node

    return max(leftHeight, rightHeight) + 1;
}
//TC = O(n)

int diameterOfTree(Node* root)
{
    height(root); //calculating height --> so that it returns the diameter

    return ans;
}
//TC = O(n)

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Diameter of tree = " << diameterOfTree(root) << endl;
    return 0;
}
