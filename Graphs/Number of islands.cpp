// #newnotes
// NUMBER OF ISLANDS (LeetCode 200)

// Given an m x n 2D binary grid "grid" which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
// You may assume all four edges of the grid are all surrounded by water.

/*
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/

// LOGIC:
// Imagine the 2D grid as a graph. Consider only 1 as nodes of graph.
// The no. of disconnected components in the graph = No. of islands
// At max, any cell in the grid can have only 4 connections (as a cell has only 4 boundaries- left, right, top, bottom),
// this means, in the graph as well, each node can have atmost 4 neighbors only

#include <iostream>
#include <vector>
using namespace std;

void DFS(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& grid, int n, int m)
{

    // base case:
    if(i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j] != '1')
    {
        return;
    }

    visited[i][j] = true; // marked as visited

    // visit all 4 neighbors
    DFS(i-1, j, visited, grid, n, m); // for "Top" neighbor
    DFS(i, j+1, visited, grid, n, m); // for "Right" neighbor
    DFS(i+1, j, visited, grid, n, m); // for "Bottom" neighbor
    DFS(i, j-1, visited, grid, n, m); // for "Left" neighbor
}

int numOfIslands(vector<vector<char>>& grid)
{
    int islands = 0; // to count no. of islands
    int n = grid.size();    // for row
    int m = grid[0].size(); // for column

    vector<vector<bool>> visited(n, vector<bool>(m, false)); // to track visited and unvisited cells. Initialised with "False".

    // loop through each cell
    for(int i=0; i<n; i++)
    {
      for(int j=0; j<m; j++)
      {
          if(grid[i][j] == '1' && !visited[i][j]) // if cell is 1, and it is not yet visited --> visit it
          {
              DFS(i, j, visited, grid, n, m); // 1 DFS call --> We have visited 1 component of graph
              islands++; // means we have visted the island
          }
      }
    }
    return islands;
}
// TC = O(n*m)
// SC = O(n*m)

int main()
{
    // create the grid:
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    cout << "No. of islands = " << numOfIslands(grid) << endl;

    return 0;
}