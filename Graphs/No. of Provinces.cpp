// #newnotes
// NO. OF PROVINCES (LeetCode 547)
// using DFS

// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, 
// and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// Given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
// Return the total number of provinces.

// LOGIC
// is similar to the "no. of islands Q".
// each city acts as a node or vertex of the graph.
// connections exist only along the row.

#include <iostream>
#include <vector>
using namespace std;

void DFS(int city, vector<vector<bool>>& vis, vector<vector<int>>& isConnected, int n) // no req of no. of cols here
{
    vis[city][city] = true; // mark current city as visited

    // visit all neighbors of current city
    for(int v = 0; v < n; v++)
    {
        if(isConnected[city][v] == 1 && !vis[v][v]) // if city & neighbor are connected and neighbor is not visited
        {
            DFS(v, vis, isConnected, n);
        }
    }
}

int numOfProvinces(vector<vector<int>>& isConnected)
{
    int n = isConnected.size();    // for rows
    int provinces = 0;

    vector<vector<bool>> vis(n, vector<bool>(n, false));

    for(int i=0; i<n; i++)
    {
        if(!vis[i][i])
        {
            DFS(i, vis, isConnected, n);
            provinces++;  // One DFS call = one full province explored
        }
    }
    return provinces;
}
// TC = O(n*n)
// SC = O(n*n)

int main()
{
    vector<vector<int>> isConnected = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

    cout << "No. of provinces = " << numOfProvinces(isConnected) << endl; // ans = 2

    return 0;
}