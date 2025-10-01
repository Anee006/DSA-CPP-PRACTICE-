// #newnotes
//MERGE TWO BINARY SEARCH TREES

//Given the root of two bst- root1 and root2. Combine these two BSTs to form a single BST.

//LOGIC:
//We can find the inorder seq of both the given BSTs. Then the inorder seq of the combined BST can be found out using these.
//create the inorder seq of the combined tree. Build combined BST by taking elements from inorder seq one by one.

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

void inorder(Node* root, vector<int>& arr) //to store the inorder seq in an array
{
    if(root == NULL) return;

    inorder(root->left, arr);   //left 
    arr.push_back(root->data);  //root
    inorder(root->right, arr);  //right
}

//to build a balanced BST from a sorted array
Node* buildBSTFromSorted(vector<int>& arr, int st, int end)
{
    if(st > end) return NULL;

    int mid = st + (end-st)/2;

    Node* root = new Node(arr[mid]);

    root->left = buildBSTFromSorted(arr, st, mid-1);
    root->right = buildBSTFromSorted(arr, mid+1, end);

    return root;
}

//returns a combined balanced BST
Node* mergeTwoBST(Node* root1, Node* root2)
{
    vector<int> arr1, arr2;

    inorder(root1, arr1); //arr1 stores inorder seq of 1st BST
    inorder(root2, arr2);  //arr2 stores inorder seq of 2nd BST

    int i=0, j=0;
    vector<int> temp; //to store the merged inorder seq from arr1 and arr2

    while(i < arr1.size() && j< arr2.size())
    {
        if(arr1[i] < arr2[j])
        {
            temp.push_back(arr1[i]);  //can also write temp.push_back(arr1[i++]) instead of these two lines
            i++;
        }
        else
        {
            temp.push_back(arr2[j]); //can also write temp.push_back(arr2[j++]) instead of these two lines
            j++;
        }
    }
    //to insert remaining elements into the temp vector
    while(i < arr1.size())
    {
        temp.push_back(arr1[i++]);
    }
    while(j < arr2.size())
    {
        temp.push_back(arr2[j++]);
    }

    return buildBSTFromSorted(temp, 0, temp.size() -1); //to build balanced BST using the sorted inorder array
}

//to insert node in a BST
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

Node* buildBST(vector<int>& arr)
{
    Node* root = NULL;

    for(int val: arr)
    {
        root = insert(root, val);
    }
    return root;
}

int main()
{
    vector<int> arr1 = {8,2,1,10};
    vector<int> arr2 = {5,3,0};

    Node* root1 = buildBST(arr1);
    Node* root2 = buildBST(arr2);

    Node* root = mergeTwoBST(root1, root2);

    //to print the sorted seq of the merged BST:
    vector<int> seq;
    inorder(root, seq);

    for(int val: seq)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}