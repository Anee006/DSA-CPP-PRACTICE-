// #newnotes

//LOWEST COMMON ANCESTOR OF A BINARY TREE (LeetCode 236)

//Given a binary tree, find the lowest common ancestor (LCA) of two given nodes (p and q) in the tree.
//NOTE: a node can be ancestor of itself. Also nodes p and q will exist in the tree. And p and q are diff nodes

//LOGIC:
//we try to find a node in whose left subtree either of p/q node exists and in whose right subtree either of p/q node exists.
//If we find a node which has p and q in its left and right subtree, then that node is the LCA.
//recursively, try to return the LCA from each level of the BT.

//first try to find the LCA in the left subtree of a node, then search in the right subtree.
//as soon as we find either of p and q, return that node.

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

Node* LCA(Node* root, Node* p, Node* q)
{
    if(root == NULL) //base case
    {
        return NULL;
    }

    if (root->data == p->data || root->data == q->data) //if we have found the node p and q, then we assume, that node is our LCA
    {
        return root;
    }

    //try to find p and q nodes in the left and right subtree
    Node* leftLCA = LCA(root->left, p , q);
    Node* rightLCA = LCA(root->right, p , q);
    
    if(leftLCA && rightLCA) //if both leftLCA and rightLCA are valid it means that root is the LCA
    {
        return root;
    }
    else if (leftLCA != NULL) //it means only leftLCA is valid and rightLCA is NULL
    {
        return leftLCA;
    }
    else //it means only rightLCA is valid and leftLCA is NULL
    {
        return rightLCA;
    }
}

int main()
{
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node* lca_1 = LCA(root, root->right, root->right->left); //p = 3 and q = 6
    Node* lca_2 = LCA(root, root->left->left, root->left->right->right); //p = 4 and q = 9

    cout << "LCA of 3 and 6 = " << lca_1->data << endl;
    cout << "LCA of 4 and 9 = " << lca_2->data << endl;

    return 0;
}

//TC = O(n) where n is the number of nodes
//SC = O(n)