// #newnotes
// LeetCode 547
// using DFS

// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, 
// and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// Given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
// Return the total number of provinces.

/*
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
*/

// LOGIC
// is similar to the "no. of islands Q".
// each city acts as a node or vertex of the graph. 
// So, n x n means there are "n" cities

#include <iostream>
#include <vector>
using namespace std;

void DFS(int i, vector<bool>& vis, vector<vector<int>>& isConnected) { 
    vis[i] = true; // mark current city as visited

    // visit all neighbors of current city
    for(int v = 0; v < isConnected[i].size(); v++) {
        if(isConnected[i][v] == 1 && !vis[v]) { // if city & neighbor are connected and neighbor is not visited
            DFS(v, vis, isConnected);
        }
    }
}

int numOfProvinces(vector<vector<int>>& isConnected) {
    int n = isConnected.size();  // for rows
    int provinces = 0;

    vector<bool> vis(n, false);

    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            DFS(i, vis, isConnected);
            provinces++;  // One DFS call = one full province explored
        }
    }
    return provinces;
}

int main() {
    vector<vector<int>> isConnected = { // n = 3 here (3 x 3 matrix)
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

    cout << "No. of provinces = " << numOfProvinces(isConnected) << endl; // ans = 2

    return 0;
}

// TC = O(n*n)
// SC = O(n*n)