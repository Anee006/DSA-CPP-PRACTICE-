// #newnotes

//BINARY TREE PATHS (LeetCode 257)

//Given the root of a binary tree, return all root-to-leaf paths in any order. Store the paths as strings
//NOTE: A leaf is a node with no children.

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

//helper fn --> to find all the paths from root to leaf node and store it in an "ans" vector of string
void allPaths(Node* root, string path, vector<string>& ans)
{
    //check if the node is a leaf node or not. //our recursion stops if we reach a leaf node
    if(root->left == NULL && root->right == NULL)
    {
        ans.push_back(path); //base case
        return;
    }

    //we will add arrows (->) only to the non-root nodes of the tree
    if(root->left)
    {
        allPaths(root->left, path + "->" + to_string(root->left->data), ans);
    }
    if(root->right)
    {
        allPaths(root->right, path + "->" + to_string(root->right->data), ans);
    }
}

vector <string> binaryTreePaths(Node* root)
{
    vector<string> ans; //to store all paths 

    string path = to_string(root->data); //we are assuming ki arrow add karne se pehle hamare paas path mai root already add hua hoga
    //to_string is used to convert data at root to a string

    allPaths(root, path, ans);

    return ans;

}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);

    vector<string> ans = binaryTreePaths(root);

    for(string val: ans)
    {
        cout << val << endl;
    }

    return 0;
}

//TC = O(n)