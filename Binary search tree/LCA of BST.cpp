//LOWEST COMMON ANCESTOR OF BST (LeetCode 235)

//Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
//The lowest common ancestor is defined between two nodes p and q as the lowest node in tree that has both p and q as descendants 
//(where we allow a node to be a descendant of itself).”

//Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
//Output: 6


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

}

int main()
{
    return 0;
}