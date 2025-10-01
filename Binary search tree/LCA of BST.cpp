// #newnotes
//LOWEST COMMON ANCESTOR OF BST (LeetCode 235)

//Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
//The lowest common ancestor is defined between two nodes p and q as the lowest node in tree that has both p and q as descendants 
//(where we allow a node to be a descendant of itself).”

//Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
//Output: 6


//LCA --> is the first node in whose lst and rst both p and q exist.

//to find p and q we will use BST properties.
//case 1: if(root->val > p->val && root->val > q->val) --> ans will be in the LST
//case 2: else if(root->val < p->val && root->val < q->val) --> ans will be in the RST
//case 3: p exists in the LST and q exists in the RST --> this is the condition for an LCA  --> return root as the ans
//case 4: when either of p or q is the LCA --> is handled in case 3 itself --> root will be the ans in this case as well

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

Node* LCA(Node* root, Node* p, Node* q)
{
    if(root == NULL) return NULL; //base case

    // case 1:
    if(root->data > p->data && root->data > q->data)  //means p & q are both less than root --> ans is in LST
    {
        return LCA(root->left, p, q);
    }

    //case 2:
    else if(root->data < p->data && root->data < q->data) //means p & q are both greater than root --> ans is in RST
    {
        return LCA (root->right, p, q);
    }

    //case 3:
    else
    {
        return root; 
    }
}
//TC = O(height of tree)
// Since, it is a balanced BST, TC = O(log n).

int main()
{
    Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);

    Node* p1 = root->left->right->left; //p = 3
    Node* q1 = root->left->right->right;  // q = 5
    Node* lca_1= LCA(root, p1, q1);

    cout << "LCA of " << p1->data << " and " << q1->data << " is: " << lca_1->data << endl;

    Node* p2 = root; // p = 6
    Node* q2 = root->right->right; // q = 9
    Node* lca_2 = LCA(root, p2, q2);

    cout << "LCA of " << p2->data << " and " << q2->data << " is: " << lca_2->data << endl;
    return 0;
}