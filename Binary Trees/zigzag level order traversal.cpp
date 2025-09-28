//ZIG-ZAG LEVEL ORDER TRAVERSAL  OR  SPIRAL ORDER TRAVERSAL  (LeetCode 103)

//Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
//(i.e., from left to right, then right to left for the next level and alternate between)

//Using BFS (iterative) level order approach.

#include <iostream>
#include <vector>
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

vector<vector<int>> zigzagLevelOrder(Node* root)
{
    vector<vector<int>> result;  //to store the zigzag level order

    if(root == NULL) return result; //base case

    queue <Node*> q;
    q.push(root);

    bool leftToRight = true; //direction flag  //initially we start from left to right, then we reverse the direction to right to left.

    while(q.size() > 0)
    {
        int size = q.size();
        vector<int> level(size);  //to store the nodes that belong to the same level

        for(int i=0; i<size; i++)
        {
            Node* curr = q.front();
            q.pop();

            //find position to fill the node
            int idx = leftToRight ? i : (size-1-i);
            level[idx] = curr->data;

            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
        }
        result.push_back(level);
        leftToRight = !leftToRight; //to flip the direction for the next level
    }
    return result;
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

    vector<vector<int>> ans = zigzagLevelOrder(root);


    cout << "Zigzag Level Order Traversal:\n";

    for(auto level: ans)
    {
        for(int x: level)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

//TC = O(n)
//SC = O(n)