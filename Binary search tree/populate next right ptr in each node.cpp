//POPULATING NEXT RIGHT POINTERS IN EACH NODE (LeetCode 116)

//You are given a perfect binary tree where all leaves are on the same level, and every parent has two children
//Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
//Initially, all next pointers are set to NULL.

#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
        Node* next;

        Node(int val)
        {
            data = val;
            left = right = next = NULL;
        }
};

int main()
{
    return 0;
}

 