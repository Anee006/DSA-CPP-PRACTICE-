//SUBTREE OF ANOTHER TREE (LeetCode 572)

//Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of 
//subRoot and false otherwise.


//Input: root = [3,4,5,1,2], subRoot = [4,1,2]
//Output: true

//LOGIC:
//1. find the root of subtree (i.e subroot) in the main tree.
//2. If subroot exists in the main tree then check for the rest of the part of the subroot i.e, check whether both subroots are identical or not
// (use the logic of "isSame Tree" Q to check whether subroot we found inside main tree and the original subroot are identical)

//first check if root (of main tree) = subroot, then try to find subroot in the left subtree and then try finding it in right sub tree.

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

bool isIdentical(Node* root1, Node* root2)
{
    if(root1 == NULL || root2 == NULL)
    {
        return root1 == root2;
    }

    return root1->data == root2->data 
            && isIdentical(root1->left, root2->left) 
            && isIdentical(root1->right, root2->right);

}

bool isSubtree(Node* root, Node* subRoot)
{
    //base case:
    if(root == NULL || subRoot == NULL)
    {
        return root == subRoot; //if returns true means subroot is equal to root, else subroot does not exist in the main tree
    }

    //checking whether the root and subroot are same
    if(root->data == subRoot->data && isIdentical(root, subRoot))
    {
        return true;  //means the given subroot exists in the main tree
    }

    //if the root of main tree is != subroot then check for the subroot in the left subtree, if not found in left subtree then check in the 
    //right subtree. 
    //If either one of the left/right subtree returns true means we have found the subroot in the main root.
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    
}

int main()
{
    Node* root = new Node(3);
    root->left = new Node(4);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(2);
    
    Node* subRoot = new Node(4);
    subRoot->left = new Node(1);
    subRoot->right = new Node(2);

    if(isSubtree(root, subRoot))
    {
        cout << "is subtree of another tree" << endl;
    }
    else cout << "Not a subtree of another tree\n";

    return 0;
}