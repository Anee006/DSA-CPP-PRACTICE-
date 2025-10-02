// #newnotes
//INORDER PREDECESSOR AND INORDER SUCCESSOR IN A BST

//Given a key, return its IP and IS , where IP = Inorder Predecessor and IS = Inorder Successor.
//Key might be a value which may not exist in the BST.
//Assume that the IP and IS for a key will always exist in the BST.

//IP --> the node just before the key in the inorder traversal of the BST
//IS --> the node just after the key in the inorder traversal of the BST

//LOGIC:
//Find the key in the BST following inorder manner. Assume that we will get IP and IS while searching for the key.
//Three cases are possible when searching for a key in a BST:
//Case 1: key < curr->val --> search for key in LST
//in case 1, when we are searching for the key in the LST, the root may be a potential candidate for IS.

//Case 2: key > curr->val -->search for key in RST. 
//in case 2, when we are searching for the key in the RST, the root may be a potential candidate for IP.

//Case 3: key == curr->val

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

//to get the IP
Node* rightMostInLeftSubTree(Node* root)
{
    Node* ans;

    while(root != NULL)
    {
        ans = root;
        root = root->right; //to get the right-most
    }
    return ans;
}

//to get the IS
Node* leftMostInRightSubtree(Node* root)
{
    Node* ans;

    while(root != NULL)
    {
        ans = root;
        root = root->left; //to get the left-most
    }
    return ans;
}

//returns the IP and IS of the key after storing it in a vector
vector<int> getInorderPreAndSuc(Node* root, int key)
{
    Node* curr = root;
    Node* pred = NULL; //to store the IP
    Node* succ = NULL; //to store the IS

    while(curr != NULL)
    {
        //case 1:
        if(key < curr->data) //search in LST
        {
            succ = curr; //current node may be a potential IS for the key, hence storing it.
            curr = curr->left;
        }

        //case 2:
        else if(key > curr->data) //search in RST
        {
            pred = curr; //curr may be a potential IP, hence storing it
            curr = curr->right;
        }

        //case 3:
        else
        {
            if(curr->left != NULL)
            {
                //find the IP

                pred = rightMostInLeftSubTree(curr->left);
            }

            if(curr->right != NULL)
            {
                //find the IS

                succ = leftMostInRightSubtree(curr->right);
            }
            break;
        }
    }
    return {pred->data, succ->data}; //returning a vector of IP and IS
}
//TC = O(h), h is the height of the BST
//SC = O(1)

int main()
{
    Node* root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int key = 7;
    vector<int> ans = getInorderPreAndSuc(root, key);

    cout << "Inorder Predecessor of " << key << " is: " << ans[0] << endl; // IP = 6
    cout << "Inorder Successor of " << key << " is: " << ans[1] << endl;   // IS = 8

    cout << "\n--------------------------------------------\n\n";
    
    int key2 = 6;
    vector<int> ans2 = getInorderPreAndSuc(root, key2);

    cout << "Inorder Predecessor of " << key2 << " is: " << ans2[0] << endl; // IP = 5
    cout << "Inorder Successor of " << key2 << " is: " << ans2[1] << endl;   // IS = 7
    
    return 0;
}