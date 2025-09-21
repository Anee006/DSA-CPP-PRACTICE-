// #newnotes

//MORRIS INORDER TRAVERSAL

//Used to print inorder traversal using iterative approach

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

vector<int> inOrder(Node* root)
{
    vector<int> ans;
    Node* curr = root;

    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            //find the Inorder Predecessor
            Node* IP = curr->left;

            while(IP->right != NULL && IP->right != curr)
            {
                IP = IP->right; //to find the right most node in the left subtree
            }

            //if the temporary thread is not created
            if(IP->right == NULL)
            {
                IP->right = curr;
                curr = curr->left;
            }
            else
            {
                //to delete the existing connection or thread
                IP->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    vector<int> ans = inOrder(root);

    for(int val: ans)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

//TC = O(n)