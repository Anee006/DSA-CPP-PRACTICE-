// geeksforgeeks

// Given a binary tree and an integer k, where you start from the root at level 1. The cost of visiting a leaf node is equal to the 
// level of that leaf node. You can visit any number of leaf nodes, but the total cost of visiting them must not exceed k.
// Return the maximum number of leaf nodes that can be visited within the given budget.

/*
Input: root[] = [10, 8, 2, 3, N, 3, 6, N, N, N, 4], k = 8
Output: 2

Explanation:
Cost For visiting Leaf Node 3: 3
Cost For visiting Leaf Node 4: 4
Cost For visiting Leaf Node 6: 3
To maximize the number of visited leaves, choose the two cheapest leaves: Cost = 3 + 3 = 6 ≤ 8. 
Thus, the maximum number of leaf nodes that can be visited is 2.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// to find level of each leaf node and store it in costs
void findLevel(Node* root, int level, vector<int>& costs) {
    if(root == NULL) return;

    if(root->left == NULL && root->right == NULL) costs.push_back(level); // if it is a leaf node

    findLevel(root->left, level + 1, costs);
    findLevel(root->right, level + 1, costs);
}

int getCount(Node *root, int k) {
    vector<int> costs;

    findLevel(root, 1, costs); // root is at level 1

    sort(costs.begin(), costs.end()); // sort leaves in asc order

    int count = 0;

    for(int cost : costs) {
        if(cost > k) break;

        k -= cost;
        count++;
    }
    return count;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(8);
    root->left->left = new Node(3);
    root->right = new Node(2);
    root->right->left = new Node(3);
    root->right->right = new Node(6);
    root->right->left->right = new Node(4);

    int k = 8;

    cout << getCount(root, k);
    
    return 0;
}

// TC = O(n + L*log(L)) , where n = no. of nodes and L = no. of leaf nodes
// SC = O(L + h) , where h = height of tree