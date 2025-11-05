// INVERT BINARY TREE (LeetCode 226)

//Given the root of a binary tree, invert the tree, and return its root.

#include <iostream>
#include <queue>
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

Node* invertTree(Node* root)
{
    if(root == NULL) return NULL;

    //invert both subtrees 
    Node* leftInvert = invertTree(root->left);
    Node* rightInvert = invertTree(root->right);

    //swap left and right pointers
    root->left = rightInvert;
    root->right = leftInvert;

    return root;
}
//TC = O(n)

void levelOrder(Node* root)
{
    if(root == NULL) return;

    queue <Node*> q;
    q.push(root);
    q.push(NULL);

    while(q.size() > 0)
    {
        Node* curr = q.front();
        q.pop();

        if(curr == NULL)
        {
            if(!q.empty())
            {
                cout << endl;
                q.push(NULL);
                continue;
            }
            else
            {
                break;
            }
        }

        cout << curr->data << " ";

        if(curr->left != NULL) q.push(curr->left);
        if(curr->right != NULL) q.push(curr->right);
    }
}

int main()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(9);

    cout << "Before inverting:\n";
    levelOrder(root);

    invertTree(root);

    cout << "\n-----------------------------------------------\n";
    cout << "After inverting:\n";
    levelOrder(root);

    return 0;
}