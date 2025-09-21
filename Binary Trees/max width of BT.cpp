// #newnotes

//MAXIMUM WIDTH OF BINARY TREE (Leetcode 662)

//Given the root of a binary tree, return the maximum width of the given tree.
//The maximum width of a tree is the maximum width among all levels.

//The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes are also counted into 
//the length calculation.

//Input: root = [1,3,2,5,3,null,9]
//Output: 4
//Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

//LOGIC:
//we will find the width for each "level" and the ans will be the max of all these calculated widths

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

int widthOfTree(Node* root)
{
    queue< pair<Node*, unsigned long long>> q;  //to store the value of a node and the idx at which it will be stored

    q.push({root,0}); //root is always pushed at idx = 0

    int maxWidth = 0; //to find the max width 

    while(q.size() > 0)
    {
        int currLevelSize = q.size(); 

        unsigned long long stIdx = q.front().second; //value at front of q will be the startIdx
        unsigned long long endIdx = q.back().second; //value at back of q will be the endIdx

        maxWidth = max(maxWidth, (int)(endIdx-stIdx + 1));  //(endIdx-stIdx + 1) is the width of a level

        //double loop is used bcoz we need to process stIdx and endIdx at the same time to apply the formula correctly
        for(int i=0; i<currLevelSize; i++)
        {
            auto curr = q.front();
            q.pop(); //we will pop the parent and then add its left and right child with their indexes

            if(curr.first->left)
            {
                q.push({curr.first->left, curr.second*2+1}); //curr.second*2+1 is the idx
            }
            if(curr.first->right)
            {
                q.push({curr.first->right, curr.second*2+2}); //curr.second*2+2 is the idx
            }
        }
    }
    return maxWidth;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->right = new Node(9);

    cout << "max width of BT = " << widthOfTree(root) << endl;
    return 0;
}

//TC = O(n)