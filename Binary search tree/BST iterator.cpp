// #newnotes
//BST ITERATOR (LeetCode 173)

//Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST).

//LOGIC:
//use stack to perform inorder traversal (so that we get O(1) TC instead of the usual O(n) TC which recursion gives)

//1. in the stack store all the left-most nodes, starting from the root. So for the given BST, we will store first 7 then 3.
//2. When we have to return the next node using next() fn, we will return the val at top of the stack and then pop that val.
//If additional nodes exist in the right subtree of the node,then starting from the right child store the left-most nodes in the rst, in the stack.
//3. If size of stack > 0 means true, i.e, the current node has a next node else return false i.e no next node exists.

#include <iostream>
#include <stack>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int  val)
        {
            data = val;
            left = right = NULL;
        }
};

class BSTIterator
{
public:
    stack<Node*> s;

    //stores the left-most nodes in the stack
    void storeLeftNodes(Node* root)
    {
        while(root != NULL)
        {
            s.push(root);
            root = root->left; //as we need to store only the left-most nodes
        }
    }

    //The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller 
    //than any element in the BST, by initializing the pointer to a non-existent smallest number, 
    //the first call to next() will return the smallest element in the BST.

    BSTIterator(Node* root)
    {
        storeLeftNodes(root); //stores the left-most nodes of the root, including the root, in a stack
    }

    //int next() Moves the pointer to the right, then returns the number at the pointer.
    int next()
    {
        Node* ans = s.top(); //the val at top of the stack will be the "next" node
        s.pop();

        storeLeftNodes(ans->right);  //to store left-most nodes of current node starting from the root, which may exist in its right subtree 

        return ans->data; 
    }
    //TC = O(1)  (for avg case)

    //boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
    bool hasNext()
    {
        return s.size() > 0; //returns true if stack is not empty. If stack is empty, returns false.
    }

};

//SC = O(h) where h is the height of the BST


int main()
{
    Node* root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(15);
    root->right->left = new Node(9);
    root->right->right = new Node(20);

    BSTIterator * obj = new BSTIterator(root);
    cout << "Smallest val in the BST is: " << obj->next() << endl; //the first val is the smallest

    if(obj->hasNext()) cout << "Next ptr exists" << endl;  //returns true
    else cout << "No next ptr exists" << endl;

    cout << obj->next() << endl; //7
    cout << obj->next() << endl; //9
    cout << obj->next() << endl; //15
    cout << obj->next() << endl; //20

    if(obj->hasNext()) cout << "Next ptr exists" << endl;  //returns false
    else cout << "No next ptr exists" << endl;

    return 0;
}





