//SAME TREE (LeetCode 100)

//Given the roots of two binary trees p and q, write a function to check if they are the same or not.
//NOTE: Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

//Input: p = [1,2,3], q = [1,2,3]
//Output: true

//Input: p = [1,2], q = [1,null,2]
//Output: false

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

//STEPS:
//1. check if left subtree is same for p and q. (i.e, isLeftSame)
//2. check if right subtree is same for p and q. (i.e, isRightSame)
//3. Check if roots p and q are identical.
//tree is identical only if isLeftSame && isRightSame && p->data == q->data.

bool isSame(Node* p, Node* q)
{
    //base case:
    if(p == NULL || q == NULL)
    {
        return p == q;  //here, if both p and q are NULL then returns true else if any one of p and q is NULL, returns false.
    }

    //check if left subtree is same
    bool isLeftSame = isSame(p->left, q->left);

    //check if right subtree is same
    bool isRightSame = isSame(p->right, q->right);

    //check if trees are identical
    return isLeftSame && isRightSame && p->data == q->data; //all three conditions need to be true for both trees to be identical
}

int main()
{
    //for identical
    Node* p = new Node(1);
    p->left = new Node(2);
    p->right = new Node(3);

    Node* q = new Node(1);
    q->left = new Node(2);
    q->right = new Node(3);

    if(isSame(p,q)) 
        cout << "Both trees are identical\n";
    else   
        cout << "Both trees are not identical\n";
    
    //not identical:
    Node* root1 = new Node(1);
    root1->left = new Node(2);

    Node* root2 = new Node(1);
    root2->right = new Node(2);

    if(isSame(root1,root2)) 
        cout << "Both trees are identical\n";
    else   
        cout << "Both trees are not identical\n";

    return 0;
}

//TC = O(n), where n is size of tree (where both trees are identical)
