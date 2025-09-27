//VERTICAL ORDER TRAVERSAL (LeetCode 987)

//Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

//For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. 
//The root of the tree is at (0, 0).

//There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

#include <iostream>
#include <map>
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
            left = right =  NULL;
        }
};

void verticalOrder(Node* root)
{
    if(root == NULL) return; //base case

    map<int, vector<int>> m;  //to store the HD and the nodes that have the same HD in form of a vector
    queue<pair<Node*, int>> q; //to store the val at node and its Horizontal distance

    q.push({root,0});

    while(q.size() > 0)
    {
        Node* curr = q.front().first;  //to get the node val
        int currHD = q.front().second; //to get the HD
        q.pop();

        m[currHD].push_back(curr->data); //pushing the nodes having same HD into the vector<int>

        if(curr->left != NULL)
        {
            q.push({curr->left, currHD-1});
        }
        if(curr->right != NULL)
        {
            q.push({curr->right, currHD+1});
        }
    }

    //printing the result:
    for(auto it: m)
    {
        for(int x: it.second) //to print the value stored in vector 
        {
            cout << x << " ";
        }
        cout << endl;
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
    root->right->left->right = new Node(8);

    cout << "Vertical Order Traveral of Tree:\n";
    verticalOrder(root);
    
    return 0;
}