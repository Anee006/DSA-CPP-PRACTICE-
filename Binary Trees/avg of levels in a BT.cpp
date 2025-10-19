//AVERAGE OF LEVELS IN A BT (LeetCode 637)

//Given the root of a binary tree, return the average value of the nodes on each level in the form of an array

//Approach:
//Use level order traversal. For each level: count the no. of nodes, sum their values and find avg.
// average = sum / count


//TC = O(n)

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

vector<double> averageOfLevels(Node* root)
{
    vector<double> result;

    if(root == NULL) //base
    {
        return result;
    }

    queue <Node*> q;
    q.push(root);

    while(q.size() > 0)
    {
        int levelSize = q.size();
        long long levelSum = 0; //use long long to prevent overflow  //to calc sum of nodes in each level

        for(int i=0; i<levelSize; i++)
        {
            Node* curr = q.front();
            q.pop();

            levelSum += curr->data;

            if(curr->left)
                q.push(curr->left);

            if(curr->right)
                q.push(curr->right);
        }

        double avg = (double) levelSum / levelSize;
        result.push_back(avg);
    }
    return result;
}


int main()
{
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    vector <double> ans = averageOfLevels(root);
    cout << "Average of each level:\n";

    for(auto val : ans)
    {
        cout << val << " ";
    }

    return 0;
}