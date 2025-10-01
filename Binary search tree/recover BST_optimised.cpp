//RECOVER BST (LeetCode 99)
//WITH OPTIMISED SPACE COMPLEXITY OF O(1).  --> Using Morris Inorder Traversal

//You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake.
//Recover the tree without changing its structure.

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

void recoverTree(Node* root)
{
    Node* previous = NULL; //used to track the previous node or last visited node of each node
    Node* first = NULL; //to store the first el of the incorrect/swapped pair.   //stores the prev
    Node* second = NULL; //to store the second el of the incorrect/swapped pair  //stores the root

    while(root != NULL)
    {
        //traverse left subtree
        if(root->left == NULL)
        {
            if(previous != NULL && previous->data > root->data)
            {
                if(first == NULL)
                {
                    first = previous;
                }
                second = root;
            }
            previous = root;
            root = root->right;
        }

        else
        {
            //find previous (inorder previous i.e, IP)
            Node* IP = root->left;
            while(IP->right != NULL && IP->right != root)
            {
                IP = IP->right;
            }

            if(IP->right == NULL)
            {
                IP->right = root;
                root = root->left;
            }
            else
            {
                if(previous != NULL && previous->data > root->data)
                {
                    if(first == NULL) first = previous;
                    second = root;
                }
                previous = root;
                IP->right = NULL;
                root = root->right;
            }
        }
    }

    if(first != NULL && second != NULL)
    {
        int temp = first->data;
        first->data = second->data;
        second->data = temp;
    }
}
//TC = O(n)
//SC = O(1)  --> no call stack used


void printInorder(Node* root)
{
    if(root == NULL) return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    Node* root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(4);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(9);

    //original inorder sequence of the above bst: 1,3,8,6,4,9 --> this is not in sorted order

    cout << "Inorder of original BST: ";
    printInorder(root);

    cout << endl;

    recoverTree(root);
    cout << "\nInorder of recovered BST: ";
    printInorder(root);

    
    return 0;
}