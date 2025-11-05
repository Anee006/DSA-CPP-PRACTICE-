// #newnotes
//POPULATING NEXT RIGHT POINTERS IN EACH NODE (LeetCode 116)

//You are given a perfect binary tree where all leaves are on the same level, and every parent has two children
//Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
//Initially, all next pointers are set to NULL.

//LOGIC:
//use a NULL ptr in level order traversal to track when the level ends.

#include <iostream>
#include <queue>
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

Node* connect(Node* root)
{
    if(root == NULL) //base case
    {
        return NULL;
    }

    queue<Node*> q;
    q.push(root);

    while(q.size() > 0)
    {
        int level_size = q.size();
        Node* prev = NULL; //used to track the previous val of a node //resets the prev value to NULL for each level

        for(int i=0; i<level_size; i++)
        {
            Node* curr = q.front();
            q.pop();

            //link the previous node in this level to the current node
            if(prev != NULL)
            {
                prev->next = curr;
            }
            prev = curr; //to update the prev ptr. The current node now becomes prev

            //push left and right child of the node, if they exist
            if(curr->left != NULL)
            {
                q.push(curr->left);
            }

            if(curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
    return root;
}
//TC = O(n)

//to print the created next right ptr
void printNextPointers(Node* root)
{
    if(root == NULL)
    {
        cout << "Tree is empty, so no next ptr exists\n";
        return;
    }

    cout << "\nDisplaying right next pointers for each level:\n";

    Node* level_start = root;
    while(level_start != NULL)
    {
        Node* curr = level_start;
        while(curr != NULL)
        {
            cout << curr->data << " -> ";

            if(curr->next == NULL) cout << "NULL";

            curr = curr->next;
        }
        cout << endl;
        level_start = level_start->left; //to move to the start of the next level
    }
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    //to populate the next right ptr of each node:
    root = connect(root);

    //to print the created right next ptr:
    printNextPointers(root);

    return 0;
}

 