//DELETE NODE IN BST (LeetCode 450)

//Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
//Return the root node reference (possibly updated) of the BST.

//STEPS:
//1. Search for the node to be deleted.
//2. Delete the required node.
//3. Rearrange the nodes so that tree remains as a BST.

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

Node* insert(Node* root, int val)
{
    if(root == NULL)
    {
        return new Node(val);
    }

    if(val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

Node* buildBST(vector<int> arr)
{
    Node* root = NULL;

    for(int val: arr)
    {
        root = insert(root, val);
    }
    return root;
}

//to find the inorder successor of a node
Node* getInorderSuccessor(Node* root)
{
    while(root != NULL && root->left != NULL)
    {
        root = root->left;  //we want to find a node whose left child is NULL
    }
    return root;
}

//to delete a node from a BST
Node* deleteNode(Node* root, int key) //key is the node we have to delete
{
    if(root == NULL) return NULL;

    if(key < root->data)  //go to lst to search for the node to be deleted
    {
        root->left = deleteNode(root->left, key);
    }

    else if(key > root->data) //go to rst
    {
        root->right = deleteNode(root->right, key);
    }

    else  //when root->data == key. This is where actual deletion happens
    {
        //Case 1 --> node to be deleted has 0 child nodes
        if(root->left == NULL)
        {
            Node* temp = root->right; //temp can either have a null value or a valid value stored in it.
            delete root; //delete the node
            return temp; //return it to the previous level

        }

        //Case 2 --> node to be deleted has 1 child node
        //delete the node and then return the non-null child of the deleted node to the root as the new child
        else if(root->right == NULL)
        {
            Node* temp = root->left; //temp can either have a null value or a valid value stored in it.
            delete root; //delete the node
            return temp; //returns not-null child to the previous level
        }
        
        else
        {
            //Case 3 --> node to be deleted has 2 child nodes
            //STEPS:
            //1. Find the "inorder successor" of the node to be deleted (it will always be in the rst).
            //2. replace root->data with value of "inorder successor".
            //3. delete the original "inorder successor" node.

            //"inorder successor" i.e, IS can have only 0 or 1 children.
            //for a node, IS = left-most node in the right sub tree (i.e the smallest val in rst).

            Node* IS = getInorderSuccessor(root->right); //to find the "inorder successor"
            root->data = IS->data; //replace the node to be deleted with IS node
            root->right = deleteNode(root->right, IS->data);  //we want to delete IS
        }  
    }
    return root;
}

void inorder(Node* root)
{
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    vector<int> arr = {3,2,1,5,6,4};

    Node* root = buildBST(arr);

    cout << "Inorder of BST before deleting= " ;
    inorder(root);
    cout << endl;

    deleteNode(root, 5); //to delete node 5 (has 2 child nodes)
    cout << "Inorder of BST after deleting  = " ;
    inorder(root);
    cout << endl;
    
    return 0;
}