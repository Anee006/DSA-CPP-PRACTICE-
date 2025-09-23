//RIGHT SIDE VIEW and LEFT SIDE VIEW of BINARY TREE 

#include <iostream>
#include <queue>
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

//imagine yourself standing on the left side of tree, return the values of the nodes you can see ordered from top to bottom.
void leftView(Node* root)
{
    queue <Node*> q;
    q.push(root);

    cout << "Left side view = [ ";
    
    while(q.size() > 0)
    {
        int n = q.size();

        for(int i=0; i<n; i++)
        {
            Node* curr = q.front();
            q.pop();

            if(i == 0)
            {
                cout << curr->data << " ";
            }

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
    cout << "]" << endl;
}

//imagine yourself standing on the right side of tree, return the values of the nodes you can see ordered from top to bottom.
void rightView(Node* root)
{
    queue <Node*> q;
    q.push(root);

    cout << "Right side view = [ ";

    while(q.size() > 0)
    {
        int n = q.size();

        for(int i=0; i<n; i++)
        {
            Node* curr = q.front();
            q.pop();

            if(i == n-1)
            {
                cout << curr->data << " ";
            }

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

    cout << "]" << endl;
}

static int idx = -1;
Node* buildTree(vector <int>& preorder)
{
    idx++;
    Node* root = new Node(preorder[idx]);

    if(preorder[idx] == -1) return NULL;

    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

int main()
{
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(preorder);

    leftView(root);
    cout << "\n\n" ;
    rightView(root);

    return 0;

}