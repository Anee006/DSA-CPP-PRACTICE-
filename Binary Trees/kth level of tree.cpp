// #newnotes
//Kth LEVEL OF A BINARY TREE

//Given the root of a binary tree and "k". Print all those nodes which occur at the Kth level of the binary tree.

//For the given binary tree : , k = 3
//So the nodes that occur at level 3 are: 7, 4, 5

//LOGIC:
//we can solve this using either levelOrder (i.e iterative approach) or we can use recursive approach.

//To solve using recursion:
//1. At the root level, k = 3.
//2. for the left & right child of the root, k = 3-1 = 2  (we will decrease k value at each level for left & right child by 1).
//3. For the next level also, k = 2-1 = 1
//4. When k becomes 1, we have to print the nodes at that level, as that is the level which we was originally asked to print.

//TC = O(n)

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

static int idx = -1;
Node* buildTree(vector<int> preorder)
{
    idx++;

    if(preorder[idx] == -1)
    {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);

    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

void KthLevel(Node* root, int k)
{
    if(root == NULL)  //if no valid left and right child of root exists, we simply return back
    {
        return;
    }

    if(k == 1)  //means we have reached the desired level we wanted to print
    {
        cout << root->data << " ";
        return;
    }

    //if not found the level, go to left and right child
    KthLevel(root->left , k-1);  //we reduce the value of k for each level by 1
    KthLevel(root->right, k-1);
}

int main()
{
    vector <int> preorder = {1,2,7,-1,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(preorder);

    KthLevel(root, 3); //here k = 3
}