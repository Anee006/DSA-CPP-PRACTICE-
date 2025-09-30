//Kth SMALLEST ELEMENT IN A BST (LeetCode 230)
// (similar to kth largest Q)

//Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

//Input: root = [5,3,6,2,4,null,null,1], k = 3
//Output: 3


//STEPS:
//1. sort the bst --> using inorder traversal
//2. track the order or the sequence in which each val occurs in the bst. (1 based indexing)
//3. create a global variable prevOrder = 0.  Do (order + 1) for each node to get the idx/order of each node.
//4. when prevOrder == k, we will get the ans.

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

int prevOrder = 0; //to track the order of each node in the bst
int kthSmallest(Node* root, int k)
{
    if(root == NULL) return -1;  //to indicate kth smallest is not yet found

    //left
    if(root->left)
    {
        int leftAns =  kthSmallest(root->left, k);
        if(leftAns != -1) return leftAns; //means we have found the kth smallest el

    }

    //root
    if(prevOrder + 1 == k) //doing (prevOrder+1) bcoz we need 1-based indexing
    {
        return root->data;
    }

    prevOrder = prevOrder + 1; //updation

    //right
    if(root->right)
    {
        int rightAns = kthSmallest(root->right, k);
        if(rightAns != -1) return rightAns;
    }

    return -1; //if kth smallest el is not found
}
//TC = O(n)

int main()
{
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);

    int k1 = 3;
    cout << k1 << "rd smallest element: " << kthSmallest(root, k1) << endl;


    return 0;
}