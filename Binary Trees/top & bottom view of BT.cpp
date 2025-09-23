// #newnotes

//TOP VIEW OF BINARY TREE
//Given the root of  a binary tree. We need to print those nodes which are visible through a lens kept at the top of the binary tree.


#include <iostream>
#include <queue>
#include <vector>
#include <map>
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

void topView(Node* root)
{
    //levelOrder traversal:

    queue<pair<Node*, int>> q; //store pair of the node value and the horizontal distance of node
    map <int,int> m; //used to store horizontal distance and value of the node
    q.push({root, 0}); //horizontal distance of root = 0

    while (q.size() > 0)
    {
        Node* curr = q.front().first; //to get the value of the node
        int currHD = q.front().second; //to get the horizontal distance of node
        q.pop();

        if(m.find(currHD) == m.end())  //if the HD occurs first time
        {
            m[currHD] = curr->data;
        }

        if(curr->left != NULL)
        {
            q.push({curr->left, currHD-1}); //(currHD-1) is the HD
        }

        if(curr->right != NULL)
        {
            q.push({curr->right, currHD + 1}); //(currHD+1) is the HD
        }
    }

    //now the map contains all nodes which are in the top view
    for(auto it: m)
    {
        cout << it.second << " "; //to print all node values in the map
    }
    cout << endl;
}

//BOTTOM VIEW OF BINARY TREE 
//print all the nodes that will be visible when viewing the tree from the bottom.

void bottomView(Node* root)
{
    queue<pair<Node*, int>> q; //to store the value and its HD
    map<int,int> m; //to store the HD and its corresponding value
    q.push({root,0});

    while(q.size() > 0)
    {
        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();

        m[currHD] = curr->data;

        if(curr->left != NULL)
        {
            q.push({curr->left, currHD-1});
        }
        if(curr->right != NULL)
        {
            q.push({curr->right, currHD + 1});
        }
    }

    for(auto it: m)
    {
        cout << it.second << " ";
    }
    cout << endl;
}

static int idx = -1;
Node* buildTree(vector<int>& preorder)
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

    cout << "Top view of BT = ";
    topView(root);

    cout << "\nBottom view of BT = ";
    bottomView(root);
    
    return 0;
}

//TC = O(n) for levelOrder traversal
//TC = O(log n) for find() fn of map

//Total TC = O(n * log(n) )