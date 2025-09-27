//  SYMMETRIC TREE (LeetCode 101)

//Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

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

bool isMirror(Node* p, Node* q)
{
    if(p == NULL && q == NULL) return true;  // if both are NULL means are symmetric

    if(p == NULL || q == NULL) return false;  //if only one is NULL means not symmetric

    return (p->data == q->data) && 
            isMirror(p->left , q->right) &&
            isMirror(p->right, q->left);
}

//to check if tree is symmetric 
bool isSymmetric(Node* root)
{
    if(root == NULL)   //base case
    {
        return true;  
    }

    return isMirror(root->left, root->right); //to check if the left and right subtree are symmetric or not
}
//TC = O(n)
//SC = O(n)

//example of symmetric tree
Node* buildTree()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    return root;
}

//example of non-symmetric tree
Node* buildAnotherTree()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(3);
    root->right->right = new Node(3);

    return root;
}

int main()
{
    Node* root = buildTree();

    if(isSymmetric(root))
    {
        cout << "Tree is symmetric" << endl;
    }
    else
    {
        cout << "Tree is not symmetric" << endl;
    }

    cout << endl;

    Node* root2 = buildAnotherTree();

    if(isSymmetric(root2))
    {
        cout << "Tree is symmetric" << endl;
    }
    else
    {
        cout << "Tree is not symmetric" << endl;
    }
    return 0;
    
}