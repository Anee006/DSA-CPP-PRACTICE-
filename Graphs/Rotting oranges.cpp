// #newnotes
// ROTTING ORANGES (LeetCode 994)
// (using BFS traversal)

// You are given an m x n grid where each cell can have one of three values:
// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4

// LOGIC:
// imagine the given 2D grid as a graph, where each cell can have atmost 4 connections (top, right, bottom, left).
// Perform BFS. In BFS, we visit only that cell which is unvisited and it should be a valid cell. 
// Also we will visit a cell only if it is a fresh orange (i.e if grid[i][j] == 1). 
 

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0; // this will store the final ans

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<pair<int,int>, int>> q; //to store the pair: (i,j) and time(t) taken for that node(orange) to rot

    // we will push all rotten oranges into the queue first --> multi source BFS
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j] == 2) // means if it is a rotten orange --> push it into queue
            {
                q.push({ {i,j} , 0 }); // time taken to rot a rotten orange is always = 0
                visited[i][j] = true;
            }
        }
    }

    // perform BFS
    while(q.size() > 0)
    {
        int i = q.front().first.first; // to get "i" val
        int j = q.front().first.second; // to get "j" val
        int time = q.front().second; // to get "time"
        q.pop();

        ans = max(ans, time); // max out of these two will be the final ans

        // check for neighbors:

        // (i-1 >= 0) checks if it is a valid cell, (!visited[i][j]) checks if it is "unvisited", (grid[i-1][j] == 1) checks if cell has "fresh orange"
        if(i-1 >= 0 && !visited[i-1][j] && grid[i-1][j] == 1) // for top neighbor
        {
            q.push({{i-1, j}, time+1}); // increase the time by +1
            visited[i-1][j] = true;
        }

        if(j+1 < m && !visited[i][j+1] && grid[i][j+1] == 1) // for right neighbor
        {
            q.push({{i, j+1}, time+1}); 
            visited[i][j+1] = true;
        }

        if(i+1 < n && !visited[i+1][j] && grid[i+1][j] == 1) // for bottom neighbor
        {
            q.push({{i+1, j}, time+1}); 
            visited[i+1][j] = true;
        }

        if(j-1 >= 0 && !visited[i][j-1] && grid[i][j-1] == 1) // for left neighbor
        {
            q.push({{i, j-1}, time+1}); 
            visited[i][j-1] = true;
        }
    }

    // check for any "fresh orange" remaining
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j] == 1 && !visited[i][j]) // if we have a fresh orange which is not visited
            {
                return -1; // means it is impossible to rot all oranges using the given rotten orange
            }
        }
    }

    return ans; // returns the min time taken to rot all fresh oranges
}

int main()
{
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1} // if we write: {2, 1, 1} in this line, then we will have 2 rotten oranges (i.e 2 source pts), hence time taken will now be = 2
    };

    if(orangesRotting(grid) != -1)
    {
        cout << "Min no. of minutes to rot all oranges = " << orangesRotting(grid) << endl;
    }

    else cout << "It is impossible to rot all oranges = " << endl;
    

    return 0;
}