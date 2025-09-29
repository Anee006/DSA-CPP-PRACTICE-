//SEARCH IN A BST (LeetCode 700)

//You are given the root of a binary search tree (BST) and an integer val.
//Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If node does not exist, return null.

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
    if(root == NULL) return new Node(val);

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

Node* searchBST(Node* root, int key)
{
    if(root == NULL) return NULL;

    if(root->data == key) return root; //means key exists so return that node

    //if not found, search in lst and rst
    if(key < root->data)
    {
        return searchBST(root->left, key);
    }
    else
    {
        return searchBST(root->right, key);
    }
}

int main()
{
    vector <int> arr = {4,2,1,7,3};

    Node* root = buildBST(arr);

    Node* node = searchBST(root, 2); //2 exists in BST
    if(node != NULL)
    {
        cout << node->data << endl;
    }
    else
    {
        cout << "2 does not exist in the given BST" << endl;
    }

    cout << endl;

    Node* x = searchBST(root, -1); //-1 does not exist in BST
    if(x != NULL)
    {
        cout << x->data << endl;
    }
    else
    {
        cout << "-1 does not exist in this BST" << endl;
    }

    return 0;
}