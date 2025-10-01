//RECOVER BST (LeetCode 99)

//You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake.
//Recover the tree without changing its structure.

//STEPS:
//1. find the two nodes which have been swapped in the bst.
//2. reswap those two nodes.

//1. find the swapped nodes in the inorder seq of the original BST.
//2. compare each element with its prev el. If the array is sorted then its: (prev val < next val).

//LOGIC:
//if only one pair is problematic (i.e is swapped incorrectly) then we simply swap both the values.
//if we have two pairs which are problematic and both pairs are in diff subtrees, we will take the 
//1st value of 1st pair and 2nd value of 2nd pair and swap both of then.

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

Node* previous = NULL; //used to track the previous node or last visited node of each node
Node* first = NULL; //to store the first el of the incorrect/swapped pair.   //stores the prev
Node* second = NULL; //to store the second el of the incorrect/swapped pair  //stores the root

void inorder(Node* root)
{
    //traverse the bst in inorder fashion.
    if(root == NULL) return;

    //left
    inorder(root->left);

    //root
    if(previous != NULL && previous->data > root->data)  //if both are true means we have found the problematic pair
    {
        if(first == NULL)
        {
            first = previous;
        }

        second = root;
    }

    previous = root; //for the right subtree, previous value will be the root

    //right
    inorder(root->right);
}
//TC = O(n)
//SC = O(n)  --> due to the call stack of recursion

void recoverTree(Node* root)
{
    inorder(root); 
    //we now have the values of "first" and "second" of the pair we needed to swap

    //swapping first and second:
    int temp = first->data;
    first->data = second->data;
    second->data = temp;
}

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