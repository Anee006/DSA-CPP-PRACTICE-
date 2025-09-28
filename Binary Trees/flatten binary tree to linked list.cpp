// #newnotes
//FLATTEN BINARY TREE TO LINKED LIST (LeetCode 114)

//Given the root of a binary tree, flatten the tree into a "linked list":
//The "linked list" should use the same Node class where the right child pointer points to the next node in the list and the left child 
//pointer is always null.

//The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

//LOGIC:
//To build the linked list , we are going to follow "reverse preorder" i.e, we are going to convert first the rst into linked list, then we will 
//convert the lst to linked list and then finally the root.
//After flattening the rst and lst to linked list, we will convert the left sub tree of root to NULL and the flattened linked list becomes the
//right sub tree of the root in the linked list.

//create a Node ptr "nextRight" which is used to track the last visited node i.e, to track which node will be attached in the rst of the root.
//We will make the root as the "nextRight" each time.

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

Node* nextRight; //to track the last visited node
void flatten(Node* root)
{
    if(root == NULL) return; //base case

    //follow reverse preorder to flatten the tree. i.e, first we will flatten the rst then the lst
    flatten(root->right);
    flatten(root->left);

    root->left = NULL;
    root->right = nextRight; //attach root to the flattened list

    nextRight = root;
}

void preOrder(Node* root)
{
    if(root == NULL) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    flatten(root);

    cout << "After flattening BT to Linked List: ";
    preOrder(root);

    return 0;
}

//TC = O(n)
//Sc = O(1)